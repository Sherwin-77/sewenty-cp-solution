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
#include <cmath>

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
typedef unsigned long long ull;

const ll DEFAULTMOD = 1000000007;

// int log2(ull x){
//     return x == 0 ? -1 : 64 - __builtin_clzll(x);
// }

signed main(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    vector<ll> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int k = log2(n);
    vector<vector<ll>> tableu(k + 1, vector<ll>(n, 1000000000));

    for(int i = 0; i < n; i++){
        tableu[0][i] = arr[i];
    }
    for (int i = 1; i <= k; i++){
        for (int j = 0; j + (1 << i) <= n; j++){
            tableu[i][j] = min(tableu[i - 1][j], tableu[i - 1][j + (1 << (i - 1))]);
        }
    }

    // print(k);
    // for (int i = 0; i <= k; i++){
    //     for (int j = 0; j < n; j++){
    //         if (tableu[i][j] == 1000000000) continue;
    //         cout << tableu[i][j] << " ";
    //     }
    //     cout << '\n';
    // }

    while(q--) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        int x = (int)log2(r - l + 1);
        // print(x);
        print(min(tableu[x][l], tableu[x][r - (1 << x) + 1]));
        // cout << '\n';
    }
}