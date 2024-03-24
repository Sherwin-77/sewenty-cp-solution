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
    bool tsun = true;
    cin >> n;
    for(int i = 0; i < n; i++){
        if(tsun) cout << "I hate ";
        else cout << "I love ";

        if(i < n-1) cout << "that ";
        else cout << "it";

        tsun ^= 1;
    }
}