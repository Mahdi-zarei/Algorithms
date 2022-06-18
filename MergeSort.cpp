#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

void merge(int arr[],int b,int e,int m) {
	int p1=b,p2=m;
	int tmp[e-b+1];
	for (int i=0;i<e-b+1;i++) {
		if (p1==m) tmp[i]=arr[p2++];
		else if (p2==e+1) tmp[i]=arr[p1++];
		else {
			(arr[p1]>arr[p2]) ? tmp[i]=arr[p2++] : tmp[i]=arr[p1++];
		}
	}
	for (int i=0;i<e-b+1;i++) {
		arr[b+i]=tmp[i];
	}
}

void Sort (int arr[],int b,int e) {
	int n=e-b+1;
	if (n<=2) {
		if (arr[e]<arr[b]) swap(arr[e],arr[b]);
		return;
	}
	Sort(arr,b,b+n/2);
	Sort(arr,b+n/2 +1,e);
	merge(arr,b,e,b+n/2 +1);
}

int main() {
	ios::sync_with_stdio(false);
	srand(time(NULL));
	int n;
	cin>>n;
	int arr[n];
	for (int i=0;i<n;i++) {
		arr[i]=rand()%(3*n);
	}
	auto start = high_resolution_clock::now();
	Sort(arr,0,n-1);
	auto stop = high_resolution_clock::now();
	for (int i=0;i<n;i++) {
		cout<<arr[i]<<" ";
	}
	
}
