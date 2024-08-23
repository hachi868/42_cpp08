#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <algorithm>
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
    typedef typename Container::reverse_iterator reverse_iterator;

    // begin / end
    iterator begin();
    iterator begin() const;

    iterator end();
    iterator end() const;

    // cbegin / cend
    iterator cbegin() const;

    iterator cend() const;

    // rbegin / rend
    reverse_iterator rbegin();
    reverse_iterator rbegin() const;

    reverse_iterator rend();
    reverse_iterator rend() const;

    // crbegin / crend
    reverse_iterator crbegin() const;
    reverse_iterator crend() const;

    //print
    const static std::string RESET;
    const static std::string DEBUG;
    const static std::string STATE;
    const static std::string ALERT;
    const static std::string MSG;
    const static std::string ERROR;
};

#include "MutantStack.tpp"

#endif //MUTANTSTACK_HPP

//iteratorはconst_iteratorにcast可能。逆は無理

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
