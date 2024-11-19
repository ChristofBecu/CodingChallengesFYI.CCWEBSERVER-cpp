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
        set404Uri(file, code, uri);
    }

    createResponse(protocol, code, responseMessage, file);

} // namespace network

void Http::Response::createResponse(std::string &protocol, Http::StatusCodes::Code code, std::string &responseMessage, std::ifstream &file)
{
    httpResponse = protocol + " " + std::to_string(static_cast<int>(code)) + " " + responseMessage + "\r\n";
    httpResponse += "Content-Type: text/html\r\n";
    httpResponse += "Connection: close\r\n";
    httpResponse += "\r\n"; // End of headers

    std::string fileContent((std::istreambuf_iterator<char>(file)),
                            std::istreambuf_iterator<char>());

    httpResponse += fileContent;
}
void Http::Response::set404Uri(std::ifstream &file, Http::StatusCodes::Code &code, std::string &uri)
{
    file.close();
    code = Http::StatusCodes::Code::NotFound;
    uri = "404.html";
    file.open(uri);
    if (!file.good())
    {
        returnStandard404Page(uri, file);
    }
}

std::string Http::Response::getResponse()
{
    return httpResponse;
}

void Http::Response::returnStandard404Page(std::string &uri, std::ifstream &file)
{
    // 404 page does not exist, so create one
    std::ofstream file404(uri);
    file404 << "<!DOCTYPE html>\n";
    file404 << "<html>\n";
    file404 << "<head>\n";
    file404 << "<title>404 Not Found</title>\n";
    file404 << "</head>\n";
    file404 << "<body style=\"display: flex; justify-content: center; align-items: center; height: 100vh; margin: 0;\">\n";
    file404 << "<div style=\"text-align: center;\">";
    file404 << "<a href=\"index.html\">Go to home from code </a>";
    file404 << "<h1>404 Not Found</h1>\n";
    file404 << "</div>";
    file404 << "</body>\n";
    file404 << "</html>\n";

    file404.close();

    file.open(uri);
}
