#ifndef _ITEMS_EXPORT_H_
#define _ITEMS_EXPORT_H_

#if defined(COMPONENT_BUILD)
#if defined(WIN32)

#if defined(ITEMS_IMPLEMENTATION)
#define ITEMS_EXPORT __declspec(dllexport)
#else
#define ITEMS_EXPORT __declspec(dllimport)
#endif  // defined(ITEMS_IMPLEMENTATION)

#else  // defined(WIN32)
#if defined(ITEMS_IMPLEMENTATION)
#define ITEMS_EXPORT __attribute__((visibility("default")))
#else
#define ITEMS_EXPORT
#endif
#endif

#else  // defined(COMPONENT_BUILD)
#define ITEMS_EXPORT
#endif
#endif  // !_ITEMS_EXPORT_H_
