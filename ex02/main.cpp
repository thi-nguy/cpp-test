#include <iostream>
#include <string>

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

/******************************** TESTS ********************************/

void	testShrubberyCreationForm(int bureaucreatGrade)
{
	std::string		target = "home";
	std::string		b_name = "Ron Weasly";

	try
	{
		ShrubberyCreationForm	s(target);
		Bureaucrat				b(b_name, bureaucreatGrade);

		s.beSigned(b);
		s.execute(b);

		//b.signForm(s);
		//b.executeForm(r);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void testRobotomyRequestForm(int bureaucreatGrade)
{
	std::string target = "Android 18";
	std::string b_name = "Krillin";

	try 
	{
		RobotomyRequestForm r(target);
		Bureaucrat			b(b_name, bureaucreatGrade);

		r.beSigned(b);
		r.execute(b);

		// b.signForm(r);
		// b.executeForm(r);
	} 
	catch (std::exception& e) 
	{
		std::cerr << e.what() << std::endl;
	}
}

void testPresidentialPardonForm(int bureaucreatGrade)
{
	std::string target = "Voldemort";
	std::string b_name = "Albus Dumbledore";

	try 
	{
		PresidentialPardonForm p(target);
		Bureaucrat			b(b_name, bureaucreatGrade);

		p.beSigned(b);
		p.execute(b);

		// b.signForm(p);
		// b.executeForm(p);
	} 
	catch (std::exception& e) 
	{
		std::cerr << e.what() << std::endl;
	}
}

void	testFormConstructor(std::string target)
{
	try
	{
		ShrubberyCreationForm s(target);
		std::cout << s << std::endl;
		RobotomyRequestForm r(target);
		std::cout << r << std::endl;
		PresidentialPardonForm p(target);
		std::cout << p << std::endl;
	}
	catch(std::exception& err)
	{
		std::cerr << err.what() << std::endl;
	}
}

void	testCopyConstructor(std::string target, bool isSigned)
{
	try
	{
		ShrubberyCreationForm s(target);
		// RobotomyRequestForm s(target);
		// PresidentialPardonForm s(target);

		if (isSigned) {
			s.beSigned(Bureaucrat("tmp", 1));
		}

		std::cout << "Original: ";
		std::cout << s << std::endl;

		ShrubberyCreationForm s_copy(s);
		// RobotomyRequestForm s_copy(s);
		// PresidentialPardonForm s_copy(s);
		
		std::cout << "Copied  : ";
		std::cout << s_copy << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	testAssignationOperator(std::string target, bool isSigned)
{
	try
	{
		ShrubberyCreationForm f(target + "_1");
		// RobotomyRequestForm f(target + "_1");
		// PresidentialPardonForm f(target + "_1");

		if (isSigned) {
			f.beSigned(Bureaucrat("tmp", 1));
		}
		ShrubberyCreationForm g(target + "_2");
		// RobotomyRequestForm g(target + "_2");
		// PresidentialPardonForm g(target + "_2");

		std::cout << "Form_1 before copy: " << f << std::endl;
		std::cout << "Form_2 before copy: " << g << std::endl;

		g = f;
		std::cout << "Form_1 after copy : " << f << std::endl;
		std::cout << "Fomr_2 after copy : " << g << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

int		main()
{
	std::cout << "Test 01: Shrubbery Creation Form---------" << std::endl;
	testShrubberyCreationForm(138); // OK to sign, KO to execute
	testShrubberyCreationForm(145); // OK to sign, KO to execute
	testShrubberyCreationForm(146); // KO to sign, KO to execute
	testShrubberyCreationForm(151); // Bureaucrat's grade is too low
	testShrubberyCreationForm(0); // Bureaucrat's grade is too high
	testShrubberyCreationForm(137); // OK to sign, OK to execute

	std::cout << "\nTest 02: Robotomy Request Form---------" << std::endl;
	testRobotomyRequestForm(46); // OK to sign, KO to execute
	testRobotomyRequestForm(72); // OK to sign, KO to execute
	testRobotomyRequestForm(73); // KO to sign, KO to execute
	testRobotomyRequestForm(151); // Bureaucrat's grade is too low
	testRobotomyRequestForm(0); // Bureaucrat's grade is too high
	testRobotomyRequestForm(45); // OK to sign, OK to execute

	std::cout << "\nTest 03: Presidential Pardon Form---------" << std::endl;
	testPresidentialPardonForm(24); // OK to sign, KO to execute
	testPresidentialPardonForm(25); // OK to sign, KO to execute
	testPresidentialPardonForm(26); // KO to sign, KO to execute
	testPresidentialPardonForm(151); // Bureaucrat's grade is too low
	testPresidentialPardonForm(0); // Bureaucrat's grade is too high
	testPresidentialPardonForm(5); // OK to sign, OK to execute

	std::cout << "\nTest 04: Constructor function---------" << std::endl;
	testFormConstructor("Mickey");

	std::cout << "\nTest 05: Copy constructor---------" << std::endl;
	testCopyConstructor("Mickey", true);
	testCopyConstructor("Mickey", false);

	std::cout << "\nTest 06: Assignation Operator---------" << std::endl;
	testAssignationOperator("Mickey", false);
	testAssignationOperator("Mickey", true);

	return (0);
}