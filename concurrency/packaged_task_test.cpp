// future example
#include <iostream>       // std::cout
#include <future>         // std::async, std::future
#include <chrono>         // std::chrono::milliseconds
#include <thread>

// a non-optimized way of checking for prime numbers:
bool is_prime (int x) {
  for (int i=2; i<x; ++i) if (x%i==0) return false;
  return true;
}

int main ()
{
    std::packaged_task<bool(int)> tsk(is_prime);
    std::future<bool> fut =  tsk.get_future();

    std::thread th(std::move(tsk), 100000001249);


    // do something while waiting for function to set future:
    // std::cout << "checking, please wait";
    // std::chrono::milliseconds span (200);
    // while (fut.wait_for(span)==std::future_status::timeout)
    //     std::cout << '.' << std::flush;

    bool x = fut.get();     // retrieve return value

    th.join();

    std::cout << "\n100000001249 " << (x?"is":"is not") << " prime.\n";

    return 0;
}