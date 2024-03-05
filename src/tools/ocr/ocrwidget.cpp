#include <QBuffer>
#include <QMenu>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QUrl>

#include "ocrwidget.h"
#include "src/utils/globalvalues.h"

OcrWidget::OcrWidget(const QPixmap& pixmap, const QRect& geometry, const QUrl& ocrServerUrl, QWidget* parent)
    : QWidget(parent)
    , m_pixmap(pixmap)
    , m_layout(new QVBoxLayout(this))
    , m_textEdit(new QTextEdit(this))
{

    QRect ocrRect = geometry;
    ocrRect.setHeight(20);
    setGeometry(ocrRect);

    setWindowIcon(QIcon(GlobalValues::iconPath()));
    setWindowFlags(windowFlags() | Qt::WindowStaysOnTopHint);
    setFocusPolicy(Qt::StrongFocus);
    // set the bottom widget background transparent
    setAttribute(Qt::WA_TranslucentBackground);
    setAttribute(Qt::WA_DeleteOnClose);

    m_textEdit->setText("Recognizing...");
    m_layout->addWidget(m_textEdit);

    QByteArray pixArray;
    QBuffer buffer(&pixArray);
    buffer.open(QIODevice::WriteOnly);
    pixmap.save(&buffer, "PNG");

    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    QNetworkRequest request(ocrServerUrl);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "image/png");
    QNetworkReply *reply = manager->post(request, pixArray);
    connect(reply, &QNetworkReply::finished, this, [=]() {
        if (reply->error()) {
            qDebug() << "Error:" << reply->errorString();
            m_textEdit->setText("Error: " + reply->errorString());
            return;
        }

        QByteArray data = reply->readAll();
        qDebug() << "Received data:" << data;
        QString text = QString::fromUtf8(data);
        m_textEdit->setText(text);
        int contentHeight = m_textEdit->document()->size().height();
        m_textEdit->setFixedHeight(contentHeight);
        reply->deleteLater();
    });

}