#ifndef HTTP_REQUEST_HPP
#define HTTP_REQUEST_HPP

#include <string>
#include <vector>
#include <iostream>
#include <sstream>

namespace Http
{
    class Request
    {
    private:
        std::string requestLine;
        std::string requestMethod;
        std::string requestURI;
        std::string requestProtocol;

        std::string request;
        std::string path;
        void setIndexUri();

    public:
        Request(std::string request);
        std::string getUri();
        std::string getMethod();
        std::string getProtocol();
        bool isSSL = false;
    };
}

#endif