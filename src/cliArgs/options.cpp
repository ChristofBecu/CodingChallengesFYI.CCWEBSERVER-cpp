#include "cliArgs/options.hpp"

namespace CliArguments
{
    enum Options
    {
        PORT,
        HELP
    };

    const std::unordered_map<std::string, Options> optionsMap =
        {
            {"-p", PORT},
            {"--port", PORT},
            {"-h", HELP},
            {"--help", HELP}};

    std::string usage = "Usage: ccwebserver [options]\n"
                        "Options:\n"
                        "  -p, --port <port>  Set the port to listen on\n"
                        "  -h, --help         Show this help message\n\n"
                        "Press Ctrl+C to stop the server.";

    void showUsage()
    {
        std::cout << CliArguments::usage << std::endl;
    }

    std::string port;

    void parseArguments(int argc, char *argv[])
    {
        for (int i = 1; i < argc; i++)
        {
            std::string arg = argv[i];

            if (optionsMap.find(arg) != optionsMap.end())
            {
                switch (optionsMap.at(arg))
                {
                case PORT:
                    if (i + 1 < argc)
                    {
                        port = argv[i + 1];
                        i++;
                    }
                    break;
                case HELP:
                    showUsage();
                    exit(0);
                    break;
                default:
                    break;
                }
            }
        }
    }
}