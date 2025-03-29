#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;
class MAYBAYQS {
	protected:
		char hang[100], nhiemvu[100];
		float tocdo;
	public:
		MAYBAYQS(char hang[100]=" ", char nhiemvu[100]=" ", int tocdo=0) : tocdo(tocdo) {
			strcpy(this->hang, hang);
			strcpy(this->nhiemvu, nhiemvu);
		}
		~MAYBAYQS() {}
		void Nhap();
		void Xuat();
		bool operator>(float thuc) {
			return tocdo > thuc;
		}
		long long getGia() {
			return (strcmp(nhiemvu, "Trinh sát")==0) ? 500000 : 1000000;
		}
};

void MAYBAYQS::Nhap() {
	fflush(stdin);
	cout << "Nhập hãng sản xuất: "; cin.getline(hang, 100);
	cout << "Nhập nhiệm vụ: "; cin.getline(nhiemvu, 100);
	fflush(stdin);
	cout << "Nhập tốc độ: "; cin >> tocdo;
}

void MAYBAYQS::Xuat() {
	cout << left << setw(19) << hang <<
					setw(16) << nhiemvu << 
					setw(15) << tocdo <<
					setw(20) << getGia() << endl;
}

void nhap(MAYBAYQS a[], int n) {
	for(int i = 0; i < n; i++) {
		cout << i+1 << ")" << endl;
		a[i].Nhap();
		cout << endl;
	}
}

void Tieude() {
	cout << left << setw(20) << "HÃNG:" <<
					setw(20) << "NHIỆM VỤ:" <<
					setw(20) << "TỐC ĐỘ:" <<
					setw(20) << "GIÁ:" << endl;
}

void xuat(MAYBAYQS a[], int n) {
	Tieude();
	for(int i = 0; i < n; i++) {
		a[i].Xuat();
	}
}

void Tocdo(MAYBAYQS a[], int n) {
	Tieude();
	for(int i = 0; i < n; i++) {
		if(a[i] > 500) {
			a[i].Xuat();
		}
	}
}

void Swap(MAYBAYQS &x, MAYBAYQS &y) {
	MAYBAYQS temp = x;
	x = y;
	y = temp;
}

void Sapxep(MAYBAYQS a[], int n) {
	for(int i = 0; i < n-1; i++) {
		for(int j = i+1; j < n; j++) {
			if(a[i].getGia() < a[j].getGia()) {
				Swap(a[i], a[j]);
			}
		}
	}
	xuat(a, n);
}
int main() {
	int n, lc;
	MAYBAYQS a[100];
	
	do {
		cout << "===============CHƯƠNG TRÌNH QUẢN LÝ MÁY BAY QUÂN SỰ===============" << endl;
		cout << "|| 1. Nhập thông tin                                            ||" << endl;
		cout << "|| 2. Máy bay quân sự có tốc độ > 500 km/h                      ||" << endl;
		cout << "|| 3. Sắp xếp giá thành giảm dần                                ||" << endl;
		cout << "|| 0. Thoát                                                     ||" << endl;
		cout << "==================================================================" << endl;
		cout << "Nhập lựa chọn: "; cin >> lc;
		
		switch(lc) {
			case 1: {
				cout << "\n===========================NHẬP THÔNG TIN=========================" << endl;
				cout << "Nhập số máy bay quân sự: "; cin >> n;
				nhap(a, n);
				break;
			}
			
			case 2: {
				cout << "\n=========================TỐC ĐỘ > 500KM/H=========================" << endl;
				Tocdo(a, n);
				break;
			}
			
			case 3: {
				cout << "\n========================GIÁ THÀNH GIẢM DẦN========================" << endl;
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
