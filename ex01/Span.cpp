#include "Span.hpp"

const std::string Span::RESET = "\033[0m";
const std::string Span::DEBUG = "\033[90m";
const std::string Span::STATE = "\033[36m";
const std::string Span::ALERT = "\033[31m";
const std::string Span::MSG = "\033[34m";

Span::Span(unsigned int N) : N_(N), container_(), isSorted_(false)
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
        throw CapacityExceededException();
    container_.push_back(a);
    isSorted_ = false;
}

size_t Span::shortestSpan(void)
{
    checkContainerSize();
    sortIfNeeded();

    size_t minSpan = std::numeric_limits<size_t>::max();
    for (size_t i = 1; i < container_.size(); ++i) {
        minSpan = min(minSpan, (size_t)container_[i] - container_[i - 1]);
    }
    return minSpan;
}

size_t Span::longestSpan(void)
{
    checkContainerSize();
    sortIfNeeded();

    return (container_.back() - container_.front());
}

void Span::fillRange(int a, int b)
{
    //1つならaddNumber
    if (a == b) {
        addNumber(a);
        return;
    }
    //追加しきれなければ例外投げる
    if (container_.size() + (abs(b - a) + 1) > N_)
        throw CapacityExceededException();
    //a<b確定の上、追加
    if (a > b)
        std::swap(a, b);
    std::vector<int> rangeToAdd(b - a + 1);
    for (size_t i = 0; i < rangeToAdd.size(); i++)
        rangeToAdd[i] = a + i;
    if (isSorted_ && container_.back() > rangeToAdd.front()) {
        isSorted_ = false;
    }
    container_.insert(container_.end(), rangeToAdd.begin(), rangeToAdd.end());
}

void Span::checkContainerSize()
{
    if (container_.size() < 2) {
        throw InvalidSpanException();
    }
}

void Span::sortIfNeeded()
{
    if (!isSorted_) {
        std::sort(container_.begin(), container_.end());
        isSorted_ = true;
    }
}

const char* Span::CapacityExceededException::what() const throw()
{
    return ("This addition would exceed the container's capacity.");
}

const char* Span::InvalidSpanException::what() const throw()
{
    return ("No span can be found. The collection is either empty or has only one element.");
}
