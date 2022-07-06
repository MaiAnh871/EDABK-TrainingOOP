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
        vector <Shape*> Canh_Noi_Tam;

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

        // Ham tinh dien tich hinh ve
        virtual float Dien_Tich()
        {
            return 0;
        }

        // Ham lay toa do hinh ve
       float getHoanh_Do()
       {
           return hoanhdo;
       }

       float getTung_Do()
       {
           return tungdo;
       }

       // Ham in tat ca cac canh xuat phat tu mot hinh
       void showCanh_1_Hinh()
       {
           int l;
           for (l=0; l<Canh_Noi_Tam.size(); l++)
           {
               Canh_Noi_Tam[l]->xuat();
           }
       }
};

// Lop ke thua: Edge
class Edge: public Shape
{
    public:
        string mausac;
        float dodaynetve;
        Shape* hinh1;
        Shape* hinh2;

        // Ham nhap thong tin canh noi tam
        void nhap()
        {
            cin.ignore();
            cout << endl << "Hay nhap mau sac cua canh noi tam: " << endl;
            getline(cin,mausac);
            cout << "Hay nhap do day net ve cua canh noi tam: " << endl << endl;
            cin >> dodaynetve;
        }

        // Ham xuat thong tin canh noi tam
        void xuat()
        {
            cout << endl << "Doan thang noi tam 2 hinh:" << endl;
            hinh1->xuat();
            hinh2->xuat();
            cout << "Mau sac cua canh noi tam la " << mausac << endl;
            cout << "Do day net ve cua canh noi tam la " << dodaynetve << endl;
        }

        // Ham lay thong tin 2 hinh can noi tam
        void getHinh1(Shape* hinh)
        {
            hinh1 = hinh;
        }

        void getHinh2(Shape* hinh)
        {
            hinh2 = hinh;
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
            cout << endl << "Hay nhap cac thong tin cua hinh tron!" << endl;
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
            cout << endl << "Thong tin hinh tron da nhap la: " << endl;
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
            cout << endl << "Hay nhap cac thong tin hinh chu nhat! " << endl;
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
            cout << endl << "Thong tin hinh chu nhat vua nhap la: " << endl;
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
            cout << endl << "Hay nhap thong tin cua hinh vuong!" << endl;
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
            cout << endl << "Thong tin hinh vuong da nhap la:" << endl;
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
            cout << endl << "Nhap thong tin hinh Oval!" << endl;
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
            cout << endl << "Thong tin hinh Oval vua nhap la:" << endl;
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
            cout << endl << "Nhap thong tin cua doan thang!" << endl;
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
            cout << endl << "Thong tin doan thang vua nhap la:" << endl;
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
            cout << endl << "Nhap thong tin hinh tam giac" << endl;
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
            cout << endl << "Thong tin hinh tam giac vua nhap la:" << endl;
            Shape::xuat();
            cout << "Do dai day va chieu cao tam giac la " << day << "va " << chieucao << endl;
            cout << "Dien tich hinh tam giac la " << Dien_Tich() << endl << endl;
        }
};

// Khai bao mang Danh_Sach_Hinh cac hinh voi kieu Shape
vector <Shape*> Danh_Sach_Hinh;

// Khai bao mang Danh_Sach_Canh cac canh voi kieu Edge
vector <Edge*> Danh_Sach_Canh;

// Ham them thong tin mot hinh
void addHinh()
{
    int hinh;

    // Tao menu cac hinh
    cout << endl << "Nhap so tuong ung voi hinh ban muon them!" << endl;
    cout << "1. Hinh tron." << endl;
    cout << "2. Hinh chu nhat." << endl;
    cout << "3. Hinh vuong." << endl;
    cout << "4. Hinh oval." << endl;
    cout << "5. Doan thang." << endl;
    cout << "6. Hinh tam giac." << endl << endl;
    cin >> hinh;

    switch(hinh)
    {
        case 1:
        {
            Danh_Sach_Hinh.push_back(new Circle);
            Danh_Sach_Hinh.back()->nhap();
            break;
        }

        case 2: 
        {
            Danh_Sach_Hinh.push_back(new Rectangle);
            Danh_Sach_Hinh.back()->nhap();
            break;
        }

        case 3:
        {
            Danh_Sach_Hinh.push_back(new Square);
            Danh_Sach_Hinh.back()->nhap();
            break;
        }

        case 4:
        {
            Danh_Sach_Hinh.push_back(new Oval);
            Danh_Sach_Hinh.back()->nhap();
            break;
        }

        case 5:
        {
            Danh_Sach_Hinh.push_back(new Line);
            Danh_Sach_Hinh.back()->nhap();
            break;
        }

        case 6:
        {
            Danh_Sach_Hinh.push_back(new Triangle);
            Danh_Sach_Hinh.back()->nhap();
            break;
        }

        default: // Nhap cac so ngoai tu 1 toi 6
        {
            cout << "Khong co hinh nao duoc them vao!" << endl << endl;
        }
    }
}

// Ham in ra thong tin cac hinh vua nhap
void showHinh()
{
    int i;
    if (Danh_Sach_Hinh.size() == 0) cout << endl << "Danh sach khong co hinh ve nao!" << endl << endl;
    else
    {
        for (i=0; i<Danh_Sach_Hinh.size(); i++)
        {
            cout << endl << "Hinh thu " << i+1 << ":" << endl;
            Danh_Sach_Hinh[i]->xuat();
        }
    }
}

// Hap nhap thong tin mot canh
void addCanh()
{
    if (Danh_Sach_Hinh.size() < 2) cout << "Danh sach khong du hinh ve de them canh!" << endl;
    else
    {
        int u,v;
        cout << endl << "Nhap chi so 2 hinh ban muon noi tam:" << endl;
        cin >> u;
        cin >> v;

        // Goi toi ham them 1 canh noi tam
        Danh_Sach_Canh.push_back(new Edge);

        // Goi toi ham them thong tin 2 hinh can noi tam vao Danh sach cac canh
        Danh_Sach_Canh.back()->getHinh1(Danh_Sach_Hinh[u]);
        Danh_Sach_Canh.back()->getHinh2(Danh_Sach_Hinh[v]);

        // Goi toi ham them thong tin canh vua nhap vao thong tin 2 hinh tuong ung
        Danh_Sach_Hinh[u]->Canh_Noi_Tam.push_back(Danh_Sach_Canh.back());
        Danh_Sach_Hinh[v]->Canh_Noi_Tam.push_back(Danh_Sach_Canh.back());
        Danh_Sach_Canh.back()->nhap();
    }
}

// Ham in ra thong tin tat ca cac canh
void showCanh()
{
    int m;
    if (Danh_Sach_Canh.size() == 0) cout << endl << "Danh sach khong co canh noi tam nao!" << endl << endl;
    else
    {
        for (m=0; m<Danh_Sach_Canh.size(); m++)
        {
            cout << "Canh thu " << m+1 << ":" << endl;
            Danh_Sach_Canh[m]->xuat();
        }
    }
}

// Ham in ra thong tin tat ca cac canh xuat phat tu mot hinh
void showCanh_1_Hinh()
{
    int n,o;
    cout << endl << "Nhap chi so hinh ban muon xem thong tin canh:" << endl;
    cin >> n;
    if (Danh_Sach_Hinh[n]->Canh_Noi_Tam.size() == 0) cout << endl << "Khong co canh nao xuat phat tu hinh nay!" << endl;
    else
    {
        cout << endl << "Thong tin cac canh xuat phat tu hinh ban vua nhap la:" << endl;
        Danh_Sach_Hinh[n]->showCanh_1_Hinh();
    }
}

int main()
{
    vector <Shape*> Danh_Sach_Hinh;
    vector <Edge*> Danh_Sach_Canh;
    
    int a;
    while (1)
    {
        // In menu
        cout << endl << "Nhap so tuong ung voi cong viec ban muon thuc hien!" << endl;
        cout << "1. Nhap them thong tin mot hinh." << endl;
        cout << "2. In ra thong tin cac hinh da nhap." << endl;
        cout << "3. Them 1 canh noi tam." << endl;
        cout << "4. In ra thong tin cac canh da nhap." << endl;
        cout << "5. In ra thong tin cac canh xuat phat tu mot hinh." << endl;
        cout << "6. Thoat khoi chuong trinh." << endl << endl;
        cin >> a;

        switch(a)
        {
            case 1:
            {
                addHinh();
                continue;
            }

            case 2:
            {
                showHinh();
                continue;
            }

            case 3:
            {
                addCanh();
                continue;
            }

            case 4:
            {
                showCanh();
                continue;
            }

            case 5:
            {
                showCanh_1_Hinh();
                continue;
            }

            case 6:
            {
                break;
            }
        }
        break;
    }
            return 0;
}



    


