#include <iostream>
#include <vector>

int main(){
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);

    int n, m, temp;
	vector <vector<int>> arr;
	vector <int> sub;

    cin >> n >> m;

    for(int i = 0; i < n; i++){
        for(int j=0; j<m; j++){
            cin >> temp;
           sub.push_back(temp);
        }
        arr.push_back(sub);
		sub.clear();
    }

    for(int i = 0; i < m; i++){
        for(int j = n-1; j >= 0; j--){
            cout << arr[j][i] << ' ';
        }
        cout << '\n';
    }
}