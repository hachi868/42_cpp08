#include "easyfind.hpp"

__attribute__((destructor))
static void destructor() {
	system("leaks -q ex00");
}

int main()
{
    //c++98では初期化リスト不可
    //std::vector<int> contVector = {1, 2, 3, 4, 5, 6};
    int arr[] = {1, 2, 3, 4, 5, 6};
	{
        std::cout << "[test 0] vector" << std::endl;
        std::vector<int> contVector(arr, arr + sizeof(arr) / sizeof(arr[0]));
		easyfind(contVector, 4);
        easyfind(contVector, 0);
	}
    std::cout << "*-*-*-*-*-*-*" << std::endl << std::endl;
    {
        std::cout << "[test 1] deque" << std::endl;
        std::deque<int> contDeque(arr, arr + sizeof(arr) / sizeof(int));
        easyfind(contDeque, 4);
        easyfind(contDeque, 0);
    }
    std::cout << "*-*-*-*-*-*-*" << std::endl << std::endl;
    {
        std::cout << "[test 2] list" << std::endl;
        std::list<int> contList(arr, arr + sizeof(arr) / sizeof(int));
        easyfind(contList, 4);
        easyfind(contList, 0);
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
