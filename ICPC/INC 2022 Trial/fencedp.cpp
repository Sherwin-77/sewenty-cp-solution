#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

// MEMORY LIMIT

int main(){
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, tmp;
    int half = 0;
    cin >> n;
    // n = 100;
    vector<int> tile;
    queue<pair<int, int>> rilnofek;
    queue<pair<int, int>> feknoril;
    for(int i = 0; i < n; i++){
        cin >> tmp;
        half += tmp;
        tile.push_back(tmp);
        // half += 2;
        // tile.push_back(2);
    }
    half /= 2;
    rilnofek.push(make_pair(0, 0));
    for(auto x: tile){
        while(!rilnofek.empty()){
            feknoril.push(rilnofek.front());
            rilnofek.pop();
        }
        while(!feknoril.empty()){
            auto pair = feknoril.front();
            int top = pair.first;
            int bottom = pair.second;
            feknoril.pop();
            if(top + x <= half) rilnofek.push(make_pair(top+x, bottom));
            if(bottom + x <= half) rilnofek.push(make_pair(top, bottom+x));
            if(x == 2) rilnofek.push(make_pair(top, bottom));
        }
    }
    while(!rilnofek.empty()){
        auto pair = rilnofek.front();
        int top = pair.first;
        int bottom = pair.second;
        rilnofek.pop();
        if(top == bottom){
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
}
