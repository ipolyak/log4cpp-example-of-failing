#include <iostream>
#include "some.h"

static int staticVariable = Some::SomeMethod();

void main()
{
  std::cout << "Bug is not reproduced." << std::endl;

  return;
}