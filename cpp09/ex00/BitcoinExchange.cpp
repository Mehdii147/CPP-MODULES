#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(const std::string &csvPath) { loadDatabase(csvPath); }
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _rates(other._rates) {}
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other) {
        _rates = other._rates;
    }
    return *this;
}
BitcoinExchange::~BitcoinExchange() {}

static bool isLeap(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

static bool validYMD(int y, int m, int d) {
    if (y < 0 || m < 1 || m > 12 || d < 1)
        return false;
    static  int mdays[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int days = mdays[m - 1];
    if (m == 2 && isLeap(y))
        days = 29;
    return d <= days;
}

bool BitcoinExchange::loadDatabase(const std::string &csvPath) {
    _rates.clear();
    std::ifstream in(csvPath.c_str());
    if (!in.is_open())
        return false;
    std::string line;
    while (std::getline(in, line))
    {
        if (line.empty()) 
            continue;

        std::string date;
        double rate;
        if (!parseCsvLine(line, date, rate))
            continue; 
        if (!isValidDate(date))
            continue;

        _rates[date] = rate;
    }
    return !_rates.empty();
}

bool BitcoinExchange::hasRates() const { return !_rates.empty(); }

bool BitcoinExchange::getRateForDate(const std::string &date, double &rate, std::string &usedDate) const {
    if (_rates.empty() || !isValidDate(date))
        return false;
    std::map<std::string, double>::const_iterator it = _rates.lower_bound(date);
    if (it == _rates.end())
    {
        --it; // use the last available lower date
    } else if (it->first != date) {
        if (it == _rates.begin()) {
            return false; // no lower date available
        }
        --it; // move to lower date
    }
    rate = it->second;
    usedDate = it->first;
    return true;
}

bool BitcoinExchange::isValidDate(const std::string &date) {
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
        return false;
    for (size_t i = 0; i < date.size(); ++i) {
        if (i == 4 || i == 7)
            continue;
        if (!std::isdigit(static_cast<unsigned char>(date[i])))
            return false;
    }
    int y = std::atoi(date.substr(0, 4).c_str());
    int m = std::atoi(date.substr(5, 2).c_str());
    int d = std::atoi(date.substr(8, 2).c_str());
    return validYMD(y, m, d);
}

bool BitcoinExchange::parseNumber(const std::string &s, double &out) {
    std::string t = trim(s);
    if (t.empty())
        return false;
    char *end = NULL;
    errno = 0;
    double val = std::strtod(t.c_str(), &end);
    if (errno != 0 || end == t.c_str() || *end != '\0')
        return false;
    out = val;
    return true;
}

std::string BitcoinExchange::trim(const std::string &s) {
    size_t a = 0, b = s.size();
    while (a < b && std::isspace(static_cast<unsigned char>(s[a]))) ++a;
    while (b > a && std::isspace(static_cast<unsigned char>(s[b - 1]))) --b;
    return s.substr(a, b - a);
}

bool BitcoinExchange::parseCsvLine(const std::string &line, std::string &date, double &rate) {
    size_t comma = line.find(',');
    if (comma == std::string::npos)
        return false;
    date = trim(line.substr(0, comma));
    std::string val = trim(line.substr(comma + 1));

    double r;
    if (!parseNumber(val, r))
        return false;
    rate = r;
    return true;
}
