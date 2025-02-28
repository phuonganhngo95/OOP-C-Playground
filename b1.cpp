#include<iostream>

using namespace std;
class Triangle {
	protected:
		float a, b, c;
	public:
		void Nhap();
		void Xuat();
};

void Triangle::Nhap() {
	cout << "Nhap a: "; cin >> a;
	cout << "Nhap b: "; cin >> b;
	cout << "Nhap c: "; cin >> c;
}

void Triangle::Xuat() {
	if(a>0 && b>0 && c>0) {
		if(a+b>c && b+c>a && a+c>b) {
			cout << "(" << a << ", " << b << ", " << c << ") tao thanh tam giac" << endl;
		} else {
			cout << "(" << a << ", " << b << ", " << c << ") khong tao thanh tam giac" << endl; 
		}
	} else {
		cout << "(" << a << ", " << b << ", " << c << ") khong tao thanh tam giac" << endl; 
	}
}

int main() {
	Triangle a;
	a.Nhap();
	a.Xuat();
	return 0;
}
