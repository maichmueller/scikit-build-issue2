
#ifndef TESTPKG_MACROS_HPP
#define TESTPKG_MACROS_HPP

#if defined(__gnu_linux__) || defined(__linux__)
#define OS_NAME "Linux"
#define OS LINUX
#elif defined(macintosh) || defined(Macintosh) || (defined(__APPLE__) && defined(__MACH__))
#define OS_NAME "Mac"
#define OS MAC
#elif defined(_WIN32)
#define OS_NAME "Windows"
#define OS WINDOWS
#else
#define OS_NAME UNKNOWN
#define OS UNKNOWN
#warning "Operating system not recognized. Unexpected results might happen."
#endif

#if(OS == LINUX || OS == MAC) \
   && (COMPILER == ICC_COMPILER || COMPILER == GCC_COMPILER)
#ifndef EXPORT
#define EXPORT __attribute__((visibility("default")))
#endif
#ifndef IMPORT
#define IMPORT __attribute__((visibility("default")))
#endif
#ifndef LOCAL
#define LOCAL __attribute__((visibility("hidden")))
#endif
#elif(OS == WINDOWS)
#define EXPORT __declspec(dllexport)
#define IMPORT __declspec(dllimport)
#define LOCAL
#else
#define EXPORT
#define IMPORT
#define LOCAL
#endif

#if ! defined(BUILD_STATIC) && ! defined(IMPORT_LIBRARY)
#define API EXPORT
#elif defined(IMPORT_LIBRARY)
#define API IMPORT
#else
#define API
#endif


#endif // TESTPKG_MACROS_HPP
