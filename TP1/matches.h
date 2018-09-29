#ifndef MATCHES_H
#define MATCHES_H

#include<bits/stdc++.h>
#include "champions.h"
#include "tools.h"
using namespace std;

class match {
	public:
		vector<short int> blue_champs;
		vector<short int> red_champs;
		bool blue_win;
};

class MatchesInfo {
	private:
		ChampionsInfo CInfo;
		vector<match> matches;
		void loadParticipantsInfo(string path);
		void loadStatsInfo(string path);
		void loadInfo(string path);
		map<int, match> matches_by_id;
		map<int, int> match_by_player;
		map<int, bool> blue_team_player;
	public:
		MatchesInfo();
		vector<match> getAllMatches();
};

#endif
