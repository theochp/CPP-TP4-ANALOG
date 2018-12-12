/*************************************************************************
                           LogParser  -  description
                             -------------------
    début                : 12/12/2018
    copyright            : (C) 2018 par Antoine Martinot
    e-mail               : antoine.martinot@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <LogParser> (fichier LogParser.h) ----------------
#if ! defined ( LogParser_H )
#define LogParser_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <vector>
#include <map>
#include "Log.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
typedef map<string, pair<map<string, int>, int>> LogList;
//------------------------------------------------------------------------
// Rôle de la classe <LogParser>
//
//
//------------------------------------------------------------------------

class LogParser
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    LogList Parse ( );
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    LogParser ( const LogParser & unLogParser );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    LogParser ( const string filename );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~LogParser ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
	void split(const string &str, char delimiter, vector<string> &elements);
	void cleanLog(vector<string> &elements);
//----------------------------------------------------- Attributs protégés
	const string filename;
};

//-------------------------------- Autres définitions dépendantes de <LogParser>

#endif // LogParser_H

