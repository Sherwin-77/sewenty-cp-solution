#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>


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
    int cur = 0;
    int first = 0, second = 0, third = 0;
    while(getline(cin, s)){
        // cout << "->";
        // cout << s << '\n';
        if(!s.size()){
            if(cur >= first){
                third = second;
                second = first;
                first = cur;
            } else if(cur >= second){
                third = second;
                second = cur;
            } else if(cur > third) third = cur;
            cur = 0;
        } else {
            istringstream ss(s);
            int tmp;
            ss >> tmp;
            cur += tmp;
        }
    }
    cout << first+second+third;
}