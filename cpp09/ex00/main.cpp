#include "BitcoinExchange.hpp"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

static const char *kDBPath = "data.csv"; 

static void printError(const std::string &msg) {
    std::cerr << msg << std::endl;
}

static bool parseInputLine( std::string &line, std::string &date, double &value, std::string &err) {
    size_t bar = line.find('|');
    if (bar == std::string::npos) {
        err = std::string("Error: bad input => ") + line;
        return false;
    }
    date = BitcoinExchange::trim(line.substr(0, bar));
    std::string rhs = BitcoinExchange::trim(line.substr(bar + 1));
    if (!BitcoinExchange::isValidDate(date)) {
        err = std::string("Error: bad input => ") + line;
        return false;
    }
    double v;
    if (!BitcoinExchange::parseNumber(rhs, v)) {
        err = std::string("Error: bad input => ") + line;
        return false;
    }
    if (v < 0) {
        err = "Error: not a positive number.";
        return false;
    }
    if (v > 1000) {
        err = "Error: too large a number.";
        return false;
    }
    value = v;
    return true;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printError("Error: could not open file.");
        return 1;
    }

    BitcoinExchange be;
    if (!be.loadDatabase(kDBPath) || !be.hasRates()) {
        printError("Error: could not open file.");
        return 1;
    }

    std::ifstream in(argv[1]);
    if (!in.is_open()) {
        printError("Error: could not open file.");
        return 1;
    }

    std::string line;
    bool first = true;
    while (std::getline(in, line)) {
        if (line.empty()) continue;
        if (first) {
            first = false;
            if (line.find("date") != std::string::npos && line.find("|") != std::string::npos)
                continue;
        }
        std::string date; double amount; std::string err;
        if (!parseInputLine(line, date, amount, err)) {
            printError(err);
            continue;
        }
        double rate; std::string usedDate;
        if (!be.getRateForDate(date, rate, usedDate)) {
            printError(std::string("Error: bad input => ") + line);
            continue;
        }
        double result = amount * rate;
        std::cout << date << " => " << amount << " = " << result << std::endl;
    }
    return 0;
}
