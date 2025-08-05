#include "Span.hpp"

int main()
{
    Span sp(10); 
    
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    
    std::vector<int> moreNumbers;
    moreNumbers.push_back(18);
    moreNumbers.push_back(12);
    moreNumbers.push_back(2);
    moreNumbers.push_back(5);
    moreNumbers.push_back(7);

    
    try {
        sp.addNumbersRange(moreNumbers.begin(), moreNumbers.end());
    } catch (const std::length_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try {
        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    
    return 0;
}
