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
    string s;
    int counter = 1;
    while(cin >> s){
        if(s == "*") return 0;
        cout << "Case " << counter++ << ": ";
        if(s == "Hajj") cout << "Hajj-e-Akbar\n";
        if(s == "Umrah") cout << "Hajj-e-Asghar\n";
    }
}