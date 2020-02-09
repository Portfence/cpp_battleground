/**
 * @file main.cpp
 * @brief Testing Move copy constructor and Move Assignment operator
 * @version 0.1
 * @date 2020-02-05
 *
 *
 */
#include <iostream>
#include <vector>
#include <optional>

using std::cout;
using std::endl;

class Names
{
private:
  std::string* name;
public:
  Names(std::string place_name)
  {
    cout << "Overloaded constructor " << __PRETTY_FUNCTION__ << endl;
    name = new std::string;
    *name = place_name;
  }

  Names(const Names& cpy)
  {
    cout << "Copy constructor " << __PRETTY_FUNCTION__ << endl;
    name = new std::string;
    *name = *cpy.name;
  }

  Names& operator =(const Names& cpy)
  {
    cout << "Assignment operator " << __PRETTY_FUNCTION__ << endl;
    name = new std::string;
    *name = *cpy.name;
    return *this;
  }

  Names(Names&& cpy_move) noexcept
  {
    cout << "Move constructor " << __PRETTY_FUNCTION__ << endl;
    name = cpy_move.name;
    cpy_move.name = nullptr;
  }

  // Move assignment operator
  Names& operator=(Names&& cpy_move)
  {
    cout << "Move Assignment operator " << __PRETTY_FUNCTION__ << endl;
    // delete name;
    // name = cpy_move.name;
    // cpy_move.name = nullptr;
    name = std::move(cpy_move.name);
    return *this;
  }

  ~Names()
  {
    cout << "Deallocating memory " <<  __PRETTY_FUNCTION__ << endl;
    delete name;
  }
};

Names getName()
{
  Names nme("ABC");
  return std::move(nme);
}

std::string BuildString(int number)
{
  std::string s { " Super Long Builder: " };
  s += std::to_string(number);
  cout << &s << ", data: " << static_cast<void *>(s.data())  << '\n';
  return s;
}

std::vector<int> CreateVec() {
    std::vector<int> v { 0, 1, 2, 3, 4 };
    std::cout << std::hex << v.data() << '\n';
    //return {std::move(v)}; // this one will cause a copy
    return (v); // this one moves
    //return v; // this one moves as well
}

std::optional<std::vector<int>> CreateOptVec() {
    std::vector<int> v { 0, 1, 2, 3, 4 };
    std::cout << static_cast<void *>(v.data()) << '\n';
    return {v}; // this one will cause a copy
    //return v; // this one moves
}

int main()
{
  // First test use move constructor
  // Names nme("Bob");
  // auto name = std::move(nme);


  // Seconds test: move assignment
  // Names tassigned("XYZ");
  // Names temp("ABC");
  // tassigned = std::move(temp);

  auto str42 = BuildString(42);

  cout << &str42 << ", data: " << static_cast<void *>(str42.data())  << '\n';

  return 0;
}
