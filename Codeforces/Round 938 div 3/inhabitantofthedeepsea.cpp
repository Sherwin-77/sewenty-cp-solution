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


signed main(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        ll n, k;
        ll tmp;
        /**
         * n - number of ships
         * k - number of attack ship
        */
        cin >> n >> k;
        // Ship HP
        deque<ll> ships;
        for(ll i = 0; i < n; i++){
            cin >> tmp;
            ships.push_back(tmp);
        }
        bool isAttackingFront = true;
        ll destroyedShip = 0;
        while(k > 0 && !ships.empty()){
            ll lowestHp = min(ships.front(), ships.back());
            ll powerNeeded = lowestHp * 2;
            bool lowestHpIsFront = (isAttackingFront ? lowestHp == ships.front() : lowestHp != ships.back());
            if(lowestHpIsFront == isAttackingFront) powerNeeded--;

            // Not enough power to attack ship
            if(powerNeeded > k){
                if(ships.size() == 1){
                    if(lowestHp <= k){
                        k -= lowestHp;
                        destroyedShip++;
                    }
                } 
                break;
            } else {
                if(ships.size() == 1){
                    k -= lowestHp;
                    destroyedShip++;
                    break;
                } else {
                    if(lowestHpIsFront){
                        ships.pop_front();
                        k -= powerNeeded;
                        destroyedShip++;
                        ships.back() -= (powerNeeded - lowestHp);
                        if(ships.back() == 0){
                            ships.pop_back();
                            destroyedShip++;
                        }
                    } else {
                        ships.pop_back();
                        k -= powerNeeded;
                        destroyedShip++;
                        ships.front() -= (powerNeeded - lowestHp);
                        if(ships.front() == 0){
                            ships.pop_front();
                            destroyedShip++;
                        }
                    }
                }
                // debug(k, "k");
            }
            isAttackingFront = !lowestHpIsFront;
        }
        print(destroyedShip);
    }
}