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


unordered_map<char, pair<int, int>> movement = {
    {'R', {1, 0}},
    {'L', {-1, 0}},
    {'U', {0, 1}},
    {'D', {0, -1}},
};
signed main(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    int n, q;
    int ip;
    char ic;
    int tp;
    cin >> n >> q;
    vector<pair<int, int>> pos(n-1);  // X, Y / Row, Col
    vector<pair<int, int>> query;
    queue<char> moves;
    vector<pair<int, int>> predict;
    predict.push_back({1, 0});
    for(int i = 2; i <= n; i++){
        pos[i-2] = {i, 0};
    }
    int curMoves = 0;
    for(int x = 0; x < q; x++){
        cin >> tp;
        if(tp == 1){
            cin >> ic;
            moves.push(ic);
            curMoves++;
        } else {
            cin >> ip;
            query.push_back({curMoves, ip});
        }
    }
    int x = 1; int y = 0;
    while(!moves.empty()){
        auto [mx, my] = movement[moves.front()];
        moves.pop();
        x += mx;
        y += my;
        predict.push_back({x, y});
        // cout << x << ' ' << y << '\n';
    }
    // for(auto [xx, yy]: predict){
    //     cout << "PREDICT: " << xx << ' ' << yy << '\n';
    // }
    for(auto [offset, pp]: query){
        pp--;
        if(offset < pp){
            cout << pos[pp-offset-1].first << ' ' << pos[pp-offset-1].second << '\n';
        } else {
            int where = offset - pp;
            cout << predict[where].first << ' ' << predict[where].second << '\n';
        }
    }
}