/**
 * @file main.cpp
 * @brief Multithreading paradigm with loopers and dispatchers
 * @version 0.1
 * @date 2020-02-04
 *
 * @copyright Copyright (c) 2020
 *
 */
#include <iostream>
#include <tl/expected.hpp>

#include "c_looper.hpp"

int main(int argc, char ** argv)
{
  auto looper = std::make_unique<CLooper>();
  std::cout << "Starting looper" << std::endl;
  looper->run();

  auto dispatcher = looper->getDispatcher();

  std::cout << "Adding tasks" << std::endl;
  for (uint32_t k=0; k<500; k++)
  {
    auto const task = [k](){
      std::cout << "Invocation " << k
                  << ": Hello, I have been executed asynchronously on the looper for " << (k + 1)
                  << " times." << std::endl;
    };

    dispatcher->post(std::move(task));
  }

  std::cout << "Waiting 5 seconds for completion" << std::endl;
  std::this_thread::sleep_for(std::chrono::seconds(5));
  std::cout << "Stopping looper" << std::endl;
  looper->stop();
  return 0;
}