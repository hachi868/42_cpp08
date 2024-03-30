#include "MutantStack.hpp"

__attribute__((destructor))
static void destructor() {
	system("leaks -q ex02");
}

int main()
{
	{
		std::cout << "[test0] " << std::endl;
	}
	return (0);
}
