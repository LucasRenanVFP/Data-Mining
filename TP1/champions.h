#include<bits/stdc++.h>
#include "tools.h"

using namespace std;

class ChampionsInfo {
	private:
		map<string, short int> champion_id;
		vector<string> champion_by_id;

	public:
		short int getChampionId(string &champion);
		string getChampionById(short int id);
		void loadChampions(string filename);

};
