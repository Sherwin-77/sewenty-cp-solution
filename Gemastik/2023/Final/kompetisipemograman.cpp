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
    /*
    n - Number of contestant
    m - Number of region
    k - Number of contestant holding wildcard
    Wildcard -> auto pass regional competition
    */
    int n, m, k;
    int tmp;
    cin >> n >> m >> k;
    vector<priority_queue<pair<int, int>>> arr(m);
    vector<int> score(n);
    vector<bool> passFinal(n, false);
    for(int i = 0; i < n; i++){
        cin >> score[i];
    }
    for(int i = 0; i < n; i++){
        cin >> tmp;
        arr[tmp-1].push({score[i], i});
    }
    for(int i = 0; i < k; i++){
        cin >> tmp;
        passFinal[tmp-1] = true;
    }
    for(auto x: arr) passFinal[x.top().second] = true;
    int totalPass = 0;
    for(int i = 0; i < n; i++) totalPass += passFinal[i];
    cout << totalPass << '\n';
}