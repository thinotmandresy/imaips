#include "UHCPlugin.h"
#include "ps/core.hpp"
#include "registry.hpp"

#include <windows.h>

extern "C" __declspec(dllexport)
int UHCPluginMain(UHCPluginInfo* plugin_info) {
  if (!PS::init("./data/stringtablem.xml")) {
    MessageBox(NULL, "Could not read data/stringtablem.xml", "Warning", MB_OK | MB_ICONWARNING);
    return 1;
  }

  UHC::register_all(plugin_info);

  return 0;
}
