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
    int t;
    int n;
    int tmp;
    cin >> t;
    for(int x = 0; x < t; x++){
        cin >> n;
        int total = 0;
        int firstPost[101];
        fill_n(firstPost, 101, -1);
        set<int> dt;
        for(int i = 0; i < n; i++){
            cin >> tmp;
            total += tmp;
            dt.insert(tmp);
            if(firstPost[tmp] == -1) firstPost[tmp] = i+1;
        }
        for(auto x : dt){
            int cursor = total - (x * (n-1));
            if(dt.find(cursor) != dt.end()){
                cout << firstPost[cursor] << '\n';
                break;
            }
        }
    }
}