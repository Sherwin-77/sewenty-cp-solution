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
    int n, k;
    cin >> n >> k;
    string s;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    if(k >= n){
        for(int i = 0; i < n; i++) cout << "0 ";
    } else {
        for(int i = k; i < n; i++) cout << arr[i] << ' ';
        for(int i = 0; i < k; i++) cout << "0 ";
    }
}