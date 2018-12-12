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
typedef unsigned int uint;
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
    static int MonthStringToInt( const string monthString );
    // Mode d'emploi :
    //
    // Contrat :
    //

    TimeStamp (uint pDay, uint pMounth, uint pYear, uint pHour,
    uint pMinute, uint pSeconde, uint pTimezone = 0);
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
uint day;
uint mounth;
uint year;
uint hour;
uint minute;
uint seconde;
uint timezone;


};

//-------------------------------- Autres définitions dépendantes de <TimeStamp>

#endif // TimeStamp_
