#include "RPN.hpp"
#include <cstring>
#include <stdexcept>

const std::string ft::RPN::kInvalidTokenMsg = "Invalid token found";
const std::string ft::RPN::kOperandsNotEnoughMsg = "Operands not enough for operation";
const std::string ft::RPN::kInvalidOperationMsg = "Invalid operation";
const std::string ft::RPN::kInvalidNbOperandsMsg = "Number of operands is invalid";

ft::RPN::RPN() {

}

ft::RPN::RPN(const RPN& src) {
    *this = src;
}

ft::RPN::~RPN() {

}

ft::RPN& ft::RPN::operator=(const ft::RPN& rhs) {
    return *this;
}

int ft::RPN::run(const std::string& input) {
    std::deque<std::string> tokens = split(input);

    std::stack<int> calc_stack;
    while (!tokens.empty()) {
        const std::string& token = tokens.front();
        // validate token
        if (!isValidToken(token)) {
            throw std::runtime_error(kInvalidTokenMsg + ": " + token);
        }

        Operator op = getOperator(token);
        // token is operator
        if (op != NULL) {
            // operands not enough
            if (calc_stack.size() < 2) {
                throw std::runtime_error(kOperandsNotEnoughMsg + ": " + token);
            }

            // get operands
            const int rhs = calc_stack.top(); calc_stack.pop();
            const int lhs = calc_stack.top(); calc_stack.pop();

            // execute operation
            try {
                calc_stack.push(op(lhs, rhs));
            } catch (const std::exception& e) {
                throw std::runtime_error(kInvalidOperationMsg + ": " + e.what());
            }
        } else {
            // token is digit
            calc_stack.push(static_cast<int>(token[0] - '0'));
        }

        tokens.pop_front();
    }

    if (calc_stack.size() != 1) {
        throw std::runtime_error(kInvalidNbOperandsMsg);
    }

    return calc_stack.top();
}

std::deque<std::string> ft::RPN::split(const std::string& input) const {
    std::deque<std::string> result;

    size_t i = 0;
    while (true) {
        // skip space
        while (std::isspace(input[i])) {
            ++i;
        }
        if (i == input.size()) {
            break;
        }

        // create token
        const size_t begin_idx = i;
        while (i < input.size() && !std::isspace(input[i])) {
            ++i;
        }
        result.push_back(input.substr(begin_idx, i - begin_idx));
    }

    return result;
}

ft::RPN::Operator ft::RPN::getOperator(const std::string& token) const {
    if (token == "+") {
        return add;
    } else if (token == "-") {
        return sub;
    } else if (token == "*") {
        return mul;
    } else if (token == "/") {
        return div;
    } else {
        return NULL;
    }
}

bool ft::RPN::isValidToken(const std::string& token) const {
    if (token.size() != 1) {
        return false;
    }

    return ('0' <= token[0] && token[0] <= '9') || getOperator(token) != NULL;
}

int ft::RPN::add(int lhs, int rhs) {
    return lhs + rhs;
}

int ft::RPN::sub(int lhs, int rhs) {
    return lhs - rhs;
}

int ft::RPN::mul(int lhs, int rhs) {
    return lhs * rhs;
}

int ft::RPN::div(int lhs, int rhs) {
    if (rhs == 0) {
        throw std::runtime_error("divided by zero");
    }
    return lhs / rhs;
}
