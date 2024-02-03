// #ifndef BUREAUCRAT_HPP
// #define BUREAUCRAT_HPP
#pragma once
#include "Form.hpp"
#include <iostream>
#include <string>

class Form;

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
  void signForm(Form &form);
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &Bureaucrat);

// #endif
