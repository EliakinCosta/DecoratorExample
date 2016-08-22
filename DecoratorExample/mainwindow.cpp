#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <../BoloDecorator/bolodecorator.h>
#include <../IBolo/ibolo.h>
#include <../BoloDeMilho/bolodemilho.h>
#include <QDir>
#include <QPluginLoader>
#include <QApplication>
#include <QDebug>
#include <QList>
#include <QListWidgetItem>
#include <QListWidget>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_loadedDecorators(new QMap<QString, BoloDecorator*>)
{
    ui->setupUi(this);

    connect(ui->m_btInserir, SIGNAL (released()), this, SLOT (insertButton()));
    connect(ui->m_btRemover, SIGNAL (released()), this, SLOT (removeButton()));
    connect(ui->m_brPreparar, SIGNAL(released()), this, SLOT (prepararBolo()));
    connect(ui->m_btSubir, SIGNAL(released()), this, SLOT (subirDecorator()));
    connect(ui->m_btDescer, SIGNAL(released()), this, SLOT (descerDecorator()));

    loadPlugins();
    loadedPluginsToList();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::insertButton()
{
    int row = ui->listWidget_2->count();
    QListWidgetItem *newItem = new QListWidgetItem;
    newItem->setText(ui->listWidget->currentItem()->text());

    ui->listWidget_2->insertItem(row, newItem);

}


void MainWindow::removeButton()
{
    foreach (QListWidgetItem *item, ui->listWidget_2->selectedItems()) {
        ui->listWidget_2->takeItem(ui->listWidget_2->row(item));
    }
}

void MainWindow::prepararBolo()
{
    IBolo *bolo = new BoloDeMilho;
    BoloDecorator *decorator = 0;
    for(int i = 0; i < ui->listWidget_2->count(); ++i)
    {
        QListWidgetItem* item = ui->listWidget_2->item(i);
        BoloDecorator *temp_decorator = m_loadedDecorators->value(item->text())->create();
        if(i==0)
        {
            decorator = temp_decorator;
            decorator->setDecorated(bolo);
        }
        else
        {
            temp_decorator->setDecorated(decorator);
            decorator = temp_decorator;
        }
    }
    decorator->assar();
}


void MainWindow::subirDecorator()
{
    if(ui->listWidget_2->currentItem() && ui->listWidget_2->row(ui->listWidget_2->currentItem()) > 0)
    {
        int row = ui->listWidget_2->row(ui->listWidget_2->currentItem());
        QListWidgetItem *item = ui->listWidget_2->takeItem(row);
        ui->listWidget_2->insertItem(row-1, item);
    }
}

void MainWindow::descerDecorator()
{
    int count = ui->listWidget_2->count();
    if(ui->listWidget_2->currentItem() && ui->listWidget_2->row(ui->listWidget_2->currentItem()) < count-1)
    {
        int row = ui->listWidget_2->row(ui->listWidget_2->currentItem());
        QListWidgetItem *item = ui->listWidget_2->takeItem(row);
        ui->listWidget_2->insertItem(row+1, item);
    }
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
               m_loadedDecorators->insert(plugin->metaObject()->className(), plugin);
            }
        }
}

void MainWindow::loadedPluginsToList()
{
    foreach (QString decoratorName, m_loadedDecorators->keys())
    {
        QListWidgetItem *newItem = new QListWidgetItem;
        newItem->setText(decoratorName);
        ui->listWidget->insertItem(ui->listWidget->count(), newItem);
    }
}
