#include "champions.h"
#include "pattern.h"

int main() {
	cerr << "started processing.\n";
	ChampionsInfo Inf;
	cerr << "champion with id = " << 13 << " is " << Inf.getChampionById(13) << endl;
	cerr << "id of Ezreal is " << Inf.getChampionId("Ezreal") << endl;
	PatternFinder PFinder; 
	cerr << "Ended processing.\n";
	vector< vector<string> > patterns = PFinder.subsetPattern(500, 3);
	
	cout << "Pattern 500/sz3 found:\n";
	for(int i = 0; i < patterns.size(); i++) {
		for(int j = 0; j < patterns[i].size(); j++) {
			cout << patterns[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	patterns = PFinder.subsetPatternWithWinRate(100, 0.6, 3);
	cout << "Pattern 100/0.6/sz3 found:\n";
	for(int i = 0; i < patterns.size(); i++) {
		for(int j = 0; j < patterns[i].size(); j++) {
			cout << patterns[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

