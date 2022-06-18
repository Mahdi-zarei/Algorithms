#include <bits/stdc++.h>
#define PB push_back
using namespace std;
const int maxn=1e5;
int w[maxn];
bool mark[maxn];
vector <int> v[maxn];
int path[maxn];
int daddy[maxn];
int ind[maxn];
int num[maxn];
int h[maxn];
int t=0;
void mrk() {
	for (int i=0;i<maxn;i++) {
		mark[i]=0;
	}
}
void sw() {
	for (int i=0;i<maxn;i++) {
		if (v[i].size()>1 && v[i][0]==daddy[i]) swap(v[i][0],v[i][1]); 
		for (int j=0;j<v[i].size();j++) {
			if (daddy[i]!=v[i][j] && w[v[i][j]]>w[v[i][0]]) swap(v[i][0],v[i][j]);
		}
	}
}
void dfsW(int x,int dad) {
	mark[x]=1;
	daddy[x]=dad;
	for (int i:v[x]) {
		if (mark[i]==0) {
			h[i]=h[x]+1;
			dfsW(i,x);
		}
	}
	if (dad!=-1) w[dad]+=w[x];
}
void dfsF(int x) {
	mark[x]=1;
	path[t++]=x;
	ind[x]=t-1;
	for (int i=0;i<v[x].size();i++) {
		int y=v[x][i];
		if (mark[y]==0) {
			if (i==0) num[y]=num[x]+1;
			else num[y]=0;
			dfsF(y);
		}
	}
}
int height(int x, int h) {
	if (h<0) return x;
	if (h>0 && x==0) return -1;
	if (num[x]>=h) return (path[ind[x]-h]);
	else height(daddy[x],h-num[x]-1);
}
int lca(int a,int b) {
	if (h[a]!=h[b]) {
		if (h[a]<h[b]) swap(a,b); 
		a=height(a,h[a]-h[b]);
	}
	if (a==b) return a;
	else {
		if (num[a]>num[b]) swap(a,b);
		a=height(a,num[a]+1);
		lca(a,b);
	}
}
int main() {
	int n;
	cin>>n;
	for (int i=0;i<n-1;i++) {
		int a,b;
		cin>>a>>b;
		v[a].PB(b);
		v[b].PB(a);
		w[i]=w[i+1]=1;
	}
	mrk();
	h[0]=0;
	dfsW(0,-1);
	mrk();
	sw();
	num[0]=0;
	dfsF(0);
	int a,b;
	cin>>a>>b;
	cout<<lca(a,b);
}
