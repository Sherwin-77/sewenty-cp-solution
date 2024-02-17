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
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> dishReqA(n);
    vector<int> dishReqB(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    for(int i = 0; i < n; i++) cin >> dishReqA[i];
    for(int i = 0; i < n; i++) cin >> dishReqB[i];
    bool possible = true;
    ll best = 0;
    while(possible){
        ll target = best + 1;
        bool shortcut = false;
        for(ll dishA = 0; dishA <= target; dishA++){
            ll dishB = target-dishA;
            for(int i = 0; i < n; i++){
                if(dishReqA[i] * dishA + dishReqB[i] * dishB >  arr[i]){
                    possible = false;
                    break;
                }
                if(!possible) break;
            }
            if(possible) break;
        }
        if(possible) best++;
    }
    cout << best;
}