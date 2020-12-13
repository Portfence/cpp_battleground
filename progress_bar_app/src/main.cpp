/**
 * @file main.cpp
 * @brief ProgressBar
 * @version 0.1
 * @date 2020-03-17
 *
 *
 */
#include "ProgressBar.hpp"

#include <iostream>
#include <thread>
#include <termcolor/termcolor.hpp>

using std::cout;
using std::endl;

int main()
{
  std::cout << termcolor::bold << termcolor::yellow;

  ProgressBar bar;
  bar.set_progress(50.f);
  bar.set_bar_width(50);
  bar.set_status_text("Upload COVID-19");
  bar.fill_bar_progress_with("■");
  bar.fill_bar_remainder_with(" ");

  for (size_t i = 1; i <= 100; ++i) {
    bar.update(i);
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
  }

  std::cout << termcolor::reset << std::endl;
  return EXIT_SUCCESS;
}
