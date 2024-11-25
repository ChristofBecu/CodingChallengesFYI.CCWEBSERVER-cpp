#ifndef OPTIONS_H
#define OPTIONS_H

#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

namespace CliArguments
{
    extern std::string port;

    void parseArguments(int argc, char *argv[]);

    void showUsage();
}

#endif