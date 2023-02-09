#include <iostream>
#include <unordered_map>

int main(){
    using namespace std;
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
	int n, temp, maxCount = 0, maxNumber;
	unordered_map<int, int> arr;
	cin >> n;
		
	for(int i = 0; i < n; i++){
		cin >> temp;
		
		if(arr.find(temp) != arr.end()) arr[temp] += 1;
		else arr.insert({temp, 1});
		
		if (arr[temp] > maxCount || arr[temp] == maxCount && temp > maxNumber){
			maxNumber = temp;
			maxCount = arr[temp];
		}
	}
	
	cout << maxNumber;
}