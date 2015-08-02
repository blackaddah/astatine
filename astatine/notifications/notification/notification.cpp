#include "notification.h"

Notification::Notification() : QWebNotificationPresenter()
{
    window = new NotificationWindow(0, Qt::SplashScreen);
}

Notification::~Notification()
{
    delete window;
}

void Notification::showNotification(const QWebNotificationData* data)
{
    window->showNotification(data->title(), data->iconUrl(), data->message());
}
