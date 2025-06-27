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

struct Edge {
    int a, b;
    ll blueCost, redCost;
};

signed main(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int t;
    cin >> t;
    int num = 0;
    while(t--) {
        num++;
        int n, m;
        cin >> n >> m;

        vector<Edge> edges;
        for (int i = 0; i < m; i++) {
            int a, b;
            ll blueCost, redCost;
            cin >> a >> b >> blueCost >> redCost;
            a--; b--;
            edges.push_back({a, b, blueCost, redCost});
            edges.push_back({b, a, blueCost, redCost});
        }

        vector<vector<ll>> dist(n, vector<ll>(2, 1000000000));
        dist[0][0] = dist[0][1] = 0;

        for (int i = 0; i < n-1; i++) {
            for (auto edge : edges) {
                if (edge.a == n-1) continue;
                dist[edge.b][0] = min(dist[edge.b][0], dist[edge.a][0] + edge.blueCost);
                dist[edge.b][1] = min(dist[edge.b][1], dist[edge.a][1] + edge.redCost);
            }
        }

        if (dist[n-1][0] < dist[0][0]) {
            print("abyss");
            continue;
        }

        if (dist[n-1][1] < dist[0][1]) {
            print("abyss");
            continue;
        }
        cout << "Case #" << num << ": " << min(dist[n-1][0], dist[n-1][1]) << '\n';
    }    
}