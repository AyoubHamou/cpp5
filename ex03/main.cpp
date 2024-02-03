#include "Intern.hpp"
int main() {
  try {
    Intern mtellami;
    AForm *rrf;
    rrf = mtellami.makeForm("president request", "FORM");
    // std::cout << rrf->GetName() << std::endl;
    if (rrf)
      delete rrf;
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
}
