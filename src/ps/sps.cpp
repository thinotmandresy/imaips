#include "ps/core.hpp"
#include "ps/sps.hpp"

namespace PS {

bool aiSPSSetBool(const char* key, bool value) {
  auto j = load(shared_path());
  j[key] = value;
  return save(shared_path(), j);
}

bool aiSPSSetInt(const char* key, int value) {
  auto j = load(shared_path());
  j[key] = value;
  return save(shared_path(), j);
}

bool aiSPSSetFloat(const char* key, float value) {
  auto j = load(shared_path());
  j[key] = value;
  return save(shared_path(), j);
}

bool aiSPSSetString(const char* key, const char* value) {
  auto j = load(shared_path());
  j[key] = std::string(value);
  return save(shared_path(), j);
}

bool aiSPSGetBool(const char* key) {
  auto j = load(shared_path());
  if (!j.contains(key) || !j[key].is_boolean()) {
    return false;
  }
  return j[key].get<bool>();
}

int aiSPSGetInt(const char* key) {
  auto j = load(shared_path());
  if (!j.contains(key) || !j[key].is_number_integer()) {
    return -1;
  }
  return j[key].get<int>();
}

float aiSPSGetFloat(const char* key) {
  auto j = load(shared_path());
  if (!j.contains(key) || !j[key].is_number_float()) {
    return 0.0f;
  }
  return j[key].get<float>();
}

const char* aiSPSGetString(const char* key) {
  static std::string value;
  auto j = load(shared_path());
  if (!j.contains(key) || !j[key].is_string()) {
    value = "";
  } else {
    value = j[key].get<std::string>();
  }
  return value.c_str();
}

} // namespace PS
