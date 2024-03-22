#include "easyfind.hpp"

__attribute__((destructor))
static void destructor() {
	system("leaks -q ex00");
}

int main()
{
	{
		std::cout << "[test0] vector" << std::endl;
		std::vector<int> contVector1 = {1, 2, 3, 4, 5, 6};
		(void)contVector1;
	}
	std::cout << "*-*-*-*-*-*-*" << std::endl << std::endl;
	{
		std::cout << "[test0] vector(string)" << std::endl;
		std::vector<std::string> contVector2 = {"str1", "str2", "str3", "str4", "str5", "str6"};
		(void)contVector2;
	}
	std::cout << "*-*-*-*-*-*-*" << std::endl << std::endl;
	{
		std::cout << "[test0] deque" << std::endl;
		std::vector<int> contDeque = {1, 2, 3, 4, 5, 6};
		(void)contDeque;
	}
	std::cout << "*-*-*-*-*-*-*" << std::endl << std::endl;
	{
		std::cout << "[test0] list" << std::endl;
		std::vector<int> contList = {1, 2, 3, 4, 5, 6};
		(void)contList;

	}
	std::cout << "*-*-*-*-*-*-*" << std::endl << std::endl;
	return (0);
}

//c++におけるコンテナ
//* vector
//https://cpprefjp.github.io/reference/vector/vector.html
//* array(c++11)
//https://cpprefjp.github.io/reference/array.html
//deque
//https://cpprefjp.github.io/reference/deque.html
//list
//https://cpprefjp.github.io/reference/list/list.html
//forward_list(c++11)
//https://cpprefjp.github.io/reference/forward_list.html