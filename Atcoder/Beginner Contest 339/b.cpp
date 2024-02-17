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

char DIRECT[] = {
    'U', 'R', 'D', 'L'
};

pair<int, int> moves[] = {
    {0, -1},
    {1, 0},
    {0, 1},
    {-1, 0}
};

signed main(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    ll h, w, n;
    cin >> h >> w >> n;
    vector<string> arr(h, string(w, '.'));
    int mover = 0;
    int x = 0;
    int y = 0;
    for(ll i = 0; i < n; i++){
        if(arr[y][x] == '#'){
            arr[y][x] = '.';
            mover = (mover-1 + 4) % 4;
        } else {
            arr[y][x] = '#';
            mover = (mover+1 + 4) % 4;
        }   
        // mover = (mover+1 + 4) % 4;
        x = (x + moves[mover].first + w) % w;
        y = (y + moves[mover].second + h) % h;
        // cout << x << ' ' << y << '\n';
    }
    for(int i = 0; i < h; i++){
        for(auto c: arr[i]) cout << c;
        cout << '\n';
    }
}