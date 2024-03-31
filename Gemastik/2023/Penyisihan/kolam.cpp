#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

template <typename T>
void debug(T const &value, std::string valueName) {
    std::cout << "DEBUG VALUE " << valueName << ": " << value << '\n';
}

template <typename T>
void debug(T const &value, std::string valueName, int index) {
    std::cout << "DEBUG VALUE " << valueName << " INDEX " << index << ": " << value << '\n';
}

using namespace std;

pair<int, long long> find(int x, vector<int> &link, vector<long long> &cost) {
    long long minCost = cost[x];
    while (x != link[x]) {
        x = link[x];
        minCost = min(minCost, cost[x]);
    }
    return {x, minCost};
}

// bool same(int a, int b, vector<int> &link) {
//     return find(a, link) == find(b, link);
// }

int unite(int a, int b, vector<int> &link, vector<long long> &size, vector<long long> &cost) {
    auto resA = find(a, link, cost);
    auto resB = find(b, link, cost);
    a = resA.first;
    b = resB.first;
    if(a == b) return a;
    long long minCost = min(resA.second, resB.second);
    if (size[a] < size[b]) swap(a, b);
    size[a] += size[b];
    link[b] = a;

    int x = a;
    while (x != link[x]) {
        x = link[x];
    }
    cost[x] = minCost;
    return x;
}

pair<long long, int> diveToRoot(int x, vector<int> &link, vector<long long> &cost, vector<bool> &visited) {
    if (visited[x]) return {-1, -1};
    while (x != link[x] && !visited[x]) {
        visited[x] = true;
        x = link[x];
        if(visited[x]) return {-1, -1};
    }
    visited[x] = true;
    return {cost[x], x};
}

int topIndex = -1;
long long topMinCost = -1;

struct Data {
    int index;
    long long size;
    long long cost;

    Data(int index, long long size, long long cost)
        : index(index), size(size), cost(cost) {}

    long long getTotalCost() const {
        return size * cost;
    }

    bool operator<(const Data& other) const {
        long long otherTotalCost = other.getTotalCost();
        long long thisTotalCost = getTotalCost();
        if(topIndex == -1) return index < other.index;
        return (thisTotalCost - (topMinCost * size) < (otherTotalCost - (topMinCost * other.size)));
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    long long n, k, B;
    int a, b;
    cin >> n >> k >> B;
    vector<int> link(n);
    vector<long long> size(n, 1);
    vector<long long> cost(n);
    vector<bool> visited(n, false);
    priority_queue<Data> pq;
    for (int i = 0; i < n; i++) {
        cin >> cost[i];
        link[i] = i;
    }
    for (int i = 0; i < k; i++) {
        cin >> a >> b;
        unite(a - 1, b - 1, link, size, cost);
    }

    for(int i = 0; i < n; i++){
        auto [curCost, curIndex] = diveToRoot(i, link, cost, visited);
        if(curIndex == -1) continue;
        if(topIndex == -1 || curCost < topMinCost){
            topMinCost = curCost;
            topIndex = curIndex;
        }
        // cout << "PUSH " << curIndex << ": " << size[curIndex] << " " << cost[curIndex] << "\n";
        pq.push(Data(curIndex, size[curIndex], cost[curIndex]));
    }
    
    while(B-- && !pq.empty()){
        Data cur = pq.top();
        // cout << cur.index << ": " << cur.size << " " << cur.cost << "\n";
        pq.pop();
        if(cur.index == topIndex) continue;
        topIndex = unite(topIndex, cur.index, link, size, cost);
    }

    long long ans = 0;

    while(!pq.empty()){
        Data cur = pq.top();
        pq.pop();
        if(cur.index == topIndex) continue;
        if(cur.getTotalCost() < 0) terminate();
        ans += cur.getTotalCost();
    }
    if(cost[topIndex] * size[topIndex] < 0) terminate();
    ans += cost[topIndex] * size[topIndex];
    if(ans < 0) terminate();

    cout << ans;
}
