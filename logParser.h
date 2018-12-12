/*************************************************************************
                           logParser  -  description
                             -------------------
    début                : 12/12/2018
    copyright            : (C) 2018 par Antoine Martinot
    e-mail               : antoine.martinot@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <logParser> (fichier logParser.h) ----------------
#if ! defined ( logParser_H )
#define logParser_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <logParser>
//
//
//------------------------------------------------------------------------

class logParser
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
    logParser & operator = ( const logParser & unlogParser );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    logParser ( const logParser & unlogParser );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    logParser ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~logParser ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <logParser>

#endif // logParser_H

