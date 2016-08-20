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

BoloDecorator *ChocolateGranulado::create() const
{
    return new ChocolateGranulado;
}
