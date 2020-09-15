#ifndef SETSHORTCUTWIDGET_H
#define SETSHORTCUTWIDGET_H

#include <QObject>
#include <QDialog>
#include <QKeySequence>

class QVBoxLayout;


class SetShortcutDialog : public QDialog
{
    Q_OBJECT
public:
    explicit SetShortcutDialog(QDialog *parent = nullptr);
    const QKeySequence& shortcut();

public:
    void keyPressEvent(QKeyEvent *);
    void keyReleaseEvent(QKeyEvent *event);

signals:

private:
    QVBoxLayout *m_layout;
    QString m_modifier;
    QKeySequence m_ks;
};

#endif // SETSHORTCUTWIDGET_H
