#ifndef CHOCOLATEGRANULADO_H
#define CHOCOLATEGRANULADO_H

#include "chocolategranulado_global.h"
#include <../BoloDecorator/bolodecorator.h>

class CHOCOLATEGRANULADOSHARED_EXPORT ChocolateGranulado: public BoloDecorator
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.BoloDecorator.BoloDecorator")
    Q_INTERFACES(BoloDecorator)
public:
    ChocolateGranulado(QObject *parent = 0);
    virtual ~ChocolateGranulado(){}
    virtual void assar() const;
    virtual BoloDecorator *create() const;
};

#endif // CHOCOLATEGRANULADO_H
