#ifndef NOTIFICATIONSPLUGIN_H
#define NOTIFICATIONSPLUGIN_H

#include <QtWebKit/QWebKitPlatformPlugin>

class NotificationsPlugin : public QObject, public QWebKitPlatformPlugin
{
    Q_OBJECT
    Q_INTERFACES(QWebKitPlatformPlugin)

#if QT_VERSION >= 0x050000
    Q_PLUGIN_METADATA(IID "org.qtwebkit.QtWebKit.QtWebPlugin")
#endif

public:
    explicit NotificationsPlugin();
    ~NotificationsPlugin();

    bool supportsExtension(Extension ext) const;
    QObject* createExtension(Extension ext) const;
};

#endif // CUTIENS_H
