// Anh/ chị hãy viết chương trình cho phép nhập vào 3 đỉnh của 1 tam giác. Sau đó, chương trình sẽ kiểm tra xem đây có phải là 1 tam giác hợp lệ hay không.
// Biết rằng 1 tam giác là hợp lệ khi nó thoải mãn điều kiện sau: tổng độ dài của 2 cạnh bất kỳ luôn lớn hơn độ dài của cạnh còn lại.

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
