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
    string s;
    cin >> n;
    cin >> s;
    int res = n, high = 0;
    for(int i = 1; i < n; i++){
        int copyLen = i-1;
        if(i + copyLen > n) break;
        if(s[i] != s[0]) continue;
        bool fax = true;
        for(int j = i; j <= i + copyLen; j++){
            // debug(s[j-i], "first", j-i);
            // debug(s[j], "second", j);
            if(s[j-i] != s[j]){
                fax = false;
                break;
            }
        }
        if(fax) high = copyLen;
    }
    cout << res - high;
}