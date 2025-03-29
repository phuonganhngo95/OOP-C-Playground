#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;
class TAUCT {
	protected:
		char ma[100], loai[100];
		int tocdo;
	public:
		virtual void Nhap();
		virtual void Xuat();
		virtual long long getGiaThue() = 0;
};

void TAUCT::Nhap() {
	fflush(stdin);
	cout << "Nhập mã: "; cin.getline(ma, 100);
	cout << "Nhập loại: "; cin.getline(loai, 100);
	fflush(stdin);
	cout << "Nhập tốc độ tối đa: "; cin >> tocdo;
}

void TAUCT::Xuat() {
	cout << left << setw(20) << ma <<
					setw(20) << loai <<
					setw(20) << tocdo;
}

class TAUKHACHCT : public TAUCT {
	protected:
		int slgkhach;
	public:
		void Nhap();
		void Xuat();
		long long getGiaThue() {
			return slgkhach*10;
		}
};

void TAUKHACHCT::Nhap() {
	TAUCT::Nhap();
	cout << "Nhập số lượng khách: "; cin >> slgkhach;
}

void TAUKHACHCT::Xuat() {
	TAUCT::Xuat();
	cout << setw(20) << slgkhach <<
			setw(20) << getGiaThue() << endl;
}

class TAUHANGCT : public TAUCT {
	protected:
		float taitrong;
	public:
		void Nhap();
		void Xuat();
		long long getGiaThue() {
			return taitrong*15;
		}
};

void TAUHANGCT::Nhap() {
	TAUCT::Nhap();
	cout << "Nhập tải trọng tối đa: "; cin >> taitrong;
}

void TAUHANGCT::Xuat() {
	TAUCT::Xuat();
	cout << setw(20) << taitrong <<
			setw(20) << getGiaThue() << endl;
}

class QL {
	public:
		TAUCT *a[100];
		void nhap() {
			int n = 0, lc;
			long long gia = 0;
			
			while(true) {
				cout << "Chọn đối tượng Tàu cao tốc:" << endl;
				cout << "1. Tàu khách" << endl;
				cout << "2. Tàu hàng" << endl;
				cout << "0. Thoát" << endl;
				cout << "\nNhập lựa chọn: "; cin >> lc;
				
				if(lc == 1) {
					a[n] = new TAUKHACHCT();
				}
				if(lc == 2) {
					a[n] = new TAUHANGCT();
				}
				if(lc == 0) {
					break;
				}
				a[n]->Nhap();
				cout << endl;
				gia += a[n]->getGiaThue();
				n++;
			}
			cout << "\nTổng giá sau thuê của các Tàu cao tốc: " << gia << " USD" << endl;
		}
};
int main() {
	QL a;
	a.nhap();
	return 0;
}
