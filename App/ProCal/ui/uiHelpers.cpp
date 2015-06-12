#include <QString>
#include <QMessageBox>
#include <QDebug>
#include <QMouseEvent>

#include "ui/headers/uiHelpers.h"


bool showErrorsAndAskWhatToDo(const QString& message)
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(nullptr, "Attention !", message + "\n\nRééssayer ?", QMessageBox::Yes|QMessageBox::No, QMessageBox::Yes);
    return (reply == QMessageBox::No);
}

void ourCalendarWidget::mousePressEvent(QMouseEvent *e)
{
    Q_UNUSED(e);
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(nullptr, "Confirmation", "Revenir à aujourd'hui ?", QMessageBox::Yes|QMessageBox::No, QMessageBox::Yes);
    if (reply == QMessageBox::Yes)
    {
        this->showToday();
    }
}
