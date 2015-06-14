#include "core/headers/exportManager.h"

/*!
  Save in XML or TXT (depeding of class contructor parameter) a projet and all his tasks
   \param projet
   \return done or errors
 */
bool ExportManager::exportProjet(Projet *projet)
{
    bool ok = true;
    if (!file->open(QIODevice::WriteOnly)) //Error opening file"
        ok = false;
    if (ok && type == ExportManager::EXPORT_XML())
    {
        QXmlStreamWriter xmlWriter;
        xmlWriter.setAutoFormatting(true);
        xmlWriter.setDevice(file);
        xmlWriter.writeStartDocument();
        xmlWriter.writeStartElement("projet");

        foreach (Tache* tache, *projet->getTaches()) {
            xmlWriter.writeStartElement("tache");
            xmlWriter.writeAttribute("unitaire", tache->isUnitaireToString());
            xmlWriter.writeAttribute("disponibilité", tache->getDisponibilite().toString());
            xmlWriter.writeAttribute("échéance", tache->getEcheance().toString());
            if(tache->getPred() != nullptr)
                xmlWriter.writeAttribute("tachePrécedente", tache->getPred()->getNom());
            if(!tache->isUnitaire())
            {
                QString contient;
                foreach (Tache* tacheInside, *tache->getComposition()) {
                    contient += tacheInside->getNom() + ",";
                }
                contient = contient.left(contient.length() - 1); // Remove last ','
                xmlWriter.writeAttribute("contient", contient);
            }
            xmlWriter.writeCharacters(tache->getNom());
            xmlWriter.writeEndElement();
        }
        xmlWriter.writeEndElement();
        xmlWriter.writeEndElement();
    }
    else if (ok && type == ExportManager::EXPORT_TXT())
    {
        QTextStream out(file);
        foreach (Tache* tache, *projet->getTaches())
        {
            out << "Tache : " + tache->getNom() << endl;
            out << "unitaire :" + tache->isUnitaireToString() << endl;
            out << "disponibilité :" + tache->getDisponibilite().toString() << endl;
            out << "échéance :" + tache->getEcheance().toString() << endl;
            if(tache->getPred() != nullptr)
                out << "tachePrécedente :" + tache->getPred()->getNom() << endl;
            if(!tache->isUnitaire())
            {
                QString contient;
                foreach (Tache* tacheInside, *tache->getComposition()) {
                    contient += tacheInside->getNom() + ",";
                }
                contient = contient.left(contient.length() - 1); // Remove last ','
                out << "contient : "+ contient << endl;
            }
            out << endl << endl;
        }
    }
    return ok;
}

/*!
  Save in XML or TXT (depeding of class contructor parameter) all week events
   \param QList<Evenement*>* events
   \return done or errors
 */
bool ExportManager::exportEvents(QList<Evenement*>* events)
{
    bool ok = true;
    if (!file->open(QIODevice::WriteOnly)) //Error opening file"
        ok = false;
    if (ok && type == ExportManager::EXPORT_XML())
    {
        QXmlStreamWriter xmlWriter;
        xmlWriter.setAutoFormatting(true);
        xmlWriter.setDevice(file);
        xmlWriter.writeStartDocument();
        xmlWriter.writeStartElement("week");

        foreach (Evenement* event, *events) {
            xmlWriter.writeStartElement("event");
            xmlWriter.writeAttribute("description", event->getDesc());
            xmlWriter.writeAttribute("début", event->getDebut()->toString());
            xmlWriter.writeAttribute("fin", event->getFin()->toString());
            xmlWriter.writeCharacters(event->getNom());
            xmlWriter.writeEndElement();
        }
        xmlWriter.writeEndElement();
        xmlWriter.writeEndElement();
    }
    else if (ok && type == ExportManager::EXPORT_TXT())
    {
        QTextStream out(file);
        foreach (Evenement* event, *events)
        {
            out << "Event : " + event->getNom() << endl;
            out << "description :" + event->getDesc() << endl;
            out << "début :" + event->getDebut()->toString() << endl;
            out << "fin :" + event->getFin()->toString() << endl;
            out << endl << endl;
        }
    }
    return ok;
}
