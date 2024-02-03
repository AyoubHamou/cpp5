#include "AForm.hpp"

AForm::AForm()
    : name("AForm"), is_signed(false), sign_grade(2), exec_grade(3) {}

AForm::AForm(const int _sign_grade, const int _exec_grade)
    : is_signed(false), sign_grade(_sign_grade), exec_grade(_exec_grade) {
  if (this->sign_grade > 150 || this->exec_grade > 150)
    throw AForm::GradeTooLowException();
  if (this->sign_grade < 1 || this->exec_grade < 1)
    throw AForm::GradeTooHighException();
}

AForm::AForm(const AForm &other)
    : name(other.name), sign_grade(other.sign_grade),
      exec_grade(other.exec_grade) {
  *this = other;
}

AForm &AForm::operator=(const AForm &other) {
  if (this != &other) {
    this->is_signed = other.is_signed;
  }
  return *this;
}

AForm::~AForm() {}

const std::string AForm::GetName() const { return this->name; }

bool AForm::GetIsSigned() const { return this->is_signed; }

int AForm::GetSignGrade() const { return this->sign_grade; }

int AForm::GetExecGrade() const { return this->exec_grade; }

std::ostream &operator<<(std::ostream &os, const AForm &AForm) {
  os << AForm.GetName() << ", Sign grade is " << AForm.GetSignGrade()
     << "\nand it's execute Sign grade is " << AForm.GetExecGrade();
  return os;
}

void AForm::beSigned(Bureaucrat &Bureaucrat) {
  if (Bureaucrat.GetGrade() <= this->sign_grade)
    this->is_signed = true;
  else
    throw AForm::GradeTooLowException();
}

const char *AForm::GradeTooHighException::what() const throw() {
  return "GradeTooHigh";
}

const char *AForm::GradeTooLowException::what() const throw() {
  return "GradeTooLow";
}

const char *AForm::FormNotSignedException::what(void) const throw() {
  return "FormNotSigned";
}
