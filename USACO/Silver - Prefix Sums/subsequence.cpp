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
    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);
    ll n;
    ll tmp;
    cin >> n;
    vector<ll> arr(n+1, 0);
    for(int i = 1; i <= n; i++){
        cin >> tmp;
        arr[i] += tmp;
        arr[i] += arr[i-1];
    }
    for(int x = n; x > 1; x--){
        // debug(x, "LOOP");
        for(int i = 0; i+x <= n; i++){
            // debug(arr[i+x]-arr[i], "INNER LOOP");
            if((arr[i+x]-arr[i]) % 7 == 0){
                cout << x;
                return 0;
            }
        }
    }
    cout << 1;
}