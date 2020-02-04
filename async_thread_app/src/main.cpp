#include <iostream>
#include <sstream>
#include <iomanip>
#include <thread>
#include <future>
#include <vector>
#include <mutex>

/**
 * @brief Executed by an async thread. Note: IO (std::cout) is handled by caller. Task just produces data.
 *
 * @param value input
 * @return std::string output
 */
std::string process(const int value)
{
  std::ostringstream buffer;
  buffer << "my_thread" << std::setfill('0') << std::setw(2) << value;
  return buffer.str();
}

int main()
{
  std::vector<std::future<std::string> > rets;
  if (auto test = process(1); test=="my_thread01")
  {

  }
  else if(test == "")
  {

  }

  std::mutex mu;


  std::cout << "lock" << std::endl;
  if(std::scoped_lock<std::mutex> lock(mu); !rets.empty())
  {
    // critcal section
  }
  else if(rets.empty())
  {
    // also critical section
  }
  else
  {
    // also critical section
  }

  std::cout << "unlock" << std::endl;

  if (auto a{1.0}; a < 0)
  {

  }
  for (int i=0; i<4; i++)
  {
    rets.push_back(std::async(std::launch::async, process, i));
  }

  for(auto & t : rets)
  {
    t.wait();
    std::cout << t.get() << std::endl;
  }
  return 0;
}
