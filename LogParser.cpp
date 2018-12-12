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
LogList LogParser::Parse ( )
// Algorithme :
//
{
	LogList list;
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
		while (!file.eof()) {
			getline(file, log);
			split(log, ' ', itemsLog);
			if (itemsLog.size() > 1) {
				cleanLog(itemsLog);
				for (int i = 0; i < itemsLog.size(); i++) {
					TimeStamp t1(stoi(itemsLog[8]), TimeStamp::MonthStringToInt(itemsLog[9]), stoi(itemsLog[10]), stoi(itemsLog[11]),
						stoi(itemsLog[12]), stoi(itemsLog[13]));
					string ip = itemsLog[0];
					string method = itemsLog[1];
					string destination = itemsLog[2];
					int status = 0;// stoi(itemsLog[4]);
					int dataSize = 0;// stoi(itemsLog[5]);
					string userAgent = itemsLog[7];
					string source = itemsLog[6]; // TODO: enlever le domaine si la source est locale
					Log log(ip, t1, GetMethodFromString(method), destination, status, dataSize, source, userAgent);

					// recherche de la destination
					auto destinationMapElement = list.find(log.destination);
					if (destinationMapElement == list.end()) {
						// si la destination est inconnue, on l'insere
						auto returned = list.insert({ log.destination, {map<string,int>(), 0}});
						if (returned.second) {
							destinationMapElement = returned.first;
						}
						else {
							exit(1);
						}
					}

					// on recupere les hits pour les sources
					auto &sources = (*destinationMapElement).second.first;
					int  &sourceCounts = (*destinationMapElement).second.second;
					// on incremente le nombre total de hits
					sourceCounts++;

					// on recherche si la source est déjà connue pour cette destination
					auto sourceMapElement = sources.find(source);
					if (sourceMapElement == sources.end()) {
						// si elle l'est pas on insere
						auto returned = sources.insert({ log.source, 0 });
						if (returned.second) {
							sourceMapElement = returned.first;
						}
						else {
							exit(1);
						}
					}
					
					// on incremente le nombre de hits depuis cette source
					(*sourceMapElement).second++;

				}
				itemsLog.clear();
			}
		}
	}

	return list;
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

	// Fix empty data
	for (auto it = elements.begin(); it != elements.end(); ++it)
	{
		// dans le cas ou une donnée numérique est manquante, il faut remplacer le tiret par un zéro pour que le stoi fonctionne
		if (*it == "-") {
			*it = "0";
		}
	}

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