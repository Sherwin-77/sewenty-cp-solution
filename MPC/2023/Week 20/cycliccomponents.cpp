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

const int DEFAULTMOD = 1e9 + 7;

void markVisited(vector<vector<int>> &adj, vector<bool> &visited, int node){
    visited[node] = true;
    for(int &neighbour: adj[node]){
        if(!visited[neighbour]){
            markVisited(adj, visited, neighbour);
        }
    }
}

bool isCycle(vector<vector<int>> &adj, vector<bool> &visited, int node, int parent){
    visited[node] = true;
    for(int &neighbour: adj[node]){
        if(!visited[neighbour]){
            if(isCycle(adj, visited, neighbour, node)){
                return true;
            }
        }else if(neighbour != parent){
            return true;
        }
    }
    return false;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    // Mark as visited if there are more than 1 edges
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++){
        if(adj[i].size() > 2 && !visited[i]){
            markVisited(adj, visited, i);
        }
    }
    // Check if there is a cycle
    int cycleCount = 0;
    for (int i = 0; i < n; i++){
        if(!visited[i]){
            if(isCycle(adj, visited, i, -1)){
                cycleCount++;
            }
        }
    }
    print(cycleCount);
}