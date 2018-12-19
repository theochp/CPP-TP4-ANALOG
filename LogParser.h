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
    // Méthode générale pour le parsing qui va appeler les autres
    // Elle va ensuite placer les éléments de la log qui nous intéresse
    // dans le conteneur qui est ici une double map.
    // Elle va retenir les logs seulement si elle réponde au critères
    // eventuellement saisis par l'utilisateur
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
    // Contrat :
    // s'occupe de découper brutallement les logs selon un caractère passé en paramètre
    // ici le caractère ' ' et place chaque éléments dans un vecteur

	void cleanLog(vector<string> &elements);
    // Contrat :
    // Méthode qui prend le vecteur d'éléments d'une log en paramètres et qui
    // a pour rôle de les nettoyer, par exemple, enlever les caractères inutile comme
    // les guillemets, découper l'horodateur en ses différents éléments.

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

