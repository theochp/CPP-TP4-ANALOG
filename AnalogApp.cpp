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

//------------------------------------------------------ Include personnel
#include "AnalogApp.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
int AnalogApp::Run ( )
// Algorithme :
//
{
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
    for(int i = 0; i < argc; ++i) {
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

    for(auto it = args.begin(); it != args.end(); ++it)
    {
        const string& arg = *it;
        AppOption *lastAddedOption = nullptr;
        if(arg[0] == '-') {
            shouldExpectOptionArg = true;
            string argName = arg.substr(1);
            AppOption *option = new AppOption(argName);
            options.push_back(option);
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
