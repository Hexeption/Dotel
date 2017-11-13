//
// Created by Keirb on 13/11/2017.
//

#include "Logger.h"

Dotel::Logger::Logger()
{

}

Dotel::Logger::~Logger()
{

}

void Dotel::Logger::Log(const std::string error, bool isFatal)
{
    std::cerr << "Error: " << error << std::endl;

    if(isFatal)
    {
        std::exit(-1);
    }
}
