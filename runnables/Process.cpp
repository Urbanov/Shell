#include <unistd.h>
#include <iostream>
#include <memory.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <wait.h>
#include "Process.h"
#include "../Environment.h"
#include <regex>

int Process::run()
{
    if(forkNewProcess() == 0) {
        Environment::getInstance().registerProcess(pid);

        int state = 0;
        waitpid(pid, &state, 0);

        Environment::getInstance().unregisterProcess(pid);

        return WEXITSTATUS(state);
    }
}

char** Process::convertProgramArguments()
{
    auto** convertedArguments = new char* [arguments.size() + 2];
    int count = 0;
    std::regex programName("[^/]*?$");
    std::smatch match;
    if(std::regex_search(programPath.begin(), programPath.end(), match, programName)) {
        std::cout << "match " << match[0] << std::endl;
    }
    std::string name = match.str(0);
    convertedArguments[count] = new char[name.size() + 1];
    std::copy(name.begin(), name.end(), convertedArguments[count]);
    ++count;
    for (auto &element : arguments) {
        std::cout<<element->getValue().c_str()<<std::endl;
        convertedArguments[count] = strdup(element->getValue().c_str());
        count++;
//        std::cout<<convertedArguments[count]<<std::endl;
    }
    convertedArguments[count] = nullptr;
    return convertedArguments;
}

const std::string Process::getValue()
{
    if (!output.empty()) {
        run();
        return "";
    }
    setRedirections();
    return redirectOutput();

}

Process::Process(const std::string& programPath, const std::vector<std::shared_ptr<Value>>& arguments)
    : programPath(programPath)
    , arguments(arguments)
    , pid(-1)
{
    descriptors.resize(3);
    filePaths.resize(3);
    for (int i = 0; i < filePaths.size(); ++i) {
        descriptors[i] = i;
    }
}

int Process::getPid() const
{
    return pid;
}

void Process::changeStandardDescriptors()
{
    for (int i = 0; i < filePaths.size(); ++i) {
        if (!filePaths[i].empty()) {
            int flag = ((i == 0) ? O_RDONLY : O_WRONLY);
            descriptors[i] = open(filePaths[i].c_str(), flag | O_CREAT);
            dup2(descriptors[i], i);
            close(descriptors[i]);
        }
    }
}

const std::string& Process::getInput() const
{
    return input;
}

void Process::setInput(const std::string& input)
{
    Process::input = input;
}

const std::string& Process::getOutput() const
{
    return output;
}

void Process::setOutput(const std::string& output)
{
    Process::output = output;
}

void Process::setRedirections()
{
    if (!input.empty()) {
        filePaths[0] = input;
    }

    if (!output.empty()) {
        filePaths[1] = output;
    }
}

int Process::forkNewProcess()
{
    setRedirections();
    int result = fork();
    if (result == 0) {
        changeStandardDescriptors();

        execv(programPath.c_str(), convertProgramArguments());
        for (auto i : descriptors) {
            close(i);
        }
        std::cerr << "Failed to load program " << programPath.c_str() << std::endl;
        exit(1);
    } else if (result > 0) {
        pid = result;
        return 0;
    } else {

        std::cerr << "Fork failed." << std::endl;
        return -1;
    }
}

std::string Process::redirectOutput()
{
    const char* path = "/tmp/output_pipe";
    const size_t buf_len = 512;
    char buf[buf_len];
    int check = mkfifo(path, 0666);
    filePaths[1] = path;
    std::string value = redirectOutputReadLoop(path, buf, buf_len);
    unlink(path);
    return value;
}

std::string Process::redirectOutputReadLoop(const char* path, char* buf, size_t buf_len)
{
    std::string value;
    if (forkNewProcess() == 0) {
        int fd = open(path, O_RDONLY);
        ssize_t len = 0;
        while ((len = read(fd, buf, buf_len)) > 0) {
            value.append(buf, static_cast<unsigned long>(len));
        }
        close(fd);
    }
    return value;
}

void Process::setDescPath(int index, std::string& path)
{
    if (index >= 0 && index < filePaths.size()) {
        filePaths[index] = path;
    }
}
