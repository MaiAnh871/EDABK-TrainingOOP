#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <fstream>
#include <memory>
#include <math.h>

using namespace std;

class Shape //Lop co so: Shape
{
    public:
        float x, y, thickness; // Toa do tam va do rong net ve
        string color; // Mau sac hinh ve
        vector <Edge*> Edge1_List;

    public:
        Shape() // Ham constructor cua Shape
        {
            x = 0;
            y = 0;
            thickness = 0;
            color = "";
            cout << "Ham khoi tao duoc goi." << endl;
        }

        ~Shape() // Ham destructor cua Shape
        {
            x = 0;
            y = 0;
            thickness = 0;
            color = "";
            cout << "Ham huy duoc goi." << endl;
        }

        virtual void set() // Ham nhap thong tin hinh ve
        {
            cin.ignore();
            cout << "Hay nhap mau sac cua hinh ve: " << endl;
            getline (cin,color);
            cout << "Hay nhap vi tri cua hinh ve: " << endl;
            cout << "Hay nhap hoanh do cua hinh ve: " << endl;
            cin >> x;
            cout << "Hay nhap tung do cua hinh ve: " << endl;
            cin >> y;
            cout << "Hay nhap do rong net cua hinh ve: " << endl;
            cin >> thickness;
        }

        virtual void show() // Ham xuat thong tin hinh ve
        {
            cout << "Vi tri cua hinh ve la (" << x << "," << y << ")" << endl;
            cout << "Mau sac cua hinh ve la " << color << endl;
            cout << "Do rong net cua hinh ve la " << thickness << endl;
        }

        // Ham lay toa do hinh ve
        float getX()
        {
           return x;
        }

        float getY()
        {
           return y;
        }

        virtual float getArea()
        {
            return 0;
        }

        void showEdge1Shape() // Ham in ra tat ca cac canh noi tam 1 hinh bat ki
        {
           int l;
           for (l=0; l<Edge1_List.size(); l++)
           {
               Edge1_List[l]->show();
           }
        }

        // Cac ham lay thong tin cua Shape tu File
        virtual void setColor (string c)
        {
            color = c;
        }

        virtual void setX (float hd)
        {
            x = hd;
        }

        virtual void setY (float td)
        {
            y = td;
        }

        virtual void setThickness (float tn)
        {
            thickness = tn;
        }

        virtual void setSize1(double size) {}

        virtual void setSize2(double size) {}

        virtual void setSize3(double size) {}
};


class Edge // Lop co so: Edge
{
    public:
        string color;
        float thickness;
        Shape* shape1; // Tao bien hinh duoc noi tam dau tien la shape1 kieu Shape
        Shape* shape2; // Tao bien hinh duoc noi tam thu hai la shape2 kieu Shape

        virtual void set() // Ham nhap thong tin canh noi tam
        {
            cin.ignore();
            cout << endl << "Hay nhap mau sac cua canh noi tam: " << endl;
            getline (cin, color);
            cout << "Hay nhap do day net ve cua canh noi tam: " << endl << endl;
            cin >> thickness;
        }

        virtual void show() // Ham xuat thong tin canh noi tam
        {
            cout << endl << "Doan thang noi tam 2 hinh:" << endl;
            shape1->show(); // Goi ham xuat thong tin hinh duoc noi tam dau tien
            shape2->show(); // Goi ham xuat thong tin hinh duoc noi tam thu hai
            cout << "Mau sac cua canh noi tam la " << color << endl;
            cout << "Do day net ve cua canh noi tam la " << thickness << endl;
        }

        void getShape1(Shape* shape) // Ham lay thong tin hinh can noi tam thu nhat
        {
            shape1 = shape;
        }

        void getShape2(Shape* shape) // Ham lay thong tin hinh can noi tam thu hai
        {
            shape2 = shape;
        }

        // Cac ham lay thong tin cua Edge tu File
        void setColor(string c)
        {
            color = c;
        }

        void setThickness(float tn)
        {
            thickness = tn;
        }
};


class Circle: public Shape // Lop ke thua: Circle
{
    protected:
        float radius; // Ban kinh hinh tron
        const float pi = 3.14;

    public:
        void set() // Ham nhap ban kinh hinh tron
        {
            cout << endl << "Hay nhap cac thong tin cua hinh tron!" << endl;
            Shape::set();
            cout << "Hay nhap ban kinh hinh tron: " << endl;
            cin >> radius;
        }

        float getArea() // Ham tinh dien tich hinh tron
        {
            return pi * radius * radius;
        }

        void show() // Ham in thong tin hinh tron
        {
            cout << endl << "Thong tin hinh tron da nhap la: " << endl;
            Shape::show();
            cout << "Ban kinh hinh tron la " << radius << endl;
            cout << "Dien tich hinh tron la " << getArea() << endl << endl;
        }

        // Cac ham lay thong tin cua Shape tu File
        virtual void setColor (string c)
        {
            color = c;
        }

        virtual void setX (float hd)
        {
            x = hd;
        }

        virtual void setY (float td)
        {
            y = td;
        }

        virtual void setThickness (float tn)
        {
            thickness = tn;
        }

        virtual void setSize1(double size) // Circle chi co 1 kich thuoc
        {
            radius = size;
        }
};


class Rectangle: public Shape // Lop ke thua: Rectangle
{
    protected:
        float length, width; // Chieu dai va chieu rong
    
    public:
        void set() // Ham nhap kich thuoc hinh chu nhat
        {
            cout << endl << "Hay nhap cac thong tin hinh chu nhat! " << endl;
            Shape::show();
            cout << "Hay nhap chieu dai hinh chu nhat: " << endl;
            cin >> length;
            cout << "Hay nhap chieu rong hinh chu nhat: " << endl;
            cin >> width;
        }

        float getArea() // Ham tinh dien tich hinh chu nhat
        {
            return length * width;
        }

        void show() // Ham in thong tin hinh chu nhat
        {
            cout << endl << "Thong tin hinh chu nhat vua nhap la: " << endl;
            Shape::show();
            cout << "Chieu dai va chieu rong hinh chu nhat la " << length << " va " << width << endl;
            cout << "Dien tich hinh chu nhat la " << getArea() << endl << endl;
        }

        // Cac ham lay thong tin cua Shape tu File
        virtual void setColor (string c)
        {
            color = c;
        }

        virtual void setX (float hd)
        {
            x = hd;
        }

        virtual void setY (float td)
        {
            y = td;
        }

        virtual void setThickness (float tn)
        {
            thickness = tn;
        }

        // Rectangle co 2 kich thuoc
        virtual void setSize1(double size)
        {
            length = size;
        }

        virtual void setSize2(double size)
        {
            width = size;
        }
};


class Square: public Shape // Lop co so: Square
{
    protected:
        float width; // Do rong

    public:
        void set() // Ham nhap kich thuoc hinh vuong
        {
            cout << endl << "Hay nhap thong tin cua hinh vuong!" << endl;
            Shape::show();
            cout << "Hay nhap do rong canh hinh vuong" << endl;
            cin >> width;
        }

        float getArea() // Ham tinh dien tich hinh vuong
        {
            return width * width;
        }

        void show() // Ham in thong tin hinh vuong
        {
            cout << endl << "Thong tin hinh vuong da nhap la:" << endl;
            Shape::show();
            cout << "Do rong canh cua hinh vuong la " << width << endl;
            cout << "Dien tich cua hinh vuong la " << getArea() << endl << endl;
        }

        // Cac ham lay thong tin cua Shape tu File
        virtual void setColor (string c)
        {
            color = c;
        }

        virtual void setX (float hd)
        {
            x = hd;
        }

        virtual void setY (float td)
        {
            y = td;
        }

        virtual void setThickness (float tn)
        {
            thickness = tn;
        }

        virtual void setSize1(double size) // Square co 1 kich thuoc
        {
            width = size;
        }

};


class Oval: public Shape // Lop ke thua: Oval
{
    protected:
        float major, minor; // Do dai truc dai va truc ngan
        const float pi = 3.14;

    public:
        void set() // Ham nhap kich thuoc hinh Oval
        {
            cout << endl << "Nhap thong tin hinh Oval!" << endl;
            Shape::set();
            cout << "Hay nhap do dai truc dai: " << endl;
            cin >> major;
            cout << "Hay nhap do dai truc ngan" << endl;
            cin >> minor;
        }

        float getArea() // Ham tinh dien tich hinh Oval
        {
            return pi * minor/2 * major/2;
        }

        void show() // Ham in thong tin hinh Oval
        {
            cout << endl << "Thong tin hinh Oval vua nhap la:" << endl;
            Shape::show();
            cout << "Do dai truc dai va truc ngan hinh Oval la " << major << "va " << minor << endl;
            cout << "Dien tich hinh Oval la " << getArea() << endl << endl;
        }

        // Cac ham lay thong tin cua Shape tu File
        virtual void setColor (string c)
        {
            color = c;
        }

        virtual void setX (float hd)
        {
            x = hd;
        }

        virtual void setY (float td)
        {
            y = td;
        }

        virtual void setThickness (float tn)
        {
            thickness = tn;
        }

        // Oval co 2 kich thuoc
        virtual void setSize1(double size)
        {
            major = size;
        }

        virtual void setSize2(double size)
        {
            minor = size;
        }
};


class Line: public Shape // Lop ke thua Line
{
    protected:
        float length; // Chieu dai

    public:
        void set() // Ham nhap kich thuoc doan thang
        {
            cout << endl << "Nhap thong tin cua doan thang!" << endl;
            Shape::set();
            cout << "Hay nhap do dai doan thang: " << endl;
            cin >> length;
        }

        float getArea() // Dat dien tich doan thang la 0
        {
            return 0;
        }

        void show() // Ham in thong tin doan thang
        {
            cout << endl << "Thong tin doan thang vua nhap la:" << endl;
            Shape::show();
            cout << "Do dai doan thang la " << length << endl;
            cout << "Dien tich doan thang la " << getArea() << endl << endl;
        }

        // Cac ham lay thong tin cua Shape tu File
        virtual void setColor (string c)
        {
            color = c;
        }

        virtual void setX (float hd)
        {
            x = hd;
        }

        virtual void setY (float td)
        {
            y = td;
        }

        virtual void setThickness (float tn)
        {
            thickness = tn;
        }

        // Line co 1 kich thuoc
        virtual void setSize1(double size)
        {
            length = size;
        }
};


class Triangle: public Shape // Lop ke thua: Triangle
{
    protected:
        float edge1, edge2, edge3; // Do dai canh

    public:
        void set() // Ham nhap kich thuoc hinh tam giac
        {
            cout << endl << "Nhap thong tin hinh tam giac" << endl;
            Shape::set();
            cout << "Hay nhap do dai 3 canh tam giac: " << endl;
            cin >> edge1;
            cin >> edge2;
            cin >> edge3;
        }

        float getArea() // Ham tinh dien tich tam giac
        {
            double p = (edge1 + edge2 + edge3)/2;
            return sqrt((p-edge1) * (p-edge2) * (p-edge3));
        }

        void show() // Ham in thong tin hinh tam giac
        {
            cout << endl << "Thong tin hinh tam giac vua nhap la:" << endl;
            Shape::show();
            cout << "Do dai 3 canh tam giac la " << edge1 << ", " << edge2 << "va " << edge3 << endl;
            cout << "Dien tich hinh tam giac la " << getArea() << endl << endl;
        }

        // Cac ham lay thong tin cua Shape tu File
        virtual void setColor (string c)
        {
            color = c;
        }

        virtual void setX (float hd)
        {
            x = hd;
        }

        virtual void setY (float td)
        {
            y = td;
        }

        virtual void setThickness (float tn)
        {
            thickness = tn;
        }

        // Triangle co 3 kich thuoc
        virtual void setSize1(double size)
        {
            edge1 = size;
        }

        virtual void setSize2(double size)
        {
            edge2 = size;
        }

        virtual void setSize3(double size)
        {
            edge3 = size;
        }
};


class ShapeFactory // class Factory
{
    public:
        enum Shape_Type // Khai bao cac shape kieu liet ke
        {
            circle = 1,
            rectangle = 2,
            square = 3,
            oval = 4,
            line = 5,
            triangle = 6
        };

        static Shape* getShape (int shape_type)
        {
            if (shape_type == circle)
            {
                return new Circle;
            }
            else if (shape_type == rectangle)
            {
                return new Rectangle;
            }
            else if (shape_type == square)
            {
                return new Square;
            }
            else if (shape_type == oval)
            {
                return new Oval;
            }
            else if (shape_type == line)
            {
                return new Line;
            }
            else if (shape_type == triangle)
            {
                return new Triangle;
            }
            return NULL;
        }
};

//=============================================================================================================================================//

class Graph
{
    public: 
        vector <Shape*> Shape_List; // vector luu danh sach cac Shape
        vector <Edge*> Edge_List, Edge1_List; // vector luu danh sach cac Edge va vector luu danh sach cac Edge xuat phat tu mot hinh
    
        void addShape(vector <Shape*>& Shape_List) // Ham tao them mot hinh moi
        {
            int shape; // So tuong ung voi moi hinh
            cout << endl << "Nhap so tuong ung voi hinh ban muon them!" << endl; // Tao menu cac hinh
            cout << "1. Hinh tron." << endl;
            cout << "2. Hinh chu nhat." << endl;
            cout << "3. Hinh vuong." << endl;
            cout << "4. Hinh oval." << endl;
            cout << "5. Doan thang." << endl;
            cout << "6. Hinh tam giac." << endl << endl;
            cin >> shape;

            Shape_List.push_back(ShapeFactory::getShape(shape)); // Goi ham them mot hinh vao vector Shape_List
            Shape_List.back()->set(); // Goi ham nhap thong tin hinh vua moi duoc them vao
        }

        void showShape(vector <Shape*>& Shape_List) // Ham in ra tat ca cac hinh da nhap
        {
            int i;
            if (Shape_List.size() == 0) cout << endl << "Danh sach khong co hinh ve nao!" << endl << endl;
            else
            {
                for (i=0; i<Shape_List.size(); i++)
                {
                    cout << endl << "Hinh thu " << i+1 << ":" << endl;
                    Shape_List[i]->show();
                }
            }
        }

        void addEdge(vector <Shape*>& Shape_List, vector <Edge*>& Edge_List) // Ham them mot canh
        {
            if (Shape_List.size() < 2) cout << "Danh sach khong du hinh ve de them canh!" << endl;
            else
            {
                int u,v;
                cout << endl << "Nhap thu tu 2 hinh ban muon noi tam:" << endl;
                cin >> u;
                cin >> v;

                Edge_List.push_back(new Edge); // Goi toi ham them 1 canh noi tam

                // Goi toi ham them thong tin hinh can noi tam cho canh vua them
                Edge_List.back()->getShape1(Shape_List[u-1]);
                Edge_List.back()->getShape2(Shape_List[v-1]);

                // Goi toi ham them thong tin canh vua nhap vao thong tin 2 hinh tuong ung
                Shape_List[u-1]->Edge1_List.push_back(Edge_List.back());
                Shape_List[v-1]->Edge1_List.push_back(Edge_List.back());
                Edge_List.back()->set();
            }
        }

        void deleteShape(vector <Shape*>& Shape_List, vector <Edge*>& Edge1_List) // Ham xoa mot hinh va xoa canh noi tam xuat phat tu no
        {
            int j;
            if (Shape_List.size() == 0) cout << "Danh sach khong co hinh ve nao de xoa!" << endl << endl;
            else
            {
                cout << "Hay nhap thu tu hinh muon xoa!" << endl;
                cin >> j;
                if ((j<1) || (j>=Shape_List.size()))
                    cout << "Khong ton tai thu tu hinh ve nay!" << endl << endl; // Thu tu hinh bat dau tu 1
                else
                {
                    Shape_List.erase(Shape_List.begin()+j-1); // Xoa hinh thu j
                    Shape_List[j-1]->Edge1_List.clear(); // Xoa cac duong noi tam xuat phat tu hinh vua xoa
                    cout << "Danh sach cac hinh sau khi xoa la: " << endl;
                    showShape(Shape_List);
                }   
            }   
        }

        void arrangeShape(vector <Shape*>& Shape_List) // Ham sap xep cac hinh theo dien tich tang dan
        {
            Shape* temp; // Bien tam thoi de so sanh 2 Shape
            int p,q;
            for (p=0; p<Shape_List.size()-1; p++)
            {
                for (q=p+1; q<Shape_List.size(); q++)
                {
                    if (Shape_List[p]->getArea() > Shape_List[q]->getArea())
                    {
                        temp = Shape_List[p];
                        Shape_List[p] = Shape_List[q];
                        Shape_List[q] = temp; // Swap vi tri 2 Shape
                    }
                }
            }
            cout << "Danh sach cac hinh sau khi sap xep la:" << endl;
            showShape(Shape_List);
        }

        void findShape(vector <Shape*>& Shape_List) // Ham tim kiem hinh theo toa do
        {
            float x, y;
            int m;
            cout << "Hay nhap toa do hinh can tim!" << endl;
            cout << "Hay nhap hoanh do hinh can tim!" << endl;
            cin >> x;
            cout << "Hay nhap tung do hinh can tim!" << endl;
            cin >> y;

            for (m=0; m<Shape_List.size(); m++)
            {
                if ((x == Shape_List[m]->getX()) && (y == Shape_List[m]->getY()))
                {
                    cout << "Toa do da nhap ung voi hinh: " << endl;
                    Shape_List[m]->show();
                    break;
                }
                else if (m == Shape_List.size()-1)
                cout << "Khong ton tai hinh ve nay!" << endl << endl;
            }
        }

        void showEdge(vector <Edge*>& Edge_List) // Ham in tat ca cac canh da them
        {
            int m;
            if (Edge_List.size() == 0)
                cout << endl << "Danh sach khong co canh noi tam nao!" << endl << endl;
            else
            {
                for (m=0; m<Edge_List.size(); m++)
                {
                    cout << "Canh thu " << m+1 << ":" << endl;
                    Edge_List[m]->show();
                }
            }
        }

        void showEdge_per_Shape(vector <Edge*>& Edge1_List, vector <Shape*>& Shape_List) // Ham xuat thong tin cac canh noi tam 1 hinh xac dinh
        {
            int n,o;
            cout << endl << "Nhap thu tu hinh ban muon xem thong tin canh:" << endl;
            cin >> n;
            if (Shape_List[n]->Edge1_List.size() == 0)
                cout << endl << "Khong co canh nao xuat phat tu hinh nay!" << endl;
            else
            {
                cout << endl << "Thong tin cac canh xuat phat tu hinh ban vua nhap la:" << endl;
                Shape_List[n]->showEdge1Shape(); // Goi toi ham in ra canh noi tam cua hinh thu n trong Shape_List
            }
        }

        void readFile(vector <Shape*> Shape_List, vector <Edge*>& Edge_List, vector <Edge*>& Edge1_List)  // Ham doc File
        {
            ifstream file_input ("textbai4.txt");
            string getinput;

            if (file_input.fail()) // Check xem file co ton tai hay khong
            {
                cout << "Fail to open file!" << endl;
            }
            else
            {
                while (!file_input.eof()) // Duyet file tu dau toi cuoi file thi dung lai
                {
                    getline (file_input, getinput, '{'); // Doc file tu dau toi '{', gan vao getinput.

                    switch (getinput[0]) // Xet ki tu dau tien cua getinput
                    {
                        case 's': // Shape
                        {
                            switch (getinput[6]) // Xet ki tu thu 6 cua getinput
                            {
                                case 'c': // Cirlce
                                {
                                    Shape_List.push_back(ShapeFactory::getShape(1)); // them Circle

                                    // Doc ki tu tiep theo cho toi ',', gan vao getinput
                                    // Gan getinput vao toa do x, y
                                    // Stof: Chuyen kieu du lieu tu string -> float
                                    getline (file_input, getinput, ',');
                                    Shape_List.back()->setX(stof(getinput)); 

                                    getline (file_input, getinput, ',');
                                    Shape_List.back()->setY(stof(getinput));

                                    getline (file_input, getinput, ','); // Doc ki tu tiep theo cho toi ',', gan vao getinput
                                    Shape_List.back()->setSize1(stof(getinput)); // Gan getinput vao kich thuoc 1

                                    getline (file_input, getinput, ','); // Doc ki tu tiep theo cho toi ',', gan vao getinput
                                    Shape_List.back()->setColor(getinput); // Gan getinput vao mau sac

                                    getline (file_input, getinput, ','); // Doc ki tu tiep theo cho toi ',', gan vao getinput
                                    Shape_List.back()->setThickness(stof(getinput)); // Gan getinput vao do day net ve

                                    break;
                                }

                                case 'r': // Rectangle
                                {
                                    Shape_List.push_back(ShapeFactory::getShape(2));

                                    getline (file_input, getinput, ',');
                                    Shape_List.back()->setX(stof(getinput));

                                    getline (file_input, getinput, ',');
                                    Shape_List.back()->setY(stof(getinput));

                                    getline (file_input, getinput, ',');
                                    Shape_List.back()->setSize1(stof(getinput));

                                    getline (file_input, getinput, ',');
                                    Shape_List.back()->setSize2(stof(getinput));

                                    getline (file_input, getinput, ',');
                                    Shape_List.back()->setColor(getinput);

                                    getline (file_input, getinput, ',');
                                    Shape_List.back()->setThickness(stof(getinput));

                                    break;
                                }

                                case 's': // Square
                                {
                                    Shape_List.push_back(ShapeFactory::getShape(3));

                                    getline (file_input, getinput, ',');
                                    Shape_List.back()->setX(stof(getinput));

                                    getline (file_input, getinput, ',');
                                    Shape_List.back()->setY(stof(getinput));

                                    getline (file_input, getinput, ',');
                                    Shape_List.back()->setSize1(stof(getinput));

                                    getline (file_input, getinput, ',');
                                    Shape_List.back()->setColor(getinput);

                                    getline (file_input, getinput, ',');
                                    Shape_List.back()->setThickness(stof(getinput));

                                    break;
                                }

                                case 'o': // Oval
                                {
                                    Shape_List.push_back(ShapeFactory::getShape(4));

                                    getline (file_input, getinput, ',');
                                    Shape_List.back()->setX(stof(getinput));

                                    getline (file_input, getinput, ',');
                                    Shape_List.back()->setY(stof(getinput));

                                    getline (file_input, getinput, ',');
                                    Shape_List.back()->setSize1(stof(getinput));

                                    getline (file_input, getinput, ',');
                                    Shape_List.back()->setSize2(stof(getinput));

                                    getline (file_input, getinput, ',');
                                    Shape_List.back()->setColor(getinput);

                                    getline (file_input, getinput, ',');
                                    Shape_List.back()->setThickness(stof(getinput));

                                    break;
                                }

                                case 'l': // Line
                                {
                                    Shape_List.push_back(ShapeFactory::getShape(5));

                                    getline (file_input, getinput, ',');
                                    Shape_List.back()->setX(stof(getinput));

                                    getline (file_input, getinput, ',');
                                    Shape_List.back()->setY(stof(getinput));

                                    getline (file_input, getinput, ',');
                                    Shape_List.back()->setSize1(stof(getinput));

                                    getline (file_input, getinput, ',');
                                    Shape_List.back()->setColor(getinput);

                                    getline (file_input, getinput, ',');
                                    Shape_List.back()->setThickness(stof(getinput));

                                    break;
                                }

                                case 't': // Triangle
                                {
                                    Shape_List.push_back(ShapeFactory::getShape(6));

                                    getline (file_input, getinput, ',');
                                    Shape_List.back()->setX(stof(getinput));

                                    getline (file_input, getinput, ',');
                                    Shape_List.back()->setY(stof(getinput));

                                    getline (file_input, getinput, ',');
                                    Shape_List.back()->setSize1(stof(getinput));

                                    getline (file_input, getinput, ',');
                                    Shape_List.back()->setSize2(stof(getinput));

                                    getline (file_input, getinput, ',');
                                    Shape_List.back()->setSize3(stof(getinput));

                                    getline (file_input, getinput, ',');
                                    Shape_List.back()->setColor(getinput);

                                    getline (file_input, getinput, ',');
                                    Shape_List.back()->setThickness(stof(getinput));

                                    break;
                                }
                            }
                        }

                        case 'e': // Edge
                        {
                            Edge_List.push_back(new Edge); // Them 1 canh noi tam

                            getline (file_input, getinput, ','); // Doc ki tu tiep theo cho toi ',', gan vao getinput
                            Edge_List.back()->getShape1(Shape_List[stof(getinput)-1]); // Goi toi ham them thong tin hinh getinput cho canh vua them
                            Shape_List[stof(getinput)-1]->Edge1_List.push_back(Edge_List.back()); // Goi toi ham them thong tin canh vua nhap vao thong tin hinh tuong ung

                            getline (file_input, getinput, ','); // Doc ki tu tiep theo cho toi ',', gan vao getinput
                            Edge_List.back()->getShape2(Shape_List[stof(getinput)-1]); // Goi toi ham them thong tin hinh getinput cho canh vua them                
                            Shape_List[stof(getinput)-1]->Edge1_List.push_back(Edge_List.back()); // Goi toi ham them thong tin canh vua nhap vao thong tin hinh tuong ung

                            getline (file_input, getinput, ','); // Doc ki tu tiep theo cho toi ',', gan vao getinput
                            Edge_List.back()->setColor(getinput); // Gan input vao mau sac Edge

                            getline (file_input, getinput, ','); // Doc ki tu tiep theo cho toi ',', gan vao getinput
                            Edge_List.back()->setThickness(stof(getinput)); // Gan input vao do day net ve Edge
                        }
                    }
                }
                file_input.close(); // Dong file
            }   
        }

        void Menu() // Menu cac lua chon
        {
            int choice; // Lua chon
            while (1)
            {
                cout << endl << endl;
                cout << "                   MENU                  " << endl;
                cout << "NHAP SO TUONG UNG VOI CONG VIEC BAN MUON THUC HIEN!";
                cout << "1. Nhap thong tin hinh tu ban phim." << endl;
                cout << "2. Nhap thong tin hinh va canh tu File." << endl;
                cout << "3. In ra man hinh thong tin cac hinh vua nhap." << endl;
                cout << "4. Xoa mot hinh." << endl;
                cout << "5. Sap xep cac hinh theo thu tu tang dan ve dien tich." << endl;
                cout << "6. Tim kiem hinh voi toa do tam nhap tu ban phim." << endl;
                cout << "7. Them mot canh noi tam tu ban phim." << endl;
                cout << "8. In ra tat ca cac canh noi tam da co." << endl;
                cout << "9. In ra tat ca cac canh noi tam cua mot hinh." << endl;
                cout << "10. Thoat khoi chuong trinh!" << endl;

                cin >> choice;

                switch (choice)
                {
                    case 1:
                    {
                        cout << "Nhap thong tin hinh tu ban phim." << endl;
                        addShape(Shape_List);
                        break;
                    }

                    case 2:
                    {
                        cout << "Nhap thong tin hinh va canh tu File." << endl;
                        readFile(Shape_List, Edge_List, Edge1_List);
                        break;
                    }

                    case 3:
                    {
                        cout << "In ra man hinh thong tin cac hinh vua nhap." << endl;
                        showShape(Shape_List);
                        break;
                    }

                    case 4:
                    {
                        cout << "Xoa mot hinh." << endl;
                        deleteShape(Shape_List, Edge1_List);
                        break;
                    }

                    case 5:
                    {
                        cout << "Sap xep cac hinh theo thu tu tang dan ve dien tich.";
                        arrangeShape(Shape_List);
                        break;
                    }

                    case 6:
                    {
                        cout << "Tim kiem hinh voi toa do tam nhap tu ban phim." << endl;
                        findShape(Shape_List);
                        break;
                    }

                    case 7:
                    {
                        cout << "Them mot canh noi tam tu ban phim." << endl;
                        addEdge(Shape_List, Edge_List);
                        break;
                    }

                    case 8:
                    {
                        cout << "In ra tat ca cac canh noi tam da nhap." << endl;
                        showEdge(Edge_List);
                        break;
                    }

                    case 9:
                    {
                        cout << "In ra tat ca cac canh noi tam cua mot hinh." << endl;
                        showEdge_per_Shape(Edge1_List, Shape_List);
                        break;
                    }

                    case 10: break;

                    default:
                    {
                        cout << "Hay nhap cac so thoa man!!!" << endl;
                        break;
                    }
                }
            }
        }
};

int main()
{
    Graph g; 
    do
    {
        g.Menu(); 
    } while(1); 

    return 0;
}









