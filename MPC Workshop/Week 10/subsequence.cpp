#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>


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
    int n, s;
    while(cin >> n >> s){
        vector<int> arr(n);
        for(int i = 0; i < n; i++) cin >> arr[i];
        int res = INT32_MIN;
        int start = 0;
        int cur = 0;
        for(int end = start; end < n; end++){
            if(res != INT32_MIN){  // Sliding window?
                cur -= arr[start];
                start++;
            }
            cur += arr[end];
            while(cur >= s){
                res = end-start+1;  // Length has offset 1
                cur -= arr[start]; 
                start++;
            }
        }
        cout << max(res, 0) << '\n';
    }
}