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
typedef unsigned long long ull;

const ll DEFAULTMOD = 1000000007;

enum State {
    EMPTY = 0,
    SWORDMAN = 1,
    WIZARD = 2
};

signed main(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int n;
    ll cs, cw, cd;
    ll ps, pw, pd;
    ll totalEmptyCell = 0;

    cin >> n;
    cin >> cs >> cw >> cd;
    cin >> ps >> pw >> pd;

    vector<string> arr(2);
    for(int i = 0; i < 2; i++){
        cin >> arr[i];
        for (int j = 0; j < n; j++){
            if(arr[i][j] == '.') totalEmptyCell++;
        }
    }

    vector<vector<vector<vector<ll>>>> dp(n+1, vector<vector<vector<ll>>>(cs+1, vector<vector<ll>>(3, vector<ll>(3, -10000000000LL))));
    for (int j = 0; j <= cs; j++){
        for (int up = 0; up < 3; up++){
            for (int down = 0; down < 3; down++){
                if (j == 0) dp[0][j][up][down] = 0;
            }
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= cs; j++){
            for(int up = 0; up < 3; up++){
                for(int down = 0; down < 3; down++){
                    for (int prevUp = 0; prevUp < 3; prevUp++){
                        for (int prevDown = 0; prevDown < 3; prevDown++){
                            if (arr[0][i-1] == '#' && up) continue;
                            if (arr[1][i-1] == '#' && down) continue;
                            if (
                                (up == SWORDMAN && prevUp == SWORDMAN) ||
                                (up == SWORDMAN && down == SWORDMAN) ||
                                (down == SWORDMAN && prevDown == SWORDMAN) ||    

                                (up == WIZARD && prevDown == WIZARD) ||
                                (down == WIZARD && prevUp == WIZARD) 
                            ) continue;

                            ll usedSwordman = (up == SWORDMAN) + (down == SWORDMAN);
                            ll usedWizard = (up == WIZARD) + (down == WIZARD);

                            if (j < usedSwordman) continue;

                            dp[i][j][up][down] = max(dp[i][j][up][down], usedWizard + dp[i-1][j-usedSwordman][prevUp][prevDown]);
                            dp[i][j][up][down] = min(dp[i][j][up][down], cw);
                        }
                    }
                }
            }
        }
    }

    ll ans = 0;

    for(ll j = 0; j <= cs; j++){
        for(int up = 0; up < 3; up++){
            for (int down = 0; down < 3; down++) {
                ll maxk = dp[n][j][up][down];
                for (ll k = 0; k <= maxk; k++) {
                    ll l = min(totalEmptyCell - j - k, cd);
                    if (j > cs || k > cw || l > cd || l < 0){
                        terminate();
                    }
                    ans = max(ans, j * ps + k * pw + l * pd);
                }
            }
        }
    }

    print(ans);
}