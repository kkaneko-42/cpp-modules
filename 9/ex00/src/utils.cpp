#include <iostream>
#include "utils.hpp"

std::string trimString(const std::string& str) {
    size_t begin_pos = 0;
    while (isspace(str[begin_pos])) {
        ++begin_pos;
    }

    size_t end_pos = begin_pos;
    while (!isspace(str[end_pos]) && end_pos < str.size()) {
        ++end_pos;
    }

    return str.substr(begin_pos, end_pos - begin_pos);
}

template <>
Date stringTo<Date>(const std::string& str) {
    Date date(str);
    return date;
}

void printError(const std::string& msg) {
    std::cout << "Error: " << msg << std::endl;
}
