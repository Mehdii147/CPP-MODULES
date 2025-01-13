#include "Replace.hpp"

Replace::Replace(std::string file) {
    this->inputFile.open(file);
    if (!this->inputFile.is_open()) {
        std::cerr << "Error opening input file: " << file << std::endl;
        exit(1);
    }
    this->outputFile.open(file + ".replace");
    if (!this->outputFile.is_open()) {
        std::cerr << "Error opening output file: " << file << ".replace" << std::endl;
        exit(1);
    }
}

Replace::~Replace() {
    if (this->inputFile.is_open())
        this->inputFile.close();
    if (this->outputFile.is_open())
        this->outputFile.close();
}

void Replace::replace(std::string s1, std::string s2) {
    std::string line;
    while (std::getline(this->inputFile, line)) {
        size_t pos = 0;

        while ((pos = line.find(s1, pos)) != std::string::npos) {
            line.erase(pos, s1.length());
            line.insert(pos, s2);
            pos += s2.length();
        }
        this->outputFile << line << std::endl;
    }
}
