#include <bits/stdc++.h>

#define PB push_back
#define ll long long


using namespace std;

vector <double> zero_vector(int m) {
	vector <double> ans;
	while(m--) ans.PB(0);
	return ans;
}

class Matrix {
	public :
		int n, m; //dimensions of the Matrix, n rows, m columns
		int det = -1; //variable to store the candidate determinant
		vector < vector <double> > V; //internal structure to store the Matrix
		
		//
		Matrix(int _n, int _m) {
			n = _n;
			m = _m;
			while(_n--) V.PB(zero_vector(m));
		}
		
		Matrix (int _n, int _m, vector <vector <double> > _V) {
			n = _n;
			m = _m;
			V = _V;
		}
		
		Matrix (int _n, int _m, double arr[]) {
			n = _n;
			m = _m;
			for (int i=0;i<n;i++) {
				vector <double> tmp;
				for (int j=0;j<m;j++) {
					tmp.PB(arr[i * m + j]);
				}
				V.PB(tmp);
			}
		}
		
		void print() {
			cout<<"Size is "<<n<<" * "<<m<<endl;
			cout<<"The Matrix is"<<endl;
			for (int i=0;i<n;i++) {
				for (double y:V[i]) cout<<setprecision(2)<<fixed<<y<<" ";
				cout<<endl;
			}
		}
		
		vector <double> operator [](int i) const {
			return V[i];
		}
		
		vector <double> &operator [](int i) {
			return V[i];
		}
		
		Matrix operator +(Matrix const &B) {
			assert(n == B.n && m == B.m);
			Matrix result(n, m);
			for (int i=0;i<n;i++) {
				for (int j=0;j<m;j++) {
					result.V[i][j] += V[i][j] + B.V[i][j];
				}
			}
			return result;
		}
		
		Matrix operator -(Matrix const &B) {
			assert(n == B.n && m == B.m);
			Matrix result(n, m);
			for (int i=0;i<n;i++) {
				for (int j=0;j<m;j++) {
					result.V[i][j] += V[i][j] - B.V[i][j];
				}
			}
			return result;
		}
		
		Matrix operator *(Matrix const &B) {
			assert(m == B.n);
			Matrix result(n, B.m);
			for (int i=0;i<n;i++) {
				for (int j=0;j<B.m;j++) {
					for (int x=0;x<m;x++) {
						result.V[i][j] += V[i][x] * B.V[x][j];
					}
				}
			}
			return result;
		}
		
		bool operator ==(Matrix const &B) {
			if (n == B.n && m == B.m) {
				for (int i=0;i<n;i++) {
					for (int j=0;j<m;j++) {
						if (V[i][j] != B.V[i][j]) return false;
					}
				}
				return true;
			}
			return false;
		}
		
		int trailing_zeros(int ind) {
			int ans=0;
			for (auto y:V[ind]) {
				if (y==0) ans++;
				else break;
			}
			return ans;
		}
			
		int longest_row(int b) {
			int mx=trailing_zeros(b);
			int ind=b;
			for (int i=b;i<n;i++) {
				int tmp = trailing_zeros(i);
				if (tmp < mx) {
					mx = tmp;
					ind = i;
				}
			}
			return ind;
		}
		
		Matrix to_echelon() {
			int _det = 1;
			Matrix result(n, m, V);
			for (int i=0;i<n;i++) {
				int target = result.longest_row(i);
				if (target != i) {
					_det *= -1;
					for (int j=0;j<m;j++) swap(result[i][j], result[target][j]);
				}
				int ind = result.trailing_zeros(i);
				for (int j=i+1;j<n;j++) {
					if (ind == m) break;
					const double val = result[j][ind];
					for (int x=ind;x<m;x++) {
						result[j][x] -= ((long double)(val*result[i][x]) / result[i][ind]);
						if (fabs(result[j][x]) < 0.01) result[j][x] = 0;
					}
				}
			}
			for (int i=0;i<n && i<m;i++) {
				_det *= result[i][i];
			}
			det = _det;
			return result;
		}
		
		Matrix to_reduced() {
			Matrix result = to_echelon();
			for (int i=n-1;i>=0;i--) {
				int ind = result.trailing_zeros(i);
				for (int j=i-1;j>=0;j--) {
					if (ind == m) break;
					const double val = result[j][ind];
					for (int x=ind;x<m;x++) {
						result[j][x] -= ((long double)(val*result[i][x]) / result[i][ind]);
						if (fabs(result[j][x]) < 0.01) result[j][x] = 0;
					}
				}
				for (int j=m-1;j>=ind;j--) if (result[i][j] != 0) result[i][j] /= result[i][ind];
			}
			return result;
		}
		
		int determinant() {
			assert(n == m);
			to_echelon();
			return det;
		}
};

Matrix read_input() {
	int n,m;
	cin>>n>>m;
	double arr[n*m];
	for (int i=0;i<n;i++) {
		for (int j=0;j<m;j++) cin>>arr[i*m+j];
	}
	Matrix tmp(n,m,arr);
	return tmp;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	Matrix tmp = read_input();
	//Matrix tmp2 = read_input();
	//Matrix tmp3 = tmp * tmp2;
	cout<<tmp.determinant()<<endl;
}
