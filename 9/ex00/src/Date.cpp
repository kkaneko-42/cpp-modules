#include <sstream>
#include "Date.hpp"
#include "utils.hpp"
#include <iostream>

const std::string Date::kFormat = "YYYY-MM-DD";

Date::Date(const std::string& str) : year_(0), month_(0), day_(0) {
    parseString(str);
}

Date::Date(const Date& other) {
    *this = other;
}

Date::~Date() {

}

Date& Date::operator=(const Date& rhs) {
    if (this != &rhs) {
        year_ = rhs.year_;
        month_ = rhs.month_;
        day_ = rhs.day_;
    }
    return *this;
}

bool Date::operator<(const Date& rhs) const {
    if (year_ == rhs.year_) {
        if (month_ == rhs.month_) {
            return day_ < rhs.day_;
        }
        return month_ < rhs.month_;
    }
    return year_ < rhs.year_;
}

std::string Date::toString() const {
    std::stringstream ss;
    ss << year_ << "-" << +month_ << "-" << +day_;
    return ss.str();
}

bool Date::parseString(const std::string& str) {
    if (str.size() != kFormat.size()) {
        return false;
    }

    std::string year_str    = str.substr(kFormat.find_first_of('Y'), 4);
    std::string month_str   = str.substr(kFormat.find_first_of('M'), 2);
    std::string day_str     = str.substr(kFormat.find_first_of('D'), 2);

    return setYear(year_str) && setMonth(month_str) && setDay(day_str);
}

bool Date::setYear(const std::string& year_str) {
    year_ = stringTo<Year>(year_str);
    return true;
}

bool Date::setMonth(const std::string& month_str) {
    Month month = stringTo<Month>(month_str);

    if (1 <= month && month <= 12) {
        month_ = month;
        return true;
    }

    return false;
}

bool Date::setDay(const std::string& day_str) {
    Day day = stringTo<Day>(day_str);

    if (1 <= day && day <= 31) {
        day_ = day;
        return true;
    }
    return false;
}

std::ostream& operator<<(std::ostream& os, const Date& date) {
    os << date.toString();
    return os;
}
