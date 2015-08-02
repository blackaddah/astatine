#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>
#include <QSettings>
#include "ui_settings.h"

class Settings : public QDialog, public Ui::Settings
{
    Q_OBJECT

public:
    Settings(QWidget *parent);
    ~Settings();

private:
    QSettings *settings;

public slots:
    void saveSettings();

signals:
    void settingsModified();
};

#endif // SETTINGS_H
