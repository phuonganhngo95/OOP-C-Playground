#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;
class THIETBI {
	protected:
		char ten[100];
		int congsuat, gio;
	public:
		virtual void Nhap();
		virtual void Xuat();
		virtual long long getTien() = 0;
};

void THIETBI::Nhap() {
	fflush(stdin);
	cout << "Nhập tên: "; cin.getline(ten, 100);
	fflush(stdin);
	cout << "Nhập công suất: "; cin >> congsuat;
	cout << "Nhập số giờ hoạt động mỗi ngày: "; cin >> gio;
}

void THIETBI::Xuat() {
	cout << left << setw(20) << ten <<
					setw(20) << congsuat <<
					setw(20) << gio;
}

class MAYDIEUHOA : public THIETBI {
	protected:
		char chedo[100];
	public:
		void Nhap();
		void Xuat();
		long long getTien() {
			return (strcmp(chedo, "2 chiều")==0) ? 2500*((congsuat+congsuat*0.2)/1000)*gio*30 : 2500*(congsuat/1000)*gio*30;
		}
};

void MAYDIEUHOA::Nhap() {
	THIETBI::Nhap();
	fflush(stdin);
	cout << "Nhập chế độ hoạt động: "; cin.getline(chedo, 100);
	while(strcmp(chedo, "2 chiều")!=0 && strcmp(chedo, "1 chiều")!=0) {
		cout << "Nhập lại chế độ: "; cin.getline(chedo, 100);
	}
}

void MAYDIEUHOA::Xuat() {
	THIETBI::Xuat();
	cout << setw(20) << chedo <<
			setw(20) << getTien() << endl;
}

class QUATHOINUOC : public THIETBI {
	protected:
		int dungtich;
	public:
		void Nhap();
		void Xuat();
		long long getTien() {
			return (dungtich<10) ? 2500*((congsuat-congsuat*0.1)/1000)*gio*30 : 2500*(congsuat/1000)*gio*30;
		}
};

void QUATHOINUOC::Nhap() {
	THIETBI::Nhap();
	cout << "Nhập dung tích bình chứa nước: "; cin >> dungtich;
}

void QUATHOINUOC::Xuat() {
	THIETBI::Xuat();
	cout << setw(20) << dungtich <<
			setw(20) << getTien() << endl;
}

class QL {
	public:
		THIETBI *a[100];
		void nhap() {
			int n = 0, lc;
			long long gia = 0;
			
			while(true) {
				cout << "Chọn Thiết bị:" << endl;
				cout << "1. Máy điều hòa" << endl;
				cout << "2. Quạt hơi nước" << endl;
				cout << "0. Thoát" << endl;
				cout << "\nNhập lựa chọn: "; cin >> lc;
				
				if(lc == 1) {
					a[n] = new MAYDIEUHOA();
				}
				if(lc == 2) {
					a[n] = new QUATHOINUOC();
				}
				if(lc == 0) {
					break;
				}
				a[n]->Nhap();
				cout << endl;
				gia += a[n]->getTien();
				n++;
			}
			cout << "\nTổng tiền điện tiêu thụ của tất cả thiết bị trong 1 tháng: " << gia << " đồng" << endl;
		}
};
int main() {
	QL a;
	a.nhap();
	return 0;
}
