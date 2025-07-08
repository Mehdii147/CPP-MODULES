#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>
#include <cstdint>

int main() {
    Data data;
    data._char = 'A';
    data._int = 42;
    data._float = 3.14f;
    data._double = 2.71828;

    // Serialize the data
    uintptr_t raw = Serialize::Serializer(&data);
    
    // Deserialize the data
    Data* deserializedData = Serialize::Deserializer(raw);

    // Output the deserialized values
    std::cout << "Char: " << deserializedData->_char << std::endl;
    std::cout << "Int: " << deserializedData->_int << std::endl;
    std::cout << "Float: " << deserializedData->_float << std::endl;
    std::cout << "Double: " << deserializedData->_double << std::endl;

    return 0;
}