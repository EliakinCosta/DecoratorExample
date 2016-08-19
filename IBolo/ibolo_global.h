#ifndef IBOLO_GLOBAL_H
#define IBOLO_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(IBOLO_LIBRARY)
#  define IBOLOSHARED_EXPORT Q_DECL_EXPORT
#else
#  define IBOLOSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // IBOLO_GLOBAL_H
