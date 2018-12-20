/*************************************************************************
                           AnalogApp  -  description
                             -------------------
    début                : 05/12/2018
    copyright            : (C) 2018 par Théo Champion
    e-mail               : theo.champion@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <AnalogApp> (fichier AnalogApp.cpp) 

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <deque>
#include <fstream>
#include <algorithm>
//------------------------------------------------------ Include personnel
#include "AnalogApp.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
int AnalogApp::Run ( )
// Algorithme :
//
{
	LogParser parser(options, targetFile);
	auto list = parser.Parse();
    showTopHits(list);

	bool doGenerateGraph = false;
	string outputFilename;
	for (auto it = options.begin(); it != options.end() && !doGenerateGraph; ++it)
	{
		if ((*it)->getName() == "g")
		{
			if ((*it)->getArguments().size() > 0)
				outputFilename = (*it)->getArguments()[0];
			else
				outputFilename = "out.dot";
			doGenerateGraph = true;
		}
	}
	if (doGenerateGraph)
	{
		generateGraph(outputFilename, list);
	}
	
    return 0;
} //----- Fin de Run


//------------------------------------------------- Surcharge d'opérateurs
AnalogApp & AnalogApp::operator = ( const AnalogApp & unAnalogApp )
// Algorithme :
//
{
    targetFile = unAnalogApp.targetFile;

    // écrasement des options
    for(auto it = options.begin(); it != options.end(); ++it) {
        delete *it;
    }
    for(auto it = unAnalogApp.options.begin(); it != unAnalogApp.options.end(); ++it) {
        options.push_back(new AppOption(**it));
    }

    return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
AnalogApp::AnalogApp ( const AnalogApp & unAnalogApp )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <AnalogApp>" << endl;
#endif
    targetFile = unAnalogApp.targetFile;
    for(auto it = unAnalogApp.options.begin(); it != unAnalogApp.options.end(); ++it) {
        options.push_back(new AppOption(**it));
    }
} //----- Fin de AnalogApp (constructeur de copie)


AnalogApp::AnalogApp ( const int argc, char *argv[]  ) 
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <AnalogApp>" << endl;
#endif
    vector<string> args;
    // skip first argument since it contains the name of the executable
    for(int i = 1; i < argc; ++i) {
        args.push_back(string(argv[i]));
    }
    parseArgs(args);
} //----- Fin de AnalogApp


AnalogApp::~AnalogApp ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <AnalogApp>" << endl;
#endif
    for(auto it = options.begin(); it != options.end(); ++it) {
        delete *it;
    }
} //----- Fin de ~AnalogApp


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
void AnalogApp::parseArgs ( const vector<string>& args ) 
// Algorithme :
//
{
    bool shouldExpectOptionArg = false;
    AppOption *lastAddedOption = nullptr;

    for(auto it = args.begin(); it != args.end(); ++it)
    {
        const string& arg = *it;
        if(arg[0] == '-') {
            shouldExpectOptionArg = true;
            string argName = arg.substr(1);
            lastAddedOption = new AppOption(argName);
            options.push_back(lastAddedOption);
        } else if(shouldExpectOptionArg) {
            bool added = lastAddedOption->AddArgument(arg);
            if(!added) {
                targetFile = arg;
                shouldExpectOptionArg = false;
            }
        } else {
            targetFile = arg;
        }
    }
} //----- Fin de parseArgs

void AnalogApp::showTopHits (const LogList& list, int nbDoc){

    vector<pair<int ,string>> listSorted;
    for(auto i=list.begin(); i!=list.end(); ++i) {
        listSorted.push_back(make_pair(i->second.second,i->first));
    }
	sort(listSorted.begin(), listSorted.end(), [](pair<int,string> &left, pair<int, string> &right) {
		return left.first > right.first;
	});

	int cpt = 0;
	for (auto it = listSorted.begin(); it != listSorted.end() && cpt < nbDoc; ++it, ++cpt) {
        cout << it->second << " (" << it->first << " hits)" << endl;
    }
}

void AnalogApp::generateGraph(const string outputFilename, LogList &list)
// Algorithme :
//
{
	ifstream testFile(outputFilename);
	if (testFile.is_open())
	{
		
		string answer = "";
		do
		{
			cout << "Fichier <" << outputFilename << "> déjà existant, voulez vous l'écraser ? (O/N)" << endl;
			cin >> answer;
		} while (answer != "O" && answer != "N");

		if (answer == "N") {
			cout << "Veuillez entrer un nouveau nom de fichier" << endl;
			cin >> answer;
			return generateGraph(answer, list);
		}

	}
	testFile.close();

	static const string nodePrefix = "\"node_";
	vector<string> nodes;
	vector<string> arcs;
	for (auto it = list.begin(); it != list.end(); ++it)
	{
		string pageName = (*it).first;
		string node = nodePrefix + pageName + "\" [label=\"" + pageName + "\"];";
		nodes.push_back(node);
		const auto &hitsList = (*it).second.first;
		for (auto it2 = hitsList.begin(); it2 != hitsList.end(); ++it2)
		{	
			string referer = (*it2).first;
			int count  = (*it2).second;
			string arc = nodePrefix + referer + "\" -> " + nodePrefix + pageName + "\" [label=\"" + to_string(count) + "\"];";
			arcs.push_back(arc);
		}
	}
	ofstream file(outputFilename, ios::out);
	file << "digraph {" << endl;
	for (auto it = nodes.begin(); it != nodes.end(); ++it)
	{
		file << (*it) << endl;
	}
	for (auto it = arcs.begin(); it != arcs.end(); ++it)
	{
		file << (*it) << endl;
	}
	file << "}" << endl;
	file.close();
} //----- Fin de generateGraph
