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
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);
    ll n;
    ll total = 0;
    char c;
    cin >> n;
    vector<vector<ll>> arr(3, vector<ll> (n+1, 0));  // 0 = Rock, 1 = Paper, 2 = Scissor
    for(int i = 1; i <= n; i++){
        cin >> c;
        if(c == 'P'){  // Paper
            arr[2][i]++;
        } else if(c == 'H'){  // Rock
            arr[1][i]++;
        } else if(c == 'S'){  // Scissor
            arr[0][i]++;
        }
        arr[0][i] += arr[0][i-1];
        arr[1][i] += arr[1][i-1];
        arr[2][i] += arr[2][i-1];
    }   
    ll best = 0;
    for(int opt1 = 0; opt1 < 3; opt1++){
        for(int opt2 = 0; opt2 < 3; opt2++){
            for(int x = 1; x < n; x++){
                best = max(best, arr[opt1][x] + (arr[opt2][n]-arr[opt2][x]));
            }
        }
    }
    cout << best;
}