#pragma once

#include <QWidget>

class QUrl;
class QVBoxLayout;
class QTextEdit;

class OcrWidget : public QWidget
{
        Q_OBJECT

public:
    
    explicit OcrWidget(const QPixmap& pixmap,
                        const QRect& geometry,
                        const QUrl& ocrServerUrl,
                        QWidget* parent = nullptr);


private:

    QPixmap m_pixmap;
    QVBoxLayout* m_layout;
    QTextEdit* m_textEdit;
    QPoint m_dragStart;
    qreal m_offsetX{}, m_offsetY{};
};