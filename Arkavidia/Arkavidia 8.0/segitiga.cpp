#include <iostream>
#include <vector>
#include <algorithm>

typedef unsigned long long ull;
typedef long long ll;

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
    ull n;
    ull drop;
    cin >> n;
    vector<ull> arr(n);
    for (ull i = 0; i < n; i++){
        cin >> arr[i] >> drop;
    }
    sort(arr.begin(), arr.end());
    ull ans = 0;
    ull diff = 0;
    ull same = 1;
    for (ull i = 1; i < arr.size(); i++){
        if(arr[i] != arr[i-1]){
            diff += same;
            same = 0;
        }
        ans += diff;
        same++;
    }
    cout << ans;
}