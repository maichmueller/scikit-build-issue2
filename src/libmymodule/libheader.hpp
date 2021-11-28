
#ifndef TESTPKG_LIBHEADER_HPP
#define TESTPKG_LIBHEADER_HPP

#if(OS == LINUX || OS == MAC) && COMPILER_VERSION >= 4000 \
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

class API MyLibClass {
  void f();
};

#endif // TESTPKG_LIBHEADER_HPP
