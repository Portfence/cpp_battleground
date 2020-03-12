
#pragma once

#include <map>
#include <optional>

namespace helper
{
/**
 * @brief Try to find a the value to the adjecent key in a map
 *
 * @tparam T key
 * @tparam U value
 * @param t_selection key used to search for value
 * @param t_map map to search
 * @return std::optional<U> returns value if found
 */
template <typename T, typename U>
static std::optional<U> try_find(const T& t_selection, const std::map<T, U>& t_map)
{
  auto it = t_map.find(t_selection);
  if (it != t_map.end())
  {
    return it->second;
  }
  else
  {
    return std::nullopt;
  }
}
} // namespace helper
