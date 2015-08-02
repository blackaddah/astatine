#include <QDebug>
#include "notificationview.h"

NotificationView::NotificationView(QWidget *parent) : QWebView(parent)
{
    setContextMenuPolicy(Qt::NoContextMenu);
    page()->setLinkDelegationPolicy(QWebPage::DelegateAllLinks);
}

void NotificationView::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::RightButton)
        emit rightClick();

    else
        QWebView::mousePressEvent(event);
}
