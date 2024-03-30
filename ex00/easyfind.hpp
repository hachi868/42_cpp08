#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <list>
#include <algorithm>

template <typename T>void easyfind(const T &container, int n) {
	typename T::const_iterator it = std::find(container.begin(), container.end(), n);

	if (it != container.end())
		std::cout << "FIND!" << std::endl;
	else
		std::cerr << "404" << std::endl;
	return ;
}

//is_same_v, is_integral_vはc++98で使えない
//std::findはC11以降なので、STLコンテナのfindメンバ関数を使用。

#endif //EASYFIND_HPP
