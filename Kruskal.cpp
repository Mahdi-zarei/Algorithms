#include <bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define INF 2147483647
using namespace std;
const int maxn=1e5;
int arr[maxn];
int siz[maxn];
vector< pair <int,int> > v;
int find (int x) {
	while (x!=arr[x]) x=arr[x];
	return x;
}
void unite (int a,int b) {
	a=find(a);
	b=find(b);
	if (siz[a]<siz[b]) swap(a,b);
	siz[a]+=siz[b];
	arr[b]=a; 
}
bool same(int a,int b) {
	return find(a)==find(b);
}
bool comp(const tuple <int,int,int> &a,const tuple <int,int,int> &b) {
	int f,s;
	tie(ignore,ignore,f)=a;
	tie(ignore,ignore,s)=b;
	return s>f;
}
int kruskal (vector <tuple <int,int,int> > &edge,int n) {
	int count=0;
	int last=0;
	int ans=0;
	while (count!=n-1) {
		int a,b,w;
		tie(a,b,w)=edge[last];
		if (!same(a,b)) {
			v.PB(MP(a,b));
			unite(a,b);
			ans+=w;
			count++;
		}
		last++;
	}
	return ans;
}
int main() {
	int n;
	cin>>n;
	int m;
	cin>>m;
	for (int i=0;i<n;i++) {
		arr[i]=i;
		siz[i]=1;
	}
	vector <tuple <int,int,int> > edge;
	for (int i=0;i<m;i++) {
		int a,b,c;
		cin>>a>>b>>c;
		edge.PB({a,b,c});
	}
	sort(edge.begin(),edge.end(),comp);
	int ans=kruskal(edge,n);
	cout<<ans<<endl;
	for (auto y:v) {
		cout<<y.F<<" "<<y.S<<endl;
	}
}
