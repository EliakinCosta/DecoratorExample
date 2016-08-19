#ifndef BOLODECORATOR_H
#define BOLODECORATOR_H

#include <../IBolo/ibolo.h>
#include <QtCore/QObject>

class BoloDecorator: public IBolo,
                     public QObject
{
public:
    BoloDecorator(QObject* parent = 0);
    virtual ~BoloDecorator(){}
    void setDecorated(IBolo *component);
protected:
    IBolo *m_decorated;
};

Q_DECLARE_INTERFACE(BoloDecorator, "org.qt-project.BoloDecorator.BoloDecorator")

#endif // BOLODECORATOR_H
