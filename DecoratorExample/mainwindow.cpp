#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <../BoloDecorator/bolodecorator.h>
#include <QDir>
#include <QPluginLoader>
#include <QApplication>
#include <QDebug>
#include <QList>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_loadedDecorators(new QList<BoloDecorator*>)
{
    ui->setupUi(this);

    connect(ui->m_btInserir, SIGNAL (released()), this, SLOT (insertButton()));
    connect(ui->m_btRemover, SIGNAL (released()), this, SLOT (removeButton()));

    loadPlugins();
    loadedPluginsToList();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::insertButton()
{
    qDebug() << "insert";
}


void MainWindow::removeButton()
{
    qDebug() << "remove";
}

void MainWindow::loadPlugins()
{
        QDir pluginsDir = QDir(qApp->applicationDirPath());
        #if defined(Q_OS_WIN)
            qDebug() << pluginsDir.dirName().toLower();
            if (pluginsDir.dirName().toLower() == "debug" || pluginsDir.dirName().toLower() == "release")
                pluginsDir.cdUp();
        #elif defined(Q_OS_MAC)
            if (pluginsDir.dirName() == "MacOS") {
                pluginsDir.cdUp();
                pluginsDir.cdUp();
                pluginsDir.cdUp();
            }
        #endif
        pluginsDir.cdUp();
        pluginsDir.cd("plugins/");
        qDebug() << "diretorio plugins: " << pluginsDir.path();
        BoloDecorator* plugin = 0;

        foreach (QString pluginFileName, pluginsDir.entryList(QDir::Files))
        {
            QPluginLoader loader(pluginsDir.absoluteFilePath(pluginFileName));
            plugin = dynamic_cast<BoloDecorator *>(loader.instance());
            qDebug() << pluginFileName;
            if (plugin)
            {
               qDebug() << plugin;
               m_loadedDecorators->append(plugin);
            }
        }
}

void MainWindow::loadedPluginsToList()
{
    foreach (BoloDecorator *decorator, *m_loadedDecorators)
    {
        ui->listWidget->addItem(decorator->metaObject()->className());
    }
}
