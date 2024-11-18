#include "network/http/request.hpp"

Http::Request::Request(std::string buffer)
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

    if (this->requestURI == "/")
    {
        this->requestURI = "/index.html";
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
