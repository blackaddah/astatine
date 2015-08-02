#include <QDebug>

#include "awebpage.h"

AWebPage::AWebPage(QObject *parent=0) : QWebPage(parent)
{
    m_forceFlash = true;
}

QString AWebPage::userAgentForUrl(const QUrl & url) const
{
    // we say we are IE 9.0, otherwise YouTube sends us their HTML5 player
    // which doesn't work really well with QWebKit
    // that's how we force the use of the Flash plugin
    // sad but true
    if (m_forceFlash)
        return QString("Mozilla/5.0 (Windows; U; MSIE 9.0; WIndows NT 9.0; en-US))");

    else
        return QWebPage::userAgentForUrl(url);
}

void AWebPage::forceFlash(bool val)
{
    m_forceFlash = val;
    settings()->setAttribute(QWebSettings::PluginsEnabled, val);
}

void AWebPage::enableNotifications(bool val)
{
    if (val)
        setFeaturePermission(currentFrame(),
                             QWebPage::Notifications,
                             QWebPage::PermissionGrantedByUser);

    else
        setFeaturePermission(currentFrame(),
                            QWebPage::Notifications,
                            QWebPage::PermissionDeniedByUser);
}
