#include "Span.hpp"

__attribute__((destructor))
static void destructor() {
	system("leaks -q ex01");
}

int main()
{
	{
		std::cout << "[test0] " << std::endl;
	}
	return (0);
}
