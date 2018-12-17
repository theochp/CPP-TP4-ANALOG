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
			itemsLog.clear();
			getline(file, log);
			split(log, ' ', itemsLog);
			if (itemsLog.size() > 1) {
				cleanLog(itemsLog);

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

				// filter images
				bool shouldIgnoreLog = false;
				for (auto it = options.begin(); it != options.end(); ++it)
				{
					if ((*it)->getName() == "e" && isAssetUrl(log.destination))
					{
						shouldIgnoreLog = true;
					}

					if ((*it)->getName() == "t" && !isHourValid(log.timeStamp, (*it)->getArguments()[0]))
					{
						shouldIgnoreLog = true;
					}
				}

				if (shouldIgnoreLog)
				{
					continue;
				}


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
		}
	}

	return list;
} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
LogParser::LogParser ( const LogParser & unLogParser ) : filename(unLogParser.filename), options(options)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <LogParser>" << endl;
#endif
} //----- Fin de LogParser (constructeur de copie)


LogParser::LogParser (vector<AppOption*> options, const string filename) : filename(filename), options(options)
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
		if (item != "") {
            if (nbItem != 2 && nbItem != 3 && nbItem < 12)
                elements.push_back(item);

            nbItem++;
        }
	}
	for (int i = 0; i < 11; i++) {
		pos1 = str.find(delimiter, pos1 + 1);
	}
	item = str.substr(pos1 + 1, str.size());
	elements.push_back(item);

    //si le log n'as pas de source ou de destination on le prend pas en compte
    if (elements[4] == "-" || elements[4] == "/")
        elements.clear();

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
	int pos1, pos2;

	if(elements[1].size() == 21){
        itemsTime[0] = elements[1].substr(1, 2); //jour
        itemsTime[1] = elements[1].substr(4, 3); //mois
        itemsTime[2] = elements[1].substr(8, 4); //année
        itemsTime[3] = elements[1].substr(13, 2); //heure
        itemsTime[4] = elements[1].substr(16, 2); //minutes
        itemsTime[5] = elements[1].substr(19, 2); //secondes
        itemsTime[6] = elements[2].substr(1, 2); //fuseaux
	}else{
        itemsTime[0] = "-";
        itemsTime[1] = "-";
        itemsTime[2] = "-";
        itemsTime[3] = "-";
        itemsTime[4] = "-";
        itemsTime[5] = "-";
        itemsTime[6] = "-";
	}

    if(elements[3] != "\"-\""){
        elements[1] = elements[3].substr(1, elements[3].size() - 1); //methode
    }else{
        elements[1] = elements[3];
    }
	elements[2] = elements[4]; //destination
	elements[3] = elements[6]; //status
	elements[4] = elements[7]; //data size

	if (elements[8] != "\"-\""){
        pos1 = elements[8].find('/', 1);
        pos1 += 2;
        pos2 = elements[8].find('/', pos1);
        if (pos2 != -1) {
            pos2--;
            elements[5] = elements[8].substr(pos1, pos2 - pos1 + 1); //domaine
            elements[6] = elements[8].substr(pos2 += 1, elements[8].size() - pos2 - 2); //source
        }else{
            elements[5] = elements[8].substr(pos1, elements[8].size()- pos1 - 1); //domaine
            elements[6] = elements[5]; //source
        }

	}else{
        elements[5] = "-";
        elements[6] = "-";
	}

	elements[7] = elements[9].substr(1, elements[9].size() - 2); //user agent

	elements[8] = itemsTime[0];
	elements[9] = itemsTime[1];

	for (int i = 2; i<7; i++) {
		elements.push_back(itemsTime[i]);
	}

} //----- Fin de cleanLog

bool LogParser::isAssetUrl(const string url)
// Algorithme :
//
{
	const char *extensions[] = {
		".jpg",
		".jpeg",
		".png",
		".gif",
		".bmp",
		".svg",
		".ico",
		".css",
		".js"
	};
	int extensions_t = sizeof(extensions) / sizeof(char*);
	bool isAsset = false;
	size_t position;
	for (int i = 0; i < extensions_t && !isAsset; ++i) {
		position = url.find(extensions[i]);
		if (position == url.size() - strlen(extensions[i])) {
			isAsset = true;
		}
	}

	return isAsset;
} //----- Fin de isAssetUrl

bool LogParser::isHourValid(const TimeStamp time, const string hour)
{
	try {
		int h = stoi(hour);

		if (time.GetHour() == h)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	catch (exception e) {
		return false;
	}
}