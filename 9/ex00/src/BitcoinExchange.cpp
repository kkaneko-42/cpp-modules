#include <fstream>
#include <iostream>
#include "BitcoinExchange.hpp"
#include "utils.hpp"

const std::string BitcoinExchange::kUsage = "usage: ./btc <filename>";
const BitcoinExchange::ExchangeRate BitcoinExchange::kHavingMax = 1000;

bool BitcoinExchange::exchange(const KeyValueStore<Date, ExchangeRate>& db, const std::string& input_file) {
    std::ifstream ifs(input_file);

    if (!ifs) {
        return false;
    }

    std::string row;
    while (std::getline(ifs, row)) {
        std::pair<Date, ExchangeRate> row_info;

        if (!parseRow(row, row_info)) {
            continue;
        }
        doExchange(db, row_info);
    }

    return true;
}

bool BitcoinExchange::parseRow(const std::string& row, std::pair<Date, ExchangeRate>& result) {
    const std::string::size_type delim_pos = row.find("|");
    if (delim_pos == std::string::npos) {
        return false;
    }

    std::string date_str = trimString(row.substr(0, delim_pos));
    if (!result.first.parseString(date_str)) {
        printError("bad input => " + date_str);
        return false;
    }

    std::string value_str = trimString(row.substr(delim_pos + 1));
    ExchangeRate having_coins = stringTo<ExchangeRate>(value_str);
    if (!validateHavingCoins(having_coins)) {
        return false;
    }
    result.second = having_coins;

    return true;
}

void BitcoinExchange::doExchange(const KeyValueStore<Date, ExchangeRate>& db, const std::pair<Date, ExchangeRate>& row_info) {
    const Date date = row_info.first;
    const ExchangeRate having = row_info.second;

    ExchangeRate rate;
    db.getLowerBound(date, rate);
    
    std::cout << date << " => " << having << " = " << static_cast<float>(having * rate) << std::endl;
}

bool BitcoinExchange::validateHavingCoins(ExchangeRate having) {
    if (having < 0) {
        printError("not a positive number.");
        return false;
    } else if (having > kHavingMax) {
        printError("exceed max value");
        return false;
    }

    return true;
}
