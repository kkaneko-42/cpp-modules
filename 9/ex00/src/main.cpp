#include <iostream>
#include "BitcoinExchange.hpp"
#include "CSVparser.hpp"

typedef BitcoinExchange::ExchangeRate ExchangeRate;

int main(int ac, char** av) {
    // validate args
    if (ac != 2) {
        std::cerr << BitcoinExchange::kUsage << std::endl;
        return EXIT_FAILURE;
    }

    // setup db
    CSVparser<Date, ExchangeRate> parser;
    KeyValueStore<Date, ExchangeRate> db(&parser);

    // load db content
    const std::string csv_name = "data.csv";
    if (!db.load(csv_name)) {
        return EXIT_FAILURE;
    }

    // db.dump();

    // execute exchanging
    if (!BitcoinExchange::exchange(db, av[1])) {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
