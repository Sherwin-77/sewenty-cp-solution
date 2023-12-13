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
#include <numeric>

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
    int t;
    cin >> t;
    for(int x = 1; x <= t; x++){
        ll a, b;
        cin >> a >> b;
        ll gc = gcd(a, b);
        ll lc = lcm(a, b);
        if(gc < 0 || lc < 0) terminate();
        if(gc == 1){
            cout << "Case #" << x << ": " << -1 << ' ' << lc * 2  << '\n';
        } else {
            ll bg = 1;
            for(ll g = 2; g < gc; g++){
                if(gc % g == 0){
                    bg = gc/g;
                    break;
                }
            }
            cout << "Case #" << x << ": " << bg << ' ' << lc * 2 << '\n';
        }
        
    }
}