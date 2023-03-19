#pragma once

#include <map>
#include <string>

template <class KeyType, class ValueType>
class KeyValueStore {
public:
    class IParser {
    public:
        IParser() {}
        IParser(const IParser&) {}
        virtual ~IParser() {}

        IParser& operator=(const IParser&) {}

        virtual bool parse(
            const std::string& filepath,
            std::string& key_title,
            std::string& value_title,
            std::map<KeyType, ValueType>& data
        ) = 0;
    };

    KeyValueStore(IParser* parser = NULL) : parser_(parser) {}
    KeyValueStore(const KeyValueStore& other) { *this = other; }
    virtual ~KeyValueStore() {}

    KeyValueStore& operator=(const KeyValueStore& rhs) {
        if (this != &rhs) {
            parser_ = rhs.parser_;
            data_ = rhs.data_;
        }
    }

    void setParser(const IParser* parser) { parser_ = parser; }

    bool load(const std::string& filepath) {
        if (parser_ == NULL) {
            return false;
        }

        return parser_->parse(filepath, key_title_, value_title_, data_);
    }

    bool getLowerBound(KeyType key, ValueType& value) const {
        typename std::map<KeyType, ValueType>::const_iterator it = data_.lower_bound(key);

        if (it == data_.end()) {
            return false;
        }

        value = it->second;
        return true;
    }

    void dump() const {
        std::cout << key_title_ << "," << value_title_ << std::endl;
        for (typename std::map<KeyType, ValueType>::const_iterator it = data_.begin(); it != data_.end(); ++it) {
            std::cout << it->first << "," << it->second << std::endl;
        }
    }

private:
    IParser* parser_;
    std::string key_title_;
    std::string value_title_;
    std::map<KeyType, ValueType> data_;
};
