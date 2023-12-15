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
    char a, b;
    int score = 0;
    while(cin >> a >> b){
        switch (a){
        case 'A':
            switch(b){
                case 'X':
                    score += 4;
                    break;
                case 'Y':
                    score += 8;
                    break;
                case 'Z':
                    score += 3;
                    break;
            }
            break;

        case 'B':
            switch(b){
                case 'X':
                    score += 1;
                    break;
                case 'Y':
                    score += 5;
                    break;
                case 'Z':
                    score += 9;
                    break;
            }
            break;

        case 'C':
            switch(b){
                case 'X':
                    score += 7;
                    break;
                case 'Y':
                    score += 2;
                    break;
                case 'Z':
                    score += 6;
                    break;
            }
            break;
        }
    }
    cout << score;
}