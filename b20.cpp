#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;
class THIETBI {
	protected:
		char ten[100], loai[100];
		int congsuat;
	public:
		virtual void Nhap();
		virtual void Xuat();
		virtual long long getTien() = 0;
};

void THIETBI::Nhap() {
	fflush(stdin);
	cout << "Nhập tên: "; cin.getline(ten, 100);
	cout << "Nhập loại: "; cin.getline(loai, 100);
	fflush(stdin);
	cout << "Nhập công suất: "; cin >> congsuat;
}

void THIETBI::Xuat() {
	cout << left << setw(20) << ten <<
					setw(20) << loai <<
					setw(20) << congsuat;
}

class MAYGIAT : public THIETBI {
	protected:
		char chedo[100];
	public:
		void Nhap();
		void Xuat();
		long long getTien() {
			return (strcmp(chedo, "vừa")==0) ? 2*30*(congsuat/1000)*2500 : 3*30*(congsuat/100)*2500;
		}
};

void MAYGIAT::Nhap() {
	THIETBI::Nhap();
	fflush(stdin);
	cout << "Nhập chế độ: "; cin.getline(chedo, 100);
	while(strcmp(chedo, "vừa")!=0 && strcmp(chedo, "nặng")!=0) {
		cout << "Nhập lại chế độ: "; cin.getline(chedo, 100);
	}
}

void MAYGIAT::Xuat() {
	THIETBI::Xuat();
	cout << setw(20) << chedo <<
			setw(20) << getTien() << endl;
}

class TULANH : public THIETBI {
	protected:
		char congnghe[100];
	public:
		void Nhap();
		void Xuat();
		long long getTien() {
			return (strcmp(congnghe, "thường")==0) ? (congsuat*1/100)*24*30*2500 : (congsuat*0.7/100)*24*30*2500;
		}
};

void TULANH::Nhap() {
	THIETBI::Nhap();
	fflush(stdin);
	cout << "Nhập công nghệ làm lạnh: "; cin.getline(congnghe, 100);
	while(strcmp(congnghe, "thường")!=0 && strcmp(congnghe, "inverter")!=0) {
		cout << "Nhập lại công nghệ làm lạnh: "; cin.getline(congnghe, 100);
	}
}

void TULANH::Xuat() {
	THIETBI::Xuat();
	cout << setw(20) << congnghe <<
			setw(20) << getTien() << endl;
}

class QL {
	public:
		THIETBI *a[100];
		void nhap() {
			int n = 0, lc;
			long long gia = 0;
			
			while(true) {
				cout << "Chọn đối tượng thiết bị:" << endl;
				cout << "1. Máy giặt" << endl;
				cout << "2. Tủ lạnh" << endl;
				cout << "0. Thoát" << endl;
				cout << "\nNhập lựa chọn: "; cin >> lc;
				
				if(lc == 1) {
					a[n] = new MAYGIAT();
				}
				if(lc == 2) {
					a[n] = new TULANH();
				}
				if(lc == 0) {
					break;
				}
				a[n]->Nhap();
				cout << endl;
				gia += a[n]->getTien();
				n++;
			}
			cout << "\nTổng tiền điện tiêu thụ trong 1 tháng của  các thiết bị đó: " << gia << " đồng" << endl;
		}
};
int main() {
	QL a;
	a.nhap();
	return 0;
}
