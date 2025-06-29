#include <iostream>

class Base
{
public:
	virtual ~Base() { std::cout << "Base destroyed\n"; }
};

class Derived : public Base
{
public:
	~Derived() { std::cout << "Derived destroyed\n"; }
};

int main()
{
	// virtual destructors ensure that the derived class destructor is called
	// when deleting an object through a base class pointer.
	// This prevents resource leaks and ensures proper cleanup of derived class resources.
	// If the base class destructor is not virtual, only the base class destructor will be called
	// when deleting a derived class object through a base class pointer,
	// leading to potential resource leaks or undefined behavior.
	Base *ptr = new Derived();
	delete ptr;
				
}