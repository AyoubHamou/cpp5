#pragma once
#include "AForm.hpp"
#include <iostream>
#include <string>

class AForm;

class Bureaucrat {
private:
  const std::string name;
  int grade;

public:
  Bureaucrat();
  Bureaucrat(const Bureaucrat &other);
  Bureaucrat &operator=(const Bureaucrat &other);
  ~Bureaucrat();

  Bureaucrat(const std::string _name, int _grade);
  const std::string GetName() const;
  int GetGrade() const;
  void increment();
  void decrement();
  class GradeTooHighException : public std::exception {
  public:
    virtual const char *what() const throw();
  };
  class GradeTooLowException : public std::exception {
  public:
    virtual const char *what() const throw();
  };
  void signForm(AForm &form);
  void executeForm(AForm const &form);
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &Bureaucrat);
