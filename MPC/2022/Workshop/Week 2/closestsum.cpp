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
    int n;
    int counter = 1;
    while(cin >> n){
        if(n == 0) break;
        vector<int> arr(n);
        for(int i = 0; i < n; i++) cin >> arr[i];
        sort(arr.begin(), arr.end());
        int t;
        cin >> t;
        cout << "Case " << counter++ << ":\n";
        for(int i = 0; i < t; i++){
            int target;
            int dist = INT32_MAX;
            int best = 0;
            cin >> target;
            int first = 0;
            int last = n-1;
            while(first < last){
                int temp = arr[first] + arr[last];
                if(temp == target){
                    best = target;
                    break;
                }
                if(abs(target-temp) < dist){
                    dist = abs(target-temp);
                    best = temp;
                }
                if(temp > target) last--;
                else first++; 
            }
            cout << "Closest sum to " << target << " is " << best << ".\n";
        } 
    }
}