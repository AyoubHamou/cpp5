#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm(25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
    : AForm(25, 5) {
  this->target = target;
}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm &form)
    : AForm(25, 5) {
  *this = form;
}

PresidentialPardonForm &
PresidentialPardonForm::operator=(const PresidentialPardonForm &form) {
  if (this != &form)
    this->target = form.target;
  return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

const std::string PresidentialPardonForm::GetName() const {
  return this->target;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
  if (executor.GetGrade() > this->GetExecGrade())
    throw AForm::GradeTooLowException();
  if (!this->GetIsSigned())
    throw AForm::FormNotSignedException();
  std::cout << this->target << " has been pardoned by Zaphod Beeblebrox"
            << std::endl;
}
