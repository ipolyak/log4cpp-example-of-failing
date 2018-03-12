#include "some.h"
#include "log.h"

int Some::SomeMethod()
{
  TLogger::GetLogger() << TLogger::EPriority::DEBUG << "AAA";

  return 0;
}
