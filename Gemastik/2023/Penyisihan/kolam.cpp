#include <iostream>
#include <vector>
#include <algorithm>


template <typename T>
void debug(T const &value, std::string valueName){
    std::cout << "DEBUG VALUE " << valueName << ": " << value << '\n';
}

template <typename T>
void debug(T const &value, std::string valueName, int index){
    std::cout << "DEBUG VALUE " << valueName << " INDEX " << index << ": " << value << '\n';
}

using namespace std;

pair<int, long long> find(int x, vector<int> &link, vector<long long> &cost) {
    long long minCost = cost[x];
    while (x != link[x]){ 
        x = link[x];
        min(minCost, cost[x]);
    }
    return make_pair(x, minCost);
}


// bool same(int a, int b, vector<int> &link) {
//     return find(a, link) == find(b, link);
// }

void unite(int a, int b, vector<int> &link, vector<int> &size, vector<long long> &cost) {
    auto resA = find(a, link, cost);
    auto resB = find(b, link, cost);
    a = resA.first;
    b = resB.first;
    long long minCost = min(resA.second, resB.second);
    if (size[a] < size[b]) swap(a,b);
    size[a] += size[b];
    link[b] = a;

    int x = a;
    while (x != link[x]){ 
        x = link[x];
        cost[x] = minCost;
    }
}

// Not solved yet
int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    long long n, k, b;
    int a, b;
    vector<long long> cost(n);
    vector<int> link(n);
    vector<int> size(n, 1);
    for(int i = 0; i < n; i++) {
        cin >> cost[i];
        link[i] = i;
    }
    for(int i = 0; i < k; i++){
        cin >> a >> b;
        unite(a-1, b-1, link, size, cost);
    }
    for(int i = 0; i < n; i++){
        // DP?
    }
}