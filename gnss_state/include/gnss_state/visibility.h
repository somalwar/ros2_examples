#ifndef GNSS_STATE__VISIBILITY_H_
#define GNSS_STATE__VISIBILITY_H_

#ifdef __cplusplus
extern "C"
{
#endif

// This logic was borrowed (then namespaced) from the examples on the gcc wiki:
//     https://gcc.gnu.org/wiki/Visibility

#if defined _WIN32 || defined __CYGWIN__

  #ifdef __GNUC__
    #define GNSS_STATE_EXPORT __attribute__ ((dllexport))
    #define GNSS_STATE_IMPORT __attribute__ ((dllimport))
  #else
    #define GNSS_STATE_EXPORT __declspec(dllexport)
    #define GNSS_STATE_IMPORT __declspec(dllimport)
  #endif

  #ifdef GNSS_STATE_DLL
    #define GNSS_STATE_PUBLIC GNSS_STATE_EXPORT
  #else
    #define GNSS_STATE_PUBLIC GNSS_STATE_IMPORT
  #endif

  #define GNSS_STATE_PUBLIC_TYPE GNSS_STATE_PUBLIC

  #define GNSS_STATE_LOCAL

#else

  #define GNSS_STATE_EXPORT __attribute__ ((visibility("default")))
  #define GNSS_STATE_IMPORT

  #if __GNUC__ >= 4
    #define GNSS_STATE_PUBLIC __attribute__ ((visibility("default")))
    #define GNSS_STATE_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define GNSS_STATE_PUBLIC
    #define GNSS_STATE_LOCAL
  #endif

  #define GNSS_STATE_PUBLIC_TYPE
#endif

#ifdef __cplusplus
}
#endif

#endif  // GNSS_STATE__VISIBILITY_H_