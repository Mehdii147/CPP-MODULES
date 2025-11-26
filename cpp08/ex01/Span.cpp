#include "Span.hpp"

Span::Span(unsigned int N) : _maxSize(N) 
{
}

Span::Span(const Span &other) : _maxSize(other._maxSize), _numbers(other._numbers) 
{
}

Span &Span::operator=(const Span &other) 
{
	if (this != &other) {
		_maxSize = other._maxSize;
		_numbers = other._numbers;
	}
	return *this;
}

Span::~Span() 
{
}

void Span::addNumber(int value)
{
	if (_numbers.size() >= _maxSize) {
		throw std::length_error("Span is full");
	}
	_numbers.push_back(value);
}

unsigned int Span::shortestSpan() const
{
	if (_numbers.size() < 2) {
		throw std::logic_error("Not enough numbers to find a span");
	}

	std::vector<int> sortedNumbers = _numbers;
	std::sort(sortedNumbers.begin(), sortedNumbers.end());

	unsigned int minSpan = std::numeric_limits<unsigned int>::max();
	for (size_t i = 1; i < sortedNumbers.size(); ++i) {
		unsigned int span = sortedNumbers[i] - sortedNumbers[i - 1];
		if (span < minSpan) {
			minSpan = span;
		}
	}
	return minSpan;
}

unsigned int Span::longestSpan() const
{
    if (_numbers.size() < 2)
        throw std::runtime_error("Not enough elements");

    unsigned int minVal = *std::min_element(_numbers.begin(), _numbers.end());
    unsigned int maxVal = *std::max_element(_numbers.begin(), _numbers.end());
    return maxVal - minVal;
}

