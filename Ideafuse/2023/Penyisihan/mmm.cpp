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
    int n, m;
    cin >> n >> m;
    int count = 0;
    for(int ab = 2; ab <= n; ab++){
        for(int bd = ab; bd <= m && bd <= (ab * 2); bd++){
            for(int i = 0; i+ab <= n; i++){
                for(int j = 0; j+bd <= m; j++){
                    if(bd % 2 == 0 && ab % 2 == 0) count++;

                }
            }
        }
    }
    cout << count;
}