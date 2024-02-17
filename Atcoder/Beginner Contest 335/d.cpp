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
pair<int, int> rotate(int curmx, int curmy){
    if(curmy == 1 && curmx == 0) return {1, 0}; 
    if(curmy == 0 && curmx == 1) return {0, -1};
    if(curmy == -1 && curmx == 0) return {-1, 0};
    if(curmy == 0 && curmx == -1) return {0, 1};
}
bool frees(int curx, int cury, int bound, vector<vector<int>> &state){
    return curx >= 0 && cury >= 0 && curx < bound && cury < bound && state[cury][curx] == 0;
}


signed main(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(n, 0));
    ll counts = n * n - 1;
    ll curCounts = 1;
    arr[n/2][n/2] = -1;
    int x = 0;
    int y = 0;
    int vx = 0;
    int vy = 1;
    while(curCounts <= counts){
        arr[y][x] = curCounts++;
        if(!frees(x + vx, y + vy, n, arr)){
            auto [nx, ny] = rotate(vx, vy);
            vx = nx;
            vy = ny;
        } 
        x += vx;
        y += vy;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(arr[i][j] == -1) cout << 'T';
            else cout << arr[i][j];
            cout << ' ';
        }
        cout << '\n';
    }
}