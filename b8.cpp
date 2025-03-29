#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;
class MOTO {
	protected:
		char ma[100];
		int dungtich;
		long long truocthue;
	public:
		MOTO(char ma[100]=" ", int dungtich=0, long long truocthue=0) : dungtich(dungtich), truocthue(truocthue) {
			strcpy(this->ma, ma);
		}
		
		~MOTO() {}
		
		friend istream& operator>>(istream& cin, MOTO &mt);
		
		friend ostream& operator<<(ostream& cout, MOTO &mt);
		
		bool operator>=(float s) {
			return dungtich >= s;
		}
		
		long long getSauThue() {
			return (dungtich>=250) ? (truocthue*1.5) : (truocthue*1.2);
		}
		
		friend void Sapxep(MOTO a[], int n);
};

istream& operator>>(istream& cin, MOTO &mt) {
	fflush(stdin);
	cout << "Nhập mã: "; cin.getline(mt.ma, 100);
	fflush(stdin);
	cout << "Nhập dung tích xi lanh: "; cin >> mt.dungtich;
	cout << "Nhập giá trước thuế: "; cin >> mt.truocthue;
	return cin;
}

ostream& operator<<(ostream& cout, MOTO &mt) {
	cout << left << setw(20) << mt.ma <<
					setw(20) << mt.dungtich <<
					setw(20) << mt.truocthue <<
					setw(20) << mt.getSauThue() << endl;
	return cout;
}

void Nhap(MOTO a[], int n) {
	for(int i = 0; i < n; i++) {
		cout << i+1 << ")" << endl;
		cin >> a[i];
		cout << endl;
	}
}

void Tieude() {
	cout << left << setw(20) << "MÃ:" <<
					setw(20) << "DUNG TÍCH:" <<
					setw(20) << "TRƯỚC THUẾ:" <<
					setw(20) << "SAU THUẾ:" << endl;
}

void Xuat(MOTO a[], int n) {
	Tieude();
	for(int i = 0; i < n; i++) {
		cout << a[i];
	}
}

void Dungtich(MOTO a[], int n) {
	Tieude();
	for(int i = 0; i < n; i++) {
		if(a[i] >= 300) {
			cout << a[i];
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
		for(int j = i+1; j < n; j++) {
			if(strcmp(a[i].ma, a[j].ma) > 0) {
				Swap(a[i], a[j]);
			}
		}
	}
	Xuat(a, n);
}
int main() {
	int n, lc;
	MOTO a[100];
	
	do {
		cout << "======================CHƯƠNG TRÌNH QUẢN LÝ MOTO======================" << endl;
		cout << "|| 1. Nhập thông tin                                               ||" << endl;
		cout << "|| 2. Dung tích xi lanh từ 300 trở lên                             ||" << endl;
		cout << "|| 3. Sắp xếp mã moto tăng dần                                     ||" << endl;
		cout << "|| 0. Thoát                                                        ||" << endl;
		cout << "=====================================================================" << endl;
		cout << "Nhập lựa chọn: "; cin >> lc;
		
		switch(lc) {
			case 1: {
				cout << "\n============================NHẬP THÔNG TIN===========================" << endl;
				cout << "Nhập số moto: "; cin >> n;
				Nhap(a, n);
				break;
			}
			
			case 2: {
				cout << "\n==================DUNG TÍCH XI LANH TỪ 300 TRỞ LÊN===================" << endl;
				Dungtich(a, n);
				cout << endl;
				break;
			}
			
			case 3: {
				cout << "\n==========================MÃ MOTO TĂNG DẦN===========================" << endl;
				Sapxep(a, n);
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
