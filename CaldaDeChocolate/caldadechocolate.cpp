#include "caldadechocolate.h"
#include <../BoloDecorator/bolodecorator.h>
#include <QDebug>

CaldaDeChocolate::CaldaDeChocolate(QObject *parent):BoloDecorator(parent)
{
}

void CaldaDeChocolate::assar() const
{
    m_decorated->assar();
    qDebug() << "Calda de chocolate";
}
