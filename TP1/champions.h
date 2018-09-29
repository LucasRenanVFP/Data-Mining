#ifndef CHAMPIONS_H
#define CHAMPIONS_H

#include<bits/stdc++.h>
#include "tools.h"

using namespace std;

#define ChampionSubset bitset<138>
#define N_CHAMPIONS 138

class ChampionsInfo {
	private:
		map<string, short int> champion_id;
		vector<string> champion_by_id;
		map<short int, short int> old_to_new_id;
		void loadChampions(string filename);
	public:
		ChampionsInfo();
		short int getChampionId(string champion);
		string getChampionById(short int id);
		short int getNewId(short int old_id);

};

#endif
