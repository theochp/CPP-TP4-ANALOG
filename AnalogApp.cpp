/*************************************************************************
                           AnalogApp  -  description
                             -------------------
    début                : 05/12/2018
    copyright            : (C) 2018 par Théo Champion
    e-mail               : theo.champion@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <AnalogApp> (fichier AnalogApp.cpp) 

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "AnalogApp.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
int AnalogApp::Run ( const int argc, char *argv[] )
// Algorithme :
//
{
    return 0;
} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
AnalogApp & AnalogApp::operator = ( const AnalogApp & unAnalogApp )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
AnalogApp::AnalogApp ( const AnalogApp & unAnalogApp )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <AnalogApp>" << endl;
#endif
} //----- Fin de AnalogApp (constructeur de copie)


AnalogApp::AnalogApp ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <AnalogApp>" << endl;
#endif
} //----- Fin de AnalogApp


AnalogApp::~AnalogApp ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <AnalogApp>" << endl;
#endif
} //----- Fin de ~AnalogApp


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

