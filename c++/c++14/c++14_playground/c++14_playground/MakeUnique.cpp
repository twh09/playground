void MakeUnique()
{
  /*
    std::make_unique is the recommended way to create instances of std::unique_ptrs due to the following reasons:

    Avoid having to use the new operator.
    Prevents code repetition when specifying the underlying type the pointer shall hold.
    Most importantly, it provides exception-safety. Suppose we were calling a function foo like so:
    foo(std::unique_ptr<T>{new T{}}, function_that_throws(), std::unique_ptr<T>{new T{}});
    The compiler is free to call new T{}, then function_that_throws(), and so on...
    Since we have allocated data on the heap in the first construction of a T,
    we have introduced a leak here. With std::make_unique, we are given exception-safety:

    foo(std::make_unique<T>(), function_that_throws(), std::make_unique<T>());
    See the C++11 section on smart pointers for more information on std::unique_ptr and std::shared_ptr.
  */
}