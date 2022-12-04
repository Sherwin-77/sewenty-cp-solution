#include <iostream>
#include <vector>


int main()
{
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // Variable used
    int h, w, n, temp;

    // start input
    cin >> h >> w >> n;

    // Logic here
    int curHeight = 0;
    int curWidth = 0;
    bool complete = false;
    while(n--){
        if(curHeight >= h) break;
        cin >> temp;
        curWidth += temp;
        if(curWidth == w){
            ++curHeight;
            curWidth = 0;
        }

        if (curWidth > w) break;
        
        if(curHeight == h){
            complete = true;
        }
    }
    cout << (complete ? "YES":"NO") << '\n';
}
