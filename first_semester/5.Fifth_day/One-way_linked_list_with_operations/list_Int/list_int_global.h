#ifndef LIST_INT_GLOBAL_H
#define LIST_INT_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(LIST_INT_LIBRARY)
#  define LIST_INTSHARED_EXPORT Q_DECL_EXPORT
#else
#  define LIST_INTSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // LIST_INT_GLOBAL_H
