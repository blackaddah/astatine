#ifndef AWEBVIEW_H
#define AWEBVIEW_H

#include <QWebView>
#include "awebpage.h"

class AWebView : public QWebView
{
    Q_OBJECT

public:
    AWebView(QWidget *parent);
    ~AWebView();

    AWebPage * page() const;

private:
    AWebPage *m_page;

public slots:
    void receiveFeatureRequest(QWebFrame * frame, QWebPage::Feature feature);
};

#endif // AWEBVIEW_H
