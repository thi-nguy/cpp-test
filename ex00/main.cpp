#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

void	testDecrement(int grade)
{
	std::string		name = "Songoku";
	try
	{
		Bureaucrat b(name, grade);
		std::cout << "before: ";
		std::cout << b << std::endl;

		std::cout << "after : ";
		b.decreaseGrade();
		std::cout << b << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	testIncrement(int grade)
{
	std::string		name = "Poccolo";
	try
	{
		Bureaucrat b(name, grade);
		std::cout << "before: ";
		std::cout << b << std::endl;

		std::cout << "after : ";
		b.increaseGrade();
		std::cout << b << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	testConstructor(int grade)
{
	std::string		name = "ChiChi";

	try
	{
		Bureaucrat b(name, grade);
		std::cout << b << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	testCopyConstructor(int grade)
{
	std::string		name = "Ron Weasly";
	try
	{
		Bureaucrat b(name, grade);
		std::cout << "Original: ";
		std::cout << b << std::endl;

		Bureaucrat b_copy(b);
		std::cout << "Copied  : ";
		std::cout << b_copy << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	testAssignationOperator(int grade)
{
	std::string		name = "Ron Weasly";
	try
	{
		Bureaucrat b(name, grade);
		std::cout << "Original b: ";
		std::cout << b << std::endl;

		Bureaucrat c("Harry Potter", 20);
		std::cout << "Original c: ";
		std::cout << c << std::endl;
		c = b;
		std::cout << "Copied c  : ";
		std::cout << c << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

int		main()
{
    std::cout << "\nTest 01: Contructor---------------" << std::endl;
	testConstructor(-1);
	testConstructor(1);
	testConstructor(42);
	testConstructor(150);
	testConstructor(151);

    std::cout << "\nTest 02: Copy Constructor---------------" << std::endl;
	testCopyConstructor(-1);
	testCopyConstructor(1);
	testCopyConstructor(42);
	testCopyConstructor(150);
	testCopyConstructor(151);

    std::cout << "\nTest 03: Assignation Operator---------------" << std::endl;
	testAssignationOperator(-1);
	testAssignationOperator(1);
	testAssignationOperator(42);
	testAssignationOperator(150);
	testAssignationOperator(151);

    std::cout << "\nTest 04: Increment---------------" << std::endl;
	testIncrement(-1);
	testIncrement(1);
	testIncrement(42);
	testIncrement(150);
	testIncrement(151);

    std::cout << "\nTest 05: Decrement---------------" << std::endl;
	testDecrement(-1);
	testDecrement(1);
	testDecrement(42);
	testDecrement(150);
	testDecrement(151);
}