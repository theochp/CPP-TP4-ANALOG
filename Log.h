/*************************************************************************
                           Log  -  description
                             -------------------
    début                : 05/12/2018
    copyright            : (C) 2018 par Antoine Martinot
    e-mail               : antoine.martinot@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Log> (fichier Log.h) ----------------
#if ! defined ( Log_H )
#define Log_H

//--------------------------------------------------- Interfaces utilisées
#include <cstring>
#include "LogParser.h"
#include "TimeStamp.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
typedef enum method {GET, POST, OPTIONS} eMethod;

//------------------------------------------------------------------------
// Rôle de la classe <Log>
//
//
//------------------------------------------------------------------------

class Log
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
 
//-------------------------------------------- Constructeurs - destructeur
    Log (string pIpAddress, TimeStamp pTimeStamp,method pActionType,string pDestination,
    int pStatus, unsigned int pSizeData, string pSource,string pUserAgent);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Log ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
string ipAddress;
TimeStamp timeStamp;
method actionType;
string destination;
int status;
unsigned int sizeData;
string source;
string userAgent;

friend class LogParser;

};

//-------------------------------- Autres définitions dépendantes de <Log>
eMethod GetMethodFromString(const string methodString);
#endif // Log_H

