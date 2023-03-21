#pragma once

#include <fstream>
#include "KeyValueStore.hpp"
#include "utils.hpp"

template <class KeyType, class ValueType>
class CSVparser : public KeyValueStore<KeyType, ValueType>::IParser {
public:
    bool parse(
        const std::string& filepath,
        std::string& key_title,
        std::string& value_title,
        std::map<KeyType, ValueType>& data
    ) {
        std::ifstream ifs(filepath.c_str());

        if (!ifs) {
            return false;
        }

        current_row_ = 0;
        std::string row;
        while (std::getline(ifs, row)) {
            if (current_row_ == 0) {
                if (!parseTitle(row, key_title, value_title)) {
                    return false;
                }
            } else if (!parseRow(row, data)){
                return false;
            }

            ++current_row_;
        }
        return true;
    }

private:
    bool parseTitle(const std::string& row, std::string& key_title, std::string& value_title) {
        const std::string::size_type delim_pos = row.find(",");
        if (delim_pos == std::string::npos) {
            return false;
        }

        key_title = trimString(row.substr(0, delim_pos));
        value_title = trimString(row.substr(delim_pos));
        return true;
    }

    bool parseRow(const std::string& row, std::map<KeyType, ValueType>& data) {
        const std::string::size_type delim_pos = row.find(",");
        if (delim_pos == std::string::npos) {
            return false;
        }

        std::string key_str = trimString(row.substr(0, delim_pos));
        KeyType key = stringTo<KeyType>(key_str);

        std::string value_str = trimString(row.substr(delim_pos + 1));
        ValueType value = stringTo<ValueType>(value_str);

        data.insert(std::make_pair<const KeyType, ValueType>(key, value));
        return true;
    }
    
    size_t current_row_;
};
