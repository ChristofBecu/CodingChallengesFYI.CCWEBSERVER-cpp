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
        void returnStandard404Page(std::string &uri, std::ifstream &file);
        void set404Uri(std::ifstream &file, Http::StatusCodes::Code &code, std::string &uri);
        void createResponse(std::string &protocol, Http::StatusCodes::Code code, std::string &responseMessage, std::ifstream &file);

    public:
        Response(std::string method, std::string uri, std::string protocol);
        std::string getResponse();
    };
}

#endif
