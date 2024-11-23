#include "network/http/request.hpp"
#include <algorithm>

Http::Request::Request(std::string buffer)
{
    isSSL = false;

    // look if buffer[0] is one of the ssl/tsl bytes
    auto sslBytes = {'\x80', '\x17', '\x16', '\x15', '\x14'};
    if (std::any_of(sslBytes.begin(), sslBytes.end(), [buffer](char sslByte)
                    { return buffer[0] == sslByte; }))
    {
        isSSL = true;
        return;
    }

    try
    {
        std::istringstream requestStream(buffer);
        std::getline(requestStream, this->requestLine);
        std::vector<std::string> requestVector;

        std::istringstream iss(requestLine);
        std::string word;

        while (iss >> word)
        {
            requestVector.push_back(word);
        }

        this->requestMethod = requestVector[0];

        this->requestURI = requestVector[1];
        this->requestProtocol = requestVector[2];

        setIndexUri();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

std::string Http::Request::getUri()
{
    return requestURI.substr(1);
}

std::string Http::Request::getMethod()
{
    return requestMethod;
}

std::string Http::Request::getProtocol()
{
    return requestProtocol;
}

void Http::Request::setIndexUri()
{
    if (this->requestURI == "/")
    {
        this->requestURI = "/index.html";
    }
}
