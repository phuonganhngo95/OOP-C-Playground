#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;
class SINHVIEN {
	protected:
		char ma[100], hoten[100];
	public:
		virtual void Nhap();
		virtual void Xuat();
		virtual long long getHocPhi() = 0;
};

void SINHVIEN::Nhap() {
	fflush(stdin);
	cout << "Nhập mã: "; cin.getline(ma, 100);
	cout << "Nhập họ tên: "; cin.getline(hoten, 100);
}

void SINHVIEN::Xuat() {
	cout << left << setw(20) << ma <<
					setw(20) << hoten;
}

class SINHVIENCHINHQUY : public SINHVIEN {
	protected:
		int tinchi;
	public:
		void Nhap();
		void Xuat();
		long long getHocPhi() {
			return tinchi*500000;
		}
};

void SINHVIENCHINHQUY::Nhap() {
	SINHVIEN::Nhap();
	fflush(stdin);
	cout << "Nhập số tín chỉ: "; cin >> tinchi;
}

void SINHVIENCHINHQUY::Xuat() {
	SINHVIEN::Xuat();
	cout << setw(20) << tinchi <<
			setw(20) << getHocPhi() << endl;
}

class SINHVIENLIENTHONG : public SINHVIEN {
	protected:
		int tinchi, heso;
	public:
		void Nhap();
		void Xuat();
		long long getHocPhi() {
			return tinchi*700000*heso;
		}
};

void SINHVIENLIENTHONG::Nhap() {
	SINHVIEN::Nhap();
	fflush(stdin);
	cout << "Nhập số tín chỉ: "; cin >> tinchi;
	cout << "Nhập hệ số liên thông: "; cin >> heso;
}

void SINHVIENLIENTHONG::Xuat() {
	SINHVIEN::Xuat();
	cout << setw(20) << tinchi <<
			setw(20) << getHocPhi() << endl;
}

class QL {
	public:
		SINHVIEN *a[100];
		void nhap() {
			int n = 0, lc;
			long long hocphi = 0;
			
			while(true) {
				cout << "Chọn đối tượng sinh viên:" << endl;
				cout << "1. Chính quy" << endl;
				cout << "2. Liên thông" << endl;
				cout << "0. Thoát" << endl;
				cout << "\nNhập lựa chọn: "; cin >> lc;
				
				if(lc == 1) {
					a[n] = new SINHVIENCHINHQUY();
				}
				if(lc == 2) {
					a[n] = new SINHVIENLIENTHONG();
				}
				if(lc == 0) {
					break;
				}
				a[n]->Nhap();
				cout << endl;
				hocphi += a[n]->getHocPhi();
				n++;
			}
			cout << "\nTrung bình học phí của sinh viên: " << hocphi/n << " đồng" << endl;
		}
};
int main() {
	QL a;
	a.nhap();
	return 0;
}
