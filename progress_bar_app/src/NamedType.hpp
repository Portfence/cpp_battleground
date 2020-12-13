#pragma once

template <typename T>
class NamedType
{
public:
  explicit NamedType(const T& value) : mValue(value) {}
  explicit NamedType(T&& value) : mValue(std::move(value)) {}
  T& get() { return mValue; }
  T const& get() const { return mValue; }
private:
  T mValue;
};
