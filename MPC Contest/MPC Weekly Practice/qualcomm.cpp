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
    int n, k;
    string s;
    string ns = "";
    cin >> n >> k;
    cin >> s;
    for(char c: s){
        ns += c;
        if(c == 'o') k--;
        if(!k){ns += string(s.length()-ns.length(), 'x'); break;}
    }
    cout << ns;
}