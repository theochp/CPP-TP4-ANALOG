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
int TimeStamp::GetHour() const
{
    return hour;
}

int TimeStamp::MonthStringToInt(const string monthString) 
// Algorithme :
//
{
	int monthConverted = 1;

	if (monthString == "Jan")
		monthConverted = 1;
	else if (monthString == "Feb")
		monthConverted = 2;
	else if (monthString == "Mar")
		monthConverted = 3;
	else if (monthString == "Apr")
		monthConverted = 4;
	else if (monthString == "May")
		monthConverted = 5;
	else if (monthString == "Jun")
		monthConverted = 6;
	else if (monthString == "Jul")
		monthConverted = 7;
	else if (monthString == "Aug")
		monthConverted = 8;
	else if (monthString == "Sep")
		monthConverted = 9;
	else if (monthString == "Oct")
		monthConverted = 10;
	else if (monthString == "Nov")
		monthConverted = 11;
	else if (monthString == "Dec")
		monthConverted = 12;

	return monthConverted;
}

TimeStamp::TimeStamp (uint pDay, uint pMounth, uint pYear, uint pHour,
uint pMinute, uint pSeconde, uint pTimezone)
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

