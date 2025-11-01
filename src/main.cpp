#include "UHCPlugin.h"
#include <windows.h>

extern "C" _declspec(dllexport)
int UHCPluginMain(UHCPluginInfo *plugin_info) {
  MessageBox(NULL, "Hello, world!", "Notice", MB_OK | MB_ICONINFORMATION);
  return 0;
}
