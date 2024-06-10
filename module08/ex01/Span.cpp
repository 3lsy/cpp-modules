/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 10:55:03 by echavez-          #+#    #+#             */
/*   Updated: 2024/06/10 12:52:47 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : max_size(0) {}

Span::Span(unsigned int n) : max_size(n) {}

Span::Span(const Span &src) : numbers(src.numbers), max_size(src.max_size) {}

Span::~Span() {}

Span &Span::operator=(const Span &src) {
    if (this != &src) {
        numbers = src.numbers;
        max_size = src.max_size;
    }
    return *this;
}

void Span::addNumber(int n) {
	if (numbers.size() >= max_size)
		throw FullSpanException();
	numbers.push_back(n);
}

void Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	if (numbers.size() + std::distance(begin, end) > max_size)
		throw FullSpanException();
	numbers.insert(numbers.end(), begin, end);
}

int Span::shortestSpan() {
    if (numbers.size() < 2) {
        throw NotEnoughNumbersException();
    }
    std::vector<int> sorted(numbers);
    std::sort(sorted.begin(), sorted.end());
    int min_span = std::numeric_limits<int>::max();
    for (std::size_t i = 0; i < sorted.size() - 1; ++i) {
        int span = sorted[i + 1] - sorted[i];
        if (span < min_span) {
            min_span = span;
        }
    }
    return min_span;
}

int Span::longestSpan() {
    if (numbers.size() < 2) {
        throw NotEnoughNumbersException();
    }
    int min_number = *std::min_element(numbers.begin(), numbers.end());
    int max_number = *std::max_element(numbers.begin(), numbers.end());
    return max_number - min_number;
}

//exception
const char* Span::FullSpanException::what() const throw() {
	return "Span is full";
}

const char* Span::NotEnoughNumbersException::what() const throw() {
	return "Not enough numbers to find a span";
}
