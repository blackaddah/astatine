#include "systray.h"

Systray::Systray(QWidget *parent)
{
    this->parent = parent;
    tray = new QSystemTrayIcon(this);
    trayMenu = new QMenu(this);
    openSettings = new QAction(tr("&Settings"), this);
    restoreAction = new QAction(tr("&Restore"), this);
    quitAction = new QAction(tr("&Quit"), this);

    trayMenu->addAction(openSettings);
    trayMenu->addSeparator();
    trayMenu->addAction(restoreAction);
    trayMenu->addAction(quitAction);

    tray->setIcon(QIcon(":/res/systray.png"));
    tray->setContextMenu(trayMenu);

    prepareSignals();
}

void Systray::prepareSignals()
{
    connect(tray, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(onTrayDoubleClick(QSystemTrayIcon::ActivationReason)));
    connect(restoreAction, SIGNAL(triggered()), parent, SLOT(restoreWindow()));
    connect(quitAction, SIGNAL(triggered()), parent, SLOT(quit()));
    connect(openSettings, SIGNAL(triggered()), parent, SLOT(openSettings()));
}

void Systray::show()
{
    if (!tray->isVisible())
        tray->show();
}

void Systray::hide()
{
    if (tray->isVisible())
        tray->hide();
}

bool Systray::isEnabled()
{
    return tray->isVisible();
}

void Systray::onTrayDoubleClick(QSystemTrayIcon::ActivationReason reason)
{
    if (reason == QSystemTrayIcon::DoubleClick) {
        if (parent->isHidden())
            parent->show();
        else
            parent->hide();
    }
}

