#include "registry.hpp"
#include "ps/sps.hpp"
#include <UHCPlugin.h>

namespace UHC {

const char* g_default_key = "";
int g_default_int = -1;

void register_all(UHCPluginInfo* info) {
  {
    auto& syscall = info->RegisterSyscall(
      GroupAI, SyscallBool, "aiSPSSetInt",
      (const void*)PS::aiSPSSetInt, 2,
      ""
    );
    info->SyscallSetParam(syscall, 0, SyscallString, g_default_key);
    info->SyscallSetParam(syscall, 1, SyscallInteger, &g_default_int);
  }

  {
    auto& syscall = info->RegisterSyscall(
      GroupAI, SyscallInteger, "aiSPSGetInt",
      (const void*)PS::aiSPSGetInt, 1,
      ""
    );
    info->SyscallSetParam(syscall, 0, SyscallString, g_default_key);
  }
}

} // namespace UHC
