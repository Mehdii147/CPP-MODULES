#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed) {
    // std::cout << "Copy constructor called" << std::endl;
    *this = fixed;
}

Fixed::Fixed(const int value){
    // std::cout << "Int constructor called" << std::endl;
    _value = value << _fractionalBits;
}

Fixed::Fixed(const float value){
    // std::cout << "Float constructor called" << std::endl;
    _value = roundf(value * (1 << _fractionalBits));// value * 256
}
//roundf .5 >> .6      +1
//roundf .3 >> .4 

Fixed::~Fixed() {
	// std::cout << "Destructor called" << std::endl;
}

int Fixed::toInt( void ) const{
    return _value >> _fractionalBits;
}

float Fixed::toFloat( void ) const{
    return (float)_value / (1 << _fractionalBits);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed){
    out << fixed.toFloat();
    return out;
}
Fixed &Fixed::operator=(const Fixed &fixed) {
    // std::cout << "Assignation operator called" << std::endl;
    _value = fixed.getRawBits();
    return *this;
}

int Fixed::getRawBits(void) const {
    // std::cout << "getRawBits member function called" << std::endl;
    return _value;
}

void Fixed::setRawBits(int const raw) {
    _value = raw;
}

bool	Fixed::operator>(Fixed fixed) const
{
	return (this->toFloat() > fixed.toFloat());
}

bool	Fixed::operator<(Fixed fixed) const
{
	return (this->toFloat() < fixed.toFloat());
}

bool	Fixed::operator>=(Fixed fixed) const
{
	return (this->toFloat() >= fixed.toFloat());
}

bool	Fixed::operator<=(Fixed fixed) const
{
	return (this->toFloat() <= fixed.toFloat());
}

bool	Fixed::operator==(Fixed fixed) const
{
	return (this->toFloat() == fixed.toFloat());
}

bool	Fixed::operator!=(Fixed fixed) const
{
	return (this->toFloat() != fixed.toFloat());
}

float	Fixed::operator+(Fixed fixed) const
{
	return (this->toFloat() + fixed.toFloat());
}

float	Fixed::operator-(Fixed fixed) const
{
	return (this->toFloat() - fixed.toFloat());
}

float	Fixed::operator*(Fixed fixed) const
{
	return (this->toFloat() * fixed.toFloat());
}

float	Fixed::operator/(Fixed fixed) const
{
	return (this->toFloat() / fixed.toFloat());
}

Fixed	Fixed::operator++()
{
	this->_value++;
	return (*this);
}

Fixed	Fixed::operator--()
{
	this->_value--;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed before = *this;
	++this->_value;
	return (before);
}

Fixed	Fixed::operator--(int)
{
	Fixed before = *this;
	--this->_value;
	return (before);
}

Fixed	&Fixed::min(Fixed &f1, Fixed &f2)
{
	if (f1.toFloat() <= f2.toFloat())
		return (f1);
	else
		return (f2);
}

const Fixed	&Fixed::min(const Fixed &f1, const Fixed &f2)
{
	if (f1.toFloat() <= f2.toFloat())
		return (f1);
	else
		return (f2);
}

Fixed	&Fixed::max(Fixed &f1, Fixed &f2)
{
	if (f1.toFloat() >= f2.toFloat())
		return (f1);
	else
		return (f2);
}

const Fixed	&Fixed::max(const Fixed &f1, const Fixed &f2)
{
	if (f1.toFloat() >= f2.toFloat())
		return (f1);
	else
		return (f2);
}