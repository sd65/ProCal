#include <QMessageBox>

#include "core/headers/projet.h"

#include "ui/headers/ajouterProjet.h"
#include "ui_ajouterProjet.h"
#include "ui/headers/uiHelpers.h"

ajouterProjet::ajouterProjet(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ajouterProjet)
{
    ui->setupUi(this);
    ui->disponibilite->setDate(QDate::currentDate());
    ui->echeance->setDate(QDate::currentDate().addMonths(1));
}

ajouterProjet::~ajouterProjet()
{
    delete ui;
}

/*!
  Override default behaviour of accept buttons or enter key. Performs checks before insert datas.
 */
void ajouterProjet::accept() {
    bool statusOk = true;
    QString message;

    if(ui->nom->text().isEmpty())
    {
        message += "Remplissez le titre du projet !";
        statusOk = false;
    }

    if(ui->disponibilite->date() > ui->echeance->date())
    {
        message += "\nL'échéance est antérieure à la date de disponibilité !";
        statusOk = false;
    }

    if(statusOk)
    {
        ProjetManager& myProjetManager = ProjetManager::getInstance();
        myProjetManager.creerProjet(ui->nom->text(), ui->disponibilite->date(), ui->echeance->date());
        this->close();
    }
    else
        if (showErrorsAndAskWhatToDo(message))
            this->close();
}
