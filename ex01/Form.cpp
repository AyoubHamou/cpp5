#include "Form.hpp"

Form::Form() : name("Form"), is_signed(false), sign_grade(2), exec_grade(3) {}

Form::Form(const std::string _name, const int _sign_grade,
           const int _exec_grade)
    : name(_name), is_signed(false), sign_grade(_sign_grade),
      exec_grade(_exec_grade) {
  if (this->sign_grade > 150 || this->exec_grade > 150)
    throw Form::GradeTooLowException();
  if (this->sign_grade < 1 || this->exec_grade < 1)
    throw Form::GradeTooHighException();
}

Form::Form(const Form &other)
    : name(other.name), sign_grade(other.sign_grade),
      exec_grade(other.exec_grade) {
  *this = other;
}

Form &Form::operator=(const Form &other) {
  if (this != &other) {
    this->is_signed = other.is_signed;
  }
  return *this;
}

Form::~Form() {}

const std::string Form::GetName() const { return this->name; }

bool Form::GetIsSigned() const { return this->is_signed; }

int Form::GetSignGrade() const { return this->sign_grade; }

int Form::GetExecGrade() const { return this->exec_grade; }

std::ostream &operator<<(std::ostream &os, const Form &Form) {
  os << Form.GetName() << ", Sign grade is " << Form.GetSignGrade()
     << "\nand it's execute Sign grade is " << Form.GetExecGrade();
  return os;
}

void Form::beSigned(Bureaucrat &Bureaucrat) {
  if (Bureaucrat.GetGrade() <= this->sign_grade)
    this->is_signed = true;
  else
    throw Form::GradeTooLowException();
}

const char *Form::GradeTooHighException::what() const throw() {
  return "GradeTooHigh";
}

const char *Form::GradeTooLowException::what() const throw() {
  return "GradeTooLow";
}
