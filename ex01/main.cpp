#include "Span.hpp"

__attribute__((destructor))
static void destructor() {
	system("leaks -q ex01");
}

int main()
{
    {
        std::cout << "[test 0] from subject" << std::endl;
        try {
            Span sp = Span(5);
            sp.addNumber(6);
            sp.addNumber(3);
            sp.addNumber(17);
            sp.addNumber(9);
            sp.addNumber(11);
            std::cout << sp.shortestSpan() << std::endl;
            std::cout << sp.longestSpan() << std::endl;
        } catch (const std::exception& e) {
            std::cerr << Span::ERROR << "Standard exception caught: " << e.what() << Span::RESET << std::endl;
        } catch (...) {
            std::cerr << Span::ERROR << "Unknown exception caught" << Span::RESET << std::endl;
        }
    }
    std::cout << "*-*-*-*-*-*-*" << std::endl;
    {
        std::cout << "[test 1] constructor" << std::endl;
        try {
            Span sp1 = Span(10);
            sp1.addNumber(6);
            sp1.addNumber(3);

            Span sp2 = Span(sp1);
            sp2.addNumber(-11);

            Span sp3 = Span(sp2);
            sp3.fillRange(2, 8);

            std::cout << "[sp1]";
            sp1.printContainer();
            std::cout << "shortest: " << sp1.shortestSpan() << " / longest: " << sp1.longestSpan() << std::endl;
            std::cout << "[sp2]";
            sp2.printContainer();
            std::cout << "shortest: " << sp2.shortestSpan() << " / longest: " << sp2.longestSpan() << std::endl;
            std::cout << "[sp3]";
            sp3.printContainer();
            std::cout << "shortest: " << sp3.shortestSpan() << " / longest: " << sp3.longestSpan() << std::endl;
        } catch (const std::exception& e) {
            std::cerr << Span::ERROR << "Standard exception caught: " << e.what() << Span::RESET << std::endl;
        } catch (...) {
            std::cerr << Span::ERROR << "Unknown exception caught" << Span::RESET << std::endl;
        }
    }
    std::cout << "*-*-*-*-*-*-*" << std::endl;
    {
        std::cout << "[test 2] throw CapacityExceededException" << std::endl;
        try {
            Span sp = Span(3);
            sp.addNumber(6);
            sp.addNumber(3);
            sp.addNumber(9);
            sp.addNumber(12);
            sp.addNumber(15);
            std::cout << "[sp]";
            sp.printContainer();
            std::cout << "shortest: " << sp.shortestSpan() << " / longest: " << sp.longestSpan() << std::endl;
        } catch (const std::exception& e) {
            std::cerr << Span::ERROR << "Standard exception caught: " << e.what() << Span::RESET << std::endl;
        } catch (...) {
            std::cerr << Span::ERROR << "Unknown exception caught" << Span::RESET << std::endl;
        }
    }
    std::cout << "*-*-*-*-*-*-*" << std::endl;
    {
        std::cout << "[test 3] throw CapacityExceededException(fillRange)" << std::endl;
        try {
            Span sp = Span(3);
            sp.fillRange(2, 8);
            std::cout << "[sp]";
            sp.printContainer();
            std::cout << "shortest: " << sp.shortestSpan() << " / longest: " << sp.longestSpan() << std::endl;
        } catch (const std::exception& e) {
            std::cerr << Span::ERROR << "Standard exception caught: " << e.what() << Span::RESET << std::endl;
        } catch (...) {
            std::cerr << Span::ERROR << "Unknown exception caught" << Span::RESET << std::endl;
        }
    }
    std::cout << "*-*-*-*-*-*-*" << std::endl;
    {
        std::cout << "[test 4] throw InvalidSpanException" << std::endl;
        try {
            Span sp = Span(3);
            sp.addNumber(6);
            std::cout << "[sp]";
            sp.printContainer();
            std::cout << "shortest: " << sp.shortestSpan() << " / longest: " << sp.longestSpan() << std::endl;
        } catch (const std::exception& e) {
            std::cerr << Span::ERROR << "Standard exception caught: " << e.what() << Span::RESET << std::endl;
        } catch (...) {
            std::cerr << Span::ERROR << "Unknown exception caught" << Span::RESET << std::endl;
        }
    }
    std::cout << "*-*-*-*-*-*-*" << std::endl;
    {
        std::cout << "[test 5] fillRange(a<b)" << std::endl;
        try {
            Span sp = Span(10);
            sp.fillRange(2, 8);
            std::cout << "[sp]";
            sp.printContainer();
            std::cout << "shortest: " << sp.shortestSpan() << " / longest: " << sp.longestSpan() << std::endl;
        } catch (const std::exception& e) {
            std::cerr << Span::ERROR << "Standard exception caught: " << e.what() << Span::RESET << std::endl;
        } catch (...) {
            std::cerr << Span::ERROR << "Unknown exception caught" << Span::RESET << std::endl;
        }
    }
    std::cout << "*-*-*-*-*-*-*" << std::endl;
    {
        std::cout << "[test 6] fillRange(a>b)" << std::endl;
        try {
            Span sp = Span(10);
            sp.fillRange(2, -5);
            std::cout << "[sp]";
            sp.printContainer();
            std::cout << "shortest: " << sp.shortestSpan() << " / longest: " << sp.longestSpan() << std::endl;
        } catch (const std::exception& e) {
            std::cerr << Span::ERROR << "Standard exception caught: " << e.what() << Span::RESET << std::endl;
        } catch (...) {
            std::cerr << Span::ERROR << "Unknown exception caught" << Span::RESET << std::endl;
        }
    }
    std::cout << "*-*-*-*-*-*-*" << std::endl;
    {
        std::cout << "[test 7] fillRange(more than 10,000)" << std::endl;
        try {
            Span sp = Span(11000);
            //sp.fillRange(0, 10000);
            sp.addNumber(12);
            sp.addNumber(-12);
            sp.addNumber(2147483647);
            sp.addNumber(-2147483648);
            std::cout << "[sp]";
            sp.printContainer();
            std::cout << "shortest: " << sp.shortestSpan() << " / longest: " << sp.longestSpan() << std::endl;
        } catch (const std::exception& e) {
            std::cerr << Span::ERROR << "Standard exception caught: " << e.what() << Span::RESET << std::endl;
        } catch (...) {
            std::cerr << Span::ERROR << "Unknown exception caught" << Span::RESET << std::endl;
        }
    }
    std::cout << "*-*-*-*-*-*-*" << std::endl;
    {
        std::cout << "[test 8] fillRange(a == b)" << std::endl;
        try {
            Span sp = Span(10);
            sp.fillRange(5, 5);
            std::cout << "[sp]";
            sp.printContainer();
            std::cout << "shortest: " << sp.shortestSpan() << " / longest: " << sp.longestSpan() << std::endl;
        } catch (const std::exception& e) {
            std::cerr << Span::ERROR << "Standard exception caught: " << e.what() << Span::RESET << std::endl;
        } catch (...) {
            std::cerr << Span::ERROR << "Unknown exception caught" << Span::RESET << std::endl;
        }
    }
	return 0;
}
