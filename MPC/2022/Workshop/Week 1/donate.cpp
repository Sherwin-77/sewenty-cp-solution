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
    cin >> n;
    string command;
    int cur = 0;
    int tmp;
    for(int i = 0; i < n; i++){
        cin >> command;
        if(command == "donate"){
            cin >> tmp;
            cur += tmp;
        }
        if(command == "report"){
            cout << cur << '\n';
        }
    }
}