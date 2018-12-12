/*************************************************************************
                           LogParser  -  description
                             -------------------
    début                : 12/12/2018
    copyright            : (C) 2018 par Antoine Martinot
    e-mail               : antoine.martinot@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <LogParser> (fichier LogParser.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <sstream>
#include <fstream>

//------------------------------------------------------ Include personnel
#include "LogParser.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
vector<Log> LogParser::Parse ( )
// Algorithme :
//
{
	ifstream file;
	file.open(filename);
	if ((file.rdstate() & ifstream::failbit) != 0)
	{
		cerr << "Erreur d'ouverture de <" << filename << ">" << endl;
		exit(1);
	}
	else
	{
		string log;
		vector<string> itemsLog;
		itemsLog.clear();
		while (!file.eof()) {
			getline(file, log);
			split(log, ' ', itemsLog);
			cout << "**********************************" << endl;
			cout << itemsLog.size() << endl;
			if (itemsLog.size() > 1) {
				cleanLog(itemsLog);
				for (int i = 0; i < itemsLog.size(); i++) {
					TimeStamp t1(stoi(itemsLog[8]), TimeStamp::MonthStringToInt(itemsLog[9]), stoi(itemsLog[10]), stoi(itemsLog[11]),
						stoi(itemsLog[12]), stoi(itemsLog[13]));
					Url u1(itemsLog[3], itemsLog[2]);
					Log l1(itemsLog[0], t1, GetMethodFromString(itemsLog[1]), u1, stoi(itemsLog[4]), stoi(itemsLog[5]), itemsLog[6], itemsLog[7]);

					cout << itemsLog[i] << endl;
				}
			}
			itemsLog.clear();
		}
	}
} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
LogParser::LogParser ( const LogParser & unLogParser )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <LogParser>" << endl;
#endif
} //----- Fin de LogParser (constructeur de copie)


LogParser::LogParser ( const string filename ) : filename(filename)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <LogParser>" << endl;
#endif
} //----- Fin de LogParser


LogParser::~LogParser ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <LogParser>" << endl;
#endif
} //----- Fin de ~LogParser


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
void LogParser::split(const string &str, char delimiter, vector<string> &elements)
// Algorithme :
//
{
	string item;
	int nbItem = 1, pos1 = 1, pos2;


	stringstream ss(str);
	while (getline(ss, item, delimiter))
	{
		if (nbItem != 2 && nbItem != 3 && nbItem < 12)
			elements.push_back(item);

		nbItem++;
	}
	for (int i = 0; i < 11; i++) {
		pos1 = str.find(delimiter, pos1 + 1);
	}
	item = str.substr(pos1 + 1, str.size());
	elements.push_back(item);
} //----- Fin de split

void LogParser::cleanLog(vector<string> &elements)
// Algorithme :
//
{
	string itemsTime[7];
	const string localDomain = "intranet-if.insa-lyon.fr";
	int pos1, pos2;

	itemsTime[0] = elements[1].substr(1, 2);
	itemsTime[1] = elements[1].substr(4, 3);
	itemsTime[2] = elements[1].substr(8, 4);
	itemsTime[3] = elements[1].substr(13, 2);
	itemsTime[4] = elements[1].substr(16, 2);
	itemsTime[5] = elements[1].substr(19, 2);
	itemsTime[6] = elements[2].substr(1, 2);

	elements[1] = elements[3].substr(1, elements[3].size() - 1);
	elements[2] = elements[4];
	elements[3] = elements[5].substr(0, elements[5].size() - 1);
	elements[4] = elements[6];
	elements[5] = elements[7];

	pos1 = elements[8].find(1, '/');
	pos1 += 2;
	pos2 = elements[8].find(pos1 + 1, '/');
	pos2--;
	if (elements[8].substr(pos1, pos2) == localDomain)
		elements[6] = elements[8].substr(pos2 += 1, elements[8].size() - 2);
	else
		elements[6] = elements[8].substr(pos1, elements[8].size() - 2);

	elements[7] = elements[9].substr(1, elements[9].size() - 2);

	elements[8] = itemsTime[0];
	elements[9] = itemsTime[1];

	for (int i = 2; i<7; i++) {
		elements.push_back(itemsTime[i]);
	}
} //----- Fin de cleanLog