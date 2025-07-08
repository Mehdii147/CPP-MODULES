#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h>
#include "Data.hpp"


class Serialize
{
    private:
        Serialize() {}

    public:
        static uintptr_t Serializer(Data* ptr);
        static Data* Deserializer(uintptr_t raw);
};

#endif
