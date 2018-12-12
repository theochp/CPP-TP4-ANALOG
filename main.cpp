using namespace std;
#include "Log.h"
#include "TimeStamp.h"
#include "Url.h"
#include <cstring>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

#include "AnalogApp.h"

void testClasses(){
    TimeStamp ts(8, 9, 2012, 11, 15, 0, 2);
    string s1 = "page2.html";
    string s2 = "HTTP/1.1";
    Url u(s1, s2);

}



void split(const string &str, char delimiter, vector<string> &elements)
{
    string item;
    int nbItem = 1, pos1 = 1, pos2;


    stringstream ss(str);
    while (getline(ss, item, delimiter))
    {
        if(nbItem != 2 && nbItem != 3 && nbItem < 12)
            elements.push_back(item);

        nbItem ++;
    }
    for(int i = 0; i<11; i++){
        pos1 = str.find(delimiter, pos1+1);
    }
    item = str.substr(pos1+1, str.size());
    elements.push_back(item);
}

void cleanLog(vector<string> &elements){
    string itemsTime[7];
    const string localDomain = "intranet-if.insa-lyon.fr";
    int pos1, pos2;

    itemsTime[0] = elements[1].substr(1,2);
    itemsTime[1] = elements[1].substr(4,3);
    itemsTime[2] = elements[1].substr(8,4);
    itemsTime[3] = elements[1].substr(13,2);
    itemsTime[4] = elements[1].substr(16,2);
    itemsTime[5] = elements[1].substr(19,2);
    itemsTime[6] = elements[2].substr(1,2);

    elements[1] = elements[3].substr(1, elements[3].size()-1);
    elements[2] = elements[4];
    elements[3] = elements[5].substr(0, elements[5].size()-1);
    elements[4] = elements[6];
    elements[5] = elements[7];

    pos1 = elements[8].find(1, '/');
    pos1+=2;
    pos2 = elements[8].find(pos1+1, '/');
    pos2--;
    if(elements[8].substr(pos1, pos2) == localDomain)
        elements[6] = elements[8].substr(pos2+=1, elements[8].size()-2);
    else
        elements[6] = elements[8].substr(pos1, elements[8].size()-2);

    elements[7] = elements[9].substr(1, elements[9].size()-2);

    elements[8] = itemsTime[0];
    elements[9] = itemsTime[1];

    for(int i = 2; i<7; i++) {
        elements.push_back(itemsTime[i]);
    }
}

int mounthToInt(string mounth){
    int mounthConverted;

    if(mounth == "Jan")
        mounthConverted = 1;
    else if (mounth == "Feb")
        mounthConverted = 2;
    else if (mounth == "Mar")
        mounthConverted = 3;
    else if (mounth == "Apr")
        mounthConverted = 4;
    else if (mounth == "May")
        mounthConverted = 5;
    else if (mounth == "Jun")
        mounthConverted = 6;
    else if (mounth == "Jul")
        mounthConverted = 7;
    else if (mounth == "Aug")
        mounthConverted = 8;
    else if (mounth == "Sep")
        mounthConverted = 9;
    else if (mounth == "Oct")
        mounthConverted = 10;
    else if (mounth == "Nov")
        mounthConverted = 11;
    else if (mounth == "Dec")
        mounthConverted = 12;

    return mounthConverted;
}

eMethod convertToMethod(string method){
    eMethod converted;

    if(method == "GET")
        converted = GET;
    else if (method == "POST")
        converted = POST;
    else if (method == "OPTIONS")
        converted = OPTIONS;

    return converted;
}

void importLog(){
    string name;
    cout << "Entrer le répertoire du fichier à importer" << endl;
    cin >> name;

    ifstream file;
    file.open (name);
    if ((file.rdstate() & ifstream::failbit) != 0)
    {
        cerr << "Erreur d'ouverture de <" << name << ">" << endl;
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
            if(itemsLog.size() > 1) {
                cleanLog(itemsLog);
                for (int i = 0; i < itemsLog.size(); i++) {
                    TimeStamp t1(stoi(itemsLog[8]), mounthToInt(itemsLog[9]), stoi(itemsLog[10]), stoi(itemsLog[11]),
                            stoi(itemsLog[12]), stoi(itemsLog[13]));
                    Url u1(itemsLog[3], itemsLog[2]);
                    Log l1(itemsLog[0], t1, convertToMethod(itemsLog[1]), u1, stoi(itemsLog[4]), stoi(itemsLog[5]), itemsLog[6], itemsLog[7]);

                    cout << itemsLog[i] << endl;
                }
            }
            itemsLog.clear();
        }

}
}

int main(int argc, char *argv[])
{
    AnalogApp app(argc, argv);
    //return app.Run();

    importLog();
}

