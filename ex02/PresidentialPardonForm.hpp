#pragma once
#include "AForm.hpp"
#include <string>

class PresidentialPardonForm : public AForm {
private:
  std::string target;
  PresidentialPardonForm();

public:
  PresidentialPardonForm(std::string target);
  PresidentialPardonForm(const PresidentialPardonForm &form);
  PresidentialPardonForm &operator=(const PresidentialPardonForm &form);
  ~PresidentialPardonForm();

  void execute(Bureaucrat const &executor) const;
  const std::string GetName() const;
};
