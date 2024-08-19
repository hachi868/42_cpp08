#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <algorithm>
#include <vector>
#include <iostream>
#include <stack>
#include <deque>
#include <iterator>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
public:
    MutantStack();
    MutantStack(const MutantStack &obj);
    MutantStack &operator = (const MutantStack &obj);
    ~MutantStack();

    //iterator
    typedef typename Container::iterator iterator;

    iterator begin();
    iterator end();

    //print
    const static std::string RESET;
    const static std::string DEBUG;
    const static std::string STATE;
    const static std::string ALERT;
    const static std::string MSG;
    const static std::string ERROR;

    //throw
//    class CapacityExceededException : public std::exception {
//    public:
//        virtual const char* what() const throw();
//    };

//private:
};

#include "MutantStack.tpp"

#endif //MUTANTSTACK_HPP


//template <typename T, typename Container = std::deque<T>>
//class stack {
//protected:
//    Container c;  // スタックの要素を保持するコンテナ
//
//public:
//    // スタック操作のメンバ関数
//    void push(const T& value);
//    void pop();
//    T& top();
//    const T& top() const;
//    bool empty() const;
//    size_t size() const;
//};
