#include <Windows.h>
#include <nvapi.h>
#include <stdio.h>

#include <NvApiDriverSettings.h>

// profile includes: ((mohaa itself + expansion packs) + their demo executables)
#define PROFILE_NAME L"Medal of Honor: Allied Assault"

int main(int argc, char *argv[]) {
  NvDRSSessionHandle session_handle = 0;
  NvDRSProfileHandle profile_handle = 0;

  if (NvAPI_Initialize() || NvAPI_DRS_CreateSession(&session_handle) ||
      NvAPI_DRS_LoadSettings(session_handle) ||
      NvAPI_DRS_FindProfileByName(session_handle, PROFILE_NAME,
                                  &profile_handle)) {
    fprintf(stderr, "[-] unable to initialize nvapi\n");
    return 1;
  }

  NVDRS_SETTING present_method_setting = {
      .version = NVDRS_SETTING_VER,
      .settingId = OGL_CPL_PREFER_DXPRESENT_ID,
      .settingType = NVDRS_DWORD_TYPE,
  };

  if (NvAPI_DRS_GetSetting(session_handle, profile_handle,
                           OGL_CPL_PREFER_DXPRESENT_ID,
                           &present_method_setting)) {
    fprintf(stderr,
            "[-] unable to get 'present method' nvapi profile setting\n");
    return 1;
  }

  printf("[+] current 'present method' value: %lu\n",
         present_method_setting.u32CurrentValue);

  int new_value;
  printf("=> input new value to set (0/2 = DEFAULT, 1 = OBS-FIX): ");
  scanf_s("%d", &new_value);

  if (new_value < 0 || new_value > 2) {
    fprintf(stderr, "[-] invalid value\n");
    return 1;
  }

  present_method_setting.u32CurrentValue = new_value;

  if (NvAPI_DRS_SetSetting(session_handle, profile_handle,
                           &present_method_setting)) {
    fprintf(stderr, "[-] unable to set value of 'present method' setting");
    return 1;
  }

  printf("\n\n[+] value updated, now: %lu\n",
         present_method_setting.u32CurrentValue);

  NvAPI_DRS_SaveSettings(session_handle);
  NvAPI_DRS_DestroySession(session_handle);
  NvAPI_Unload();

  return 0;
}
