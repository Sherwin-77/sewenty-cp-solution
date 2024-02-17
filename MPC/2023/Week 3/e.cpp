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
    int a, b, c, d;
    cin >> n;
    for(int x = 0; x < n; x++){
        bool fair = true;
        cin >> a >> b >> c >> d;
        vector<int> test = {
            a, b, c, d
        };
        sort(test.begin(), test.end(), greater<int>());
        if(a < b) swap(a, b);
        if(a == test[0] && b == test[1]) fair = false;
        if(c < d) swap(c, d);
        if(c == test[0] && d == test[1]) fair = false;
        cout << (fair ? "YES\n" : "NO\n");
    }
}