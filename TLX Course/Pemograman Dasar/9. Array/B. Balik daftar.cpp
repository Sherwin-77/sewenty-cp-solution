#include <iostream>
#include <vector>

int main(){
    using namespace std;
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
	vector<int> arr;
	int temp;
	while(cin >> temp) arr.push_back(temp);
	for(auto it = arr.rbegin(); it != arr.rend(); it++) cout << *it << '\n';
}