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
        bool operator>(Fixed fixed)const;
		bool operator<(Fixed fixed)const;
		bool operator>=(Fixed fixed)const;
		bool operator<=(Fixed fixed)const;
		bool operator==(Fixed fixed)const;
		bool operator!=(Fixed fixed)const;
		float operator+(Fixed fixed)const;
		float operator-(Fixed fixed)const;
		float operator*(Fixed fixed)const;
		float operator/(Fixed fixed)const;
		Fixed operator++();
		Fixed operator--();
		Fixed operator++(int);
		Fixed operator--(int);
        static Fixed &min(Fixed &f1, Fixed &f2);
        static const Fixed &min(const Fixed &f1, const Fixed &f2);
        static Fixed &max(Fixed &f1, Fixed &f2);
        static const Fixed &max(const Fixed &f1, const Fixed &f2);
        int getRawBits(void) const;
        void setRawBits(int const raw);
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);
#endif