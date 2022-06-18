#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5;
vector <int> v[maxn];
vector <char> link;
vector <bool> marker;
int num=0;
int inc(char c,int x) {
	for (int y:v[x]) {
		if (link[y]==c) return y;
	}
	return -1;
}
void adder(string s) {
	int last=0;
	int tmp=0;
	for (int i=0;i<s.size();i++) {
		if (tmp==-1) {
			num++;
			v[last].push_back(num);
			link.push_back(s[i]);
			marker.push_back(false);
			last=num;
		}
		else {
			last=tmp;
			tmp=inc(s[i],last);
			if (tmp==-1) i--;
		}
	}
	marker[last]=true;
}
bool finder(string s) {
	int last=0;
	for (int i=0;i<s.size();i++) {
		last=inc(s[i],last);
		if (last==-1) return false;
	}
	return marker[last];
}
int main() {
	link.push_back(' ');
	marker.push_back(false);
	int n;
	cin>>n;
	for (int i=0;i<n;i++) {
		string s;
		cin>>s;
		adder(s);
	}
	cout<<"q num"<<endl;
	int q;
	cin>>q;
	for (int i=0;i<q;i++) {
		string s;
		cin>>s;
		cout<<(finder(s) ? "exists" : "does not exist")<<endl;
	}
}
