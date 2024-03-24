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
//  UU (keatas), SS (kebawah), BB (kekiri), dan TT (kekanan).
unordered_map<char, pair<int, int>> DIRECTION {
    {'U', {-1, 0}},
    {'S', {1, 0}},
    {'B', {0, -1}},
    {'T', {0, 1}},
};

signed main(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    int r, c, y;
    while(cin >> r >> c >> y){
        if(r == 0 && c == 0 && y == 0) break;
        vector<string> arr(r);
        vector<vector<pair<bool,  int>>> tracker(r, vector<pair<bool, int>> (c, {false, 0}));
        for(int i = 0; i <  r; i++){
            cin >> arr[i];
        }
        int cr = 0;
        int cc = y-1;
        int moves = 0;
        bool success = true;
        while(cr >= 0 && cr < r && cc >= 0 && cc < c){
            if(tracker[cr][cc].first){
                success = false;
                break;
            }
            tracker[cr][cc] = {true, moves};
            auto [mr, mc] = DIRECTION[arr[cr][cc]];
            cr += mr;
            cc += mc;
            // cout  << "MOVE "<< cr << ' ' << cc << ' ' << arr[cr][cc] << '\n';
            moves++;
        }
        if(success){
            cout << "1 " << moves << '\n';
        } else {
            cout << "1 " << tracker[cr][cc].second << " 0 " << moves - tracker[cr][cc].second << '\n';
        }
    }
}