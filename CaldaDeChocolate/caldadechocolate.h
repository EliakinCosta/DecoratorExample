#ifndef CALDADECHOCOLATE_H
#define CALDADECHOCOLATE_H

#include "caldadechocolate_global.h"
#include <../BoloDecorator/bolodecorator.h>

class CALDADECHOCOLATESHARED_EXPORT CaldaDeChocolate: public BoloDecorator
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.BoloDecorator.BoloDecorator")
    Q_INTERFACES(BoloDecorator)
public:
    CaldaDeChocolate(QObject *parent = 0);
    ~CaldaDeChocolate(){}
    virtual void assar() const;
};

#endif // CALDADECHOCOLATE_H
