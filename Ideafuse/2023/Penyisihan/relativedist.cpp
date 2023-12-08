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

template <typename T>
void debug(T const &value, std::string valueName){
    cout << "DEBUG VALUE " << valueName << ": " << value << '\n';
}
template <typename T>
void debug(T const &value, std::string valueName, int index){
    cout << "DEBUG VALUE " << valueName << " INDEX " << index << ": " << value << '\n';
}

template <typename T>
void print(T const &value, bool newLine=false){
    cout << value;
    if(newLine) cout << '\n';
}


// Alternative
typedef long long ll;


pair<pair<ll, ll>, string> constructStr(string &s){
    string ret(s.length(), 'a');
    ll dist = 0;
    ll actualDist = 0;
    for(char c: s){
        if(abs(c-'a') < abs(c-'z')){
            dist += abs(c-'z');
        } else {
            dist += abs(c-'a');
        }
        actualDist += abs(c-'a');
    }
    if(dist < 0 || actualDist < 0) terminate();
    return {{dist, actualDist}, ret};
}

signed main(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    int t;
    cin >> t;
    for(int x = 1; x <= t; x++){
        string s;
        ll target;
        cin >> s >> target;
        auto [dst, res] = constructStr(s); 
        if(dst.first < target) cout << "Case #" << x << ": -1\n";
        else {
            ll dist = dst.second;
            for(int i = s.length()-1; i >= 0; i--){
                if(dist == target) break;
                ll aCost = abs(s[i]-'a');
                ll zCost = abs(s[i]-'z');
                // By default we use all aCost
                // To increase, we convert to Z if Zcost is greater
                // To decrease, we simply convert to original which has 0 cost
                if(dist < target){
                    if(aCost >= zCost) continue;
                    if(dist-aCost + zCost > target){
                        res[i] = s[i] + (target-(dist-aCost));
                        // debug(i, "Lower bound");
                        break;
                    }
                    res[i] = 'z';
                    dist += zCost-aCost;
                } else {
                    if(dist-aCost < target){
                        res[i] = 'a' + (dist-target);
                        // debug(i, "Upper bound");
                        break;
                    }
                    res[i] = s[i];
                    dist -= aCost;
                }
            }
            // ll test = 0;
            // for(int i = 0; i < s.length(); i++){
            //     ll sc = abs(s[i]-res[i]);
            //     test += sc;
            // }
            // if(test != target) terminate();
            cout << "Case #" << x << ": " << res << '\n';
        }
    }
}