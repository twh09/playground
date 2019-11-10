#include <iostream>
#include <string>
#include "Lambda.h"

void GenericLambda()
{
  std::cout << "C++14 now allows the auto type-specifier in the parameter list, enabling polymorphic lambdas.\n";

  std::cout << "Using \'x\' as auto parameter\n\n";
  std::cout << "auto identity = [](auto x) {return x;};\n\n";
  auto identity = [](auto x) {return x;};

  std::cout << "Usage in function\nint three = identity(3)\n";
  int three = identity(3);
  std::cout << "Output: " << three << "\n\n";

  std::cout << "Using in function\nstd::string foo = identity(\"foo\");\n";
  std::string foo = identity("foo");
  std::cout << "Output: " << foo << "\n";
}

void CaptureInitializers()
{
  std::cout << "This allows creating lambda captures initialized with arbitrary expressions.\n"
    << "The name given to the captured value does not need to be related to any variables\nin the enclosing scopes and introduces a new name inside the lambda body.\n"
    << "The initializing expression is evaluated when the lambda is created (not when it is invoked).\n\n";

  std::cout << "auto f = [x = 1]{ return x; };\n";
  auto f = [x = 1]{ return x; }; // returns 1
  std::cout << "Result f: " << f() << "\n";
}