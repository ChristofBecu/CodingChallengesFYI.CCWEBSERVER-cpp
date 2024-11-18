#include "network/http/statusCodes.hpp"

namespace Http
{

    StatusCodes::StatusCodes(Code code)
    {
        getStatusMessage(code);
    }

    std::string StatusCodes::getStatusMessage(Code code)
    {
        switch (code)
        {
        case Code::OK:
            return "OK";
        case Code::BadRequest:
            return "Bad Request";
        case Code::NotFound:
            return "Not Found";
        default:
            return "Unknown";
        }
    }

} // namespace network
