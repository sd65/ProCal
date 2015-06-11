#ifndef AJOUTERACTIVITE_H
#define AJOUTERACTIVITE_H

#include <QDialog>

namespace Ui {
class ajouterActivite;
}

class ajouterActivite : public QDialog
{
    Q_OBJECT

public:
    explicit ajouterActivite(QWidget *parent = 0);
    ~ajouterActivite();

private:
    Ui::ajouterActivite *ui;

    void accept();

};

#endif // AJOUTERACTIVITE_H
