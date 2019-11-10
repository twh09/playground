#include <iostream>
#include <string>

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