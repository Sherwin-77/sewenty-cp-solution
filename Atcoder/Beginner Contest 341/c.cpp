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

unordered_map<char, pair<int, int>> moveAjg = {
    {'L', {0, -1}},
    {'R', {0, 1}},
    {'U', {-1, 0}},
    {'D', {1, 0}},
};

bool isFree(int i, int j, int maxH, int maxW, vector<string> &arr){
    return i >= 0 && j >= 0 && i < maxH && j < maxW && arr[i][j] == '.';
}
bool validateMove(vector<char> &moves, vector<string> &arr, int i, int j, int maxH, int maxW, int curMove = 0){
    bool cur = isFree(i, j, maxH, maxW, arr);
    if(!cur) return false;
    if(curMove == moves.size()) return true;
    auto [mi, mj] = moveAjg[moves[curMove]];
    return validateMove(moves, arr, i+mi, j+mj, maxH, maxW, curMove+1);
}

signed main(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int h, w, n;
    int res = 0;
    cin >> h >> w >> n;
    vector<string> arr(h);
    vector<char> moves(n);
    for(int i = 0; i < n; i++) cin >> moves[i];
    for(int i = 0; i < h; i++) cin >> arr[i];
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(arr[i][j] == '.') res += validateMove(moves, arr, i, j, h, w);
        }
    }
    cout << res;
}