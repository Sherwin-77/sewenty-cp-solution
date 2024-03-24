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
    int n, tmp;
    cin >> n;
    vector<bool> exist(n, false);
    for(int i = 0; i < n-1; i++){
        cin >> tmp;
        exist[tmp-1] = true;
    }
    for(int i = 0; i < n; i++){
        if(!exist[i]){
            cout << i+1;
            return 0;
        }
    }
}