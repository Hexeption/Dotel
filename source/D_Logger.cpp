#include "D_Logger.h"

D_Logger::D_Logger()
{

}

D_Logger::~D_Logger()
{

}

void D_Logger::Log(const std::string error, bool isFatal)
{
    std::cerr << "Error: " << error << std::endl;

    if (isFatal)
    {
        std::exit(-1);
    }
}