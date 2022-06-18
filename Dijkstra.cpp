#include <bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define INF 2147483647
using namespace std;
const int maxn=1e5;
vector <pair <int,int> > v[maxn];
int len[maxn];
bool mark[maxn];
priority_queue<pair <int,int> > q;
void alg (int x) {
	len[x]=0;
	q.push(MP(0,x));
	while (!q.empty()) {
		int ver=q.top().S;
		int w=len[ver];
		q.pop();
		if (mark[ver]==1) {
			continue;
		}
		mark[ver]=1;
		for (auto y:v[ver]) {
			if (w+y.F<len[y.S]) {
				len[y.S]=w+y.F;
				q.push(MP(-len[y.S],y.S));
			}
		}
	}
}
int main() {
	for (int i=0;i<maxn;i++) {
		len[i]=INF;
		mark[i]=0;
	}
	int n;
	cin>>n;
	int m;
	cin>>m;
	for (int i=0;i<m;i++) {
		int a,b,w;
		cin>>a>>b>>w;
		v[a].PB(MP(w,b));
		v[b].PB(MP(w,a));
	}
	alg(0);
	for (int i=0;i<n;i++) {
		cout<<len[i]<<endl;
	}
}
