/*************************************************************************
                           TimeStamp  -  description
                             -------------------
    début                : 05/12/2018
    copyright            : (C) 2018 par Antoine Martinot
    e-mail               : antoine.martinot@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <TimeStamp> (fichier TimeStamp.h) ----------------
#if ! defined ( TimeStamp_H )
#define TimeStamp_H

//--------------------------------------------------- Interfaces utilisées
#include <cstring>

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TimeStamp>
//
//
//------------------------------------------------------------------------

class TimeStamp
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    TimeStamp ();

    TimeStamp (unsigned int pDay, unsigned int pMounth, unsigned int pYear, unsigned int pHour,
    unsigned int pMinute, unsigned int pSeconde, unsigned int pTimezone = 0);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~TimeStamp ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
unsigned int day;
unsigned int mounth;
unsigned int year;
unsigned int hour;
unsigned int minute;
unsigned int seconde;
unsigned int timezone;


};

//-------------------------------- Autres définitions dépendantes de <TimeStamp>

#endif // TimeStamp_H

