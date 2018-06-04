//
// Created by grzegorz on 04.06.18.
//

#include <cstring>
#include "Process.h"

int Process::parseArgsAndExecute(std::string* args, int& nArgs)
{
    char** cArgs = stringToCStringTable(args, nArgs);
    int pipe = countPipes(args, nArgs);
    if(pipe == 0)
    {
        std::string* in = checkRedirect(args, nArgs, "<");
        std::string* out = checkRedirect(args, nArgs, ">");
        if((in != nullptr && *in == " ") || (out != nullptr && *out == " "))
        {
            return -1;
        }
        createSingleProcess(cArgs, in, out);
        if(in != nullptr)
        {
            delete in;
        }
        if(out != nullptr)
        {
            delete out;
        }
    }
    else if(pipe > 0)
    {
        //TODO
    }
    return -1;
}

int Process::countPipes(std::string* args, int& nArgs)
{
    bool redirect = false;
    int result = 0;
    for(int i = 0; i < nArgs; ++i)
    {
        if(args[i] == "|")
        {
            if(i == 0 || i + 1 >= nArgs)
            {
                std::cerr << "Pipe as first or last argument\n";
                return -1;
            }
            ++result;
        }
        else if(args[i] == "<" || args[i] == ">")
        {
            redirect = true;
        }
    }
    if(result > 0 && redirect)
    {
        std::cerr << "Trying to redirect and create pipeline simultaneously\n";
        return -1;
    }
    return result;
}

std::string* Process::checkRedirect(std::string* args, int& nArgs, std::string redirectType)
{
    std::string* result = nullptr;
    for(int i = 0; i < nArgs; ++i)
    {
        if(args[i] == redirectType)
        {
            if(i == 0 || i + 1 >= nArgs || result != nullptr)
            {
                std::cerr << "Redirect as first or last argument, or more then one the same redirect\n";
                *result = " ";
                return result;
            }
            result = new std::string;
            *result = args[i + 1];
        }
    }
    if(result != nullptr && (*result == "<" || *result == ">"))
    {
        std::cerr << "Argument for redirect file is another redirection\n";
        *result = " ";
        return result;
    }
    return result;
}

int Process::createSingleProcess(char** args, std::string* in = nullptr, std::string* out = nullptr)
{
    pid_t pid;
    int status;
    int inFd = -1, outFd = -1;
    pid = fork();
    if(pid == 0)
    {
        if(in != nullptr)
        {
            inFd = open((*in).c_str(), O_RDONLY);
            if(inFd < 0)
            {
                std::cerr << "File to redirect stdin does not exist\n";
                exit(-1);
            }
            dup2(inFd, 0);
        }
        if(out != nullptr)
        {
            outFd = open((*out).c_str(), O_RDWR | O_CREAT);
            if(outFd < 0)
            {
                std::cerr << "File to redirect stdout does not exist\n";
                exit(-1);
            }
            dup2(outFd, 1);
        }
        if(execvp(args[0], args) == -1)
        {
            std::cerr << "Program exec does not exist\n";
            exit(-1);
        }
    }
    else if(pid < 0)
    {
        std::cerr << "Cannot create new process\n";
    }
    else
    {
        waitpid(pid, &status, WUNTRACED);
        if(inFd >= 0)
        {
            close(inFd);
        }
        if(outFd >= 0)
        {
            close(outFd);
        }
        //can do something with the status
    }
    return 0;
}

char** Process::stringToCStringTable(std::string* args, int& nArgs)
{
    char** result = new char*[nArgs + 1];
    for(int i = 0; i < nArgs; ++i)
    {
        char* cstring = new char[args[i].size() + 1];
        std::strcpy(cstring, args[i].c_str());
        result[i] = cstring;
    }
    result[nArgs] = NULL;
    return result;
}