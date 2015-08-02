#include <QDebug>

#include <QDialog>
#include "settings.h"
#include "ui_settings.h"

Settings::Settings(QWidget *parent=0) : QDialog(parent)
{
    settings = new QSettings(this);

    setupUi(this);

        useSystray->setChecked(settings->value("systray/enabled", true).toBool());
        closeToTray->setChecked(settings->value("systray/close", true).toBool());
        minimizeToTray->setChecked(settings->value("systray/minimize", false).toBool());
        useFlash->setChecked(settings->value("web/flash", true).toBool());
        enableNotifications->setChecked(settings->value("web/notifications", true).toBool());

    connect(this, SIGNAL(accepted()), this, SLOT(saveSettings()));
}

Settings::~Settings()
{
    delete settings;
}

void Settings::saveSettings()
{
    settings->setValue("systray/enabled", useSystray->isChecked());
    settings->setValue("systray/close", closeToTray->isChecked());
    settings->setValue("systray/minimize", minimizeToTray->isChecked());

    settings->setValue("web/flash", useFlash->isChecked());
    settings->setValue("web/notifications", enableNotifications->isChecked());

    emit settingsModified();
}
