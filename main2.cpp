#include "Log.h"
#include "TimeStamp.h"
#include "Url.h"
#include <cstring>
#include <iostream>
using namespace std;


int main(){

    TimeStamp ts(8, 9, 2012, 11, 15, 0, 2);
    string s1 = "page2.html";
    string s2 = "HTTP/1.1";
    Url u(s1, s2);



    return 0;
}