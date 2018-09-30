#include "champions.h"

ChampionsInfo::ChampionsInfo() { loadChampions("files/champs.csv"); }

short int ChampionsInfo::getChampionId(string champion) {
  if (champion_id.count(champion))
    return champion_id[champion];
  cerr << champion << " is not a valid champion.\n";
  return -1;
}

string ChampionsInfo::getChampionById(short int id) {
  if (id < 0 or id >= champion_by_id.size()) {
    cerr << id << " is not in range [0, "
         << (short int)champion_by_id.size() - 1 << "]\n";
    exit(1);
  }
  return champion_by_id[id];
}

void ChampionsInfo::loadChampions(string filename) {
  cerr << "Init Load ChampionsInfo!!" << endl;
  vector<vector<string>> tokens = readCSV(filename);
  cerr << "Load ChampionsInfo sucessful!!" << endl;

  short int cur_id = 0;
  // Skips first line because of headers
  for (int i = 1; i < tokens.size(); i++) {
    assert(tokens[i].size() > 0);
    string &champion = tokens[i][0];
    if (!champion_id.count(champion)) {
      assert(tokens[i].size() > 1);
      short int old_id = atoi(tokens[i][1].c_str());
      old_to_new_id[old_id] = cur_id;
      if (tokens[i].size() >= 2) {
        // cerr << "adding " << tokens[i][0] << " to map\n";
        champion_id[champion] = cur_id++;
      } else {
        cerr << "Champion " << champion << " is missing Id.\n";
      }
    }
  }
  // cerr << "Added " << champion_id.size() << " champions.\n";
  champion_by_id.resize(cur_id);
  for (auto p : champion_id) {
    champion_by_id[p.second] = p.first;
  }
}

short int ChampionsInfo::getNewId(short int old_id) {
  if (!old_to_new_id.count(old_id)) {
    cerr << old_id << " is not an old id\n";
    return champion_id.size();
  }
  return old_to_new_id[old_id];
}
