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
    cin >> s;
    int cur = 0;
    int offset = 0;
    for(auto c: s) if(c == 'a') cur++;
    int remainder = s.size()-cur;
    if(cur <= remainder) offset = remainder-cur+1;
    cout << s.size()-offset;
}