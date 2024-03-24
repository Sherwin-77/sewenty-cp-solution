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
    int n, m;
    int tmp;
    cin >> n >> m;
    vector<int> arr(n);
    int total = 0;
    for(int i = 0; i < n; i++) cin >> arr[i];
    for(int i = 0; i < m; i++){
        cin >> tmp;
        total += arr[tmp-1];
    }
    cout << total;
}