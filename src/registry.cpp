#include "registry.hpp"
#include "ps/sps.hpp"
#include <UHCPlugin.h>

namespace UHC {

const char* g_default_key = "default";
const char* g_default_str = "";
float g_default_float = 0.0f;
int g_default_int = -1;
bool g_default_bool = false;

void register_all(UHCPluginInfo* info) {
  {
    auto& syscall = info->RegisterSyscall(
      GroupAI, SyscallBool, "aiSPSSetBool",
      (const void*)PS::aiSPSSetBool, 2,
      ""
    );
    info->SyscallSetParam(syscall, 0, SyscallString, g_default_key);
    info->SyscallSetParam(syscall, 1, SyscallBool, &g_default_bool);
  }

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
      GroupAI, SyscallBool, "aiSPSSetFloat",
      (const void*)PS::aiSPSSetFloat, 2,
      ""
    );
    info->SyscallSetParam(syscall, 0, SyscallString, g_default_key);
    info->SyscallSetParam(syscall, 1, SyscallFloat, &g_default_float);
  }

  {
    auto& syscall = info->RegisterSyscall(
      GroupAI, SyscallBool, "aiSPSSetString",
      (const void*)PS::aiSPSSetString, 2,
      ""
    );
    info->SyscallSetParam(syscall, 0, SyscallString, g_default_key);
    info->SyscallSetParam(syscall, 1, SyscallString, g_default_str);
  }

  {
    auto& syscall = info->RegisterSyscall(
      GroupAI, SyscallBool, "aiSPSGetBool",
      (const void*)PS::aiSPSGetBool, 1,
      ""
    );
    info->SyscallSetParam(syscall, 0, SyscallString, g_default_key);
  }

  {
    auto& syscall = info->RegisterSyscall(
      GroupAI, SyscallInteger, "aiSPSGetInt",
      (const void*)PS::aiSPSGetInt, 1,
      ""
    );
    info->SyscallSetParam(syscall, 0, SyscallString, g_default_key);
  }

  {
    auto& syscall = info->RegisterSyscall(
      GroupAI, SyscallFloat, "aiSPSGetFloat",
      (const void*)PS::aiSPSGetFloat, 1,
      ""
    );
    info->SyscallSetParam(syscall, 0, SyscallString, g_default_key);
  }

  {
    auto& syscall = info->RegisterSyscall(
      GroupAI, SyscallString, "aiSPSGetString",
      (const void*)PS::aiSPSGetString, 1,
      ""
    );
    info->SyscallSetParam(syscall, 0, SyscallString, g_default_key);
  }
}

} // namespace UHC
