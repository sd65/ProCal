#ifndef UIHELPERS_H
#define UIHELPERS_H

#include <QString>
#include <QCalendarWidget>
#include <QPainter>

#include "core/headers/programmation.h"

bool showErrorsAndAskWhatToDo(const QString& message);

class ourCalendarWidget : public QCalendarWidget
{

    Q_OBJECT

public:
    ourCalendarWidget(QWidget *parent = 0) : QCalendarWidget(parent){}
    ~ourCalendarWidget() {}


protected:
    void paintCell(QPainter *painter, const QRect &rect, const QDate &date) const
    {

        Programmation& myProgrammationManager = Programmation::getInstance();
        bool haveWritten = false;
        painter->save();

        if(date == QDate::currentDate())
        {
            painter->drawText(rect, Qt::AlignLeft, "♢");
            haveWritten = true;
        }
        if(myProgrammationManager.progExistanteEntre(QDateTime(date, QTime(0,0,0,1)), QDateTime(date, QTime(23,59,59,59))) != nullptr && this->selectedDate() != date)
        {
            painter->fillRect(rect, QColor(229, 127, 73, 170));
            haveWritten = true;
        }

        if (haveWritten)
            painter->drawText(rect, Qt::AlignCenter, QString::number(date.day()));

        painter->restore();

        if (haveWritten == false)
        { // if our conditions are not matching, show the default way.
            QCalendarWidget::paintCell(painter, rect, date);
        }
    }
};

#endif // UIHELPERS_H