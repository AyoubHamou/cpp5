#include "Bureaucrat.hpp"

int main() {
  try {
    Bureaucrat b("Bureaucrat 1", 150);
    std::cout << b
              << std::endl; // this one will show the infos of the Bureaucrat
    std::cout << "Incrementing the Grade" << std::endl;
    b.decrement();
    std::cout
        << b
        << std::endl; // this one willn't beacause we throw exception before it
  } catch (std::exception &e) {
    std::cerr << "exception : " << e.what() << std::endl;
  }
}
