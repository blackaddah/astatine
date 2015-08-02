#include <QStandardPaths>
#include <QDesktopServices>
#include <QCloseEvent>
#include "astatine.h"
#include "ui_astatine.h"

astatine::astatine(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::astatine)
{
    QSettings::setDefaultFormat(QSettings::IniFormat);

    view = new AWebView(this);
    tray = new Systray(this);
    settings = new QSettings(this);
    settingsWnd = new Settings(this);
    settingsShortcut = new QShortcut(QKeySequence(tr("Ctrl+O")), this);

    view->settings()->enablePersistentStorage();

    connect(view, SIGNAL(linkClicked(const QUrl &)),
            this, SLOT(onUrlClicked(const QUrl &)));
    connect(view, SIGNAL(loadFinished(bool)),
            this, SLOT(loadFinished(bool)));
    connect(settingsWnd, SIGNAL(settingsModified()),
            this, SLOT(reloadSettings()));
    connect(settingsShortcut, SIGNAL(activated()),
            this, SLOT(openSettings()));

    ui->setupUi(this);
    ui->gridLayout->setContentsMargins(0, 0, 0, 0);
    ui->gridLayout->addWidget(view);

    loadSettings();

    view->load(QUrl("https://tweetdeck.twitter.com"));
}

astatine::~astatine()
{
    delete ui;
    delete view;
    delete tray;
    delete settings;
    delete settingsWnd;
}

void astatine::loadSettings()
{
    qDebug() << settings->fileName();

    if (settings->value("mainwindow/maximized", true).toBool())
        showMaximized();
    else
        resize(settings->value("mainwindow/size", QSize(640, 480)).toSize());

    if (settings->value("systray/enabled", true).toBool())
        tray->show();

    view->page()->forceFlash(settings->value("web/flash", true).toBool());
}

void astatine::closeEvent(QCloseEvent *event)
{
    if (settings->value("systray/enabled", true).toBool() &&
        settings->value("systray/close", true).toBool() &&
        !isHidden())
    {
        hide();
        event->ignore();
    }

    else
        quit();
}

void astatine::resizeEvent(QResizeEvent* event)
{
    QMainWindow::resizeEvent(event);

    settings->setValue("mainwindow/size", size());
}

void astatine::changeEvent(QEvent* event)
{
    QMainWindow::changeEvent(event);

    if(event->type() == QEvent::WindowStateChange) {
        settings->setValue("mainwindow/maximized", isMaximized());

        if (settings->value("systray/enabled", true).toBool() &&
            settings->value("systray/minimize", false).toBool() &&
            isMinimized())
        {
            hide();
        }
    }
}

/************************
 * slots
 ************************/

void astatine::reloadSettings()
{
    if (settings->value("systray/enabled").toBool())
        tray->show();

    else {
        // in case main window is hidden
        show();
        tray->hide();
    }

    view->page()->enableNotifications(settings->value("web/notifications").toBool());
    view->page()->forceFlash(settings->value("web/flash").toBool());
}

void astatine::openSettings()
{
    settingsWnd->show();
}

void astatine::onUrlClicked(const QUrl &url)
{
    QRegExp extUrl("(https?://t.co/\\w+)");

    if (extUrl.exactMatch(url.toEncoded()))
        QDesktopServices::openUrl(url);
}

void astatine::loadFinished(bool ok)
{
    if (ok && settings->value("web/notifications", true).toBool())
        view->page()->enableNotifications(true);
}


void astatine::quit()
{
    QApplication::quit();
}

void astatine::restoreWindow()
{
    if (isHidden())
        show();
}
