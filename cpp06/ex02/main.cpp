#include "Functions.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

int main()
{
	std::cout << "=== Testing type identification ===" << std::endl;
	
	// Test with known types
	std::cout << "\n--- Testing with pointer identification ---" << std::endl;
	Base* a = new A();
	Base* b = new B();
	Base* c = new C();
	
	std::cout << "A object: ";
	identify(a);
	std::cout << "B object: ";
	identify(b);
	std::cout << "C object: ";
	identify(c);
	
	std::cout << "\n--- Testing with reference identification ---" << std::endl;
	std::cout << "A object: ";
	identify(*a);
	std::cout << "B object: ";
	identify(*b);
	std::cout << "C object: ";
	identify(*c);
	
	// Clean up
	delete a;
	delete b;
	delete c;
	
	// Test with randomly generated objects
	std::cout << "\n--- Testing with randomly generated objects ---" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		Base* random = generate();
		std::cout << "Random object " << i + 1 << " (pointer): ";
		identify(random);
		std::cout << "Random object " << i + 1 << " (reference): ";
		identify(*random);
		delete random;
		std::cout << std::endl;
	}
	
	return 0;
}
