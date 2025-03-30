#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;
class BACSI {
	protected:
		char ma[100], hoten[100];
		int heluong;
	public:
		virtual void Nhap();
		virtual void Xuat();
		virtual long long getLuong() = 0;
};

void BACSI::Nhap() {
	fflush(stdin);
	cout << "Nhập mã: "; cin.getline(ma, 100);
	cout << "Nhập họ tên: "; cin.getline(hoten, 100);
	fflush(stdin);
	cout << "Nhập hệ số lương: "; cin >> heluong;
}

void BACSI::Xuat() {
	cout << left << setw(20) << ma <<
					setw(20) << hoten <<
					setw(20) << heluong;
}

class BACSIDK : public BACSI {
	protected:
		int cakham;
	public:
		void Nhap();
		void Xuat();
		long long getLuong() {
			return (cakham<20) ? heluong*4000000+300000 : heluong*4000000+350000;
		}
};

void BACSIDK::Nhap() {
	BACSI::Nhap();
	cout << "Nhập số ca khám: "; cin >> cakham;
}

void BACSIDK::Xuat() {
	BACSI::Xuat();
	cout << setw(20) << cakham <<
			setw(20) << getLuong() << endl;
}

class BACSICK : public BACSI {
	protected:
		int caphauthuat;
	public:
		void Nhap();
		void Xuat();
		long long getLuong() {
			return (caphauthuat<10) ? heluong*6000000+1000000 : heluong*6000000+1200000;
		}
};

void BACSICK::Nhap() {
	BACSI::Nhap();
	cout << "Nhập số ca phẫu thuật: "; cin >> caphauthuat;
}

void BACSICK::Xuat() {
	BACSI::Xuat();
	cout << setw(20) << caphauthuat <<
			setw(20) << getLuong() << endl;
}

class QL {
	public:
		BACSI *a[100];
		void nhap() {
			int n = 0, lc;
			
			while(true) {
				cout << "Chọn đối tượng Bác sĩ:" << endl;
				cout << "1. Đa khoa" << endl;
				cout << "2. Chuyên khoa" << endl;
				cout << "0. Thoát" << endl;
				cout << "\nNhập lựa chọn: "; cin >> lc;
				
				if(lc == 1) {
					a[n] = new BACSIDK();
				}
				if(lc == 2) {
					a[n] = new BACSICK();
				}
				if(lc == 0) {
					break;
				}
				a[n]->Nhap();
				cout << endl;
				n++;
			}
			cout << "Lương bé nhất: ";
			long long min = a[0]->getLuong();
			for(int i = 0; i < n; i++) {
				if(a[i]->getLuong() < min) {
					min = a[i]->getLuong();
				}
			}
			cout << min << " đồng" << endl;
		}
};
int main() {
	QL a;
	a.nhap();
	return 0;
}
