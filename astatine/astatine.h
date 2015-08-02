#ifndef ASTATINE_H
#define ASTATINE_H

#include <QMainWindow>
#include <QWebView>
#include <QShortcut>
#include <QSettings>
#include "settings.h"
#include "webview/awebview.h"
#include "systray/systray.h"

namespace Ui {
class astatine;
}

class astatine : public QMainWindow
{
    Q_OBJECT

public:
    explicit astatine(QWidget *parent = 0);
    ~astatine();

    void loadSettings();

protected:
    void changeEvent(QEvent* event);
    void closeEvent(QCloseEvent *event);
    void resizeEvent(QResizeEvent* event);

private:
    Ui::astatine *ui;
    AWebView *view;
    QSettings *settings;
    QShortcut *settingsShortcut;
    Settings *settingsWnd;
    Systray *tray;

public slots:
    void reloadSettings();
    void openSettings();
    void onUrlClicked(const QUrl &url);
    void loadFinished(bool ok);
    void quit();
    void restoreWindow();
};

#endif // ASTATINE_H
