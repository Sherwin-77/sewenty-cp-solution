#include <iostream>
#include <string>

int main()
{
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string word;
    while(getline(cin, word)){
        cout << word << '\n';
    }
}
