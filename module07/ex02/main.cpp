#include <iostream>
#include <ctime>
#include "Array.hpp"

/*
#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}
*/

#define MAX_VAL 10

int main() {
    srand(static_cast<unsigned int>(time(NULL)));

	std::cout << "-----Testing with int:-----" << std::endl;
	{
		//Creating empty array
		// Test default constructor and operator[]
        Array<int> numbers;
        std::cout << "Default constructor test:\n";
        for (unsigned int i = 0; i < numbers.size(); ++i) {
            numbers[i] = rand() % 100;
            std::cout << numbers[i] << " ";
        }
		std::cout << "numbers.size() = " << numbers.size();
		std::cout << "\n" << std::endl;

		std::cout << "MAX_VALL =" << MAX_VAL << std::endl;
		// Test constructor with size and operator[]
		Array<int> numbers2(MAX_VAL);
		std::cout << "Constructor with size test (number2.size = MAX_VAL):" << std::endl;
		for (unsigned int i = 0; i < numbers2.size(); ++i) {
			numbers2[i] = rand() % 100;
			std::cout << numbers2[i] << " ";
		}
		std::cout << "\n" << std::endl;

		// Test copy constructor and assignment operator
		Array<int> numbers3 = numbers2;
		std::cout << "Copy constructor and assignment operator test: (Copying numbers2 to create numbers3)" << std::endl;
		for (unsigned int i = 0; i < numbers3.size(); ++i) {
			std::cout << numbers3[i] << " ";
		}
		std::cout << "\n" << std::endl;

		// Test modification
		std::cout << "Modification test (+10 to each number in numbers3):" << std::endl;
		for (unsigned int i = 0; i < numbers3.size(); ++i) {
			numbers3[i] += 10;
			std::cout << numbers3[i] << " ";
		}
		std::cout << "\n" << std::endl;

		//check if numbers2 is still the same
		std::cout << "Check if numbers2 is still the same:" << std::endl;
		for (unsigned int i = 0; i < numbers2.size(); ++i) {
			std::cout << numbers2[i] << " ";
		}
		std::cout << "\n" << std::endl;

		// Test const version of operator[]
        const Array<int>& constNumbers = numbers3;
        std::cout << "Const operator[] test:" << std::endl;
        for (unsigned int i = 0; i < constNumbers.size(); ++i) {
            std::cout << constNumbers[i] << " ";
        }
		std::cout << "\n" << std::endl;

		/*
		// Try to write into constNumbers
		std::cout << "Trying to write into constNumbers..." << std::endl;
		try {
			constNumbers[0] = 5; // Try to write into constNumbers, should result in an error
		} catch(const std::exception& e) {
			std::cerr << "Exception caught: " << e.what() << std::endl;
		}
		std::cout << "\n" << std::endl;
		*/

		// Test out-of-bounds access
		std::cout << "Out-of-bounds access test (numbers3[MAX_VAL]):" << std::endl;
		try {
			std::cout << numbers3[MAX_VAL] << std::endl;
		} catch (const std::exception& e) {
			std::cerr << "Exception caught: " << e.what() << std::endl;
		}
	}

	// Test with std::string
    std::cout << "\n-----Testing with std::string:-----" << std::endl;
    {
		// Test constructor with size and operator[]
        Array<std::string> strings2(MAX_VAL);
        std::cout << "Constructor with size test:" << std::endl;
        for (unsigned int i = 0; i < strings2.size(); ++i) {
            strings2[i] = "String" + std::to_string(i);
            std::cout << strings2[i] << " ";
        }
        std::cout << std::endl;

    }

	return 0;
}