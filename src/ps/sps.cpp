#include "ps/core.hpp"
#include "ps/sps.hpp"

namespace PS {
  
bool aiSPSSetInt(const char* key, int value) {
  auto j = load(shared_path());
  j[key] = value;
  return save(shared_path(), j);
}

int aiSPSGetInt(const char* key) {
  auto j = load(shared_path());
  if (!j.contains(key) || !j[key].is_number_integer()) {
    return -1;
  }
  return j[key].get<int>();
}

} // namespace PS
