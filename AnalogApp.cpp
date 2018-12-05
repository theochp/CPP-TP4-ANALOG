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
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
AnalogApp::AnalogApp ( const AnalogApp & unAnalogApp )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <AnalogApp>" << endl;
#endif
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
        if(arg[0] == '-') {
            shouldExpectOptionArg = true;
            string argName = arg.substr(1);
            AppOption option(argName);
            options.push_back(option);
        } else if(shouldExpectOptionArg) {
            //bool added = option.AddArgument("blabla");
            if(!added) {
                //l'option n'accepte pas plus d'arguments
                //il faut donc considerer cette chaine comme le nom du fichier
                // a ouvrir
            }
            // soit l'option accepte 1 ou plusieurs arguments, et on continue, 
            // soit il faut aller dans le else
        } else {
            // c'est le nom du fichier à charger
        }
    }
} //----- Fin de parseArgs
