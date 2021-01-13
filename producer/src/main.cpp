/**
 * @file main.cpp
 * @brief Testing producer C++20
 * @version 0.1
 * @date 2020-02-07
 *
 *
 */

#include <plog/Log.h>
#include <plog/Appenders/ConsoleAppender.h>

struct Key
{

};

class IUserInput
{
public:
  virtual ~IUserInput() {}
  virtual void onKeyLongPress(const Key& key)     { PLOG_DEBUG << __FUNCTION__  << " unimplemented"; }
  virtual void onKeyLongRelease(const Key& key)   { PLOG_DEBUG << __FUNCTION__  << " unimplemented"; }
  virtual void onKeyShortPress(const Key& key)    { PLOG_DEBUG << __FUNCTION__  << " unimplemented"; }
  virtual void onKeyShortRelease(const Key& key)  { PLOG_DEBUG << __FUNCTION__  << " unimplemented"; }
  virtual void onKeyDoubleTap(const Key& key)     { PLOG_DEBUG << __FUNCTION__  << " unimplemented"; }
  virtual void onKeyDoubleRelease(const Key& key) { PLOG_DEBUG << __FUNCTION__  << " unimplemented"; }
  // std::mutex& getLock() const {return mMutex;}
private:
  // mutable std::mutex mMutex;
};

class Consumer : public IUserInput
{
public:
  Consumer() : IUserInput() {}
  void onKeyShortPress(const Key& key) override
  {
    PLOGD << __PRETTY_FUNCTION__;
  }
};

class Producer
{
public:
  Producer(std::vector<IUserInput>& consumers) : mConsumers(consumers) {}
  ~Producer() {}

  void runOne()
  {
    Key k;

    std::for_each(mConsumers.begin(), mConsumers.end(), [&k](IUserInput& consumer){
      // std::scoped_lock<std::mutex> lock(consumer.getLock());
      consumer.onKeyShortPress(k);
    });
  }
private:
  std::vector<IUserInput> mConsumers;
};


int main()
{
  static plog::ConsoleAppender<plog::TxtFormatter> consoleAppender;
  plog::init(plog::debug, &consoleAppender);

  Consumer con_1;
  Consumer con_2;
  auto consumers = std::vector<IUserInput>{con_1, con_2};

  Producer p(consumers);

  p.runOne();
  return 0;
}
