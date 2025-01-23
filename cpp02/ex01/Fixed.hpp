#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
    private:
        int _value;
        static const int _fractionalBits = 8;
    public:
        Fixed();
        Fixed(const Fixed &fixed);
        Fixed(const int value);
        Fixed(const float value);
        ~Fixed();
        int toInt( void ) const;
        float toFloat( void ) const;
        Fixed &operator=(const Fixed &fixed);
        int getRawBits(void) const;
        void setRawBits(int const raw);
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);
#endif