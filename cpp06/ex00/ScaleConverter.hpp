#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <limits>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <sstream>


class ScalarConverter {
    private:
        ScalarConverter();
    public:
        static void convert(const std::string& input);
};

#endif 