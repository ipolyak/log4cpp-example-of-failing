#include <iostream>
#include "some.h"

static int staticVariable = Some::SomeMethod();

int main()
{
  std::cout << "Bug is not reproduced." << std::endl;

  return 0;
}