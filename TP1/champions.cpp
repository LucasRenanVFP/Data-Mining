#include "champions.h"

short int ChampionsInfo::getChampionId(string &champion) {
	if(champion_id.count(champion))
		return champion_id[champion];
	cerr << champion << " is not a valid champion.\n";
}

string ChampionsInfo::getChampionById(short int id) {
	if(id < 0 or id >= champion_by_id.size()) {
		cerr << id << " is not in range [0, " << (short int)champion_by_id.size() - 1 << "]\n";
		exit(1);
	}
	return champion_by_id[id];
}

void ChampionsInfo::loadChampions(string filename) {
	vector< vector<string> > tokens = readCSV(filename);
	int cur_id = 0;

	//Skips first line because of headers
	for(int i = 1; i < tokens.size(); i++) {
		string &champion = tokens[i][0];
		if(!champion_id.count(champion)) {
			cerr << "adding " << tokens[i][0] << " to map\n";
			champion_id[champion] = cur_id++;
		}
	}
}
