#ifndef AJOUTERTACHECOMPOSITE_H
#define AJOUTERTACHECOMPOSITE_H

#include <QDialog>

namespace Ui {
class ajouterTacheComposite;
}

class ajouterTacheComposite : public QDialog
{
    Q_OBJECT

public:
    explicit ajouterTacheComposite(QWidget *parent = 0);
    ~ajouterTacheComposite();

private:
    Ui::ajouterTacheComposite *ui;
};

#endif // AJOUTERTACHECOMPOSITE_H
