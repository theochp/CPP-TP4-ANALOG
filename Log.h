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
#include "Url.h"
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
    Log & operator = ( const Log & unLog );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Log (string pIpAddress, TimeStamp pTimeStamp,method pActionType,Url pDestination,
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
Url destination;
int status;
unsigned int sizeData;
string source;
string userAgent;


};

//-------------------------------- Autres définitions dépendantes de <Log>

#endif // Log_H

