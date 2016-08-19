#include "bolodecorator.h"


BoloDecorator::BoloDecorator(QObject* parent):QObject(parent)
{
}


void BoloDecorator::setDecorated(IBolo *component)
{
    m_decorated = component;
}
