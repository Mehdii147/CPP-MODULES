#include <iostream>
#include "iter.hpp"

// Function to print integers
void printInt(const int& n)
{
    std::cout << n << " ";
}

// Function to print characters
void printChar(const char& c)
{
    std::cout << c;
}

// Function to convert to uppercase
void toUpper(char& c)
{
    if (c >= 'a' && c <= 'z')
        c = c - 'a' + 'A';
}

// Function to convert to lowercase
void toLower(char& c)
{
    if (c >= 'A' && c <= 'Z')
        c = c - 'A' + 'a';
}

int main()
{
    std::cout << "=== Testing iter function template ===" << std::endl;
    
    // Test with int array
    std::cout << "\n1. Testing with int array:" << std::endl;
    int intArray[] = {1, 2, 3, 4, 5};
    std::cout << "Int array: ";
    iter(intArray, 5, printInt);
    std::cout << std::endl;
    
    // Test with char array - print and uppercase
    std::cout << "\n2. Testing with char array:" << std::endl;
    char charArray[] = {'h', 'e', 'l', 'l', 'o'};
    std::cout << "Original: ";
    iter(charArray, 5, printChar);
    std::cout << std::endl;
    
    // Convert to uppercase
    iter(charArray, 5, toUpper);
    std::cout << "Uppercase: ";
    iter(charArray, 5, printChar);
    std::cout << std::endl;
    
    // Convert to lowercase
    iter(charArray, 5, toLower);
    std::cout << "Lowercase: ";
    iter(charArray, 5, printChar);
    std::cout << std::endl;
    
    return 0;
}