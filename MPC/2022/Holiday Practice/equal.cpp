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
    int row, col;
    cin >> row >> col;
    int n = row * col;
    vector<int> arr(n);
    int target = INT32_MAX;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        target = min(target, arr[i]);
    }
    int res = 0;
    for(int i = 0; i < n; i++){
        res += arr[i]-target;
    }
    cout << res;
}