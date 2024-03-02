#include <iostream>

#include <algorithm>

#include <bitset>

#include <vector>

#include <map>

#include <unordered_map>

#include <set>

#include <unordered_set>

#include <deque>

#include <queue>

#include <stack>

#include <string>



using namespace std;

// #define int long long



void fileIO(string fileName, string inExt=".in", string outExt=".out"){

    string fIn = fileName + inExt;

    string fOut = fileName + outExt; 

    freopen(fIn.c_str(), "r", stdin);

    freopen(fOut.c_str(), "w", stdout);

}



template <typename T>

void debug(T const &value, std::string valueName){

    cout << "DEBUG VALUE " << valueName << ": " << value << '\n';

}

template <typename T>

void debug(T const &value, std::string valueName, int index){

    cout << "DEBUG VALUE " << valueName << " INDEX " << index << ": " << value << '\n';

}



template <typename T>

void print(T const &value, bool newLine=true){

    cout << value;

    if(newLine) cout << '\n';

}





// Alternative

typedef long long ll;





unordered_map<char, int> powerList{

    {'6', 1},

    {'7', 2},

    {'8', 3},

    {'9', 4},

    {'T', 5},

    {'J', 6},

    {'Q', 7},

    {'K', 8},

    {'A', 9}

};

signed main(){

    ios_base::sync_with_stdio(false);

    cout.tie(NULL);

    cin.tie(NULL);

    int t;

    string s;

    char truf;

    cin >> t;

    int nA, nB;

    for(int x = 0; x < t; x++){

        cin >> nA >> nB >> truf;

        unordered_map<char, priority_queue<int>> ally {

            {'S', priority_queue<int>()},

            {'C', priority_queue<int>()},

            {'D', priority_queue<int>()},

            {'H', priority_queue<int>()},

        };

        unordered_map<char, priority_queue<int>> enemy {

            {'S', priority_queue<int>()},

            {'C', priority_queue<int>()},

            {'D', priority_queue<int>()},

            {'H', priority_queue<int>()},

        };

        for(int i = 0; i < nA; i++){

            cin >> s;

            int power = powerList[s[0]];

            ally[s[1]].push(power);

        }

        for(int i = 0; i < nB; i++){

            cin >> s;

            int power = powerList[s[0]];

            enemy[s[1]].push(power);

        }

        auto trufAlly = ally[truf];
        priority_queue<pair<bool, int>> trufEnemy;

        while(!enemy[truf].empty()){

            trufEnemy.push({true, enemy[truf].top()});

            enemy[truf].pop();

        }

        for(auto enemyForce: enemy){

            auto [group, pqe] = enemyForce;

            auto pqa = ally[group];

            if(group == truf) continue;

            bool defeated = false;

            while(!pqe.empty()){

                int powerEnemy = pqe.top();

                while(!pqa.empty()){

                    int powerAlly = pqa.top();

                    if(powerAlly >= powerEnemy){

                        defeated = true;

                        break;

                    }

                    pqa.pop();

                }

                if(!defeated) trufEnemy.push({0, powerEnemy});

                pqe.pop();

            }

        }

        if(trufEnemy.empty()) {

            cout << "YA\n";

        }

        else {

            bool defeated = true;

            while(!trufEnemy.empty()){

                if(trufAlly.empty()){

                    defeated = false;

                    break;

                }

                auto [realTruf, powerEnemy] = trufEnemy.top();

                while(!trufAlly.empty()){

                    int powerAlly = trufAlly.top();

                    trufAlly.pop();

                    if(!realTruf){

                        trufEnemy.pop();

                        break;

                    }

                    if(powerAlly >= powerEnemy){

                        trufEnemy.pop();

                        break;

                    } 

                }

            }

            cout <<  (defeated ? "YA\n": "TIDAK\n");

        }

    }

}