#include "chocolategranulado.h"
#include <../BoloDecorator/bolodecorator.h>
#include <QDebug>

ChocolateGranulado::ChocolateGranulado(QObject *parent):BoloDecorator(parent)
{
}

void ChocolateGranulado::assar() const
{
    m_decorated->assar();
    qDebug() << "Chocolate granulado";
}
