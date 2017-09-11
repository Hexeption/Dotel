//
// Created by Keir on 11/09/2017.
//

#ifndef DOTEL_D_LOGGER_H
#define DOTEL_D_LOGGER_H


#include <string>
#include <iostream>

class D_Logger
{
public:
    D_Logger();

    ~D_Logger();

    void Log(const std::string error, bool isFatal);

protected:
private:
};


#endif //DOTEL_D_LOGGER_H
