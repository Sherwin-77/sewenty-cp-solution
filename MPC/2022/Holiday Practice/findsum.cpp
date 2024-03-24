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

int main(){
    using namespace std;
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    int n, target;
    int tmp;
    cin >> n >> target;
    vector<pair<int, int>> arr(n);
    for(int i = 0; i < n; i++){
        cin >> tmp;
        arr[i] = make_pair(tmp, i);
    }
    sort(arr.begin(), arr.end());
    int i = 0;
    int j = n-1;
    bool found = false;
    pair<int, int> res;
    while(i < j){
        if(arr[i].first + arr[j].first == target){
            found = true;
            res = make_pair(arr[i].second+1, arr[j].second+1);
            break;
        } else if(arr[i].first + arr[j].first < target) i++;
        else j--;
    }
    if(!found) cout << "IMPOSSIBLE";
    else cout << min(res.first, res.second) << ' ' << max(res.first, res.second);
}