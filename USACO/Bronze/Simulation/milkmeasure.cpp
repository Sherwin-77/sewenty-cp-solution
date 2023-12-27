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

unordered_map<string, int> status = {
    {"Bessie", 7},
    {"Elsie", 7},
    {"Mildred", 7}
};

unordered_map<string, bool> displayed = {
    {"Bessie", true},
    {"Elsie", true},
    {"Mildred", true}
};

signed main(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    fileIO("measurement");
    int n;
    int idx;
    string a, b;
    int res = 0;
    int highest = 7;
    cin >> n;
    vector<pair<int, pair<string, string>>> arr(n);
    for(int i = 0; i < n; i++){
        cin >> idx >> a >> b;
        arr[i] = {idx, {a, b}};
    }
    sort(arr.begin(), arr.end());
    for(auto [idx, dt]: arr){  
        auto [name, mdf] = dt;
        if(mdf[0] == '-')status[name] -= mdf[1]-'0';
        else status[name] += mdf[1]-'0';
        int best = 0;
        for(auto x: status){
            best = max(best, x.second);
        }
        bool newed = false;
        for(auto x: status){
            if(x.second == best){
                if(!displayed[x.first]) newed = true;
                displayed[x.first] = true;
            } else {
                if(displayed[x.first]) newed = true;
                displayed[x.first] = false;
            }
        }
        res += newed;
    }
    cout << res;
}