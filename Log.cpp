/*************************************************************************
                           Log  -  description
                             -------------------
    début                : 05/12/2018
    copyright            : (C) 2018 par Antoine Martinot
    e-mail               : antoine.martinot@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Log> (fichier Log.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Log.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Log::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

Log::Log (string pIpAddress, TimeStamp pTimeStamp,method pActionType,string pDestination,
int pStatus, unsigned int pSizeData, string pSource,string pUserAgent) : timeStamp(pTimeStamp)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Log>" << endl;
#endif
    ipAddress = pIpAddress;
    actionType = pActionType;
    destination = pDestination;
    status = pStatus;
    sizeData = pSizeData;
    source = pSource;
    userAgent = pUserAgent;
} //----- Fin de Log


Log::~Log ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Log>" << endl;
#endif
} //----- Fin de ~Log


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//-------------------------------------- Autre méthodes dépendantes de Log
eMethod GetMethodFromString(const string methodString)
{
	eMethod converted = GET;

	if (methodString == "GET")
		converted = GET;
	else if (methodString == "POST")
		converted = POST;
	else if (methodString == "OPTIONS")
		converted = OPTIONS;

	return converted;
}