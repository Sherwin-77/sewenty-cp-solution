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
    int n;
    cin >> n;
    for(int x = 0; x < n; x++){
        vector<string> arr(8);
        for(int i = 0; i < 8; i++){
            string s;

            cin >> s;
            arr[i] = s;
        }
        // for(string t: arr){
        //     cout << t << '\n';
        // }
        bool found = false;
        for(int i = 0; i < 8; i++){
            bool streak = true;
            for(int j = 0; j < 8; j++){
                if(arr[i][j] != 'R'){
                    streak = false;
                    break;
                }
            }
            if(streak){
                cout << 'R' << '\n';
                found = true;
                break;
            }
        }
        if(!found){
            for(int j = 0; j < 8; j++){
                bool streak = true;
                for(int i = 0; i < 8; i++){
                    if(arr[i][j] != 'B'){
                        streak = false;
                        break;
                    }
                }
                if(streak){
                    cout << 'B' << '\n';
                    found = true;
                    break;
                }
            }
        }
    }
}