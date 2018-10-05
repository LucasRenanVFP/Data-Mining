#include "champions.h"
#include "pattern.h"

int main() {
  cerr << "started processing.\n";
  ChampionsInfo Inf;
  cerr << "champion with id = " << 13 << " is " << Inf.getChampionById(13)
       << endl;
  cerr << "id of Ezreal is " << Inf.getChampionId("Ezreal") << endl;
  PatternFinder PFinder;
  cerr << "Ended processing.\n";
  vector<vector<string>> patterns;

  while (true) {
    cout << "TIPO DE CONSULTA" << endl;
    int tipo;
    cin >> tipo;
    if (tipo) {
      cerr << "Digite o numero de partidas minimos que um conjunto deve "
              "estar: "
           << endl;

      int kpartmin, lenconj;
      cin >> kpartmin;

      cerr << "Tamanho do conjunto a ser considerado.. [1, 5] : " << endl;

      cin >> lenconj;

      PFinder.subsetPattern(kpartmin, lenconj);
    } else {
      int knpart;
      cerr << "Digite o numero de partidas minimas a ser considerada: " << endl;
      cin >> knpart;
      cerr << "Digite o winrate: " << endl;
      double kwinrate;
      cin >> kwinrate;
      cerr << "Digite o tamanho do subconjunto a ser considerado: " << endl;
      int lenconj2;
      cin >> lenconj2;
      PFinder.subsetPatternWithWinRate(knpart, kwinrate, lenconj2);
    }
  }
}
