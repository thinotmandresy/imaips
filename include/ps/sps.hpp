#pragma once
#include <string>

namespace PS {

// Sets the key/value pair in the shared storage
bool aiSPSSetInt(const char* key, int value);

// Returns the value corresponding to the key, read from the shared storage
int  aiSPSGetInt(const char* key);

} // namespace PS
