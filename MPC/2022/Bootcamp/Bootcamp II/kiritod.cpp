#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<pair<int, int>> arr;
    int s, n;
    int strength, bonus;
    cin >> s >> n;
    for(int i = 0; i < n; i++){
        cin >> strength >> bonus;
        arr.push_back(make_pair(strength, bonus));
    }
    sort(arr.begin(), arr.end());
    for(auto &itr: arr){
        if(s <= itr.first){
            cout << "NO";
            return 0;
        }
        s += itr.second;
    }
    cout << "YES";
}
