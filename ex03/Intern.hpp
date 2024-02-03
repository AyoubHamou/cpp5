#pragma once

#include "AForm.hpp"
#include <string>

class Intern {
public:
  Intern();
  Intern(const Intern &other);
  Intern &operator=(const Intern &other);
  ~Intern();

  AForm *makeForm(std::string name, std::string target);
};
