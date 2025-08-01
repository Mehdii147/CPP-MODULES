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
		~Span();

		void addNumber(int value);
		int shortestSpan() const;
		int longestSpan() const;
};




#endif