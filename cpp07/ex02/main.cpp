#include <iostream>
#include "Array.hpp"

int main() {
    std::cout << "=== Array Template Tests ===" << std::endl;
    
    Array<int> empty;
    Array<int> arr(5);
    std::cout << "Empty size: " << empty.size() << ", Array size: " << arr.size() << std::endl;
    
    for (unsigned int i = 0; i < arr.size(); i++)
        arr[i] = i * 10;
    std::cout << "Array values: ";
    for (unsigned int i = 0; i < arr.size(); i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
    
    Array<int> copy(arr);
    arr[0] = 999;
    std::cout << "Original[0]: " << arr[0] << ", Copy[0]: " << copy[0] << std::endl;
    
    Array<int> assigned;
    assigned = copy;
    std::cout << "Assigned size: " << assigned.size() << std::endl;
    
    try {
        std::cout << arr[10] << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception caught for out of bounds access" << std::endl;
    }
    
    try {
        std::cout << empty[0] << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception caught for empty array access" << std::endl;
    }
    
    Array<std::string> strings(2);
    strings[0] = "Hello";
    strings[1] = "World";
    std::cout << "String array: " << strings[0] << " " << strings[1] << std::endl;
    
    std::cout << "=== All tests completed ===" << std::endl;
    
    return 0;
}