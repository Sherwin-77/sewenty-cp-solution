#include <iostream>
#include <string>

int main(){
    // Testing this yourself won't show any output
    using namespace std;
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    string word;
    char buffer[4096];
    while(cin.read(buffer, sizeof(buffer))) word.append(buffer, sizeof(buffer));
    word.append(buffer, cin.gcount());
    cout << word;
}