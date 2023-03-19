#pragma once

#include "KeyValueStore.hpp"
#include "Date.hpp"

class BitcoinExchange {
public:
    typedef float ExchangeRate;

    static bool exchange(const KeyValueStore<Date, ExchangeRate>& db, const std::string& input_file);

    static const std::string kUsage;

private:
    static bool parseRow(const std::string& row, std::pair<Date, ExchangeRate>& result);
    static void doExchange(const KeyValueStore<Date, ExchangeRate>& db, const std::pair<Date, ExchangeRate>& row_info);
    static bool validateHavingCoins(ExchangeRate having);

    static const ExchangeRate kHavingMax;
};
