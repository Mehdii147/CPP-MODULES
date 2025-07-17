#include "ScaleConverter.hpp"
#include <iomanip>
#include <cstdlib>

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    (void)other; 
    return *this; 
}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
    (void)other; 
}


ScalarConverter::ScalarConverter() {

}

ScalarConverter::~ScalarConverter() {
}

static bool isChar(const std::string& input) {
    return input.length() == 3 && input[0] == '\'' && input[2] == '\'';
}

static bool isInt(const std::string& input) 
{
    if (input.empty())
        return false;
    
    size_t start = 0;
    if (input[0] == '+' || input[0] == '-')
        start = 1;
    
    if (start == input.length())
        return false;
    
    for (size_t i = start; i < input.length(); i++) {
        if (!std::isdigit(input[i])) return false;
    }
    return true;
}

static bool isFloat(const std::string& input) {
    if (input == "-inff" || input == "+inff" || input == "nanf")
        return true;
    if (input.length() < 2 || input[input.length() - 1] != 'f') 
        return false;
    
    std::string withoutF = input.substr(0, input.length() - 1);
    size_t dotCount = 0;
    size_t start = 0;
    
    if (withoutF[0] == '+' || withoutF[0] == '-')
        start = 1;
    if (start == withoutF.length()) 
        return false;
    
    for (size_t i = start; i < withoutF.length(); i++) {
        if (withoutF[i] == '.') {
            dotCount++;
            if (dotCount > 1) return false;
        } else if (!std::isdigit(withoutF[i])) {
            return false;
        }
    }
    return dotCount == 1;
}

static bool isDouble(const std::string& input) {
    if (input == "-inf" || input == "+inf" || input == "nan")   
        return true;
    
    size_t dotCount = 0;
    size_t start = 0;
    
    if (input[0] == '+' || input[0] == '-') 
        start = 1;
    if (start == input.length())    
        return false;
    
    for (size_t i = start; i < input.length(); i++) {
        if (input[i] == '.') {
            dotCount++;
            if (dotCount > 1) return false;
        } else if (!std::isdigit(input[i])) {
            return false;
        }
    }
    return dotCount == 1;
}

static void printChar(double value) {
    std::cout << "char: ";
    if (std::isnan(value) || std::isinf(value)) {
        std::cout << "impossible" << std::endl;
    } else if (value < 0 || value > 127) {
        std::cout << "impossible" << std::endl;
    } else if (value < 32 || value == 127) {
        std::cout << "Non displayable" << std::endl;
    } else {
        std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
    }
}

static void printInt(double value) {
    std::cout << "int: ";
    if (std::isnan(value) || std::isinf(value)) {
        std::cout << "impossible" << std::endl;
    } else if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max()) {
        std::cout << "impossible" << std::endl;
    } else {
        std::cout << static_cast<int>(value) << std::endl;
    }
}

static void printFloat(double value) {
    std::cout << "float: ";
    if (std::isnan(value)) {
        std::cout << "nanf" << std::endl;
    } else if (std::isinf(value)) {
        if (value > 0) 
            std::cout << "+inff" << std::endl;
        else 
            std::cout << "-inff" << std::endl;
    } else if (value < -std::numeric_limits<float>::max() || value > std::numeric_limits<float>::max()) {
        std::cout << "impossible" << std::endl;
    } else {
        float f = static_cast<float>(value);
        if (std::isinf(f) && !std::isinf(value)) {
            std::cout << "impossible" << std::endl;
        } else {
            std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;
        }
    }
}

static void printDouble(double value) {
    std::cout << "double: ";
    if (std::isnan(value)) {
        std::cout << "nan" << std::endl;
    } else if (std::isinf(value)) {
        if (value > 0) std::cout << "+inf" << std::endl;
        else std::cout << "-inf" << std::endl;
    } else {
        std::cout << std::fixed << std::setprecision(1) << value << std::endl;
    }
}

void ScalarConverter::convert(const std::string& input) {
    double value = 0.0;
    
    if (input.empty()) {
        std::cout << "Error: empty input" << std::endl;
        return;
    }
    
    // Handle char literals
    if (isChar(input)) {
        value = static_cast<double>(input[1]);
    }
    // Handle pseudo-literals
    else if (input == "nanf" || input == "nan") {
        value = std::numeric_limits<double>::quiet_NaN();
    }
    else if (input == "+inff" || input == "+inf") {
        value = std::numeric_limits<double>::infinity();
    }
    else if (input == "-inff" || input == "-inf") {
        value = -std::numeric_limits<double>::infinity();
    }
    // Handle numeric literals
    else if (isInt(input) || isFloat(input) || isDouble(input)) {
        try {
                if (isFloat(input)) {
                    std::string withoutF = input.substr(0, input.length() - 1);
                    value = std::stod(withoutF);
                } else {
                    value = std::stod(input);
                }
            } catch (const std::exception& e) {
            std::cout << "Error: invalid conversion" << std::endl;
            return;
            }
    }
    else {
        std::cout << "Error: invalid input format" << std::endl;
        return;
    }
    
    printChar(value);
    printInt(value);
    printFloat(value);
    printDouble(value);
}