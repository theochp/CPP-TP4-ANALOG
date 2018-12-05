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
    int Run ( const int argc, char *argv[] );
    // Mode d'emploi :
    //
    // Contrat :
    //  argv doit être un tableau de chaînes de caractères de taille argc


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

    AnalogApp ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~AnalogApp ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <AnalogApp>

#endif // AnalogApp_H

