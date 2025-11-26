#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>

class RPN
{
    private:
        std::string _expression;
    public:
        RPN(const std::string &expression);
        RPN(const RPN &other);
        RPN &operator=(const RPN &other);
        ~RPN();

        void parseFile();
        int calculate();
        bool isToken(char c);
        int Operations(int a, int b, char op);
};

#endif