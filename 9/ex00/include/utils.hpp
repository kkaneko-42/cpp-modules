#pragma once

#include <sstream>
#include "Date.hpp"

template <class T>
T stringTo(const std::string& str) {
    T value;
    std::stringstream ss;
    ss << str;
    ss >> value;
    return value;
}

template <>
Date stringTo(const std::string& str);

std::string trimString(const std::string& str);
void printError(const std::string& msg);
