/*************************************************************************
                           AnalogApp  -  description
                             -------------------
    début                : 05/12/2018
    copyright            : (C) 2018 par Théo Champion
    e-mail               : theo.champion@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <AnalogApp> (fichier AnalogApp.h) ----------------
#if ! defined ( AnalogApp_H )
#define AnalogApp_H

//--------------------------------------------------- Interfaces utilisées
#include <vector>
#include <string>
#include "AppOption.h"
#include "LogParser.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <AnalogApp>
//
//
//------------------------------------------------------------------------

class AnalogApp
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    int Run ( );
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
    AnalogApp & operator = ( const AnalogApp & unAnalogApp );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    AnalogApp ( const AnalogApp & unAnalogApp );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    AnalogApp ( const int argc, char *argv[] );
    // Mode d'emploi :
    //
    // Contrat :
    //  argv doit être un tableau de chaînes de caractères de taille argc

    virtual ~AnalogApp ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
    void parseArgs ( const vector<string>& args );
    // Mode d'emploi :
        //
        // Contrat :
        //

    void showTopHits (LogList list, int nbPages);
    // Mode d'emploi :
    //
    // Contrat :
    //

//----------------------------------------------------- Attributs protégés
vector<AppOption*> options;
string targetFile;
};

//-------------------------------- Autres définitions dépendantes de <AnalogApp>

#endif // AnalogApp_H

