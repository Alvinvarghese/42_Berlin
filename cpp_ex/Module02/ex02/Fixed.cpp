#include "Fixed.h"

const int Fixed::fractionalBits = 8;

Fixed::Fixed() : fixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int intValue) : fixedPointValue(intValue << fractionalBits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float floatValue) : fixedPointValue(roundf(floatValue * (1 << fractionalBits)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) : fixedPointValue(other.fixedPointValue)
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->setRawBits(other.getRawBits());
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return fixedPointValue;
}

void Fixed::setRawBits(int const raw)
{
	// std::cout << "setRawBits member function called" << std::endl;
	fixedPointValue = raw;
}

float Fixed::toFloat(void) const
{
	return static_cast<float>(fixedPointValue) / (1 << fractionalBits);
}

int Fixed::toInt(void) const
{
	return fixedPointValue >> fractionalBits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}

// Comparison operators

bool Fixed::operator>(const Fixed &other) const
{
	return this->getRawBits() > other.getRawBits();
}

bool Fixed::operator<(const Fixed &other) const
{
	return this->getRawBits() < other.getRawBits();
}

bool Fixed::operator>=(const Fixed &other) const
{
	return this->getRawBits() >= other.getRawBits();
}

bool Fixed::operator<=(const Fixed &other) const
{
	return this->getRawBits() <= other.getRawBits();
}

bool Fixed::operator==(const Fixed &other) const
{
	return this->getRawBits() == other.getRawBits();
}

bool Fixed::operator!=(const Fixed &other) const
{
	return this->getRawBits() != other.getRawBits();
}

// Arithmetic operators

Fixed Fixed::operator+(const Fixed &other) const
{
	Fixed result;
	result.setRawBits(this->getRawBits() + other.getRawBits());
	return result;
}

Fixed Fixed::operator-(const Fixed &other) const
{
	Fixed result;
	result.setRawBits(this->getRawBits() - other.getRawBits());
	return result;
}

Fixed Fixed::operator*(const Fixed &other) const
{
	Fixed result;
	result.setRawBits((this->getRawBits() * other.getRawBits()) >> fractionalBits);
	return result;
}

Fixed Fixed::operator/(const Fixed &other) const
{
	Fixed result;
	result.setRawBits((this->getRawBits() / other.getRawBits()) << fractionalBits);
	return result;
}

// Increment and Decrement operators

Fixed &Fixed::operator++(void) // Pre-increment
{
	this->fixedPointValue += 1;
	return *this;
}

Fixed Fixed::operator++(int) // Post-increment
{
	Fixed temp(*this);
	++(*this);
	return temp;
}

Fixed &Fixed::operator--(void) // Pre-decrement
{
	this->fixedPointValue -= 1;
	return *this;
}

Fixed Fixed::operator--(int) // Post-decrement
{
	Fixed temp(*this);
	--(*this);
	return temp;
}

// Min and Max functions

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b) ? a : b;
}
