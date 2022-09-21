#ifndef CONVERTER_HPP
#define CONVERTER_HPP

#include <string>
#include <limits>
#include <iostream>

// bool isChar( const std::string& input );
// bool isInt( const std::string& input );
bool isFloat( const std::string& input );
bool isDouble( const std::string& input );

// Static class
class Converter
{
    public:
        typedef union
        {
            char c;
            int i;
            float f;
            double d;
        }   uValue;

        typedef enum
        {
            CHAR,
            INT,
            FLOAT,
            DOUBLE,
            UNKNOWN
        }   eType;

        typedef struct
        {
            eType type;
            uValue value;
        }   Result;

        static const std::string kImpossibleMsg;

        // static eType typeOf( const std::string& input );
        // static Result convert( const std::string& input );
        // static char toChar( const std::string& input );
        // static int toInt( const std::string& input );
        static float toFloat( const std::string& input );
        static double toDouble( const std::string& input );

    private:
        Converter( void );
};

#endif
