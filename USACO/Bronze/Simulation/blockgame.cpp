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

int res[26] = {};
signed main(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    fileIO("blocks");
    int n;
    string a, b;
    cin >> n;
    vector<vector<pair<int, int>>> checked(n, vector<pair<int, int>>(26, {0, 0}));
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        for(char c: a) checked[i][c-'a'].first++;
        for(char c: b) checked[i][c-'a'].second++;
        for(int j = 0; j < 26; j++) res[j] += max(checked[i][j].first, checked[i][j].second);
    }
    for(auto x: res) cout << x << '\n';
}