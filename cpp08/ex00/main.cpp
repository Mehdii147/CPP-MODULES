#include <iostream>
#include <vector>
#include "easyfind.hpp"

int main() {
    std::vector<int> numbers;
	numbers.push_back(1);
	numbers.push_back(2);
	numbers.push_back(244);
	numbers.push_back(244);
	numbers.push_back(5);


    try {
        std::vector<int>::iterator it = easyfind(numbers, 3);
        std::cout << "Found: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        std::vector<int>::iterator it = easyfind(numbers, 244);
        std::cout << "Found: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
