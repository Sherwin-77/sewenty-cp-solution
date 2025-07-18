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
    cin >> t;
    while(t--){
        ll n, c, d;
        ll tmp;
        cin >> n >> c >> d;
        vector<ll> original;
        vector<ll> other;
        for(ll i = 0; i < n; i++){
            for(ll j = 0; j < n; j++){
                cin >> tmp;
                other.push_back(tmp);
            }
        }
        sort(other.begin(), other.end());
        ll firstNumber = other.front();
        for(ll i = 0; i < n; i++){
            for(ll j = 0; j < n; j++){
                original.push_back(firstNumber + c * i + d * j);
            }
        }
        sort(original.begin(), original.end());
        bool ok = true;
        for(ll i = 0; i < n * n; i++){
            if(original[i] != other[i]){
                ok = false;
                break;
            }
        }
        print(ok ? "YES" : "NO");
    }
}