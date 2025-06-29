#include <iostream>

class Base
{
public:
	~Base() { std::cout << "Base destroyed\n"; }
};

class Derived : public Base
{
public:
	~Derived() { std::cout << "Derived destroyed\n"; }
};

int main()
{
	// Demonstrating the issue with non-virtual destructors
	// When a base class pointer points to a derived class object,
	// if the base class destructor is not virtual, the derived class destructor will not be called.
	
	Base *ptr = new Derived();
	delete ptr; // Only Base::~Base() is called — Derived::~Derived() is skipped!
	// This is because the destructor in Base is not declared as virtual.
	// To fix this, we should declare the destructor in Base as virtual:
}