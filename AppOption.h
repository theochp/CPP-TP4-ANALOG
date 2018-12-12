/*************************************************************************
                           AppOption  -  description
                             -------------------
    début                : 05/12/2018
    copyright            : (C) 2018 par Théo Champion
    e-mail               : theo.champion@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <AppOption> (fichier AppOption.h) ----------------
#if ! defined ( AppOption_H )
#define AppOption_H

//--------------------------------------------------- Interfaces utilisées
#include <vector>
#include <string>

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <AppOption>
//
// Gère les options passées en paramètres du main. Lors de la création
// d'une option, la classe sait combien de paramètres cette option accepte
// et adapte le comportement de AddArgument en conséquence
//------------------------------------------------------------------------

class AppOption
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    bool AddArgument ( string argument );
    // Mode d'emploi :
    // 
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    AppOption ( const AppOption & unAppOption );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    AppOption ( const string name );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~AppOption ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
vector<string> arguments;
const string name;
int acceptedArguments;
};

//-------------------------------- Autres définitions dépendantes de <AppOption>

#endif // AppOption_H

