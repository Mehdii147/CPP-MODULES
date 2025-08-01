#include "Span.hpp"

Span::Span(unsigned int N) : _maxSize(N) 
{
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

int Span::shortestSpan() const
{
	if (_numbers.size() < 2) {
		throw std::logic_error("Not enough numbers to find a span");
	}

	std::vector<int> sortedNumbers = _numbers;
	std::sort(sortedNumbers.begin(), sortedNumbers.end());

	int minSpan = std::numeric_limits<int>::max();
	for (size_t i = 1; i < sortedNumbers.size(); ++i) {
		int span = sortedNumbers[i] - sortedNumbers[i - 1];
		if (span < minSpan) {
			minSpan = span;
		}
	}
	return minSpan;
}

int Span::longestSpan() const
{
    if (_numbers.size() < 2)
        throw std::runtime_error("Not enough elements");

    int minVal = *std::min_element(_numbers.begin(), _numbers.end());
    int maxVal = *std::max_element(_numbers.begin(), _numbers.end());
    return maxVal - minVal;
}