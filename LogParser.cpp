/*************************************************************************
                           LogParser  -  description
                             -------------------
    début                : 12/12/2018
    copyright            : (C) 2018 par Antoine Martinot
    e-mail               : antoine.martinot@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <LogParser> (fichier LogParser.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "LogParser.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type LogParser::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
LogParser & LogParser::operator = ( const LogParser & unLogParser )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
LogParser::LogParser ( const LogParser & unLogParser )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <LogParser>" << endl;
#endif
} //----- Fin de LogParser (constructeur de copie)


LogParser::LogParser ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <LogParser>" << endl;
#endif
} //----- Fin de LogParser


LogParser::~LogParser ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <LogParser>" << endl;
#endif
} //----- Fin de ~LogParser


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

