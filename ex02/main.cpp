#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
  try {
    // shrubbery tests
    Bureaucrat b("Bureaucrat", 1);
    ShrubberyCreationForm formS("shrubbery");
    std::cout << formS << std::endl;
    formS.beSigned(b);
    formS.execute(b);

    std::cout << "==============================" << std::endl;

    // Robotomy tests
    RobotomyRequestForm formR("Robot");
    std::cout << formR << std::endl;
    formR.beSigned(b);
    b.executeForm(formR);
    b.executeForm(formR);
    b.executeForm(formR);
    b.executeForm(formR);

    std::cout << "===============================" << std::endl;
    // President tests

    PresidentialPardonForm formP("President");
    std::cout << formP << std::endl;
    formP.beSigned(b);
    formP.execute(b);

  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
}
