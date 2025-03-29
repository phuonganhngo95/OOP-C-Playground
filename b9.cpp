#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;
class VDV {
	protected:
		char hoten[190];
		int chieucao, nam;
	public:
		VDV(char hoten[100]=" ", int chieucao=0, int nam=0) : chieucao(chieucao), nam(nam) {
			strcpy(this->hoten, hoten);
		}
		
		~VDV() {}
		
		void Nhap();
		
		void Xuat();
};

void VDV::Nhap() {
	fflush(stdin);
	cout << "Nhập họ tên: "; cin.getline(hoten, 100);
	fflush(stdin);
	cout << "Nhập chiều cao: "; cin >> chieucao;
	cout << "Nhập năm thi đấu: "; cin >> nam;
}

void VDV::Xuat() {
	cout << left << setw(20) << hoten <<
					setw(20) << chieucao <<
					setw(20) << nam;
}

void nhapVDV(VDV a[], int n) {
	for(int i = 0; i < n; i++) {
		cout << i+1 << ")" << endl;
		a[i].Nhap();
		cout << endl;
	}
}

void TieudeVDV() {
	cout << left << setw(20) << "HỌ TÊN:" <<
					setw(20) << "CHIỀU CAO:" <<
					setw(20) << "SỐ NĂM THI:";
}

void xuatVDV(VDV a[], int n) {
	TieudeVDV();
	cout << endl;
	for(int i = 0; i < n; i++) {
		a[i].Xuat();
		cout << endl;
	}
}

class VDVDK : public VDV {
	protected:
		int huychuong, culy;
	public:
		VDVDK(char hoten[100]=" ", int chieucao=0, int nam=0, int huychuong=0, int culy=0) : VDV(hoten, chieucao, nam), huychuong(huychuong), culy(culy) {}
		
		~VDVDK() {}
		
		friend istream& operator>>(istream& cin, VDVDK &dk);
		
		long long GetThuong() {
			return huychuong*2000000 + nam*100000;
		}
		
		bool operator<(VDVDK other) {
			return huychuong < other.huychuong;
		}
		
		friend ostream& operator<<(ostream& cout, VDVDK &dk);
		
		friend void Max(VDVDK b[], int n);
};

istream& operator>>(istream& cin, VDVDK &dk) {
	dk.Nhap();
	cout << "Nhập số huy chương: "; cin >> dk.huychuong;
	cout << "Nhập cự ly thi đấu: "; cin >> dk.culy;
	return cin;
}

ostream& operator<<(ostream& cout, VDVDK &dk) {
	dk.Xuat();
	cout << setw(20) << dk.huychuong <<
			setw(20) << dk.culy <<
			setw(20) << dk.GetThuong() << endl;
	return cout;
}

void nhapVDVDK(VDVDK b[], int n) {
	for(int i = 0; i < n; i++) {
		cout << i+1 << ")" << endl;
		cin >> b[i];
		cout << endl;
	}
}

void TieudeVDVDK() {
	TieudeVDV();
	cout << setw(20) << "SỐ HUY CHƯƠNG:" <<
			setw(20) << "CỰ LY:" <<
			setw(20) << "THƯỞNG:" << endl;
}

void xuatVDVDK(VDVDK b[], int n) {
	TieudeVDVDK();
	for(int i = 0; i < n; i++) {
		cout << b[i];
	}
}

void Max(VDVDK b[], int n) {
	int max = b[0].huychuong;
	for(int i = 0; i < n; i++) {
		if(b[i].huychuong > max) {
			max = b[i].huychuong;
		}
	}
	TieudeVDVDK();
	for(int i = 0; i < n; i++) {
		if(b[i].huychuong == max) {
			cout << b[i];
		}
	}
}
int main() {
	int n, lc;
	VDV a[100];
	VDVDK b[100];
		
	cout << "1. Vận động viên" << endl;
	cout << "2. Vận động viên điền kinh" << endl; 
	cout << "0. Thoát" << endl;
	cout << "Chọn đối tượng: "; cin >> lc;
	
	do {
		switch(lc) {
			case 1: {
				do {
					cout << "\n====================VẬN ĐỘNG VIÊN====================" << endl;
					cout << "|| 1. Nhập thông tin                               ||" << endl;
					cout << "|| 2. Hiển thị danh sách                           ||" << endl;
					cout << "|| 0. Thoát                                        ||" << endl;
					cout << "=====================================================" << endl;
					cout << "Nhập lựa chọn: "; cin >> lc;
					
					switch(lc) {
						case 1: {
							cout << "\n====================NHẬP THÔNG TIN===================" << endl;
							cout << "Nhập số vận động viên: "; cin >> n;
							nhapVDV(a, n);
							break;
						}
						
						case 2: {
							cout << "\n===============DANH SÁCH VẬN ĐỘNG VIÊN===============" << endl;
							xuatVDV(a, n);
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
					cout << "\n==========================================VẬN ĐỘNG VIÊN ĐIỀN KINH==========================================" << endl;
					cout << "|| 1. Nhập thông tin                                                                                     ||" << endl; 
					cout << "|| 2. Vận động viên có số huy chương lớn nhất                                                            ||" << endl;
					cout << "|| 0. Thoát                                                                                              ||" << endl;
					cout << "===========================================================================================================" << endl;
					cout << "Nhập lựa chọn: "; cin >> lc;
					
					switch(lc) {
						case 1: {
							cout << "\n==============================================NHẬP THÔNG TIN===============================================" << endl;
							cout << "Nhập số vận động viên: "; cin >> n;
							nhapVDVDK(b, n);
							break;
						}
						
						case 2: {
							cout << "\n==========================================SỐ HUY CHƯƠNG LỚN NHẤT===========================================" << endl;
							Max(b, n);
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
			
			case 0: {
				break;
			}
			
			default:
				cout << "Lựa chọn không hợp lệ" << endl;
		}
	}while(lc != 0);
	return 0;
}