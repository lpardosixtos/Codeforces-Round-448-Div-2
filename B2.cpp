#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int > > A;
int k;

int binSearch(int m, int start, int end){
	int med=start+(end-start)/2;
	if(A[m].second==0){
		while(start<end-1){
			if(A[med].first-A[m].first+1<k) start=med;
			else end=med;
			med=start+(end-start)/2;
		}
		if(A[start].first-A[m].first+1==k) return start;
		if(A[end].first-A[m].first+1==k) return end;
		return -1; 
	}
	else{
		while(start<end-1){
		if(A[med].first-A[m].first<k) start=med;
		else end=med;
		med=start+(end-start)/2;
		}
		if(A[start].first-A[m].first==k) return med;
		if(A[end].first-A[m].first==k) return med+1;
		return -1;
	}
}

int binSearchSame(int m,int start, int end){
	int med=start+(end-start)/2;
	while(start<end-1){
		if(A[med]==A[m]) start=med;
		else end=med;
		med=start+(end-start)/2;
	}
	if(A[end]==A[m]) return end;
	return start;
}

int binSearchSecond(int m, int start, int end){
	int med=start+(end-start)/2;
	while(start<end-1){
		if(A[med].first==A[m].first) start=med;
		else end=med;
		med=start+(end-start)/2;
	}
	if(A[end].first==A[m].first) return end;
	return start;
}
	


int main(void){

	int n, x;
	cin >>n >> x >> k;
	for(int i=0; i<n; i++){
		int aux, aux1;
		cin >> aux;
		aux1=aux;
		aux/=x;
		aux1=aux1-(x*aux);
		pair<int , int > p=make_pair(aux, aux1);
		A.push_back(p);
	}
	sort(A.begin(), A.end());
	long long int ans=0;
	for(int i=0; i<n; i++){
		int aux=binSearch(i, i, n-1);
		if(aux!=-1){
			int next=aux;
			int cont=0;
			if(next==i){
				next=binSearchSame(i, i, n-1)+1;
				cont=next-i;
				ans+=2*cont;
				ans--;
			}
			if(next<n && A[next].first==A[aux].first){
				cont=binSearchSecond(next, next, n-1)-next+1;
				ans+=cont;
			}
			
		}		
	}
	cout << ans << "\n";

	return 0;
}