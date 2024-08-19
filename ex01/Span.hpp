#ifndef SPAN_HPP
#define SPAN_HPP

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>

template <typename T>T min(const T &a, const T &b) {
    return (a < b) ? a : b;
}

class Span {
public:
    Span(unsigned int N);
    Span(const Span &obj);
    Span &operator = (const Span &obj);
    ~Span();

    void addNumber(int a);
    size_t shortestSpan(void);
    size_t longestSpan(void);
    void fillRange(int a, int b);
    void checkContainerSize();
    void sortIfNeeded();

    const static std::string RESET;
    const static std::string DEBUG;
    const static std::string STATE;
    const static std::string ALERT;
    const static std::string MSG;

    //throw
    class CapacityExceededException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class InvalidSpanException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
private:
    unsigned int N_;
    std::vector<int> container_;
    bool isSorted_;
    Span();
};


#endif //SPAN_HPP
