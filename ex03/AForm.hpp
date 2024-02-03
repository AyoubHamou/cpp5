#pragma once

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

class Bureaucrat;

class AForm {
private:
  const std::string name;
  bool is_signed;
  const int sign_grade;
  const int exec_grade;
  AForm();

public:
  AForm(const int _sign_grade, const int _exec_grade);
  AForm(const AForm &other);
  AForm &operator=(const AForm &other);
  virtual ~AForm();

  virtual const std::string GetName() const;
  bool GetIsSigned() const;
  int GetSignGrade() const;
  int GetExecGrade() const;
  void beSigned(Bureaucrat &Bureaucrat);
  class GradeTooHighException : public std::exception {
  public:
    virtual const char *what() const throw();
  };
  class GradeTooLowException : public std::exception {
  public:
    virtual const char *what() const throw();
  };
  class FormNotSignedException : public std::exception {
  public:
    virtual const char *what() const throw();
  };
  virtual void execute(Bureaucrat const &executor) const = 0;
};
std::ostream &operator<<(std::ostream &os, const AForm &AForm);
