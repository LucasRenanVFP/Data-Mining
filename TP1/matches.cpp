#include "matches.h"

MatchesInfo::MatchesInfo() {
	loadInfo("files/");
	for(auto p : matches_by_id) {
		matches.push_back(p.second);
	}
	
}

void MatchesInfo::loadParticipantsInfo(string path) {
	string filename = path + "participants.csv";
	ifstream fin(filename.c_str());
	vector<string> tokens;
	getTokensByLine(fin, tokens);
	while(!fin.eof()) {
		getTokensByLine(fin, tokens);
		int player_id = atoi(tokens[0].c_str());
		int match_id = atoi(tokens[1].c_str());
		int player = atoi(tokens[2].c_str());
		int champion_id = CInfo.getNewId(atoi(tokens[3].c_str()));
		if(player <= 5) {
			matches_by_id[match_id].blue_champs.push_back(champion_id);
			blue_team_player[player_id] = true;
		}
		else {
			matches_by_id[match_id].red_champs.push_back(champion_id);
			blue_team_player[player_id] = false;
		}
		match_by_player[player_id] = match_id;
	}
}

void MatchesInfo::loadStatsInfo(string path) {
	string filename = path + "stats1.csv";
	ifstream fin(filename.c_str());
	vector<string> tokens;
	getTokensByLine(fin, tokens);
	while(!fin.eof()) {
		getTokensByLine(fin, tokens);
		int player_id = atoi(tokens[0].c_str());
		int win = atoi(tokens[1].c_str());
		if(blue_team_player[player_id]) {
			matches_by_id[match_by_player[player_id]].blue_win = win;
		}
		else {
			matches_by_id[match_by_player[player_id]].blue_win = !win;
		}
	}


	filename = path + "stats2.csv";
	ifstream fin2(filename.c_str());
	getTokensByLine(fin2, tokens);
	while(!fin2.eof()) {
		getTokensByLine(fin2, tokens);
		int player_id = atoi(tokens[0].c_str());
		int win = atoi(tokens[1].c_str());
		if(blue_team_player[player_id]) {
			matches_by_id[match_by_player[player_id]].blue_win = win;
		}
		else {
			matches_by_id[match_by_player[player_id]].blue_win = !win;
		}
	}
}

void MatchesInfo::loadInfo(string path) {

	loadParticipantsInfo(path);
	loadStatsInfo(path);
}

vector<match> MatchesInfo::getAllMatches() {
	return matches;
}
