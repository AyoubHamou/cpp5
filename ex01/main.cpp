#include "Form.hpp"

int main() {
  try {
    Bureaucrat b("Bureaucrat", 140);
    Form f("Form", 140, 141);
    std::cout << b << std::endl;
    std::cout << f << std::endl;
    b.signForm(f);
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
}
