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
  std::cout << "Result f: " << f() << "\n\n";

  std::cout << "Because it is now possible to move (or forward) values into a lambda that could previously be only captured by \ncopy or reference we can now capture move-only types in a lambda by value.\n";
  std::cout << "Note that in the below example the p in the capture-list of task2 on the left-hand-side of = is a \nnew variable private to the lambda body and does not refer to the original p.\n\n";


  std::cout << "auto p = std::make_unique<int>(1);\n";
  auto p = std::make_unique<int>(1);

  std::cout << "auto task1 = [=] { *p = 5; };\n"
    << "ERROR: std::unique_ptr cannot be copied\n\n";
  // auto task1 = [=] { *p = 5; };
  // ERROR: std::unique_ptr cannot be copied

  // vs.
  std::cout << "vs.\nauto task2 = [p = std::move(p)]{ *p = 5; };\n";
  auto task2 = [p = std::move(p)]{ *p = 5; }; // OK: p is move-constructed into the closure object
  std::cout << "OK: p is move-constructed into the closure object\n";
  std::cout << "the original p is empty after task2 is created\n";

  std::cout << "Using this reference-captures can have different names than the referenced variable.\n";
}
