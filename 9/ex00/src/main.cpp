#include <iostream>
#include "BitcoinExchange.hpp"
#include "Database.hpp"

int main(int ac, char** av) {
    if (ac != 2) {
        std::cerr << USAGE << std::endl;
        return 1;
    }

    const std::string db_name = "data.csv";
    Database database;
    if (!database.load(db_name)) {
        return 1;
    }

    exchange(database, av[1]);

    return 0;
}
