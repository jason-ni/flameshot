#ifndef CONFIGSHORTCUTS_H
#define CONFIGSHORTCUTS_H

#include <QVector>
#include <QString>
#include <QStringList>
#include <QKeySequence>
#include "src/widgets/capture/capturebutton.h"

class ConfigShortcuts
{
public:
    ConfigShortcuts();

    const QVector<QStringList>& captureShortcutsDefault(const QVector<CaptureButton::ButtonType> &buttons);
    const QKeySequence& captureShortcutDefault(const CaptureButton::ButtonType &buttonType);

private:
    QVector<QStringList> m_shortcuts;
    QKeySequence m_ks;
};

#endif // CONFIGSHORTCUTS_H
