#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;
class DOCGIA {
	protected:
		char ma[100], ten[100];
	public:
		virtual void Nhap();
		virtual void Xuat();
		virtual long long getPhi() = 0;
};

void DOCGIA::Nhap() {
	fflush(stdin);
	cout << "Nhập mã: "; cin.getline(ma, 100);
	cout << "Nhập tên: "; cin.getline(ten, 100);
}

void DOCGIA::Xuat() {
	cout << left << setw(20) << ma <<
					setw(20) << ten;
}

class DOCGIATHUONG : public DOCGIA {
	protected:
		int sothang;
	public:
		void Nhap();
		void Xuat();
		long long getPhi() {
			return sothang * 10000;
		}
};

void DOCGIATHUONG::Nhap() {
	DOCGIA::Nhap();
	fflush(stdin);
	cout << "Nhập số tháng đăng kí: "; cin >> sothang;
}

void DOCGIATHUONG::Xuat() {
	DOCGIA::Xuat();
	cout << setw(20) << sothang <<
			setw(20) << getPhi() << endl;
}

class DOCGIAVIP : public DOCGIA {
	protected:
		int sothang, hevip;
	public:
		void Nhap();
		void Xuat();
		long long getPhi() {
			return sothang*20000*hevip;
		}
};

void DOCGIAVIP::Nhap() {
	DOCGIA::Nhap();
	fflush(stdin);
	cout << "Nhập số tháng đăng kí: "; cin >> sothang;
	cout << "Nhập hệ số VIP: "; cin >> hevip;
}

void DOCGIAVIP::Xuat() {
	DOCGIA::Xuat();
	cout << setw(20) << sothang <<
			setw(20) << hevip <<
			setw(20) << getPhi() << endl;
}

class QL {
	public:
		DOCGIA *a[100];
		void nhap() {
			int n = 0, lc;
			
			while(true) {
				cout << "Chọn đối tượng Độc giả:" << endl;
				cout << "1. Thường" << endl;
				cout << "2. VIP" << endl;
				cout << "0. Thoát" << endl;
				cout << "\nNhập lựa chọn: "; cin >> lc;
				
				if(lc == 1) {
					a[n] = new DOCGIATHUONG();
				}
				if(lc == 2) {
					a[n] = new DOCGIAVIP();
				}
				if(lc == 0) {
					break;
				}
				a[n]->Nhap();
				cout << endl;
				n++;
			}
			cout << "Phí đăng kí cao nhất: ";
			long long max = a[0]->getPhi();
			for(int i = 0; i < n; i++) {
				if(a[i]->getPhi() > max) {
					max = a[i]->getPhi();
				}
			}
			cout << max << " đồng" << endl;
		}
};
int main() {
	QL a;
	a.nhap();
	return 0;
}
