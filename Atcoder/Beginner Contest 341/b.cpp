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
    vector<long long> budget(n, 0);
    vector<pair<long long, long long>> exchange(n-1);
    long long best = 0;
    for(int i = 0; i < n; i++) cin >> budget[i];
    for(int i = 0; i < n-1; i++){
        long long a, b;
        cin >> a >> b;
        exchange[i] = {a, b};
    }
    for(int i = 0; i < n-1; i++){
        long long div = budget[i]/exchange[i].first;
        budget[i+1] += div * exchange[i].second; 
    }
    cout << budget[n-1];
}