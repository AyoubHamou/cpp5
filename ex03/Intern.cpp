#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &other) { *this = other; }

Intern &Intern::operator=(const Intern &other) {
  (void)other;
  return *this;
}

Intern::~Intern() {}

AForm *Intern::makeForm(std::string name, std::string target) {
  std::string forms[3] = {"robotomy request", "president request",
                          "shrubbery request"};
  int i;
  for (i = 0; i < 3; i++)
    if (!forms[i].compare(name))
      break;
  switch (i) {
  case 0:
    std::cout << "Intern creates " << forms[0] << std::endl;
    return (new RobotomyRequestForm(target));
  case 1:
    std::cout << "Intern creates " << forms[1] << std::endl;
    return (new PresidentialPardonForm(target));
  case 2:
    std::cout << "Intern creates " << forms[2] << std::endl;
    return (new ShrubberyCreationForm(target));
  default:
    std::cout << "Intern Can't Create the Form" << std::endl;
    return (NULL);
  }
}
