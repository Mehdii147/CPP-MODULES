#include "Serializer.hpp"

uintptr_t Serialize::Serializer(Data* ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serialize::Deserializer(uintptr_t raw) {
    return reinterpret_cast<Data*>(raw);
}
