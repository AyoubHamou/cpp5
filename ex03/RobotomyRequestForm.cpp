#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"

static int i = 0;

RobotomyRequestForm::RobotomyRequestForm() : AForm(72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm(72, 45) {
  this->target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &form)
    : AForm(72, 45) {
  *this = form;
}

RobotomyRequestForm &
RobotomyRequestForm::operator=(const RobotomyRequestForm &form) {
  if (this != &form)
    this->target = form.target;
  return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

const std::string RobotomyRequestForm::GetName() const { return this->target; }

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
  if (executor.GetGrade() > this->GetExecGrade())
    throw AForm::GradeTooLowException();
  if (!this->GetIsSigned())
    throw AForm::FormNotSignedException();
  i++;
  std::cout << "Drilling Noises" << std::endl;
  if (i % 2)
    std::cout << this->target << " has been robotomized" << std::endl;
  else
    std::cout << "The Robotomy Failed" << std::endl;
}
