#pragma once

#include <string>
#include <deque>
#include <stack>
#define MAX_OPERATORS 256

namespace ft {
    class RPN {
    public:
        RPN();
        RPN(const RPN& src);
        ~RPN();

        RPN& operator=(const RPN& rhs);
        int run(const std::string& input);

    private:
        typedef int (*Operator)(int, int);
        static const std::string kInvalidTokenMsg;
        static const std::string kOperandsNotEnoughMsg;
        static const std::string kInvalidOperationMsg;
        static const std::string kInvalidNbOperandsMsg;

        std::deque<std::string> split(const std::string& input) const;
        Operator getOperator(const std::string& token) const;
        bool isValidToken(const std::string& token) const;

        // Operators
        static int add(int lhs, int rhs);
        static int sub(int lhs, int rhs);
        static int mul(int lhs, int rhs);
        static int div(int lhs, int rhs);
    };
}
