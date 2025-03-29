//Viết một chương trình bằng NNLT C++ thực hiện các công việc sau:
//1.  (4 điểm) Xây dựng lớp nhân viên NV gồm những thuộc tính sau:
// Mã nhân viên, Họ tên, chức vụ, Hệ số lương là các thuộc tính. 
// Trong lớp có định nghĩa các hàm công cộng sau:	
//-	Hàm khởi tạo với các tham số có giá trị ngầm định.
//-	Hàm hủy.
//-	Hàm nhập dữ liệu cho một nhân viên.
//-	Hàm in các thông tin của một nhân viên.
//2. (4 điểm) Xây dựng lớp cán bộ CB kế thừa từ lớp NV, lớp CB 
// bổ sung thêm các thuộc tính: Số năm công tác và lớp này gồm các
// hàm thành phần:
//-	Hàm khởi tạo với các tham số có giá trị ngầm định.
//-	Hàm hủy.
//-	Tái định nghĩa toán tử nhập  “>>”.
//-	Hàm tính tiền phụ cấp chức vụ. Nếu chức vụ là  giám đốc “GD” 
// thì phụ cấp là 10 triệu, nếu chức vụ là  trưởng phòng “TP” 
// thì phụ cấp là 5 triệu còn lại là 1 triệu. 
//-	Tái định nghĩa toán tử lớn hơn  “>” để so sánh 2 CB với nhau 
// (theo số năm công tác)
//-	Tái định nghĩa toán tử xuất “<<”. 
//3. (1 điểm) Nhập vào danh sách n nhân viên (n nguyên dương 
// nhập từ bàn phím), hiển thị danh sách đã nhập.
//4. (1 điểm) Nhập vào danh sách n cán bộ (n nguyên dương nhập 
// từ bàn phím), hiển thị danh sách cán bộ theo thứ tự giảm dần 
// của số năm công tác(bằng cách sử dụng chồng toán tử so sánh 
// đã định nghĩa ở câu 2).

#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;
class NV {
	protected:
		char ma[100], hoten[100], chucvu[100];
		float heluong;
	public:
		NV(char ma[100]=" ", char hoten[100]=" ", char chucvu[100]=" ", float heluong=0.0) : heluong(heluong) {
			strcpy(this->ma, ma);
			strcpy(this->hoten, hoten);
			strcpy(this->chucvu, chucvu);
		}
		
		~NV() {}
		
		void Nhap();
		
		void Xuat();
};

void NV::Nhap() {
	fflush(stdin);
	cout << "Nhập mã: "; cin.getline(ma, 100);
	cout << "Nhập họ tên: "; cin.getline(hoten, 100);
	cout << "Nhập chức vụ: "; cin.getline(chucvu, 100);
	fflush(stdin);
	cout << "Nhập hệ số lương: "; cin >> heluong;
}

void NV::Xuat() {
	cout << left << setw(20) << ma <<
					setw(20) << hoten <<
					setw(20) << chucvu <<
					setw(20) << heluong;
}

void nhapNV(NV a[], int n) {
	for(int i = 0; i < n; i++) {
		cout << i+1 << ")" << endl;
		a[i].Nhap();
		cout << endl;
	}
}

void TieudeNV() {
	cout << left << setw(20) << "MÃ:" <<
					setw(20) << "HỌ TÊN:" <<
					setw(20) << "CHỨC VỤ:" <<
					setw(20) << "HỆ LƯƠNG:";
}

void xuatNV(NV a[], int n) {
	TieudeNV();
	cout << endl;
	for(int i = 0; i < n; i++) {
		a[i].Xuat();
		cout << endl;
	}
}

class CB : public NV {
	protected:
		int sonam;
	public:
		CB(char ma[100]=" ", char hoten[100]=" ", char chucvu[100]=" ", float heluong=0.0) : NV(ma, hoten, chucvu, heluong), sonam(sonam) {}
		
		~CB() {}
		
		friend istream& operator>>(istream& cin, CB &cb);
		
		long long getPhuCap() {
			if(strcmp(chucvu, "GD") == 0) {
				return 10000000;
			} else if(strcmp(chucvu, "TP") == 0) {
				return 5000000;
			} else {
				return 1000000;
			}
		}
		
		bool operator>(CB other) {
			return sonam > other.sonam;
		}
		
		friend ostream& operator<<(ostream& cout, CB &cb);
		
		friend void Sapxep(CB b[], int n);
};

istream& operator>>(istream& cin, CB &cb) {
	cb.Nhap();
	cout << "Nhập số năm công tác: "; cin >> cb.sonam;
	return cin;
}

ostream& operator<<(ostream& cout, CB &cb) {
	cb.Xuat();
	cout << setw(20) << cb.sonam <<
			setw(20) << cb.getPhuCap() << endl;
	return cout;
}

void nhapCB(CB b[], int n) {
	for(int i = 0; i < n; i++) {
		cout << i+1 << ")" << endl;
		cin >> b[i];
		cout << endl;
	}
}

void TieudeCB() {
	TieudeNV();
	cout << setw(20) << "SỐ NĂM LÀM:" <<
			setw(20) << "PHỤ CẤP:" << endl;
}

void xuatCB(CB b[], int n) {
	TieudeCB();
	for(int i = 0; i < n; i++) {
		cout << b[i];
	}
}

void Swap(CB &x, CB &y) {
	CB temp = x;
	x = y;
	y = temp;
}

void Sapxep(CB b[], int n) {
	for(int i = 0; i < n-1; i++) {
		for(int j = i+1; j < n; j++) {
			if(b[i].sonam < b[j].sonam) {
				Swap(b[i], b[j]);
			}
		}
	}
	xuatCB(b, n);
}
int main() {
	int n, lc;
	NV a[100];
	CB b[100];
	
	do {
		cout << "1. Nhân viên" << endl;
		cout << "2. Cán bộ" << endl;
		cout << "3. Thoát" << endl;
		cout << "Chọn đối tượng: "; cin >> lc;
		
		switch(lc) {
			case 1: {
				do {
					cout << "\n==============================NHÂN VIÊN===============================" << endl;
					cout << "|| 1. Nhập thông tin                                                ||" << endl;
					cout << "|| 2. In thông tin                                                  ||" << endl;
					cout << "|| 0. Thoát                                                         ||" << endl;
					cout << "======================================================================" << endl;
					cout << "Nhập lựa chọn: "; cin >> lc;
					
					switch(lc) {
						case 1: {
							cout << "\n===========================NHẬP THÔNG TIN=============================" << endl;
							cout << "Nhập số nhân viên: "; cin >> n;
							nhapNV(a, n);
							break;
						}
						
						case 2: {
							cout << "\n==============================IN THÔNG TIN============================" << endl;
							xuatNV(a, n);
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
					cout << "\n=====================================================CÁN BỘ==================================================" << endl;
					cout << "|| 1. Nhập thông tin                                                                                       ||" << endl;
					cout << "|| 2. In thông tin                                                                                         ||" << endl;
					cout << "|| 0. Thoát                                                                                                ||" << endl;
					cout << "=============================================================================================================" << endl;
					cout << "Nhập lựa chọn: "; cin >> lc;
					
					switch(lc) {
						case 1: {
							cout << "\n=================================================NHẬP THÔNG TIN==============================================" << endl;
							cout << "Nhập số nhân viên: "; cin >> n;
							nhapCB(b, n);
							break;
						}
						
						case 2: {
							cout << "\n=============================================NĂM CÔNG TÁC TĂNG DẦN===========================================" << endl;
							Sapxep(b, n);
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
				cout << "Đối tượng không phù hợp" << endl;
		}
	}while(lc != 0);
	return 0;
}
