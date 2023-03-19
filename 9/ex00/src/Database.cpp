#include "Database.hpp"
#include <fstream>
#include <iostream>

const std::string Database::kFileOpenErrorMsg = "could not open file.";

Database::Database() {}
Database::Database(const Database& other) {
    *this = other;
}
Database::~Database() {}

Database& Database::operator =(const Database& rhs) {
    if (this != &rhs) {
        data_ = rhs.data_;
    }

    return *this;
}

bool Database::load(const std::string& filename) {
    std::string content;
    if (!readFile(filename, content)) {
        return false;
    }

    return true;
}

bool Database::readFile(const std::string& filename, std::string& content) {
    // open file
    std::ifstream ifs(filename);
    if (!ifs) {
        printError(kFileOpenErrorMsg);
        return false;
    }

    // read file
    std::string row;
    while (std::getline(ifs, row)) {
        content += row + "\n";
    }

    // return as succcess
    return true;
}

void Database::printError(const std::string& msg) {
    std::cerr << "Error: " << msg << std::endl;
}
