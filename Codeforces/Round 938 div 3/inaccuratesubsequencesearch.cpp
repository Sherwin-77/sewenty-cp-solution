#include <iostream>
#include <algorithm>
#include <bitset>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <deque>
#include <queue>
#include <stack>
#include <string>

using namespace std;
// #define int long long

void fileIO(string fileName, string inExt=".in", string outExt=".out"){
    string fIn = fileName + inExt;
    string fOut = fileName + outExt; 
    freopen(fIn.c_str(), "r", stdin);
    freopen(fOut.c_str(), "w", stdout);
}

template <typename T>
void debug(T const &value, std::string valueName){
    cout << "DEBUG VALUE " << valueName << ": " << value << '\n';
}
template <typename T>
void debug(T const &value, std::string valueName, int index){
    cout << "DEBUG VALUE " << valueName << " INDEX " << index << ": " << value << '\n';
}

template <typename T>
void print(T const &value, bool newLine=true){
    cout << value;
    if(newLine) cout << '\n';
}


// Alternative
typedef long long ll;


signed main(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        /**
         * n - (Number of array)
         * m - (Number of array to compare)
         * k - (at least K of the subsegment match in the array to compare)
        */
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> arr(n);
        vector<int> compare(m);
        int max_ = 0;
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        for(int i = 0; i < m; i++){
            cin >> compare[i];
            max_ = max(max_, compare[i]);
        }
        vector<int> numberCount(max_ + 1, 0);
        vector<int> matchedNumberCount(max_ + 1, 0);
        vector<int> extraNumber(max_ + 1, 0);
        for(int x: compare) numberCount[x]++;
        int ans = 0;
        int currentMatch = 0;
        int start = 0;
        int end = start+m-1;
        bool currentLoopMatched = false;

        for(int i = start; i <= end; i++){
            int cur = arr[i];
            if(cur > max_) continue;
            if(numberCount[cur] > 0){
                if(matchedNumberCount[cur] < numberCount[cur]){
                    matchedNumberCount[cur]++;
                    currentMatch++;
                } else {
                    extraNumber[cur]++;
                }
            }
            if(currentMatch >= k && !currentLoopMatched){
                currentLoopMatched = true;
            }
        }
        if(currentLoopMatched) ans++;

        while(end < n-1){
            int front = arr[start];

            if(front <= max_ && numberCount[front] > 0){
                if(extraNumber[front] > 0){
                    extraNumber[front]--;
                } else {
                    matchedNumberCount[front]--;
                    currentMatch--;
                }
            }
            start++;
            end++;
            int back = arr[end];
            if(back <= max_ && numberCount[back] > 0){
                if(matchedNumberCount[back] < numberCount[back]){
                    matchedNumberCount[back]++;
                    currentMatch++;
                } else {
                    extraNumber[back]++;
                }
            }
            if(currentMatch >= k) ans++;
        }
        print(ans);
    }
}