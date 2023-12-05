#include <iostream>
#include <vector>
#include <algorithm>
#include <map>


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
    map<char, map<char, string>> table1;
    map<char, map<char, string>> table2;

    table1['A'] = {{'A', "AB"}, {'B', "DC"}, {'C', "CC"}, {'D', "CB"}};
    table1['B'] = {{'A', "CA"}, {'B', "DA"}, {'C', "CD"}, {'D', "DD"}};
    table1['C'] = {{'A', "BC"}, {'B', "AA"}, {'C', "BA"}, {'D', "DB"}};
    table1['D'] = {{'A', "BD"}, {'B', "AD"}, {'C', "BB"}, {'D', "AC"}};

    table2['A'] = {{'A', "CD"}, {'B', "BB"}, {'C', "AC"}, {'D', "CC"}};
    table2['B'] = {{'A', "CB"}, {'B', "DB"}, {'C', "AD"}, {'D', "DD"}};
    table2['C'] = {{'A', "DA"}, {'B', "DC"}, {'C', "BC"}, {'D', "BD"}};
    table2['D'] = {{'A', "AA"}, {'B', "BA"}, {'C', "CA"}, {'D', "AB"}};

    map<string, string> decodeTable1;
    map<string, string> decodeTable2;
    string cur;

    for (char c1 = 'A'; c1 <= 'D'; c1++) {
        for (char c2 = 'A'; c2 <= 'D'; c2++) {
            cur = c1;
            cur += c2;
            decodeTable1[table1[c1][c2]] = cur;
            decodeTable2[table2[c1][c2]] = cur;
        }
    }


    string s, ab;
    string res="";
    char a, b;
    cin >> s;
    for(int i=0; i < s.length(); i+=2){\
        ab = s[i];
        ab += s[i+1];
        res += decodeTable1[decodeTable2[ab]];
    }
    cout << res;
}