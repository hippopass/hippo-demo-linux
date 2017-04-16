#ifndef HIPPO_H
#define HIPPO_H

#ifdef __unix__
#define OS_Unix
#elif defined(_WIN32) || defined(_WIN64)
#define OS_Windows
#endif

# ifdef __cplusplus
extern "C"
{
# endif

#ifdef OS_Windows
#ifdef BUILDING_HIPPO_DLL
#define HIPPO_DLL __declspec(dllexport)
#else
#define HIPPO_DLL __declspec(dllimport)
#endif /* BUILDING_HIPPO_DLL */
#endif /* OS_Windows */

#ifdef OS_Unix
#define HIPPO_DLL
#endif /* OS_Unix */

int HIPPO_DLL hippo_init(char* apiKey);
int HIPPO_DLL hippo_signup(int handle, int level, char* username, char* pinCode);
int HIPPO_DLL hippo_pre_auth(int handle, char* gCode, size_t len);
int HIPPO_DLL hippo_verify_otp(int handle, char* username, int token, char* otp);
void HIPPO_DLL hippo_done(int handle);

# ifdef __cplusplus
}
# endif

#endif /* HIPPO_H */

