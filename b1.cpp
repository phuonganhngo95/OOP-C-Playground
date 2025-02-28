//Bài 1: Một số phức được biểu diễn dưới dạng  
//a = phầnthực + phần ảo*j. 
//Viết chương trình nhập 2 số phức và in ra màn hình tổng, hiệu 2 số 
//phức đó.

#include<iostream>

using namespace std;
class SP {
	protected:
		float r, i;
	public:
		void Nhap();
		void Xuat();
		SP Tong(SP other) {
			SP tong;
			tong.r = r + other.r;
			tong.i = i + other.i;
			return tong;
		}
		
		SP Hieu(SP other) {
			SP hieu;
			hieu.r = r - other.r;
			hieu.i = i - other.i;
			return hieu;
		}
};

void SP::Nhap() {
	cout << "Nhap phan thuc: "; cin >> r;
	cout << "Nhap phan ao: "; cin >> i;
}

void SP::Xuat() {
	cout << "a = " << r << " + " << i << "j" << endl;
}
int main() {
	SP sp1, sp2;
	
	cout << "Nhap so phuc 1: " << endl;
	sp1.Nhap();
	sp1.Xuat();
	
	cout << "Nhap so phuc 2: " << endl;
	sp2.Nhap();
	sp2.Xuat();
	
	SP sum = sp1.Tong(sp2);
	SP sub = sp1.Hieu(sp2);
	
	cout << "Tong: ";
	sum.Xuat();
	cout << "Hieu: ";
	sub.Xuat();
	return 0;
}
