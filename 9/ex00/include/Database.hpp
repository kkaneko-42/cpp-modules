#pragma once

#include <map>
#include <string>

class Database {
public:
    typedef float RateType;
    typedef size_t Date;

    Database();
    Database(const Database&);
    ~Database();

    Database& operator =(const Database&);

    bool load(const std::string& filename);

private:
    static bool readFile(const std::string& filename, std::string& content);
    static void printError(const std::string& msg);

    static const std::string kFileOpenErrorMsg;
    std::string key_title_, value_title_;
    std::map<Date, RateType> data_;
};
