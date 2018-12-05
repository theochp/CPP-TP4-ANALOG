/*************************************************************************
                           Url  -  description
                             -------------------
    début                : 05/12/2018
    copyright            : (C) 2018 par Antoine Martinot
    e-mail               : antoine.martinot@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Url> (fichier Url.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Url.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Url::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
Url & Url::operator = ( const Url & unUrl )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Url::Url ( const Url & unUrl )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Url>" << endl;
#endif
} //----- Fin de Url (constructeur de copie)


Url::Url(string pDomain, string pPath)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Url>" << endl;
#endif

    domain = pDomain;
    path = pPath;

} //----- Fin de Url


Url::~Url ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Url>" << endl;
#endif
} //----- Fin de ~Url


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

