#include "pattern.h"

PatternFinder::PatternFinder() {
	MatchesInfo MInfo;
	matches_data = MInfo.getAllMatches();
	cerr << "matches data.size() = " << matches_data.size() << endl;
	for(int i = 0; i < matches_data.size(); i++) {
		match &cur_match = matches_data[i];
		ChampionSubset blue;	
		ChampionSubset red;
		for(int mask = 1; mask < (1 << 5); mask++) {
			for(int j = 0; j < cur_match.blue_champs.size(); j++) {
				if(!(mask & (1 << j))) continue;
				blue[cur_match.blue_champs[j]] = 1;
			}
			subset_info[blue].first++;
			subset_info[blue].second += cur_match.blue_win;
			for(int j = 0; j < cur_match.red_champs.size(); j++) {
				if(!(mask & (1 << j))) continue;
				red[cur_match.red_champs[j]] = 1;
			}
			subset_info[red].first++;
			subset_info[red].second += !cur_match.blue_win;
			for(int j = 0; j < cur_match.blue_champs.size(); j++) {
				blue[cur_match.blue_champs[j]] = 0;
			}
			for(int j = 0; j < cur_match.red_champs.size(); j++) {
				red[cur_match.red_champs[j]] = 0;
			}
		}
	}
}
		
vector< vector<string> > PatternFinder::subsetPattern(int min_sup, int min_size) {
	vector< vector<string> > patterns;
	vector<string> subset;
	for(auto &p : subset_info) {
		if(p.first.count() < min_size) continue;
		if(p.second.first >= min_sup) {
			getChampionsInSubset(p.first, subset);
			patterns.push_back(subset);
		}
	}
	return patterns;
}


vector< vector<string> > PatternFinder::subsetPatternWithWinRate(int min_sup, double win_rate, int min_size) {
	vector< vector<string> > patterns;
	vector<string> subset;
	double cur_win_rate;
	for(auto &p : subset_info) {
		if(p.first.count() < min_size) continue;
		if(p.second.first >= min_sup) {
			cur_win_rate = (double)p.second.second / (double)p.second.first;
			if(cur_win_rate + 1e-9 > win_rate) {
				getChampionsInSubset(p.first, subset);
				patterns.push_back(subset);
			}
		}
	}
	return patterns;
	
}

void PatternFinder::getChampionsInSubset(ChampionSubset subset, vector<string> &string_subset) {
	string_subset.clear();
	for(int i = 0; i < N_CHAMPIONS; i++) {
		if(subset[i]) {
			string_subset.push_back(CInfo.getChampionById(i));
		}
	}
}
