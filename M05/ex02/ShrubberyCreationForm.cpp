#include <fstream>

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() :
	AForm("NoName", "NoName", 145, 137)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(
		const std::string& name, const std::string& target)
	: AForm(name, target, 145, 137)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(
		const ShrubberyCreationForm& other) :
	AForm(other)
{

}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(
		const ShrubberyCreationForm& other)
{
	AForm::operator=(other);
	return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	checkToExecute(executor);

	std::string fileName = target + "_shrubbery";

	std::ofstream outFile;
	outFile.exceptions(std::ofstream::failbit | std::ofstream::badbit);
	outFile.open(fileName.c_str(), std::ios_base::out | std::ios_base::trunc);
	outFile << \
		"	               ,@@@@@@@,			  		\n"
		"       ,,,.   ,@@@@@@/@@,  .oo8888o.			\n"
		"    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o			\n"
		"   ,%&\%&&%&&%,@@@\\@@@/@@@88\\88888/88'		\n"
		"   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'		\n"
		"   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'		\n"
		"   `&%\\ ` /%&'    |.|        \\ '|8'			\n"
		"       |o|        | |         | |				\n"
		"       |.|        | |         | |				\n"
		"jgs \\\\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_ \n";
	outFile.close();
}
