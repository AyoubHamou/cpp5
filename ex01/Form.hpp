#pragma once

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

class Bureaucrat;

class Form {
private:
  const std::string name;
  bool is_signed;
  const int sign_grade;
  const int exec_grade;
  Form();

public:
  Form(const std::string _name, const int _sign_grade, const int _exec_grade);
  Form(const Form &other);
  Form &operator=(const Form &other);
  ~Form();

  const std::string GetName() const;
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
};

std::ostream &operator<<(std::ostream &os, const Form &Form);
