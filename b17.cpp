#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;
class KHACHSAN {
	protected:
		char ten[100], loai[100];
		int slgphong;
	public:
		virtual void Nhap();
		virtual void Xuat();
		virtual long long getDoanhThu() = 0;
};

void KHACHSAN::Nhap() {
	fflush(stdin);
	cout << "Nhập tên: "; cin.getline(ten, 100);
	cout << "Nhập loại: "; cin.getline(loai, 100);
	fflush(stdin);
	cout << "Nhập số lượng phòng: "; cin >> slgphong;
}

void KHACHSAN::Xuat() {
	cout << left << setw(20) << ten <<
					setw(20) << loai <<
					setw(20) << slgphong;
}

class KSBIEN : public KHACHSAN {
	protected:
		char huong[100];
	public:
		void Nhap();
		void Xuat();
		long long getDoanhThu() {
			return slgphong*800000;
		}
};

void KSBIEN::Nhap() {
	KHACHSAN::Nhap();
	fflush(stdin);
	cout << "Nhập hướng biển: "; cin.getline(huong, 100);
}

void KSBIEN::Xuat() {
	KHACHSAN::Xuat();
	cout << setw(20) << huong <<
			setw(20) << getDoanhThu() << endl;
}

class KSLICHSU : public KHACHSAN {
	protected:
		int capdo;
	public:
		void Nhap();
		void Xuat();
		long long getDoanhThu() {
			return slgphong*900000;
		}
};

void KSLICHSU::Nhap() {
	KHACHSAN::Nhap();
	cout << "Nhập cấp độ: "; cin >> capdo;
}

void KSLICHSU::Xuat() {
	KHACHSAN::Xuat();
	cout << setw(20) << capdo <<
			setw(20) << getDoanhThu() << endl;
}

class QL {
	public:
		KHACHSAN *a[100];
		void nhap() {
			int n = 0, lc;
			long long gia = 0;
			
			while(true) {
				cout << "Nhập đối tượng Khách sạn:" << endl;
				cout << "1. Biển" << endl;
				cout << "2. Lịch sử" << endl;
				cout << "0. Thoát" << endl;
				cout << "\nNhập lựa chọn: "; cin >> lc;
				
				if(lc == 1) {
					a[n] = new KSBIEN();
				}
				if(lc == 2) {
					a[n] = new KSLICHSU();
				}
				if(lc == 0) {
					break;
				}
				a[n]->Nhap();
				cout << endl;
				gia += a[n]->getDoanhThu();
				n++;
			}
			cout << "\nTổng doanh thu của các khách sạn: " << gia << " đồng" << endl;
		}
};
int main() {
	QL a;
	a.nhap();
	return 0;
}
