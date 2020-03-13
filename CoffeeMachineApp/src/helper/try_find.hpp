#pragma once

#include <map>
#include <optional>

namespace helper
{
/**
 * @brief Try to find a the value to the adjecent key in a map
 *
 * @tparam Key key
 * @tparam Value value
 * @param t_selection key used to search for value
 * @param t_map map to search
 * @return std::optional<Value> returns value if found
 */
template <typename Key, typename Value>
static std::optional<Value> try_find(const Key& t_selection, const std::map<Key, Value>& t_map)
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
