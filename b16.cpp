#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;
class RESORT {
	protected:
		char ten[100], loai[100];
		int slgkhach;
	public:
		virtual void Nhap();
		virtual void Xuat();
		virtual long long getDoanhThu() = 0;
};

void RESORT::Nhap() {
	fflush(stdin);
	cout << "Nhập tên: "; cin.getline(ten, 100);
	cout << "Nhập loại: "; cin.getline(loai, 100);
	fflush(stdin);
	cout << "Nhập số lượng khách: "; cin >> slgkhach;
}

void RESORT::Xuat() {
	cout << left << setw(20) << ten <<
					setw(20) << loai <<
					setw(20) << slgkhach;
}

class RESORTNUI : public RESORT {
	protected:
		char huong[100];
	public:
		void Nhap();
		void Xuat();
		long long getDoanhThu() {
			return (strcmp(loai, "Cao cấp")==0) ? slgkhach*800000 : slgkhach*500000;
		}
};

void RESORTNUI::Nhap() {
	RESORT::Nhap();
	fflush(stdin);
	cout << "Nhập hướng núi: "; cin.getline(huong, 100);
}

void RESORTNUI::Xuat() {
	RESORT::Xuat();
	cout << setw(20) << huong <<
			setw(20) << getDoanhThu() << endl;
}

class RESORTBIEN : public RESORT {
	protected:
		float khoangcach;
	public:
		void Nhap();
		void Xuat();
		long long getDoanhThu() {
			return strcmp(loai, "Cao cấp")==0 ? slgkhach*1000000 : slgkhach*700000;
		}
};

void RESORTBIEN::Nhap() {
	RESORT::Nhap();
	cout << "Nhập khoảng cách tới biển: "; cin >> khoangcach;
}

void RESORTBIEN::Xuat() {
	RESORT::Xuat();
	cout << setw(20) << khoangcach <<
			setw(20) << getDoanhThu() << endl;
}

class QL {
	public:
		RESORT *a[100];
		void nhap() {
			int n = 0, lc;
			long long gia = 0;
			
			while(true) {
				cout << "Chọn đối tượng Resort:" << endl;
				cout << "1. Núi" << endl;
				cout << "2. Biển" << endl;
				cout << "0. Thoát" << endl;
				cout << "Nhập lựa chọn: "; cin >> lc;
				
				if(lc == 1) {
					a[n] = new RESORTNUI();
				}
				if(lc == 2) {
					a[n] = new RESORTBIEN();
				}
				if(lc == 0) {
					break;
				}
				a[n]->Nhap();
				cout << endl;
				gia += a[n]->getDoanhThu();
				n++;
			}
			cout << "\nTổng doanh thu các Resort: " << gia << " đồng" << endl;
		}
};
int main() {
	QL a;
	a.nhap();
	return 0;
}
