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
#include "TimeStamp.h"
#include "AppOption.h"
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

    LogParser (vector<AppOption*> options, const string filename );
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

	bool isAssetUrl(const string url);
	// Contrat :
	// Retourne VRAI si <url> pointe vers un fichier de ressources
	// (.css, .js, .png, .jpg,...)

	bool isHourValid(const TimeStamp time, const string hour);
	// Contrat :
	// Retourne vrai si le timestamp <time> est dans l'interval [<hour>, <hour>+1]
//----------------------------------------------------- Attributs protégés
	const string filename;
	const vector<AppOption*> options;
};

//-------------------------------- Autres définitions dépendantes de <LogParser>

#endif // LogParser_H

