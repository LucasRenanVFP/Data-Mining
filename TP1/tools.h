#ifndef TOOLS_H
#define TOOLS_H

#include<bits/stdc++.h>

using namespace std;

bool alphanumeric(char c);
vector<string> getTokensByLine(ifstream &fin);
vector< vector<string> > readCSV(string filename);
void getTokensByLine(ifstream &fin, vector<string> &tokens);

#endif
