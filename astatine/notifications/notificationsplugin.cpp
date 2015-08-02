#include "notificationsplugin.h"
#include "notification/notification.h"

NotificationsPlugin::NotificationsPlugin()
{
}

NotificationsPlugin::~NotificationsPlugin()
{
}

bool NotificationsPlugin::supportsExtension(Extension ext) const
{
    return ext == Notifications;
}

QObject* NotificationsPlugin::createExtension(Extension ext) const
{
    switch (ext) {
        case Notifications:
            return new Notification();

        default:
            return 0;
    }
}

//for QT-4.8
#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(webkitplugin, cutiens);
#endif
