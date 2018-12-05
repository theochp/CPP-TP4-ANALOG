/*************************************************************************
                           Url  -  description
                             -------------------
    début                : 05/12/2018
    copyright            : (C) 2018 par Antoine Martinot
    e-mail               : antoine.martinot@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Url> (fichier Url.h) ----------------
#if ! defined ( Url_H )
#define Url_H

//--------------------------------------------------- Interfaces utilisées
#include <cstring>

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Url>
//
//
//------------------------------------------------------------------------

class Url
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
    Url & operator = ( const Url & unUrl );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Url ( const Url & unUrl );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Url(string pDomain, string pPath);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Url ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
string domain;
string path;

};

//-------------------------------- Autres définitions dépendantes de <Url>

#endif // Url_H

