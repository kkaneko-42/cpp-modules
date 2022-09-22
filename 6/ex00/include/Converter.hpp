#ifndef CONVERTER_HPP
#define CONVERTER_HPP

#include <string>
#include <limits>
#include <iostream>

bool isChar( const std::string& input );
bool isInt( const std::string& input );
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
            CHAR = 0,
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
        static const std::string kNotPrintableMsg;

        static eType typeOf( const std::string& input );
        static Result convert( const std::string& input );
        static char toChar( const std::string& input );
        static int toInt( const std::string& input );
        static float toFloat( const std::string& input );
        static double toDouble( const std::string& input );

    private:
        Converter( void );
};

std::ostream& operator<<( std::ostream& os, const Converter::Result &res );
std::ostream& operator<<( std::ostream& os, const Converter::eType type );

// return true if a + b overflows
template < class T >
static bool overflowIfAdd(T a, T b)
{
    return (std::numeric_limits<T>::max() - b < a);
}

// return true if a * b overflows
template < class T >
static bool overflowIfMul(T a, T b)
{
    if (b == 0) {
        return (false);
    }

    return (std::numeric_limits<T>::max() / b < a);
}

// return true if a + b underflows
template < class T >
static bool underflowIfAdd(T a, T b)
{
    return (std::numeric_limits<T>::min() - b > a);
}

// return true if a / b underflows
template < class T >
static bool underflowIfDiv(T a, T b)
{
    return (std::numeric_limits<T>::min() * b > a);
}

// cal a^b
template < class T >
static T ftPow(T a, int b) {
    T res = 1;

    if (a == 0) {
        return (0);
    }

    while (b > 0) {
        if (overflowIfMul<T>(res, a)) {
            throw std::overflow_error("overflow");
        }
        res *= a;
        --b;
    }
    while (b < 0) {
        if (underflowIfDiv<T>(res, a)) {
            throw std::underflow_error("underflow");
        }
        res /= a;
        ++b;
    }
    return (res);
}

#endif
