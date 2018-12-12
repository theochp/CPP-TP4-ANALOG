/*************************************************************************
                           TimeStamp  -  description
                             -------------------
    début                : 05/12/2018
    copyright            : (C) 2018 par Antoine Martinot
    e-mail               : antoine.martinot@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <TimeStamp> (fichier TimeStamp.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "TimeStamp.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type TimeStamp::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

TimeStamp::TimeStamp ()
{
#ifdef MAP
    cout << "Appel au constructeur de <TimeStamp>" << endl;
#endif
    day = 0;
    mounth = 0;
    year = 0;
    hour = 0;
    minute = 0;
    seconde = 0;
    timezone = 0;
} //----- Fin de TimeStamp


TimeStamp::TimeStamp (unsigned int pDay, unsigned int pMounth, unsigned int pYear, unsigned int pHour,
unsigned int pMinute, unsigned int pSeconde, unsigned int pTimezone)
{
#ifdef MAP
    cout << "Appel au constructeur de <TimeStamp>" << endl;
#endif
    day = pDay;
    mounth = pMounth;
    year = pYear;
    hour = pHour;
    minute = pMinute;
    seconde = pSeconde;
    timezone = pTimezone;
} //----- Fin de TimeStamp


TimeStamp::~TimeStamp ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TimeStamp>" << endl;
#endif
} //----- Fin de ~TimeStamp


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

