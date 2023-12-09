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

// WIP
int main(){
    using namespace std;
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    int n, m, k, p, y, z;
    long long temp;
    cin >> n >> m >> k >> p >> y >> z;
    vector<vector<long long>> arr {vector<long long>(m), vector<long long>(k)};
    vector<vector<long long>> cur {vector<long long>(m), vector<long long>(k)};
    vector<vector<bool>> visited {vector<bool> (m, false), vector<bool> (k, false)};
    long long first = 0;
    for (int i = 0; i < n; i++){
        cin >> temp;
        first += temp;
    }
    for (int i = 0; i < m; i++) cin >> arr[0][i];
    for (int i = 0; i < k; i++) cin >> arr[1][i];
    sort(arr[0].begin(), arr[0].end());
    sort(arr[1].begin(), arr[1].end());
    for (int i = 0; i < m; i++) cur[0][i] = arr[0][i];
    for (int i = 0; i < k; i++) cur[1][i] = arr[1][i];

    long long ans = 0;
    long long future = ans;
    int pt0 = 0, pt1 = 0;
    while(p--){

    }

}