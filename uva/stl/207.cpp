#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

#define REP(i,n) for(int i = 0; i < (n); i++)
struct Player {
    string name;
    bool amateur;
    bool dq;
    int sc[4];
    int sc36, sc72;
    int rnds;
} players [144];

string trim(const string& str)
{
    size_t first = str.find_first_not_of(' ');
    if (string::npos == first)
    {
        return str;
    }
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}

bool cmp1(const Player& p1, const Player& p2) {
  if(p1.sc36 < 0 && p2.sc36 < 0) return false; // equal
  if(p1.sc36 < 0) return false; // p2 smaller
  if(p2.sc36 < 0) return true; // p1 smaller
  return p1.sc36 < p2.sc36;
}

bool cmp2(const Player& p1, const Player& p2) {
  if(p1.dq && p2.dq) {
    if(p1.rnds != p2.rnds) return p2.rnds < p1.rnds;
    if(p1.sc72 != p2.sc72) return p1.sc72 < p2.sc72;
    return strcmp(p1.name.c_str(), p2.name.c_str()) < 0;
  }

  if(p1.dq) return false;
  if(p2.dq) return true;
  if(p1.sc72 != p2.sc72) return p1.sc72 < p2.sc72;
  return strcmp(p1.name.c_str(), p2.name.c_str()) < 0;
}

void print_result(int n, int purse, double* p) {
  printf("Player Name          Place     RD1  RD2");
  printf("  RD3  RD4  TOTAL     Money Won\n");
  printf("---------------------------------------");
  printf("--------------------------------\n");

  int i = 0, pos = 0;
  while(i < n) {
    if(players[i].dq) {
      printf("%s           ",players[i].name.c_str());
      REP(j,players[i].rnds) printf("%-5d", players[i].sc[j]);
      REP(j,4-players[i].rnds) printf("     ");
      printf("DQ\n");
      i++;
      continue;
    }

    int j = i;
    int m = 0; // number of tied players
    bool have_money = false;
    double tot = 0.0; // total pooled money
    while(j < n && players[i].sc72 == players[j].sc72) {
      if(!players[j].amateur) {
        m++;          
        if(pos < 70) {
          have_money = true; // yeah! they still have money
          tot += p[pos++];
        }
      }
      j++;
    }

    // print player [i,j) together because they have the same rank
    int rank = i + 1; // rank of all these m players
    double amount = purse * tot / m; // if m=0, amount will be nan but we don't use it in that case :)
    while(i < j) {
      printf("%s ", players[i].name.c_str());
      char t[5];
      sprintf(t, "%d%c", rank, m > 1 && have_money && !players[i].amateur ? 'T' : ' ');
      printf("%-10s", t);
      REP(e,4) printf("%-5d", players[i].sc[e]);

      // with prize
      if(!players[i].amateur && have_money) {
        printf("%-10d", players[i].sc72);
        printf("$%9.2lf\n", amount / 100.0);
      } else
        printf("%d\n", players[i].sc72);
      i++;
    }
  }
}



int main(){
    int T;
    string s;
    getline(cin, s);
    stringstream ss(s);
    ss >> T;
    while (T--) {
        getline(cin, s);  // empty line


       //prize
       int purse;
       getline(cin, s);
       ss << s;
       ss >> purse;
       double prizes[70];
       for (int i =0 ; i < 70; i++) {
            getline(cin, s);
            ss << s;
            ss >> prizes[i];
       }

       //players
       int n_players;
       getline(cin, s);
       ss << s;
       ss >> n_players;
       for (int i =0; i < n_players; i++) {
           getline(cin, s);
           players[i].name = trim(s.substr(0, 20));
           if (players[i].name.find('*') != string::npos) {
               players[i].amateur = true;
           } else {
               players[i].amateur = false;
           }
           players[i].sc[0] = players[i].sc[1] = players[i].sc[2] = players[i].sc[3] = -1;
           players[i].sc36 = players[i].sc72 = 0;
           players[i].rnds = 0;
           players[i].dq= false;
           istringstream iss(s.substr(20));
           string token;
           int j = 0 ;
           while(getline(iss, token, ' ')) {
               if (token == "DQ") {
                   players[i].dq = true;
               } else {
                   players[i].sc[j] = stoi(token);
                   j+=1;
                   players[i].rnds+=1;
               }
           }

           if (players[i].rnds < 2) {
               players[i].sc36 = -1;
           } else {
               players[i].sc36 = players[i].sc[0] +players[i].sc[1];
           }

           if (players[i].rnds == 2) {
               players[i].sc72 =  players[i].sc36;
           } else if (players[i].rnds == 3){
               players[i].sc72 = players[i].sc36 + players[i].sc[2];
           } else{
               players[i].sc72 = players[i].sc36 + players[i].sc[2] +players[i].sc[3];
           }
       }

       sort(players, players+n_players, cmp1);
       for (int i =69; i < n_players;i++) {
           if (i==n_players-1 || players[i].sc36 != players[i].sc36) {
               n_players = i+1;
               break;
           }
       }

       sort(players, players + n_players, cmp2);
       print_result(n_players, purse, prizes);

       if(T) {
           cout << "\n";
       }
    }

    return 0;

    



}