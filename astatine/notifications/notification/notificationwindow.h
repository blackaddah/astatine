#ifndef NOTIFICATIONWINDOW_H
#define NOTIFICATIONWINDOW_H

#include <QDialog>
#include <QWebView>
#include "notificationview.h"

namespace Ui {
class NotificationWindow;
}

class NotificationWindow : public QDialog
{
    Q_OBJECT

public:
    explicit NotificationWindow(QWidget *parent = 0, Qt::WindowFlags f = 0);
    ~NotificationWindow();

    void showNotification(const QString title, const QUrl icon, const QString msg);

private:
    Ui::NotificationWindow *ui;
    NotificationView *m_view;
};

#endif // NOTIFICATIONWINDOW_H
