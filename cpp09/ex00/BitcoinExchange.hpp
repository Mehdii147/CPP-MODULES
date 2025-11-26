#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <algorithm>
#include <cctype>
#include <cerrno>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <limits>
#include <sstream>

class BitcoinExchange {
    private:
        std::map<std::string, double> _rates; 
        static bool parseCsvLine(const std::string &line, std::string &date, double &rate);
    
    public:
        BitcoinExchange();
        BitcoinExchange(const std::string &csvPath);
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange &operator=(const BitcoinExchange &other);
        ~BitcoinExchange();

    bool loadDatabase(const std::string &csvPath);
    bool hasRates() const;

    bool getRateForDate(const std::string &date, double &rate, std::string &usedDate) const;

    static bool isValidDate(const std::string &date);
    static bool parseNumber(const std::string &s, double &out);
    static std::string trim(const std::string &s);

};

#endif 
