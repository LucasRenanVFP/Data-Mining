#ifndef PATTERN_H
#define PATTERN_H

#include<bits/stdc++.h>
#include "matches.h"
#include "champions.h"

using namespace std;


class PatternFinder{
	private:
		ChampionsInfo CInfo;
		vector<match> matches_data;
		unordered_map<ChampionSubset, pair<int, int> > subset_info;//first = occur, second = win

	public:
		//gets all subsets of champions that occur at least min_sup times in dataset
		vector< vector<string> > subsetPattern(int min_sup, int min_size = 1);
		//gets all subsets of champions that occur at least min_sup times 
		//and wins at least win_rate * (number of games played) in dataset
		vector< vector<string> > subsetPatternWithWinRate(int min_sup, double win_rate, int min_size = 1);
		PatternFinder();
		void getChampionsInSubset(ChampionSubset subset, vector<string> &string_subset);
};

#endif
