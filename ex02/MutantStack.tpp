#include "MutantStack.hpp"

template <typename T, typename Container>
const std::string MutantStack<T, Container>::RESET = "\033[0m";
template <typename T, typename Container>
const std::string MutantStack<T, Container>::DEBUG = "\033[90m";
template <typename T, typename Container>
const std::string MutantStack<T, Container>::STATE = "\033[36m";
template <typename T, typename Container>
const std::string MutantStack<T, Container>::ALERT = "\033[31m";
template <typename T, typename Container>
const std::string MutantStack<T, Container>::MSG = "\033[34m";
template <typename T, typename Container>
const std::string MutantStack<T, Container>::ERROR = "\033[31m";


template <typename T, typename Container>
MutantStack<T, Container>::MutantStack() {
    std::cout << MutantStack<T, Container>::DEBUG << "[MutantStack] default constructor called" << MutantStack<T, Container>::RESET << std::endl;
}

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(const MutantStack &obj) : std::stack<T, Container>(obj)
{
    std::cout << MutantStack<T, Container>::DEBUG << "[MutantStack] copy constructor called" << MutantStack<T, Container>::RESET << std::endl;
}

template <typename T, typename Container>
MutantStack<T, Container> &MutantStack<T, Container>::operator = (const MutantStack &obj)
{
    std::cout << MutantStack<T, Container>::DEBUG << "[MutantStack] assignation operator called" << MutantStack<T, Container>::RESET << std::endl;
    if (this != &obj) {
        std::stack<T, Container>::operator=(obj);
    }
    return (*this);
}

template <typename T, typename Container>
MutantStack<T, Container>::~MutantStack() {
    std::cout << MutantStack<T, Container>::DEBUG << "[MutantStack] destructor called" << MutantStack<T, Container>::RESET << std::endl;
}

//c はコンテナオブジェクトのメンバ変数。std::stackで定義

// begin / end
template <typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::begin() {
    return (this->c.begin());
}

template <typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::begin() const {
    return (const_cast<Container&>(this->c).begin());
}

template <typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::end() {
    return (this->c.end());
}

template <typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::end() const {
    return (const_cast<Container&>(this->c).end());
}

// cbegin / cend
template <typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::cbegin() const {
    return (const_cast<Container&>(this->c).begin());
}

template <typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::cend() const {
    return (const_cast<Container&>(this->c).end());
}

// rbegin / rend
template <typename T, typename Container>
typename MutantStack<T, Container>::reverse_iterator MutantStack<T, Container>::rbegin() {
    return (this->c.end());
}

template <typename T, typename Container>
typename MutantStack<T, Container>::reverse_iterator MutantStack<T, Container>::rbegin() const {
    return (const_cast<Container&>(this->c).end());
}

template <typename T, typename Container>
typename MutantStack<T, Container>::reverse_iterator MutantStack<T, Container>::rend() {
    return (this->c.begin());
}

template <typename T, typename Container>
typename MutantStack<T, Container>::reverse_iterator MutantStack<T, Container>::rend() const {
    return (const_cast<Container&>(this->c).begin());
}

// crbegin / crend
template <typename T, typename Container>
typename MutantStack<T, Container>::reverse_iterator MutantStack<T, Container>::crbegin() const {
    return (const_cast<Container&>(this->c).end());
}

template <typename T, typename Container>
typename MutantStack<T, Container>::reverse_iterator MutantStack<T, Container>::crend() const {
    return (const_cast<Container&>(this->c).begin());
}
