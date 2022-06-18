#include <bits/stdc++.h>
#define ll long long
#define PB push_back
#define F first
#define S second
#define MP make_pair
#define pii pair <int,int> 
#define pll pair <ll,ll>
using namespace std;
struct node {
	node* left0=NULL;
	node* right1=NULL;
	bool mark=0;
	char letter;
};
void treemaker (vector <pair <string,char> > v,node* x) {
	for (auto y:v) {
		node* tmp=x;
		for (char c:y.F) {
			if (c=='0') {
				if (tmp->left0==NULL) {
					node* nn=new node;
					tmp->left0=nn;	
				}
				tmp=tmp->left0;
			}
			if (c=='1') {
				node* nn=new node;
				if (tmp->right1==NULL) {
					tmp->right1=nn;
				}
				tmp=tmp->right1;
			}
		}
		tmp->mark=1;
		tmp->letter=y.S;
	}
}
string path;
void pr(node* x) {
	if (x->mark==1) cout<<path<<" "<<x->letter<<endl;
	else {
		if (x->left0!=NULL) {
			path+="0";
			pr(x->left0);
			path.pop_back();
		}
		if (x->right1!=NULL) {
			path+="1";
			pr(x->right1);
			path.pop_back();
		}
	}
}
int main() {
	node* head=new node;
	vector <pair <string,char> > v;
	for (int i=0;i<4;i++) {
		string s;
		char c;
		cin>>s>>c;
		v.PB(MP(s,c));
	}
	treemaker(v,head);
	pr(head);
}
