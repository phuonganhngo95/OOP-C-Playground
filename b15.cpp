#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;
class FLYCAM {
	protected:
		char ma[100], hang[100];
		int tocdo;
	public:
		virtual void Nhap();
		virtual void Xuat();
		virtual long long getGia() = 0;
};

void FLYCAM::Nhap() {
	fflush(stdin);
	cout << "Nhập mã: "; cin.getline(ma, 100);
	cout << "Nhập hãng sản xuất: "; cin.getline(hang, 100);
	cout << "Nhập tốc độ tối đa: "; cin >> tocdo;
}

void FLYCAM::Xuat() {
	cout << left << setw(20) << ma <<
					setw(20) << hang <<
					setw(20) << tocdo;
}

class FLYCAMCN : public FLYCAM {
	protected:
		int docao;
	public:
		void Nhap();
		void Xuat();
		long long getGia() {
			return (docao<100) ? 1000 : 1500;
		}
};

void FLYCAMCN::Nhap() {
	FLYCAM::Nhap();
	cout << "Nhập độ cao: "; cin >> docao;
}


void FLYCAMCN::Xuat() {
	FLYCAM::Xuat();
	cout << setw(20) << docao <<
			setw(20) << getGia() << endl;
}

class FLYCAMTD : public FLYCAM {
	protected:
		int thoigian;
	public:
		void Nhap();
		void Xuat();
		long long getGia() {
			return (thoigian<6) ? 800 : 1600;
		}
};

void FLYCAMTD::Nhap() {
	FLYCAM::Nhap();
	cout << "Nhập thời gian bay tối đa: "; cin >> thoigian;
}

void FLYCAMTD::Xuat() {
	FLYCAM::Xuat();
	cout << setw(20) << thoigian <<
			setw(20) << getGia() << endl;
}
 
class QL {
	public:
		FLYCAM *a[100];
		
		void nhap() {
			int n = 0, lc;
			float gia = 0;
			
			while(true) {
				cout << "Chọn đối tượng Flycam:" << endl;
				cout << "1. Chuyên nghiệp" << endl;
				cout << "2. Tiêu dùng" << endl;
				cout << "\nNhập lựa chọn: "; cin >> lc;
				
				if(lc == 1) {
					a[n] = new FLYCAMCN();
				} 
				if(lc == 2) {
					a[n] = new FLYCAMTD();
				}
				if(lc == 3) {
					break;
				}
				a[n]->Nhap();
				gia += a[n]->getGia();
				cout << endl;
				n++;
			}
			cout << "\nTổng giá của các Flycam: " << gia << " USD" << endl;
		}
};
int main() {
	QL a;
	a.nhap();
	return 0;
}
