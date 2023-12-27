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
    fileIO("speeding");
    ll n, m;
    ll a, b;
    cin >> n >> m;
    vector<pair<ll, ll>> road(n);
    vector<pair<ll, ll>> journey(m);
    for(ll i = 0; i < n; i++){
        cin >> a >> b;
        road[i] = {a, b};
    }
    for(ll i = 0; i < m; i++){
        cin >> a >> b;
        journey[i] = {a, b};
    }
    ll res = 0;
    ll cur = 0;
    for(auto x: journey){
        ll rem = x.first;
        while(rem && cur < n){
            res = max(res, x.second-road[cur].second);
            if(rem > road[cur].first) rem -= road[cur++].first;
            else {
                road[cur].first -= rem;
                if(road[cur].first == 0) cur++;
                break;
            }
        }
    }
    cout << res;
}