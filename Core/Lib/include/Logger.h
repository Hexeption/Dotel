//
// Created by Keirb on 13/11/2017.
//

#ifndef DOTEL_LOGGER_H
#define DOTEL_LOGGER_H

#include <string>
#include <iostream>

namespace Dotel
{
    class Logger
    {
    public:
        Logger();
        ~Logger();

        void Log(const std::string error, bool isFatal);
    protected:
    private:
    };
}


#endif //DOTEL_LOGGER_H
