#ifndef NETWORK_HTTPSTATUSCODES_HPP
#define NETWORK_HTTPSTATUSCODES_HPP
#include <string>

namespace Http
{

    class StatusCodes
    {
    private:
    public:
        enum Code
        {
            OK = 200,
            BadRequest = 400,
            NotFound = 404
        };
        static std::string getStatusMessage(Code code);
        StatusCodes(Code code);
    };

} // namespace network

#endif // NETWORK_HTTPSTATUSCODES_HPP
