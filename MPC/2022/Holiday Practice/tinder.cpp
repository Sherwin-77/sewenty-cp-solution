#include <iostream>
#include <vector>
#include <algorithm>
#include <set>


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
    set<char> hashmap;
    string s;
    cin >> s;
    for(auto c: s) hashmap.insert(c);
    cout << (hashmap.size() % 2 == 0 ? "CHAT WITH HER!" : "IGNORE HIM!");
}