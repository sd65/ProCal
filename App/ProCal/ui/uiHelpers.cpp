#include <QString>
#include <QMessageBox>

#include "ui/headers/uiHelpers.h"


bool showErrorsAndAskWhatToDo(const QString& message)
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(nullptr, "Attention !", message + "\n\nRééssayer ?", QMessageBox::Yes|QMessageBox::No, QMessageBox::Yes);
    return (reply == QMessageBox::No);
}
