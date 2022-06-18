#include <bits/stdc++.h>
#define ll long long
#define PB push_back
#define F first
#define S second
#define MP make_pair
#define pii pair <int,int> 
#define pll pair <ll,ll>
using namespace std;
vector <pair <string,char> > ans;
int n;
string path;
void f(vector <pair <int,char> > e[],int x) {
	path+="1";
	if (e[x][0].S<0) f(e,e[x][0].S+128);
	else ans.PB(MP(path,e[x][0].S));
	path.pop_back();
	path+="0";
	if (e[x][1].S<0) f(e,e[x][1].S+128);
	else ans.PB(MP(path,e[x][1].S));
	path.pop_back();
}
int main() {
	string s;
	cin>>s;
	vector <pair <int,char> > v;
	for (char y:s) {
		bool d=0;
		for (int i=0;i<v.size();i++) {
			if (v[i].S==y) {
				d=1;
				v[i].F++;
			}
		}
		if (!d) v.PB(MP(1,y)); 
	}
	n=v.size()-1;
	vector <pair <int,char> > p[n];
	int last=n-1;
	while (v.size()>1) {
		int y=v.size();
		sort(v.rbegin(),v.rend());
		p[last].PB(v[y-1]);
		p[last].PB(v[y-2]);
		last--;
		int tmp=v[y-1].F+v[y-2].F;
		v.pop_back();
		v.pop_back();
		v.PB(MP(tmp,last+129));
	}
	f(p,0);
}
