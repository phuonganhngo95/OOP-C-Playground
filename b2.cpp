//Bài 2: Một phân số được biểu diễn dưới dạng t/m. 
//Viết chương trình nhập  vào n phân số (n nguyên dương nhập từ 
//bàn phím) và tính tổng các phân số đó.

#include<iostream>

using namespace std;
class PS {
	protected:
		int t, m;
	public:
		int UCLN(int a, int b) {
			while(a * b != 0) {
				if(a > b) {
					a %= b;
				} else {
					b %= a;
				}
			}
			return a + b;
		}
		
		void Rutgon() {
			int ucln = UCLN(t, m);
			t /= ucln;
			m /= ucln;
		}
		
		void Nhap();
		void Xuat();
		
		PS Tong(PS other) {
			PS tong;
			tong.t = t*other.m + other.t*m;
			tong.m = m * other.m;
			tong.Rutgon();
			return tong;
		}
};

void PS::Nhap() {
	cout << "Nhap tu: "; cin >> t;
	cout << "Nhap mau: "; cin >> m;
}

void PS::Xuat() {
	cout << t << "/" << m << endl;
}
int main() {
	PS p1, p2;
	
	cout << "Nhap phan so 1: " << endl;
	p1.Nhap();
	p1.Xuat();
	
	cout << "Nhap phan so 2: " << endl;
	p2.Nhap();
	p2.Xuat();
	
	PS sum = p1.Tong(p2);
	cout << "Tong: ";
	sum.Xuat();
	return 0;
}
