#include "Span.hpp"

__attribute__((destructor))
static void destructor() {
	system("leaks -q ex01");
}

//int main()
//{
//	{
//		std::cout << "[test0] " << std::endl;
//	}
//	return (0);
//}

int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	return 0;
}
