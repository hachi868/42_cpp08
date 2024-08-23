#include "MutantStack.hpp"

__attribute__((destructor))
static void destructor() {
	system("leaks -q ex02");
}

int main()
{
    {
        std::cout << "[test 0] from subject" << std::endl;
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        std::cout << mstack.top() << std::endl;
        mstack.pop();
        std::cout << mstack.size() << std::endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
//[...]
        mstack.push(0);
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::stack<int> s(mstack);
    }
    std::cout << "*-*-*-*-*-*-*" << std::endl;
    {
        std::cout << "[test 1] iterator" << std::endl;
        MutantStack<int> mstack;
        int arr[] = {1, 2, 3, 4, 5, 6};
        size_t arr_size = sizeof(arr) / sizeof(arr[0]);
        std::cout << "mstack isEmpty(before): " << mstack.empty() << std::endl;
        for (size_t i = 0; i < arr_size; ++i) {
            mstack.push(arr[i]);
        }
        std::cout << "mstack isEmpty(after): " << mstack.empty() << std::endl;

        std::cout << "print mstack: " << std::endl;
        for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
        std::cout << "begin: " << *(mstack.begin()) << std::endl;
        size_t distance1 = std::distance(mstack.begin(), mstack.end());
        std::cout << "Distance between begin() and end(): " << distance1 << std::endl;

        std::cout << "rbegin: " << *(mstack.rbegin()) << std::endl;
        size_t distance2 = std::distance(mstack.rbegin(), mstack.rend());
        std::cout << "Distance between rbegin() and rend(): " << distance2 << std::endl;
    }
    std::cout << "*-*-*-*-*-*-*" << std::endl;
    {
        std::cout << "[test 2] iterator(const)" << std::endl;
        MutantStack<int> mstack;
        int arr[] = {1, 2, 3, 4, 5, 6};
        size_t arr_size = sizeof(arr) / sizeof(arr[0]);
        for (size_t i = 0; i < arr_size; ++i) {
            mstack.push(arr[i]);
        }

        // Copy data from non-const to const MutantStack for testing
        const MutantStack<int>& mstack_const = mstack;

        std::cout << "print mstack_const: " << std::endl;
        for (MutantStack<int>::iterator it = mstack_const.begin(); it != mstack_const.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;

        std::cout << "begin(const): " << *(mstack_const.begin()) << std::endl;
        size_t distance_begin = std::distance(mstack_const.begin(), mstack_const.end());
        std::cout << "Distance between begin() const and end() const: " << distance_begin << std::endl;

        std::cout << "cbegin: " << *(mstack_const.cbegin()) << std::endl;
        size_t distance_cbegin = std::distance(mstack_const.cbegin(), mstack_const.cend());
        std::cout << "Distance between cbegin() and cend(): " << distance_cbegin << std::endl;

        std::cout << "rbegin(const): " << *(mstack_const.rbegin()) << std::endl;
        size_t distance_rbegin = std::distance(mstack_const.rbegin(), mstack_const.rend());
        std::cout << "Distance between rbegin() const and rend() const: " << distance_rbegin << std::endl;

        std::cout << "crbegin: " << *(mstack_const.crbegin()) << std::endl;
        size_t distance_crbegin = std::distance(mstack_const.crbegin(), mstack_const.crend());
        std::cout << "Distance between crbegin() const and crend() const: " << distance_crbegin << std::endl;
    }
    std::cout << "*-*-*-*-*-*-*" << std::endl;
	return 0;
}
