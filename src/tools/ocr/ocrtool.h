
#pragma once

#include "src/tools/abstractactiontool.h"

class OcrTool : public AbstractActionTool
{
    Q_OBJECT
public:
    explicit OcrTool(QObject* parent = nullptr);

    bool closeOnButtonPressed() const override;

    QIcon icon(const QColor& background, bool inEditor) const override;
    QString name() const override;
    QString description() const override;

    CaptureTool* copy(QObject* parent = nullptr) override;

protected:
    CaptureTool::Type type() const override;

public slots:
    void pressed(CaptureContext& context) override;

private:
    QRect m_geometry;
    QPixmap m_pixmap;
};