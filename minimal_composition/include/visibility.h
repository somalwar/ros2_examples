#ifndef MINIMAL_COMPOSITION__VISIBILITY_H_
#define MINIMAL_COMPOSITION__VISIBILITY_H_

#ifdef __cplusplus
extern "C"
{
#endif

// This logic was borrowed (then namespaced) from the examples on the gcc wiki:
//     https://gcc.gnu.org/wiki/Visibility

#if defined _WIN32 || defined __CYGWIN__

  #ifdef __GNUC__
    #define MINIMAL_COMPOSITION_EXPORT __attribute__ ((dllexport))
    #define MINIMAL_COMPOSITION_IMPORT __attribute__ ((dllimport))
  #else
    #define MINIMAL_COMPOSITION_EXPORT __declspec(dllexport)
    #define MINIMAL_COMPOSITION_IMPORT __declspec(dllimport)
  #endif

  #ifdef MINIMAL_COMPOSITION_DLL
    #define MINIMAL_COMPOSITION_PUBLIC MINIMAL_COMPOSITION_EXPORT
  #else
    #define MINIMAL_COMPOSITION_PUBLIC MINIMAL_COMPOSITION_IMPORT
  #endif

  #define MINIMAL_COMPOSITION_PUBLIC_TYPE MINIMAL_COMPOSITION_PUBLIC

  #define MINIMAL_COMPOSITION_LOCAL

#else

  #define MINIMAL_COMPOSITION_EXPORT __attribute__ ((visibility("default")))
  #define MINIMAL_COMPOSITION_IMPORT

  #if __GNUC__ >= 4
    #define MINIMAL_COMPOSITION_PUBLIC __attribute__ ((visibility("default")))
    #define MINIMAL_COMPOSITION_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define MINIMAL_COMPOSITION_PUBLIC
    #define MINIMAL_COMPOSITION_LOCAL
  #endif

  #define MINIMAL_COMPOSITION_PUBLIC_TYPE
#endif

#ifdef __cplusplus
}
#endif

#endif  // MINIMAL_COMPOSITION__VISIBILITY_H_