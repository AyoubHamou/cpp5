#include "Bureaucrat.hpp"
#include <string>

Bureaucrat::Bureaucrat() : name("Bureaucrat"), grade(1) {
  // std::cout << "Default constructor for Bureaucrat is called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string _name, int _grade)
    : name(_name), grade(_grade) {
  if (grade > 150)
    throw Bureaucrat::GradeTooLowException();
  if (grade < 1)
    throw Bureaucrat::GradeTooHighException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
    : name(other.name), grade(other.grade) {
  *this = other;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
  if (this != &other) {
    this->grade = other.grade;
  }
  return *this;
}

Bureaucrat::~Bureaucrat() {}

const std::string Bureaucrat::GetName() const { return this->name; }

int Bureaucrat::GetGrade() const { return this->grade; }

std::ostream &operator<<(std::ostream &os, const Bureaucrat &Bureaucrat) {
  os << Bureaucrat.GetName() << ", bureaucrat grade " << Bureaucrat.GetGrade()
     << ".";
  return os;
}

void Bureaucrat::increment(void) {
  if (this->grade - 1 < 1)
    throw Bureaucrat::GradeTooHighException();
  this->grade--;
}

void Bureaucrat::decrement(void) {
  if (this->grade + 1 > 150)
    throw Bureaucrat::GradeTooLowException();
  this->grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
  return "GradeTooHigh";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
  return "GradeTooLow";
}
