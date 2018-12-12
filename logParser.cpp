/*************************************************************************
                           logParser  -  description
                             -------------------
    début                : 12/12/2018
    copyright            : (C) 2018 par Antoine Martinot
    e-mail               : antoine.martinot@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <logParser> (fichier logParser.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "logParser.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type logParser::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
logParser & logParser::operator = ( const logParser & unlogParser )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
logParser::logParser ( const logParser & unlogParser )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <logParser>" << endl;
#endif
} //----- Fin de logParser (constructeur de copie)


logParser::logParser ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <logParser>" << endl;
#endif
} //----- Fin de logParser


logParser::~logParser ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <logParser>" << endl;
#endif
} //----- Fin de ~logParser


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

