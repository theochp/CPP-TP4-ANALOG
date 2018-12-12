/*************************************************************************
                           AppOption  -  description
                             -------------------
    début                : 05/12/2018
    copyright            : (C) 2018 par Théo Champion
    e-mail               : theo.champion@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <AppOption> (fichier AppOption.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "AppOption.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
bool AppOption::AddArgument ( string argument )
// Algorithme :
//
{
    if(arguments.size() < (unsigned int) acceptedArguments) {
        arguments.push_back(argument);
        return true;
    } 

    return false;
} //----- Fin de Méthode



//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
AppOption::AppOption ( const AppOption & unAppOption ) : name(unAppOption.name)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <AppOption>" << endl;
#endif
    arguments = unAppOption.arguments;
    acceptedArguments = unAppOption.acceptedArguments;
} //----- Fin de AppOption (constructeur de copie)


AppOption::AppOption ( const string name) : name(name)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <AppOption>" << endl;
#endif
    arguments = vector<string>();
    acceptedArguments = 0;
    if(name == "g") {
        acceptedArguments = 1;
    }
    else if(name == "e") {
        acceptedArguments = 0;
    } else if(name == "t") {
        acceptedArguments = 1;
    }
} //----- Fin de AppOption


AppOption::~AppOption ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <AppOption>" << endl;
#endif
} //----- Fin de ~AppOption


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

