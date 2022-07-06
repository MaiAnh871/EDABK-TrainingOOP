#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Lop co so: Shape
class Shape
{
    public:
        float hoanhdo, tungdo, dorongnetve;
        string mausac;

    public:
        // Ham nhap thong tin cua hinh ve
        virtual void nhap()
        {
            cin.ignore();
            cout << "Hay nhap mau sac cua hinh ve: " << endl;
            getline(cin,mausac);
            cout << "Hay nhap vi tri cua hinh ve: " << endl;
            cout << "Hay nhap hoanh do cua hinh ve: " << endl;
            cin >> hoanhdo;
            cout << "Hay nhap tung do cua hinh ve: " << endl;
            cin >> tungdo;
            cout << "Hay nhap do rong net cua hinh ve: " << endl;
            cin >> dorongnetve;
        }

        // Ham in thong tin hinh ve ra man hinh
        virtual void xuat()
        {                                                    
            cout << "Vi tri cua hinh ve la (" << hoanhdo << "," << tungdo << ")" << endl;
            cout << "Mau sac cua hinh ve la " << mausac << endl;
            cout << "Do rong net cua hinh ve la " << dorongnetve << endl;
        }

        virtual float Dien_Tich()
        {
            return 0;
        }

       //Ham lay toa do hinh ve
       float getHoanh_Do()
       {
           return hoanhdo;
       }

       float getTung_Do()
       {
           return tungdo;
       }
};

// Lop ke thua: Circle
class Circle: public Shape
{
    public:
        float bankinh;
        const float pi = 3.14;

        // Ham nhap ban kinh hinh tron
        void nhap()
        {
            cout << "Hay nhap cac thong tin cua hinh tron!" << endl;
            Shape::nhap();
            cout << "Hay nhap ban kinh hinh tron: " << endl;
            cin >> bankinh;
        }

        // Ham tinh dien tich hinh tron
        float Dien_Tich()
        {
            return pi * bankinh * bankinh;
        }

        // Ham in thong tin hinh tron
        void xuat()
        {
            cout << "Thong tin hinh tron da nhap la: " << endl;
            Shape::xuat();
            cout << "Ban kinh hinh tron la " << bankinh << endl;
            cout << "Dien tich hinh tron la " << Dien_Tich() << endl << endl;
        }
};

// Lop ke thua: Rectangle
class Rectangle: public Shape
{
    public:
        float chieudai, chieurong;

        // Ham nhap kich thuoc hinh chu nhat
        void nhap()
        {
            cout << "Hay nhap cac thong tin hinh chu nhat! " << endl;
            Shape::nhap();
            cout << "Hay nhap chieu dai hinh chu nhat: " << endl;
            cin >> chieudai;
            cout << "Hay nhap chieu rong hinh chu nhat: " << endl;
            cin >> chieurong;
        }

        // Ham tinh dien tich hinh chu nhat
        float Dien_Tich()
        {
            return chieudai * chieurong;
        }

        // Ham in thong tin hinh chu nhat
        void xuat()
        {
            cout << "Thong tin hinh chu nhat vua nhap la: " << endl;
            Shape::xuat();
            cout << "Chieu dai va chieu rong hinh chu nhat la " << chieudai << " va " << chieurong << endl;
            cout << "Dien tich hinh chu nhat la " << Dien_Tich() << endl << endl;
        }
};

// Lop ke thua: Square
class Square: public Shape
{
    public:
        float dorong;

        // Ham nhap kich thuoc hinh vuong
        void nhap()
        {
            cout << "Hay nhap thong tin cua hinh vuong!" << endl;
            Shape::nhap();
            cout << "Hay nhap do rong canh hinh vuong" << endl;
            cin >> dorong;
        }

        // Ham tinh dien tich hinh vuong
        float Dien_Tich()
        {
            return dorong * dorong;
        }

        // Ham in thong tin hinh vuong
        void xuat()
        {
            cout << "Thong tin hinh vuong da nhap la:" << endl;
            Shape::xuat();
            cout << "Do rong canh cua hinh vuong la " << dorong << endl;
            cout << "Dien tich cua hinh vuong la " << Dien_Tich() << endl << endl;
        }
};

// Lop ke thua: Oval
class Oval: public Shape
{
    public:
        float trucdai, trucngan;
        const float pi = 3.14;

        // Ham nhap kich thuoc hinh Oval
        void nhap()
        {
            cout << "Nhap thong tin hinh Oval!" << endl;
            Shape::nhap();
            cout << "Hay nhap do dai truc dai: " << endl;
            cin >> trucdai;
            cout << "Hay nhap do dai truc ngan" << endl;
            cin >> trucngan;
        }

        // Ham tinh dien tich hinh Oval
        float Dien_Tich()
        {
            return pi * trucdai/2 * trucngan/2;
        }

        // Ham in thong tin hinh Oval
        void xuat()
        {
            cout << "Thong tin hinh Oval vua nhap la:" << endl;
            Shape::xuat();
            cout << "Do dai truc dai va truc ngan hinh Oval la " << trucdai << "va " << trucngan << endl;
            cout << "Dien tich hinh Oval la " << Dien_Tich() << endl << endl;
        }
};

// Lop ke thua: Line
class Line: public Shape
{
    public:
        float dodai;

        // Ham nhap kich thuoc doan thang
        void nhap()
        {
            cout << "Nhap thong tin cua doan thang!" << endl;
            Shape::nhap();
            cout << "Hay nhap do dai doan thang: " << endl;
            cin >> dodai;
        }

        // Dat dien tich doan thang la 0
        float Dien_Tich()
        {
            return 0;
        }

        // Ham in thong tin doan thang
        void xuat()
        {
            cout << "Thong tin doan thang vua nhap la:" << endl;
            Shape::xuat();
            cout << "Do dai doan thang la " << dodai << endl;
            cout << "Dien tich doan thang la " << Dien_Tich() << endl << endl;
        }
};

// Lop ke thua: Triangle
class Triangle: public Shape
{
    public:
        float day, chieucao;

        // Ham nhap kich thuoc hinh tam giac
        void nhap()
        {
            cout << "Nhap thong tin hinh tam giac" << endl;
            Shape::nhap();
            cout << "Hay nhap do dai day tam giac: " << endl;
            cin >> day;
            cout << "Hay nhap chieu cao tam giac: " << endl;
            cin >> chieucao;
        }

        // Ham tinh dien tich tam giac
        float Dien_Tich()
        {
            return day * chieucao / 2;
        }

        // Ham in thong tin hinh tam giac
        void xuat()
        {
            cout << "Thong tin hinh tam giac vua nhap la:" << endl;
            Shape::xuat();
            cout << "Do dai day va chieu cao tam giac la " << day << "va " << chieucao << endl;
            cout << "Dien tich hinh tam giac la " << Dien_Tich() << endl << endl;
        }
};

// Khai bao mang Danh_Sach cac hinh voi kieu Shape
vector <Shape*> Danh_Sach;

// Ham them thong tin mot hinh
void themHinh()
{
    int hinh;

    // Tao menu cac hinh
    cout << "Nhap so tuong ung voi hinh ban muon them!" << endl;
    cout << "1. Hinh tron." << endl;
    cout << "2. Hinh chu nhat." << endl;
    cout << "3. Hinh vuong." << endl;
    cout << "4. Hinh oval." << endl;
    cout << "5. Doan thang." << endl;
    cout << "6. Hinh tam giac." << endl;
    cin >> hinh;

    switch(hinh)
    {
        case 1:
        {
            Danh_Sach.push_back(new Circle);
            Danh_Sach.back()->nhap();
            break;
        }

        case 2: 
        {
            Danh_Sach.push_back(new Rectangle);
            Danh_Sach.back()->nhap();
            break;
        }

        case 3:
        {
            Danh_Sach.push_back(new Square);
            Danh_Sach.back()->nhap();
            break;
        }

        case 4:
        {
            Danh_Sach.push_back(new Oval);
            Danh_Sach.back()->nhap();
            break;
        }

        case 5:
        {
            Danh_Sach.push_back(new Line);
            Danh_Sach.back()->nhap();
            break;
        }

        case 6:
        {
            Danh_Sach.push_back(new Triangle);
            Danh_Sach.back()->nhap();
            break;
        }

        default: // Nhap cac so ngoai tu 1 toi 6
        {
            cout << "Khong co hinh nao duoc them vao!" << endl << endl;
        }
    }
}

// Ham in ra thong tin cac hinh vua nhap
void inHinh()
{
    int i;
    if (Danh_Sach.size() == 0) cout << "Danh sach khong co hinh ve nao!" << endl << endl;
    else
    {
        for (i=0; i<Danh_Sach.size(); i++)
        {
            cout << "Hinh thu " << i+1 << ":" << endl;
            Danh_Sach[i]->xuat();
        }
    }
}

// Ham xoa mot hinh
void xoaHinh()
{
    int j;
    if (Danh_Sach.size() == 0) cout << "Danh sach khong co hinh ve nao de xoa!" << endl << endl;
    else
    {
        cout << "Hay nhap chi so hinh muon xoa!" << endl;
        cin >> j;
        if ((j<0) || (j>=Danh_Sach.size())) cout << "Khong ton tai chi so hinh ve nay!" << endl << endl;
        else
        {
            Danh_Sach[j] = Danh_Sach[j+1];
            Danh_Sach.pop_back();
            cout << "Danh sach cac hinh sau khi xoa la: " << endl;
            inHinh();
        }   
    }   
}

// Sap xep cac hinh theo thu tu tang dan dien tich.
void sapxep()
{
    Shape* temp;
    int p,q;
    for (p=0; p<Danh_Sach.size()-1; p++)
    {
        for (q=p+1; q<Danh_Sach.size(); q++)
        {
            if (Danh_Sach[p]->Dien_Tich() > Danh_Sach[q]->Dien_Tich())
            {
                temp = Danh_Sach[p];
                Danh_Sach[p] = Danh_Sach[q];
                Danh_Sach[q] = temp;
            }
        }
    }
    cout << "Danh sach cac hinh sau khi sap xep la:" << endl;
    inHinh();
}

// Ham tim kiem mot hinh voi toa do cho truoc
void timkiem()
{
    float toadox, toadoy;
    int m;
    cout << "Hay nhap toa do hinh can tim!" << endl;
    cout << "Hay nhap hoanh do hinh can tim!" << endl;
    cin >> toadox;
    cout << "Hay nhap tung do hinh can tim!" << endl;
    cin >> toadoy;

    for (m=0; m<Danh_Sach.size(); m++)
    {
        if ((toadox == Danh_Sach[m]->getHoanh_Do()) && (toadoy == Danh_Sach[m]->getTung_Do()))
            {
                cout << "Toa do da nhap ung voi hinh: " << endl;
                Danh_Sach[m]->xuat();
                break;
            }
        else if (m == Danh_Sach.size()-1) cout << "Khong ton tai hinh ve nay!" << endl << endl;
    }
}

int main()
{
    vector <Shape*> Danh_Sach;
    int n;
    while (1)
    {
        // In menu
        cout << "Nhap so tuong ung voi cong viec ban muon thuc hien!" << endl;
        cout << "1. Nhap them thong tin mot hinh." << endl;
        cout << "2. In ra thong tin cac hinh da nhap." << endl;
        cout << "3. Xoa mot hinh." << endl;
        cout << "4. Sap xep cac hinh theo thu tu tang dan dien tich." << endl;
        cout << "5. Tim kiem mot hinh voi toa do nhap tu ban phim." << endl;
        cout << "6. Thoat khoi chuong trinh." << endl << endl;
        cin >> n;

        switch(n)
        {
            case 1:
            {
                themHinh();
                continue;
            }

            case 2:
            {
                inHinh();
                continue;
            }

            case 3:
            {
                xoaHinh();
                continue;
            }

            case 4:
            {
                sapxep();
                continue;
            }

            case 5:
            {
                timkiem();
                continue;
            }

            case 6:
            {
                break;
            }
        }
        break;
    }
}

        
