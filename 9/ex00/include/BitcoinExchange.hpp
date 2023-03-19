#pragma once

#include "Database.hpp"
#include <string>
#define USAGE "usage: ./btc <filename>"

void exchange(const Database& db, const std::string& input);
