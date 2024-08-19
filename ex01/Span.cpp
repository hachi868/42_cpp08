#include "Span.hpp"

const std::string Span::RESET = "\033[0m";
const std::string Span::DEBUG = "\033[90m";
const std::string Span::STATE = "\033[36m";
const std::string Span::ALERT = "\033[31m";
const std::string Span::MSG = "\033[34m";

Span::Span(unsigned int N) : N_(N), container_(N), isSorted_(false)
{
    std::cout << Span::DEBUG << "[Span] constructor called (N)" << Span::RESET << std::endl;
}

Span::Span(const Span &obj) : N_(obj.N_), container_(obj.container_), isSorted_(false)
{
    std::cout << Span::DEBUG << "[Span] copy constructor called" << Span::RESET << std::endl;
}

Span &Span::operator = (const Span &obj)
{
    std::cout << Span::DEBUG << "[Span] assignation operator called" << Span::RESET << std::endl;
    if (this != &obj) {
        this->N_ = obj.N_;
        this->container_ = obj.container_;
        this->isSorted_ = false;
    }
    return (*this);
}

Span::~Span()
{
    std::cout << Span::DEBUG << "[Span] destructor called" << Span::RESET << std::endl;
}

void	Span::addNumber(int a)
{
    if (container_.size() >= N_)
        throw fullAlready();
    container_.push_back(a);
}

size_t Span::shortestSpan(void) const
{
    return 0;
}

size_t Span::longestSpan(void) const
{
    return 0;
}

void Span::fillRange(int a, int b)
{

}

const char* Span::fullAlready::what() const throw()
{
    return ("container is full already.");
}

const char* Span::InvalidSpan::what() const throw()
{
    return ("No span can be found. The collection is either empty or has only one element.");
}
