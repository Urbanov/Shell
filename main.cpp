

#include <signal.h>
#include <iostream>
#include "Shell.h"

//void kill_em_all(int sig)
//{
//    std::cout << "DOBRA JO TAM HIPOPOTAM HEHE " << std::endl;
//}

int main()
{
//    signal(SIGINT, (void (*)(int)) kill_em_all);
    Shell shell;
    shell.start();
}

