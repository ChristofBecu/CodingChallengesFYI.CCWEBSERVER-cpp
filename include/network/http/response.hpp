#ifndef HTTP_RESPONSE_HPP
#define HTTP_RESPONSE_HPP

#include <string>
#include <fstream>
#include <network/http/statusCodes.hpp>

namespace Http
{
    class Response
    {
    private:
        std::string httpResponse;

    public:
        Response(std::string method, std::string uri, std::string protocol);
        std::string getResponse();
    };
}

#endif
