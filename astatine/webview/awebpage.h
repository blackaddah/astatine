#ifndef AWEBPAGE_H
#define AWEBPAGE_H

#include <QWebPage>

class AWebPage : public QWebPage
{
public:
    AWebPage(QObject *parent);
    QString userAgentForUrl(const QUrl & url) const;
    void forceFlash(bool val);
    void enableNotifications(bool val);

private:
    bool m_forceFlash;

public slots:
    void featurePermissionRequested(QWebFrame * frame, QWebPage::Feature feature);
};

#endif // AWEBPAGE_H
