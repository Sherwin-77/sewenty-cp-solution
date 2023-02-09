#include <iostream>
#include <cmath>

int main(){
    using namespace std;
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
	int x1, x2, y1, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	cout << abs(x1-x2) + abs(y1-y2);
}