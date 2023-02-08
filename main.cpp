#include <windows.h>
#include <cstdint>

int main(int argc, char const *argv[])
{
  /* code */
  return 0;
}

DWORD _native_dllmain_reason = -1;
int proc_attached = 0;
bool dword_18002A034 = false;

bool (*pRawDllMain)(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpReserved);

bool (*CRT_INIT)(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpReserved);

bool (*DllMain)(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpReserved);

bool CRT_ProcessAttach(HINSTANCE hinstDLL, LPVOID lpReserved);
bool CRT_ProcessDetach(HINSTANCE hinstDLL, LPVOID lpReserved);

bool CRT_ThreadAttach(HINSTANCE hinstDLL, LPVOID lpReserved);
bool CRT_ThreadDetach(HINSTANCE hinstDLL, LPVOID lpReserved);

bool _DllMainCRTStartup(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpReserved)
{
  switch (fdwReason)
  {
  case DLL_PROCESS_ATTACH:
    return CRT_ProcessAttach(hinstDLL, lpReserved);

  case DLL_THREAD_ATTACH:
    return CRT_ThreadAttach(hinstDLL, lpReserved);

  case DLL_THREAD_DETACH:
    return CRT_ThreadDetach(hinstDLL, lpReserved);

  case DLL_PROCESS_DETACH:
    return CRT_ProcessDetach(hinstDLL, lpReserved);
  }
};

bool CRT_ProcessAttach(HINSTANCE hinstDLL, LPVOID lpReserved)
{
  _native_dllmain_reason = DLL_PROCESS_ATTACH;

  if (pRawDllMain)
  {
    dword_18002A034 = true;
    if (!pRawDllMain(hinstDLL, DLL_PROCESS_ATTACH, lpReserved))
    {
      _native_dllmain_reason = -1;
      return false;
    }
  }

  if (!CRT_INIT(hinstDLL, DLL_PROCESS_ATTACH, lpReserved))
  {
    _native_dllmain_reason = -1;
    return false;
  }

  if (!DllMain(hinstDLL, DLL_PROCESS_ATTACH, lpReserved))
  {
    DllMain(hinstDLL, DLL_PROCESS_DETACH, NULL);
    CRT_INIT(hinstDLL, DLL_PROCESS_DETACH, NULL);

    if (pRawDllMain)
      pRawDllMain(hinstDLL, DLL_PROCESS_DETACH, NULL);
  }

  _native_dllmain_reason = -1;
  return true;
}
bool CRT_ProcessDetach(HINSTANCE hinstDLL, LPVOID lpReserved)
{
  _native_dllmain_reason = DLL_PROCESS_DETACH;

  if (proc_attached == 0)
  {
    _native_dllmain_reason = -1;
    return false;
  }
  if (pRawDllMain)
    if (!pRawDllMain(hinstDLL, DLL_PROCESS_DETACH, lpReserved))
    {
      _native_dllmain_reason = -1;
      return false;
    }

  if (!CRT_INIT(hinstDLL, DLL_PROCESS_DETACH, lpReserved))
  {
    _native_dllmain_reason = -1;
    return false;
  }

  DllMain(hinstDLL, DLL_PROCESS_DETACH, lpReserved);
  bool result = CRT_INIT(hinstDLL, DLL_PROCESS_DETACH, lpReserved);

  if (pRawDllMain && dword_18002A034)
    result = pRawDllMain(hinstDLL, DLL_PROCESS_DETACH, lpReserved);

  _native_dllmain_reason = -1;

  return result;
}

bool CRT_ThreadAttach(HINSTANCE hinstDLL, LPVOID lpReserved)
{
  if (pRawDllMain && !pRawDllMain(hinstDLL, DLL_THREAD_ATTACH, lpReserved))
    return false;

  return true;
}

bool CRT_ThreadDetach(HINSTANCE hinstDLL, LPVOID lpReserved)
{
  if (pRawDllMain && dword_18002A034)
    return pRawDllMain(hinstDLL, DLL_THREAD_DETACH, lpReserved);

  return true;
}