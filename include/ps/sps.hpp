#pragma once
#include <string>

namespace PS {

// Sets the key/value pair in the shared storage
bool aiSPSSetBool(const char* key, bool value);
bool aiSPSSetInt(const char* key, int value);
bool aiSPSSetFloat(const char* key, float value);
bool aiSPSSetString(const char* key, const char* value);

// Returns the value corresponding to the key, read from the shared storage
bool aiSPSGetBool(const char* key);
int aiSPSGetInt(const char* key);
float aiSPSGetFloat(const char* key);
const char* aiSPSGetString(const char* key);

} // namespace PS
