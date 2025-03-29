#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;
class MOTO {
	protected:
		char ma[100];
		int nam, dungtich;
		long long truocthue;
	public:
		MOTO(char ma[100]=" ", int nam=0, int dungtich=0, long long truocthue=0) : nam(nam), dungtich(dungtich), truocthue(truocthue) {
			strcpy(this->ma, ma);
		}
		
		~MOTO() {}
		
		void Nhap();
		
		void Xuat();
		
		long long getSauThue() {
			return (dungtich>=250) ? (truocthue*1.5) : (truocthue*1.2);
		}
		
		friend void DungTich(MOTO a[], int n);
		
		friend void Sapxep(MOTO a[], int n);
		
		friend void Xoa(MOTO a[], int n);
};

void MOTO::Nhap() {
	fflush(stdin);
	cout << "Nhập mã: "; cin.getline(ma, 100);
	fflush(stdin);
	cout << "Nhập năm sản xuất: "; cin >> nam;
	cout << "Nhập dung tích xi lanh: "; cin >> dungtich;
	cout << "Nhập giá trước thuế: "; cin >> truocthue;
}

void MOTO::Xuat() {
	cout << left << setw(20) << ma <<
					setw(20) << nam <<
					setw(20) << dungtich <<
					setw(20) << truocthue <<
					setw(20) << getSauThue() << endl;
}

void nhap(MOTO a[], int n) {
	for(int i = 0; i < n; i++) {
		cout << i+1 << ")" << endl;
		a[i].Nhap();
		cout << endl;
	}
}

void Tieude() {
	cout << left << setw(20) << "MÃ:" <<
					setw(20) << "NĂM SX:" <<
					setw(20) << "DUNG TÍCH:" <<
					setw(20) << "TRƯỚC THUẾ:" <<
					setw(20) << "SAU THUẾ:" << endl;
}

void xuat(MOTO a[], int n) {
	Tieude();
	for(int i = 0; i < n; i++) {
		a[i].Xuat();
	}
}

void DungTich(MOTO a[], int n) {
	Tieude();
	for(int i = 0; i < n; i++) {
		if(a[i].dungtich >= 300) {
			a[i].Xuat();
		}
	}
}

void Swap(MOTO &x, MOTO &y) {
	MOTO temp = x;
	x = y;
	y = temp;
}

void Sapxep(MOTO a[], int n) {
	for(int i = 0; i < n-1; i++) {
		for(int j = i; j < n; j++) {
			if(strcmp(a[i].ma, a[j].ma) > 0) {
				Swap(a[i], a[j]);
			}
		}
	}
	xuat(a, n);
}

void Xoa(MOTO a[], int n) {
	for(int i = 0; i< n; ) {
		if(a[i].nam < 2000) {
			for(int j = i; j < n-1; j++) {
				a[j] = a[j+1];
			}
			n--;
		} else {
			i++;
		}
	}
	xuat(a, n);
}
int main() {
	int n, lc;
	MOTO a[100];
	
	do {
		cout << "================================CHƯƠNG TRÌNH QUẢN LÝ MOTO================================" << endl;
		cout << "|| 1. Nhập thông tin                                                                   ||" << endl;
		cout << "|| 2. Dung tích xi lanh từ 300 trở lên                                                 ||" << endl;
		cout << "|| 3. Sắp xếp mã moto tăng dần                                                         ||" << endl;
		cout << "|| 4. Xoá moto sản xuất trước năm 2000                                                 ||" << endl;
		cout << "|| 0. Thoát                                                                            ||" << endl;
		cout << "=========================================================================================" << endl;
		cout << "Nhập lựa chọn: "; cin >> lc;
		
		switch(lc) {
			case 1: {
				cout << "\n======================================NHẬP THÔNG TIN=====================================" << endl;
				cout << "Nhập số moto: "; cin >> n;
				nhap(a, n);
				break;
			}

			case 2: {
				cout << "\n=================================DUNG TÍCH XI LANH >= 300================================" << endl;
				DungTich(a, n);
				cout << endl;
				break;
			}
			
			case 3: {
				cout << "\n=====================================MÃ MOTO TĂNG DẦN====================================" << endl;
				Sapxep(a, n);
				cout << endl;
				break;
			}
			
			case 4: {
				cout << "\n=============================XOÁ MOTO SẢN XUẤT TRƯỚC NĂM 2000============================" << endl;
				Xoa(a, n);
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
