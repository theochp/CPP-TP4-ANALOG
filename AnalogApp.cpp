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
	generateGraph(list);
    showTopHits(list);
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

    int iDoc =1;
    for(auto i=listSorted.begin(); i!=listSorted.end() && iDoc++<=nbDoc; ++i) {
        cout << i->second << " (" << i->first << " hits)" << endl;
    }
}

void AnalogApp::generateGraph(LogList &list)
// Algorithme :
//
{
	static const string nodePrefix = "\"node_";
	//TODO: check if file exists
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
	ofstream file("out.dot", ios::out);
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
