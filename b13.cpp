#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;
class HAISAN {
	protected:
		char loai[100], dacdiem[100];
		int tuoitho;
	public:
		HAISAN(char loai[100]=" ", int tuoitho=0, char dacdiem[100]=" ") : tuoitho(tuoitho) {
			strcpy(this->loai, loai);
			strcpy(this->dacdiem, dacdiem);
		}
		~HAISAN() {}
		void Nhap();
		void Xuat();
		bool operator>(int nguyen) {
			return tuoitho > nguyen;
		}
		long long getGia() {
			if(strcmp(loai, "Cá") == 0) {
				return 100000;
			} else if(strcmp(loai, "Tôm") == 0) {
				return 150000;
			} else {
				return 120000;
			}
		}
		friend void Sapxep(HAISAN a[], int n);
};

void HAISAN::Nhap() {
	fflush(stdin);
	cout << "Nhập loại: "; cin.getline(loai, 100);
	fflush(stdin);
	cout << "Nhập tuổi thọ: "; cin >> tuoitho;
	fflush(stdin);
	cout << "Nhập đặc điểm: "; cin.getline(dacdiem, 100);
}

void HAISAN::Xuat() {
	cout << left << setw(18) << loai <<
					setw(16) << tuoitho <<
					setw(14) << dacdiem <<
					setw(20) << getGia() << endl;
}

void nhap(HAISAN a[], int n) {
	for(int i = 0; i < n; i++) {
		cout << i+1 << ")" << endl;
		a[i].Nhap();
		cout << endl;
	}
}

void Tieude() {
	cout << left << setw(20) << "LOẠI:" <<
					setw(20) << "TUỔI THỌ:" <<
					setw(20) << "ĐẶC ĐIỂM:" <<
					setw(20) << "GIÁ:" << endl;
}

void xuat(HAISAN a[], int n) {
	Tieude();
	for(int i = 0; i < n; i++) {
		a[i].Xuat();
	}
}

void Tuoitho(HAISAN a[], int n) {
	Tieude();
	for(int i = 0; i < n; i++) {
		if(a[i] > 5) {
			a[i].Xuat();
		}
	}
}

void Swap(HAISAN &x, HAISAN &y) {
	HAISAN temp = x;
	x = y;
	y = temp;
}

void Sapxep(HAISAN a[], int n) {
	for(int i = 0; i < n-1; i++) {
		for(int j = i+1; j < n; j++) {
			if(strcmp(a[i].dacdiem, a[j].dacdiem) > 0) {
				Swap(a[i], a[j]);
			}
		}
	}
	xuat(a, n);
}
int main() {
	int n, lc;
	HAISAN a[100];
	
	do {
		cout << "===============CHƯƠNG TRÌNH QUẢN LÝ HẢI SẢN===============" << endl;
		cout << "|| 1. Nhập thông tin                                    ||" << endl;
		cout << "|| 2. Hải sản có tuổi thọ > 5 năm                       ||" << endl;
		cout << "|| 3. Sắp xếp đặc điểm hải sản tăng dần                 ||" << endl;
		cout << "|| 0. Thoát                                             ||" << endl;
		cout << "==========================================================" << endl;
		cout << "Nhập lựa chọn: "; cin >> lc;
		
		switch(lc) {
			case 1: {
				cout << "\n======================NHẬP THÔNG TIN======================" << endl;
				cout << "Nhập số hải sản: "; cin >> n;
				nhap(a, n);
				break;
			}
			
			case 2: {
				cout << "\n=======================TUỔI THỌ > 5=======================" << endl;
				Tuoitho(a, n);
				break;
			}
			
			case 3: {
				cout << "\n=====================ĐẶC ĐIỂM TĂNG DẦN====================" << endl;
				Sapxep(a, n);
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
