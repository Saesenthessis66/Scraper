//
// Created by lucja on 14.06.2024.
//
#include "..//Text/OutputFormatter.hpp"

int main()
{
    SetConsoleOutputCP(CP_UTF8);

    OutputFormatter out = OutputFormatter();

    std::cout<<out.getData();

    int a; std::cin>>a; // lock command line

    return 0;
}
