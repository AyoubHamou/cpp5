#pragma once
#include "AForm.hpp"
#include <fstream>
#include <string>
class ShrubberyCreationForm : public AForm {
private:
  std::string target;
  ShrubberyCreationForm();

public:
  ShrubberyCreationForm(std::string target);
  ShrubberyCreationForm(const ShrubberyCreationForm &form);
  ShrubberyCreationForm &operator=(const ShrubberyCreationForm &form);
  ~ShrubberyCreationForm();

  void execute(Bureaucrat const &executor) const;
  const std::string GetName() const;
};
