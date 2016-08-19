#ifndef BOLODEMILHO_H
#define BOLODEMILHO_H

#include "bolodemilho_global.h"
#include <../IBolo/ibolo.h>

class BOLODEMILHOSHARED_EXPORT BoloDeMilho: public IBolo
{

public:
    BoloDeMilho();
    virtual ~BoloDeMilho(){}
    virtual void assar() const;
};

#endif // BOLODEMILHO_H
