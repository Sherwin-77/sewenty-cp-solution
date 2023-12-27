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
    string s;
    cin >> s;
    vector<vector<ll>> abj(s.length()+1, vector<ll>(26, 0));
    for(ll i = 1; i <= s.length(); i++){
        for(int j = 0; j < 26; j++){
            abj[i][j] += abj[i-1][j];
        }
        abj[i][s[i-1]-'a']++;
    }
    ll q;
    cin >> q;
    ll a, b;
    for(ll i = 0; i < q; i++){
        cin >> a >> b;
        if(a == b || s[a-1] != s[b-1]){
            cout << "Yes\n";
        } else {
            int more = 0;
            for(int j = 0; j < 26; j++){
                more += abj[b][j]-abj[a-1][j] > 0;
                if(more >= 3) break;
            }
            cout << (more >= 3 ? "Yes\n" : "No\n");
        }
    }
}