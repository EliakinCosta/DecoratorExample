#ifndef IBOLO_H
#define IBOLO_H

#include "ibolo_global.h"

class IBOLOSHARED_EXPORT IBolo
{

public:
    IBolo();
    virtual ~IBolo(){}
    virtual void assar() const = 0;
};

#endif // IBOLO_H
