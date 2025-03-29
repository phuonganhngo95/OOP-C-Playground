#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;
class XEMAY {
	protected:
		char hang[100];
		int dungtich;
		long long chuathue;
	public:
		XEMAY(char hang[100]=" ", int dungtich=0, long long chuathue=0) : dungtich(dungtich), chuathue(chuathue) {
			strcpy(this->hang, hang);
		}
		~XEMAY() {}
		void Nhap();
		void Xuat();
		bool operator==(float thuc) {
			return dungtich == thuc;
		}
		long long getSauThue() {
			return chuathue + chuathue*0.12;
		}
		friend void Sapxep(XEMAY a[], int n);
};

void XEMAY::Nhap() {
	fflush(stdin);
	cout << "Nhập hãng sản xuất: "; cin.getline(hang, 100);
	fflush(stdin);
	cout << "Nhập dung tích xi lanh: "; cin >> dungtich;
	cout << "Nhập giá chưa thuế: "; cin >> chuathue;
}

void XEMAY::Xuat() {
	cout << left << setw(20) << hang <<
					setw(20) << dungtich <<
					setw(20) << chuathue <<
					setw(20) << getSauThue() << endl;
}

void nhap(XEMAY a[], int n) {
	for(int i = 0; i < n; i++) {
		cout << i+1 << ")" << endl;
		a[i].Nhap();
		cout << endl;
	}
}

void Tieude() {
	cout << left << setw(20) << "HÃNG:" <<
					setw(20) << "DUNG TÍCH:" <<
					setw(20) << "CHƯA THUẾ:" <<
					setw(20) << "SAU THUẾ:" << endl;
}

void xuat(XEMAY a[], int n) {
	Tieude();
	for(int i = 0; i < n; i++) {
		a[i].Xuat();
	}
}

void DungTich(XEMAY a[], int n) {
	Tieude();
	for(int i = 0; i < n; i++) {
		if(a[i] == 100) {
			a[i].Xuat();
		}
	}
}

void Swap(XEMAY &x, XEMAY &y) {
	XEMAY temp = x;
	x = y;
	y = temp;
}

void Sapxep(XEMAY a[], int n) {
	for(int i = 0; i < n-1; i++) {
		for(int j = i+1; j < n; j++) {
			if(strcmp(a[i].hang, a[j].hang) > 0) {
				Swap(a[i], a[j]);
			}
		}
	}
	xuat(a, n);
}
int main() {
	int n, lc;
	XEMAY a[100];
	
	do {
		cout << "==================CHƯƠNG TRÌNH QUẢN LÝ XE MÁY===================" << endl;
		cout << "|| 1. Nhập thông tin                                          ||" << endl;
		cout << "|| 2. Xe máy có dung tích xi lanh == 100CC                    ||" << endl;
		cout << "|| 3. Sắp xếp hãng sản xuất tăng dần                          ||" << endl;
		cout << "|| 0. Thoát                                                   ||" << endl;
		cout << "================================================================" << endl;
		cout << "Nhập lựa chọn: "; cin >> lc;
		
		switch(lc) {
			case 1: {
				cout << "\n=========================NHẬP THÔNG TIN=========================" << endl;
				cout << "Nhập số xe máy: "; cin >> n;
				nhap(a, n);
				break;
			}
			
			case 2: {
				cout << "\n===================DUNG TÍCH XI LANH == 100CC===================" << endl;
				DungTich(a, n);
				break;
			}
			
			case 3: {
				cout << "\n=====================HÃNG SẢN XUẤT TĂNG DẦN=====================" << endl;
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
