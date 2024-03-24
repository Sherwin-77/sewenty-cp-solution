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
    int n, d;
    while(cin >> n >> d){
        vector<vector<int>> arr(n+1, vector<int> (n, 0));
        arr[0][0] = 1;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= d; j++){
                arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
            }
        }
        cout << arr[n][d];
    }
}