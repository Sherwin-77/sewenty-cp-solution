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
    int t, n;
    cin >> t;
    for(int x = 1; x <= t; x++){
        cin >> n;
        vector<long long> arr(n);
        for(int i = 0; i < n; i++) cin >> arr[i];
        cout << "Case #" << x << ": ";
        long long best = 0;
        for(int i = n-1; i >= 0; i--) best = abs(best) + arr[i];
        if(best > 0) cout << "Oski\n";
        else if(best < 0) cout << "Ikro\n";
        else cout << "Draw\n";
    }
}