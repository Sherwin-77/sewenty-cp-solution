#include <iostream>
#include <math.h>

int main(){
    using namespace std;
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
	int n;
	double m;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> m;
		int nT = ceil(m/4);
		int nU = ceil((m-1)/4);
		int nB = ceil((m-2)/4);
		int nS = ceil((m-3)/4);
		int t = -nT + 2 * (nT * nT);
		int u = (4 * (nU * nU))/2;
		int b = nB + 2 * (nB * nB);
		int s = 2 * nS + 2 * (nS * nS);
		cout << "Timurs\t: " << nT << '\n';
		cout << "Utara\t: " << nU << '\n';
		cout << "Barat\t: " << nB << '\n';
		cout << "Selatan\t: " << nS << '\n';
		//cout << "Timur\t: " << t << '\n';
		//cout << "Utara\t: " << u << '\n';
		//cout << "Barat\t: " << b << '\n';
		//cout << "Selatan\t: " << s << '\n';
	}
}