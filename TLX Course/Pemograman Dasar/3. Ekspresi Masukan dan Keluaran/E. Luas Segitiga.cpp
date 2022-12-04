#include <iostream>

int main(){
    using namespace std;
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    float width, height;    
    cin >> width >> height;
    printf("%.2f", width * height / 2);
}