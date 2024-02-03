#pragma once
#include "AForm.hpp"
#include <string>

class RobotomyRequestForm : public AForm {
private:
  std::string target;
  RobotomyRequestForm();

public:
  RobotomyRequestForm(std::string target);
  RobotomyRequestForm(const RobotomyRequestForm &form);
  RobotomyRequestForm &operator=(const RobotomyRequestForm &form);
  ~RobotomyRequestForm();

  void execute(Bureaucrat const &executor) const;
  const std::string GetName() const;
};
