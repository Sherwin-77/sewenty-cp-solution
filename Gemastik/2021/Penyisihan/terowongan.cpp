#include <iostream>
#include <algorithm>
#include <set>

int cost[10001], link[10001];

int find(int x){
	while(x != link[x]) x = link[x];
	return x;
}

bool same(int a, int b){
	return find(a) == find(b);
}

void unite(int a, int b){
	a = find(a);
	b = find(b);
	if(a == b) return;
	if(cost[a] < cost[b]) std::swap(a, b);
	cost[a] += cost[b];
	link[b] = a;
}

int main(){
    using namespace std;
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
	int n, k;
	int a, b;
	int res = 0;
	multiset<int, greater<int>> total;
	cin >> n >> k;
	
	for(int i = 0; i < n; i++){
		cin >> cost[i];
		link[i] = i;
	}
	for(int i = 0; i < k; i++){
		cin >> a >> b;
		unite(a-1, b-1);
	}
	for(int i = 0; i < n; i++){
		if(link[i] == i) total.insert(cost[i]);
	}
	int counter = 1;
	for(auto n: total){
		res += n * counter++;
	}
	cout << res;
}
