#pragma once

#include <string>
#include <cstdint>
#include <ostream>

struct Date {
    typedef uint16_t Year;
    typedef uint16_t Month;
    typedef uint16_t Day;

    Date(const std::string& str = "0000-00-00");
    Date(const Date& other);
    ~Date();

    Date& operator=(const Date& rhs);
    bool operator<(const Date& rhs) const;

    std::string toString() const;
    bool parseString(const std::string& str);

    bool setYear(const std::string& year_str);
    bool setMonth(const std::string& month_str);
    bool setDay(const std::string& day_str);

    static const std::string kFormat;
    Year year_;
    Month month_;
    Day day_;
};

std::ostream& operator<<(std::ostream& os, const Date& date);
