#ifndef REPLACE_HPP
#define REPLACE_HPP

#include <iostream>
#include <fstream>
#include <string>

class Replace {
    private:
        std::ifstream inputFile;
        std::ofstream outputFile;
    public:
        Replace(std::string file);
        ~Replace();
        void replace(std::string s1, std::string s2);
};


#endif