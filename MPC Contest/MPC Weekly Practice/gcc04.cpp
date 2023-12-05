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
    int x, y;
    cin >> x >> y;
    for(int year = x; year <= y; year += 5){
        if(!((year-x) % 3) && !((year-x) % 4)) cout << "All positions change in year " << year << '\n';
    }
}