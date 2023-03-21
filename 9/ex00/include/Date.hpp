#pragma once

#include <string>
#include <ostream>

struct Date {
    typedef unsigned short Year;
    typedef unsigned short Month;
    typedef unsigned short Day;

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
