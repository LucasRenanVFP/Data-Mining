#include "tools.h"


vector<string> getTokensByLine(ifstream &fin) {
	vector<string> tokens;
	if(fin.eof()) {
		cerr << "Extracting tokens from an empty line. Shame.\n";
		exit(1);
	}
	string input;
	getline(fin, input);
	if(input == "\n") {
		return tokens;
	}
	
	string current;
	for(int i = 0; i < input.size(); i++) {
		if(input[i] == ' ' or input[i] == '\n') continue;
		if(input[i] == ',') {
			tokens.push_back(current);
			current.clear();
		}
		else {
			current.push_back(input[i]);
		}
	}
	if(current.size()) tokens.push_back(current);
	return tokens;
}

vector< vector<string> > readCSV(string &filename) {
	vector< vector<string> > data_table;
	ifstream fin(filename.c_str());
	int m;
	while(!fin.eof()) {
		vector<string> tokens = getTokensByLine(fin);
		m = max((int)tokens.size(), m);
		if(tokens.size())
			data_table.push_back(tokens);
	}
	for(int i = 0; i < data_table.size(); i++) {
		while(data_table[i].size() < m) data_table[i].push_back("");
	}
	return data_table;
}

