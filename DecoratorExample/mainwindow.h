#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <../IBolo/ibolo.h>
#include <../BoloDecorator/bolodecorator.h>
#include <QMap>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void loadPlugins();
    void loadedPluginsToList();
    Ui::MainWindow *ui;
    QMap<QString, BoloDecorator *> *m_loadedDecorators;

private Q_SLOTS:
    void insertButton();
    void removeButton();

};

#endif // MAINWINDOW_H
