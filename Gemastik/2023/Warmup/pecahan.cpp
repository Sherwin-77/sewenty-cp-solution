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
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    long long topA = a * d;
    long long topB = b * c;
    if(topA > topB) cout << "lebih besar";
    else if(topA < topB) cout << "lebih kecil";
    else cout << "sama";
}