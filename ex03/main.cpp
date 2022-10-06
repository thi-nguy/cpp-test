#include <iostream>
#include <string>

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int		main()
{
	{
		Intern		someRandomIntern;
		Form*		rrf;
		std::string	target = "My Palace";

		std::cout << std::endl;
		rrf = someRandomIntern.makeForm("shrubbery creation", target);
		std::cout << *rrf << std::endl;
		delete rrf;
	}
	{
		Intern		someRandomIntern;
		Form*		rrf;
		std::string	target = "Android 18";

		std::cout << std::endl;
		rrf = someRandomIntern.makeForm("robotomy request", target);
		std::cout << *rrf << std::endl;
		delete rrf;
	}
	{
		Intern		someRandomIntern;
		Form*		rrf;
		std::string	target = "Voldemort";

		std::cout << std::endl;
		rrf = someRandomIntern.makeForm("presidential pardon", target);
		std::cout << *rrf << std::endl;
		delete rrf;
	}
	{
		Intern		someRandomIntern;
		Form*		rrf;
		std::string	target = "bla bla";

		std::cout << std::endl;
		rrf = someRandomIntern.makeForm("ble ble", target);
		std::cout << rrf << std::endl;
	}
}