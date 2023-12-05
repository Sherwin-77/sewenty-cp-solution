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

// FIXME: TLE
int main(){
    using namespace std;
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    int t;
    int n, m;
    int a, b;
    int count;
    int res, mult;
    vector<short> arr;
    string command;
    cin >> t;
    for(int x = 1; x <= t; x++){
        cin >> n >> m;
        arr = vector<short>(n);
        for(int i = 0; i < n; i++) cin >> arr[i];
        for(int y = 0; y < m; y++){
            cin >> command >> a >> b;
            a--; b--;
            if(command == "flip"){
                // for(int i = a; i <= b; i++) arr[i] ^= 1;
            }
            if(command == "sort"){
                // count = 0;
                // for(int i = a; i <= b; i++){
                //     if(arr[i] == 1) count++;
                //     arr[i] = 0;
                // }
                // for(int i = b; i >= a && count > 0; i--){
                //     arr[i] = 1;
                //     count--;
                // }
            }
        }
        res = 0;
        mult = 0;
        for(auto x: arr){
            if(x == 1) mult++;
            if(x == 0) res += mult;
        }
        cout << "Case #" << x << ": " << res << '\n';
    }
}