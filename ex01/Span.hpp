#ifndef SPAN_HPP
#define SPAN_HPP

#include <stdio.h>
#include <iostream>
//#include <list>
//#include <algorithm>
#include <vector>

class Span {
public:
    Span(unsigned int N);
    Span(const Span &obj);
    Span &operator = (const Span &obj);
    ~Span();

    void addNumber(int a);
    size_t shortestSpan(void) const;
    size_t longestSpan(void) const;
    void fillRange(int a, int b);

    const static std::string RESET;
    const static std::string DEBUG;
    const static std::string STATE;
    const static std::string ALERT;
    const static std::string MSG;

    //throw
    class fullAlready : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class InvalidSpan : public std::exception {
    public:
        virtual const char* what() const throw();
    };
private:
    unsigned int N_;
    std::vector<int> container_;
    Span();
};


#endif //SPAN_HPP
