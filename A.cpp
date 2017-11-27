#include <bits/stdc++.h>

using namespace std;

int main(void){

	int pieces;
	cin >> pieces;

	int acum[2*pieces];
	cin >> acum[0];
	acum[pieces]=acum[0]+360;
	for(int i=1; i<pieces; i++){
		cin >> acum[i];
		acum[i]+=acum[i-1];
		acum[i+pieces]=acum[i]+360;
	}
	if(pieces==1) cout << 360 << "\n";
	else{
		
		int ans=361;
		for(int i=0; i<pieces; i++){
			for(int j=i+1; j<i+pieces; j++){
				int aux=abs(360-2*(acum[j]-acum[i]));
				ans=min(ans, aux);
			}
		}
		cout << ans << "\n";

	}
	return 0;
	
}