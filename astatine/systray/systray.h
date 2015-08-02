#ifndef SYSTRAY_H
#define SYSTRAY_H

#include <QSystemTrayIcon>
#include <QMenu>


class Systray : public QWidget
{
    Q_OBJECT

public:
    Systray(QWidget *parent);

    void show();
    void hide();
    bool isEnabled();

private:
    QWidget *parent;
    QSystemTrayIcon *tray;
    QMenu *trayMenu;
    QAction *openSettings;
    QAction *restoreAction;
    QAction *quitAction;

    void prepareSignals();
    void quit();

public slots:
    void onTrayDoubleClick(QSystemTrayIcon::ActivationReason reason);
};

#endif // SYSTRAY_H
