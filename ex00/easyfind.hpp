#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <list>

template <typename T>void easyfind(const T &container, int n) {
	std::cout << "-*-*- easyfind -*-*-" << std::endl;
	T::iterator it = container.find(n);

	if (it != container.end()) {
		std::cout << "FIND!" << std::endl;
	} else {
		std::cerr << "404" << std::endl;
	}
	return
}

//is_same_v, is_integral_vはc++98で使えない
//std::findはC11以降なので、STLコンテナのfindメンバ関数を使用。

#endif //EASYFIND_HPP
