#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;
class GV {
	protected:
		char ht[30], bc[15], nganh[20];
		int t;
		float bl;
	public:
		GV(char ht[30]=" ", int t=0, char bc[15]=" ", char nganh[20]=" ", float bl=0.0) : t(t), bl(bl) {
			strcpy(this->ht, ht);
			strcpy(this->bc, bc);
			strcpy(this->nganh, nganh);
		}
		
		~GV() {}
		
		void Nhap();
		
		void Xuat();
		
		double getLuongCB() {
			return bl * 610;
		}
		
		friend void ChuyenNganh(GV a[], int n);
};

void GV::Nhap() {
	fflush(stdin);
	cout << "Nhập họ tên: "; cin.getline(ht, 30);
	fflush(stdin);
	cout << "Nhập tuổi: "; cin >> t;
	fflush(stdin);
	cout << "Nhập bằng cấp cao nhất: "; cin.getline(bc, 15);
	cout << "Nhập chuyên ngành: "; cin.getline(nganh, 20);
	fflush(stdin);
	cout << "Nhập bậc lương: "; cin >> bl;
}

void GV::Xuat() {
	cout << left << setw(20) << ht <<
					setw(20) << t <<
					setw(20) << bc <<
					setw(20) << nganh <<
					setw(20) << bl <<
					setw(20) << getLuongCB() << endl;
}

void nhap(GV a[], int n) {
	for(int i = 0; i < n; i++) {
		cout << i+1 << ")" << endl;
		a[i].Nhap();
		cout << endl;
	}
}

void Tieude() {
	cout << left << setw(20) << "HỌ TÊN:" <<
					setw(20) << "TUỔI:" <<
					setw(20) << "BẰNG CẤP:" <<
					setw(20) << "NGÀNH:" <<
					setw(20) << "BẬC LƯƠNG:" <<
					setw(20) << "LƯƠNG CƠ BẢN:" << endl;
}

void xuat(GV a[], int n) {
	Tieude();
	for(int i = 0; i < n; i++) {
		a[i].Xuat();
	}
}

void LuongCb(GV a[], int n) {
	Tieude();
	for(int i = 0; i < n; i++) {
		if(a[i].getLuongCB() < 2000) {
			a[i].Xuat();
		}
	}
}

void Swap(GV &x, GV &y) {
	GV temp = x;
	x = y;
	y = temp;
}

void ChuyenNganh(GV a[], int n) {
	for(int i = 0; i < n-1; i++) {
		for(int j = i+1; j < n; j++) {
			if(strcmp(a[i].nganh, a[j].nganh) > 0) {
				Swap(a[i], a[j]);
			}
		}
	}
	xuat(a, n);
}
int main() {
	int n, lc;
	GV a[100];
	
	do {
		cout << "==========================================CHƯƠNG TRÌNH QUẢN LÝ GIÁO VIÊN==========================================" << endl;
		cout << "|| 1. Nhập thông tin                                                                                            ||" << endl;
		cout << "|| 2. Giáo viên có tiền lương < 2000                                                                            ||" << endl;
		cout << "|| 0. Thoát                                                                                                     ||" << endl;
		cout << "==================================================================================================================" << endl;
		cout << "Nhập lựa chọn: "; cin >> lc;
		
		switch(lc) {
			case 1: {
				cout << "\n==================================================NHẬP THÔNG TIN==================================================" << endl;
				cout << "Nhập số giáo viên: "; cin >> n;
				nhap(a, n);
				break;
			}
			
			case 2: {
				cout << "\n================================================TIỀN LƯƠNG < 2000=================================================" << endl;
				LuongCb(a, n);
				cout << endl;
				break;
			}
			
			case 3: {
				cout << "\n===============================================SẮP XẾP CHUYÊN NGÀNH===============================================" << endl;
				ChuyenNganh(a, n);
				cout << endl;
				break;
			}
			
			case 0: {
				break;
			}
			
			default:
				cout << "Lựa chọn không phù hợp" << endl;
		}
	}while(lc != 0);
	return 0;
}