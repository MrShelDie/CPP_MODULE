#include <iostream>

#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{

	Form *ppf = NULL;
	Form *rrf = NULL;
	Form *scf = NULL;

	try {
		Intern someRandomIntern;

		ppf = someRandomIntern.makeForm("presidential pardon", "Bender");	
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");	
		scf = someRandomIntern.makeForm("shrubbery creation", "Bender");	

		std::cout << "\n";

		{
			Bureaucrat bob("bob", 146);
			Bureaucrat bill("bill", 135);
			Bureaucrat mike("mike", 100);

			bob.signForm(*scf);
			mike.executeForm(*scf);
			bill.signForm(*scf);
			mike.executeForm(*scf);
		}

		std::cout << "\n";

		{
			Bureaucrat bob("bob", 146);
			Bureaucrat bill("bill", 70);
			Bureaucrat mike("mike", 40);

			bob.signForm(*rrf);
			mike.executeForm(*rrf);
			bill.signForm(*rrf);
			mike.executeForm(*rrf);
			mike.executeForm(*rrf);
			mike.executeForm(*rrf);
			mike.executeForm(*rrf);
			mike.executeForm(*rrf);
		}

		std::cout << "\n";

		{
			Bureaucrat bob("bob", 30);
			Bureaucrat bill("bill", 15);
			Bureaucrat mike("mike", 3);

			bob.signForm(*ppf);
			mike.executeForm(*ppf);
			bill.signForm(*ppf);
			mike.executeForm(*ppf);
		}
		
		std::cout << "\n";

		Form *uf = someRandomIntern.makeForm("unknown form", "Bender");	
		delete(uf);

	} catch (std::exception& e) {
		std::cout << e.what() << "\n";	
	}

	delete(ppf);
	delete(rrf);
	delete(scf);

	return 0;
}
