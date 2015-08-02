#ifndef NOTIFICATION_H
#define NOTIFICATION_H

#include <QtWebKit/QWebKitPlatformPlugin>
#include "notificationwindow.h"

class Notification : public QWebNotificationPresenter
{
    Q_OBJECT

public:
    explicit Notification();
    ~Notification();

    void showNotification(const QWebNotificationData* data);

private:
    NotificationWindow *window;

signals:
    void notificationClosed();
    void notificationClicked();
};

#endif // NOTIFICATION_H
