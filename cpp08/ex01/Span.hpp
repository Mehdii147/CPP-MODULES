#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <exception>
#include <algorithm>
#include <limits>
#include <iostream>


class Span {
	private:
		unsigned int _maxSize;
		std::vector<int> _numbers;

	public:
		Span(unsigned int N);
		Span(const Span &other);
		Span &operator=(const Span &other);
		~Span();

		void addNumber(int value);
		unsigned int shortestSpan() const;
		unsigned int longestSpan() const;
		    template <typename Iterator>
		void addNumbersRange(Iterator start, Iterator end)
		{
			size_t numToAdd = std::distance(start, end);
			if (_numbers.size() + numToAdd > _maxSize) {
				throw std::length_error("Not enough space in Span to add all numbers");
			}

			for (Iterator it = start; it != end; ++it) {
				_numbers.push_back(*it);
			}
		}
};

#endif