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
    int t, n, a;
    cin >> t;
    for(int x = 1; x <= t; x++){
        cin >> n;
        vector<int> arr(n);
        int total = 0;
        int cur = 0;
        int res = 0;
        for(int y = 0; y < n; y++){
            cin >> arr[y];
            total += arr[y];
        }
        sort(arr.begin(), arr.end(), greater<int>());
        while(cur < total){
            cur += arr[res];
            total -= arr[res];
            res++;
        }
        cout << "Case #" << x << ": " << res << '\n';
    }
}