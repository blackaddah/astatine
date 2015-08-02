#include "awebview.h"

AWebView::AWebView(QWidget *parent=0) : QWebView(parent)
{
    m_page = new AWebPage(this);
    setPage(m_page);

    m_page->settings()->setAttribute(QWebSettings::JavascriptEnabled, true);
    m_page->settings()->setAttribute(QWebSettings::JavascriptCanOpenWindows, true);
    m_page->settings()->setAttribute(QWebSettings::NotificationsEnabled, true);
    m_page->setLinkDelegationPolicy(QWebPage::DelegateAllLinks);

    connect(m_page, SIGNAL(featurePermissionRequested(QWebFrame*, QWebPage::Feature)),
            this, SLOT(receiveFeatureRequest(QWebFrame *, QWebPage::Feature)));
}

AWebView::~AWebView()
{
    delete m_page;
}

AWebPage * AWebView::page() const
{
    return m_page;
}

void AWebView::receiveFeatureRequest(QWebFrame * frame, QWebPage::Feature feature)
{
    if (feature == QWebPage::Notifications)
        m_page->setFeaturePermission(frame, QWebPage::Notifications, QWebPage::PermissionGrantedByUser);
}
