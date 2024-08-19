#include "easyfind.hpp"
#include <vector>

__attribute__((destructor))
static void destructor() {
	system("leaks -q ex00");
}

int main()
{
	{
		//c++98では初期化リスト不可
		//std::vector<int> contVector1 = {1, 2, 3, 4, 5, 6};
        int arr[] = {1, 2, 3, 4, 5, 6};
        std::vector<int> contVector1(arr, arr + sizeof(arr) / sizeof(arr[0]));
		easyfind(contVector1, 4);
        easyfind(contVector1, 0);
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
