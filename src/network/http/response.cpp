#include "network/http/response.hpp"

Http::Response::Response(std::string method, std::string uri, std::string protocol)
{
    Http::StatusCodes::Code code;

    std::string responseCode;
    std::string responseMessage;

    // check if the uri exists
    std::ifstream file(uri);
    if (file.good())
    {
        code = Http::StatusCodes::Code::OK;
    }
    else
    {
        file.close();
        code = Http::StatusCodes::Code::NotFound;
        uri = "404.html";
        file.open(uri);
    }

    // headers
    httpResponse = protocol + " " + std::to_string(static_cast<int>(code)) + " " + responseMessage + "\r\n";
    httpResponse += "Content-Type: text/html\r\n";
    httpResponse += "Connection: close\r\n";
    httpResponse += "\r\n"; // End of headers

    std::string fileContent((std::istreambuf_iterator<char>(file)),
                            std::istreambuf_iterator<char>());

    httpResponse += fileContent;

} // namespace network

std::string Http::Response::getResponse()
{
    return httpResponse;
}
