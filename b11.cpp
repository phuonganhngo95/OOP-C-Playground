#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;
class Developer {
	protected:
		char hoten[100];
		int nam;
		float heluong;
	public:
		Developer(char hoten[100]=" ", int nam=0, float heluong=0.0) : nam(nam), heluong(heluong) {
			strcpy(this->hoten, hoten);
		}
		
		~Developer() {}
		
		void Nhap();
		
		void Xuat();
};

void Developer::Nhap() {
	fflush(stdin);
	cout << "Nhập họ tên: "; cin.getline(hoten, 100);
	fflush(stdin);
	cout << "Nhập năm sinh: "; cin >> nam;
	cout << "Nhập hệ số lương: "; cin >> heluong;
}

void Developer::Xuat() {
	cout << left << setw(20) << hoten <<
					setw(20) << nam <<
					setw(20) << heluong;
}

void nhapDeveloper(Developer a[], int n) {
	for(int i = 0; i < n; i++) {
		cout << i+1 << ")" << endl;
		a[i].Nhap();
		cout << endl;
	}
}

void TieudeDeveloper() {
	cout << left << setw(20) << "HỌ TÊN:" <<
					setw(20) << "NĂM SINH:" <<
					setw(20) << "HỆ LƯƠNG:";
}

void xuatDeveloper(Developer a[], int n) {
	TieudeDeveloper();
	cout << endl;
	for(int i = 0; i < n; i++) {
		a[i].Xuat();
		cout << endl;
	}
}

class Teamleader : public Developer {
	protected:
		long long luongTrNh;
		int namct;
	public:
		Teamleader(char hoten[100]=" ", int nam=0, float heluong=0.0, long long luongTrNh=0, int namct=0) : Developer(hoten, nam, heluong), luongTrNh(luongTrNh), namct(namct) {}
		
		~Teamleader() {}
		
		friend istream& operator>>(istream& cin, Teamleader &t);
			
		long long getLuong() {
			return heluong*1300000 + namct*90000 + luongTrNh;
		}
		
		bool operator!=(float thuc) {
			return luongTrNh != thuc;
		}
		
		friend ostream& operator<<(ostream& cout, Teamleader &t);	
};

istream& operator>>(istream& cin, Teamleader &t) {
	t.Nhap();
	cout << "Nhập lương trách nhiệm: "; cin >> t.luongTrNh;
	cout << "Nhập số năm công tác: "; cin >> t.namct;
	return cin;
}

ostream& operator<<(ostream& cout, Teamleader &t) {
	t.Xuat();
	cout << setw(20) << t.luongTrNh <<
			setw(20) << t.namct <<
			setw(20) << t.getLuong() << endl;
}

void nhapTeamleader(Teamleader b[], int n) {
	for(int i = 0; i < n; i++) {
		cout << i+1 << ")" << endl;
		cin >> b[i];
		cout << endl;
	}
}

void TieudeTeamleader() {
	TieudeDeveloper();
	cout << setw(20) << "LƯƠNG TRÁCH NHIỆM:" <<
			setw(20) << "SỐ NĂM CT:" <<
			setw(20) << "LƯƠNG:" << endl;
}

void xuatTeamleader(Teamleader b[], int n) {
	TieudeTeamleader();
	for(int i = 0; i > n; i++) {
		cout << b[i];
	}
}

void Luong(Teamleader b[], int n) {
	TieudeTeamleader();
	for(int i = 0; i < n; i++) {
		if(b[i] != 10000000) {
			cout << b[i];
		}
	}
}
int main() {
	int n, lc;
	Developer a[100];
	Teamleader b[100];
	
	do {
		cout << "1. Developer" << endl;
		cout << "2. Teamleader" << endl;
		cout << "3. Thoát" << endl;
		cout << "Chọn đối tượng: "; cin >> lc;
		
		switch(lc) {
			case 1: {
				do {
					cout << "\n====================DEVELOPER====================" << endl;
					cout << "|| 1. Nhập thông tin                           ||" << endl;
					cout << "|| 2. In thông tin                             ||" << endl;
					cout << "|| 0. Thoát                                    ||" << endl;
					cout << "=================================================" << endl;
					cout << "Nhập lựa chọn: "; cin >> lc;
					
					switch(lc) {
						case 1: {
							cout << "\n=================NHẬP THÔNG TIN==================" << endl;
							cout << "Nhập số developer: "; cin >> n;
							nhapDeveloper(a, n);
							break;
						}
						
						case 2: {
							cout << "\n=================XUẤT THÔNG TIN==================" << endl;
							xuatDeveloper(a, n);
							break;
						}
						
						case 0: {
							break;
						}
						
						default:
							cout << "Lựa chọn không phù hợp" << endl;
					}
				}while(lc != 0);
				break;
			}
			
			case 2: {
				do {
					cout << "\n=================================================TEAMLEADER================================================" << endl;
					cout << "|| 1. Nhập thông tin                                                                                     ||" << endl;
					cout << "|| 2. In thông tin                                                                                       ||" << endl;
					cout << "|| 0. Thoát                                                                                              ||" << endl;
					cout << "===========================================================================================================" << endl;
					cout << "Nhập lựa chọn: "; cin >> lc;
					
					switch(lc) {
						case 1: {
							cout << "\n===============================================NHẬP THÔNG TIN==============================================" << endl;
							cout << "Nhập số developer: "; cin >> n;
							nhapTeamleader(b, n);
							break;
						}
						
						case 2: {
							cout << "\n================================================LƯƠNG != 10TR==============================================" << endl;
							Luong(b, n);
							break;
						}
						
						case 0: {
							break;	
						}
						
						default:
							cout << "Lựa chọn không phù hợp" << endl;
					}
				}while(lc != 0);
				break;
			}
			
			case 3: {
				break;
			}
			
			default:
				cout << "Đối tượng không phù hợp" << endl;
		}
	}while(lc != 0);
	return 0;
}
