#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <vector>

#define MSG "\033[34m"
#define ERROR "\033[31m"
#define RESET "\033[0m"

template <typename T>void easyfind(const T &container, int n) {
	typename T::const_iterator it = std::find(container.begin(), container.end(), n);

	if (it != container.end()) {
        int index = std::distance(container.begin(), it);
        std::cout << MSG << "[FOUND] " << n << " is found at position " << index << RESET << std::endl;
    } else {
		std::cerr << ERROR << "[NOT FOUND] " << n << " is not found in container" << RESET << std::endl;
    }
}

//is_same_v, is_integral_vはc++98で使えない
//std::vector<int>::iterator result：auto はc++11以降

#endif //EASYFIND_HPP
