#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;
class KYSU {
	protected:
		char ma[100], hoten[100];
		int nam;
	public:
		virtual void Nhap();
		virtual void Xuat();
		virtual int getDiem() = 0;
};

void KYSU::Nhap() {
	fflush(stdin);
	cout << "Nhập mã: "; cin.getline(ma, 100);
	cout << "Nhập họ tên: "; cin.getline(hoten, 100);
	fflush(stdin);
	cout << "Nhập năm bắt đầu công tác: "; cin >> nam;
}

void KYSU::Xuat() {
	cout << left << setw(20) << ma <<
					setw(20) << hoten <<
					setw(20) << nam;
}

class KYSUTK : public KYSU {
	protected:
		int duan;
	public:
		void Nhap();
		void Xuat();
		int getDiem() {
			return (duan<3) ? 70 : 90;
		}
};

void KYSUTK::Nhap() {
	KYSU::Nhap();
	cout << "Nhập số dự án: "; cin >> duan;
}

void KYSUTK::Xuat() {
	KYSU::Xuat();
	cout << setw(20) << duan <<
			setw(20) << getDiem() << endl;
}

class KYSUST : public KYSU {
	protected:
		int sangkien;
	public:
		void Nhap();
		void Xuat();
		int getDiem() {
			return (sangkien<2) ? 75 : 95;
		}
};

void KYSUST::Nhap() {
	KYSU::Nhap();
	cout << "Nhập số sáng kiến: "; cin >> sangkien;
}

void KYSUST::Xuat() {
	KYSU::Xuat();
	cout << setw(20) << sangkien <<
			setw(20) << getDiem() << endl;
}

class QL {
	public:
		KYSU *a[100];
		void nhap() {
			int n = 0, lc;
			int tongdiem = 0;
			
			while(true) {
				cout << "Chọn đối tượng Kỹ sư:" << endl;
				cout << "1. Thiết kế" << endl;
				cout << "2. Sáng tạo" << endl;
				cout << "0. Thoát" << endl;
				cout << "\nNhập lựa chọn: "; cin >> lc;
				
				if(lc == 1) {
					a[n] = new KYSUTK();
				}
				if(lc == 2) {
					a[n] = new KYSUST();
				}
				if(lc == 0) {
					break;
				}
				a[n]->Nhap();
				cout << endl;
				tongdiem += a[n]->getDiem();
				n++;
			}
			cout << "\nTrung bình điểm chuyên môn của các kỹ sư: " << (float)tongdiem/n << " điểm" << endl;
		}
};
int main() {
	QL a;
	a.nhap();
	return 0;
}
