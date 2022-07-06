#include <iostream>
#include <string>

using namespace std;

class sinhvien
{
public:
		string ten, dob, que;
		int mssv;
		float diem;
public:
		sinhvien()
		{
				this->ten = "";
				this->dob = "";
				this->que = "";
				this->mssv = 0;
				this->diem = 0;
		}
		
		~sinhvien()
		{
				this->ten = "";
				this->dob = "";
				this->que = "";
				this->mssv = 0;
				this->diem = 0;
		}
		
		void nhap()
		{
				cin.ignore();
				cout << "Nhap ten: ";
				getline(cin, this->ten);
				cout << "Nhap ngay thang nam sinh: ";
				getline(cin, this->dob);
				cout << "Nhap que quan: ";
				getline(cin, this->que);
				cout << "Nhap MSSV: ";
				cin >> this->mssv;
				cout << "Nhap diem thi dau vao: ";
				cin >> this->diem;
		}
		
		void xuat()
		{
				cout << "Ten la " << this->ten << endl;
				cout << "Ngay thang nam sinh la " << this->dob << endl;
				cout << "Que o " << this->que << endl;
				cout << "MSSV la " << this->mssv << endl;
				cout << "Diem thi dau vao la " << this->diem << endl;
		}
		
		void xoa()
		{
				this->ten = "";
				this->dob = "";
				this->que = "";
				this->mssv = 0;
				this->diem = 0;
		}	
};

int main()
{
		int n,i,mssv,j,k;
		string que;
		sinhvien temp;
		sinhvien sv[50];
		cout << "Nhap so sinh vien nhe: " << endl;
		cin >> n;
		
		//Nhap thong tin sinh vien
		for (i=0; i<n; i++)
		{		
				cout << "Nhap thong tin sinh vien thu " << i+1 << endl;
				sv[i].nhap();
				cout << endl;
		}
		
		//Xuat thong tin sinh vien
		for (i=0; i<n; i++)
		{
				cout << "Thong tin sinh vien thu " << i+1 << endl;
				sv[i].xuat();
				cout << endl;
		}
		
		//Sap xep sinh vien theo diem
		for (i=0; i<n-1; i++)
				for (k=1; k<n; k++)
				{
						if (sv[i].diem > sv[k].diem)
						{
								temp = sv[i];
								sv[i] = sv[k];
								sv[k] = temp;
						}
				}
		cout << "Danh sach moi sau khi sap xep theo diem la: " << endl;
		for (i=0; i<n; i++)
		{
				cout << "Thong tin sinh vien thu " << i+1 << endl;
				sv[i].xuat();
				cout << endl;
		}
		
		//Sap xep sinh vien theo ten
		for (i=0; i<n-1; i++)
				for (k=1; k<n; k++)
				{
						if (sv[i].ten > sv[k].ten)
						{
								temp = sv[i];
								sv[i] = sv[k];
								sv[k] = temp;
						}
				}
		cout << "Danh sach moi sau khi sap xep theo ten la: " << endl;
		for (i=0; i<n; i++)
		{
				cout << "Thong tin sinh vien thu " << i+1 << endl;
				sv[i].xuat();
				cout << endl;
		}
		
		//Sap xep sinh vien theo mssv
		for (i=0; i<n-1; i++)
				for (k=1; k<n; k++)
				{
						if (sv[i].mssv > sv[k].mssv)
						{
								temp = sv[i];
								sv[i] = sv[k];
								sv[k] = temp;
						}
				}
		cout << "Danh sach moi sau khi sap xep theo mssv la: " << endl;
		for (i=0; i<n; i++)
		{
				cout << "Thong tin sinh vien thu " << i+1 << endl;
				sv[i].xuat();
				cout << endl;
		}
		
		//Sap xep sinh vien theo que quan
		for (i=0; i<n-1; i++)
				for (k=1; k<n; k++)
				{
						if (sv[i].que > sv[k].que)
						{
								temp = sv[i];
								sv[i] = sv[k];
								sv[k] = temp;
						}
				}
		cout << "Danh sach moi sau khi sap xep theo que quan la: " << endl;
		for (i=0; i<n; i++)
		{
				cout << "Thong tin sinh vien thu " << i+1 << endl;
				sv[i].xuat();
				cout << endl;
		}
		
		//Hien thi sinh vien cung que
		cout << "Nhap que can tim: " << endl;
		cin.ignore();
		getline(cin, que);
		for (i=0; i<n; i++)
		{
				if (que == sv[i].que)
				{
						cout << "Sinh vien que o " << que << " co: " << endl;
						sv[i].xuat();
				}
				else if (i == n-1)	
						cout << "Khong co sinh vien nao que o " << que << endl;
		}
		
		//Xoa thong tin sinh vien bat ki
		cout << "Nhap MSSV muon xoa " << endl;
		cin >> mssv;
		for (i=0; i<n; i++)
		{
				if (mssv == sv[i].mssv)			
				{
						sv[i].xoa();
						for (j=i; j<n; j++)
								sv[j] = sv[j+1];
						n=n-1;
						break;
				}
				else if (i == n-1)
						cout << "Khong ton tai MSSV nay" << endl;
		}
		cout << "Danh sach moi sau khi xoa la: " << endl;
		for (i=0;i<n;i++)
		{
				cout << "Thong tin sinh vien thu " << i+1 << endl;
				sv[i].xuat();
				cout << endl;
		}	
}