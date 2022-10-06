#include <iostream>
#include <string>

#include "Bureaucrat.hpp"
#include "Form.hpp"

/******************************** TESTS ********************************/

void	testAssignationOperator(int gradeToSign, int gradeToExec, bool isSigned)
{
	std::string		name = "Random Form";
	try
	{
		Form f(name + "_1", gradeToSign, gradeToExec);
		if (isSigned) {
			f.beSigned(Bureaucrat("tmp", 1));
		}
		Form g(name + "_2", 100, 100);

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

void	testFormConstructor(int gradeToSign, int gradeToExec)
{
	std::string		name = "Random Form";
	try
	{
		Form f(name, gradeToSign, gradeToExec);
		std::cout << f << std::endl;
		std::cout << f.getGradeToSign() << std::endl;
		std::cout << f.getGradeToExec() << std::endl;
	}
	catch(std::exception& err)
	{
		std::cerr << err.what() << std::endl;
	}
}

void	testCopyConstructor(int gradeToSign, int gradeToExec, bool isSigned)
{
	std::string		name = "Random Form";
	try
	{
		Form f(name, gradeToSign, gradeToExec);
		if (isSigned) {
			f.beSigned(Bureaucrat("tmp", 1));
		}

		std::cout << "Original: ";
		std::cout << f << std::endl;

		Form f_copy(f);
		std::cout << "Copied  : ";
		std::cout << f_copy << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}


void	testBeSigned(int bureaucreatGrade, int gradeToSign, int gradeToExec, bool is_signed)
{
	std::string	b_name = "Harry Potter";
	std::string	f_name = "My Form";
	try
	{
		Bureaucrat	b(b_name, bureaucreatGrade);
		Form		f(f_name, gradeToSign, gradeToExec);
		if (is_signed == true)
			f.beSigned(Bureaucrat("tmp", 1));
		std::cout << std::endl << b << std::endl;
		std::cout << "Before: " << f << std::endl;
		f.beSigned(b);
		std::cout << "After : ";
		std::cout << f << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

}

void	testSignForm(int bureaucreatGrade, int gradeToSign, int gradeToExec, bool is_signed)
{
	std::string	b_name = "Ron Weasly";
	std::string	f_name = "My Form";
	try
	{
		Bureaucrat	b(b_name, bureaucreatGrade);
		Form		f(f_name, gradeToSign, gradeToExec);
		if (is_signed == true)
			f.beSigned(Bureaucrat("tmp", 1));
		std::cout << std::endl << b << std::endl;
		std::cout << "Before: " << f << std::endl;
		b.signForm(f);
		std::cout << "After : ";
		std::cout << f << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

int		main()
{
	std::cout << "Test 01: Form Constructor---------" << std::endl;
	testFormConstructor(42, 24);
	testFormConstructor(0, 150);
	testFormConstructor(1, 151);

	std::cout << "\nTest 02: Form Copy constructor---------" << std::endl;
	testCopyConstructor(40, 80, true);
	testCopyConstructor(40, 80, false);
	testCopyConstructor(0, 150, true);
	testCopyConstructor(1, 151, true);

	std::cout << "\nTest 03: Form Assignation Operator---------" << std::endl;
	testAssignationOperator(1, 150, true);
	testAssignationOperator(0, 150, true);
	testAssignationOperator(1, 151, true);

	std::cout << "\nTest 04: signForm function---------" << std::endl;
	testBeSigned(1, 12, 15, false);
	testBeSigned(1, 12, 15, true); // Form is already signed
	testBeSigned(150, 149, 15, false); // Not high enough to sign
	testBeSigned(151, 149, 15, false); // bureaucrat with invalid grade
	testBeSigned(0, 149, 15, false); // bureaucrat with invalid grade

	std::cout << "\nTest 05: signForm function---------" << std::endl;
	testSignForm(1, 12, 15, false);
	testSignForm(1, 12, 15, true); // Form is already signed
	testSignForm(150, 149, 15, false); // Not high enough to sign
	testSignForm(151, 149, 15, false); // bureaucrat with invalid grade
	testSignForm(0, 149, 15, false); // bureaucrat with invalid grade
}