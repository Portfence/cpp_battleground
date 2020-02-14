#pragma once

#include <thread>
#include <atomic>
#include <mutex>
#include <queue>
#include <memory>
#include <functional>
#include <stdexcept>
#include <optional>

class CLooper
{
public:
  using Runnable = std::function<void()>;

  class CDispatcher
  {
    friend class CLooper; // Allow the looper to access the private const

  public:
    bool post(CLooper::Runnable &&aRunnable)
    {
      return mAssignedLooper.post(std::move(aRunnable));
    }

  private:
    CDispatcher(CLooper &aLooper)
      : mAssignedLooper(aLooper) {}

  private:
    CLooper &mAssignedLooper;
  };

public:
    // Copy denied, Move to be implemented
    CLooper()
      : mDispatcher(std::shared_ptr<CDispatcher>(new CDispatcher(*this))) {}

    ~CLooper()
    {

    }

    void stop()
    {
      abortAndJoin();
    }

    // To be called, once the looper should start looping.
    bool run()
    {
        try
        {
            mThread = std::thread(&CLooper::runFunc, this);
        }
        catch(...)
        {
            return false;
        }

        return true;
    }

    bool running() const
    {
      return mRunning.load();
    }

    bool post(CLooper::Runnable&& aRunnable)
    {
      if (!running())
      {
        return false;
      }

      try
      {
        std::lock_guard guard(mRunnablesMutex);
        mRunnables.push(std::move(aRunnable));
      }
      catch(const std::exception& e)
      {
        return false;
      }
      return true;
    }

    std::shared_ptr<CDispatcher> getDispatcher()
    {
      return mDispatcher;
    }

private:
    void runFunc()
    {
        // Thread function
        mRunning.store(true);
        while (false == mAbortRequested.load())
        {
          try
          {
            using namespace std::chrono_literals;
            std::optional<Runnable> r = next();
            if (r)
            {
              r.value()();
            }
            else
            {
              std::this_thread::sleep_for(1ms);
            }
          }
          catch(const std::runtime_error& e)
          {
            // somethin specific
          }
          catch(const std::exception& e)
          {
            // make sure nothing leaves the thread for now
          }
        }
        mRunning.store(false);
    }

    void abortAndJoin()
    {
      mAbortRequested.store(true);
      if (mThread.joinable())
      {
        mThread.join();
      }
    }

    std::optional<Runnable> next()
    {
      std::lock_guard guard(mRunnablesMutex);
      if (mRunnables.empty())
      {
        return std::nullopt;
      }

      Runnable runnable = mRunnables.front();
      mRunnables.pop();

      return runnable;
    }
private:
    std::thread mThread;
    std::atomic_bool mRunning;
    std::atomic_bool mAbortRequested;
    std::recursive_mutex mRunnablesMutex;
    std::queue<Runnable> mRunnables;

    std::shared_ptr<CDispatcher> mDispatcher;
};
