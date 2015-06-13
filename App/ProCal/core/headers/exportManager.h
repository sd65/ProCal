#ifndef ExportManager_H
#define ExportManager_H

#include <QXmlStreamWriter>
#include <QFile>

#include "core/headers/projet.h"

class ExportManager
{
    int type;
    QFile* file;

public:

    ExportManager(QFile* pfile, int ptype = ExportManager::EXPORT_XML()) : type(ptype), file(pfile) {}

    static int EXPORT_XML() { return 1; }
    static int EXPORT_TXT() { return 2; }

    bool exportProjet(Projet* projet);
};

#endif // ExportManager_H
