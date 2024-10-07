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
typedef unsigned long long ull;

const int DEFAULTMOD = 1e9 + 7;


void markEagle(vector<vector<bool>> &isEagle, vector<vector<bool>> &visited, int i, int j){
    if(i < 0 || i >= isEagle.size() || j < 0 || j >= isEagle.size() || visited[i][j] || !isEagle[i][j]) return;
    visited[i][j] = true;
    markEagle(isEagle, visited, i-1, j);
    markEagle(isEagle, visited, i+1, j);
    markEagle(isEagle, visited, i, j-1);
    markEagle(isEagle, visited, i, j+1);
    if (i > 0 && j > 0) markEagle(isEagle, visited, i-1, j-1);
    if (i > 0 && j < isEagle.size()-1) markEagle(isEagle, visited, i-1, j+1);
    if (i < isEagle.size()-1 && j > 0) markEagle(isEagle, visited, i+1, j-1);
    if (i < isEagle.size()-1 && j < isEagle.size()-1) markEagle(isEagle, visited, i+1, j+1);
}

signed main(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int n;
    int counter = 1;
    while (cin >> n) {
        vector<vector<bool>> isEagle(n, vector<bool>(n, false));
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        for(int i = 0; i < n; i++){
            string s;
            cin >> s;
            for(int j = 0; j < n; j++){
                isEagle[i][j] = s[j] == '1';
            }
        }
        int count = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(isEagle[i][j] && !visited[i][j]){
                    count++;
                    markEagle(isEagle, visited, i, j);
                }
            }
        }
        cout << "Image number " << counter << " contains " << count << " war eagles.\n";
        counter++;
    }
}