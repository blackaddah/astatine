#include <QDesktopWidget>
#include "notificationwindow.h"
#include "ui_notificationwindow.h"

NotificationWindow::NotificationWindow(QWidget *parent, Qt::WindowFlags f) :
    QDialog(parent, f),
    ui(new Ui::NotificationWindow)
{
    int x, y;

    m_view = new NotificationView(this);

    ui->setupUi(this);
    ui->gridLayout->setContentsMargins(0, 0, 0, 0);
    ui->gridLayout->addWidget(m_view);

    x = QApplication::desktop()->screenGeometry().width() -
        size().width() - 100;
    y = QApplication::desktop()->screenGeometry().height() -
        size().height() - 100;

    connect(m_view, SIGNAL(rightClick()),
            this, SLOT(hide()));

    // prevent it from stealing the focus
    setAttribute(Qt::WA_ShowWithoutActivating);
    setFocusPolicy(Qt::NoFocus);
    move(x, y);
}

NotificationWindow::~NotificationWindow()
{
    delete ui;
}

void NotificationWindow::showNotification(const QString title, const QUrl icon, const QString msg)
{
    QString code("<html><head></head>"
                 "<body style=\"font-family: 'Open Sans', Arial, Helvetica, sans-serif; font-size: 14px; background-color: #222426; color:white;\">"
                 "<div>"
                 "<img src=\"" + icon.toString() + "\" style=\"float: left;margin-right: 5px;\">"
                 "<section>"
                 "<h4 style=\"margin: 0;\">" + title + "</h4>"
                 "<p>" + msg + "</p>"
                 "</section></div>"
                 "</body></html>");
    m_view->setHtml(code);

    this->show();
}
