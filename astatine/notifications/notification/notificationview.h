#ifndef NOTIFICATIONVIEW_H
#define NOTIFICATIONVIEW_H

#include <QWebView>
#include <QMouseEvent>

class NotificationView : public QWebView
{
    Q_OBJECT

public:
    NotificationView(NotificationView::QWidget *parent);
    void mousePressEvent(QMouseEvent *event);

signals:
    void rightClick();
};

#endif // NOTIFICATIONVIEW_H
