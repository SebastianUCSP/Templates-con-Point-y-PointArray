#include <iostream>
using namespace std;


template<class T>
class Point
{
    public:
        Point()
        {
           x = 0;
           y = 0;
        }

        Point(T xh, T yh)
        {
           x = xh;
           y = yh;
        }
        Point(Point &p)
        {
           x = p.x;
           y = p.y;
        }

        void offset(T nx, T ny)
        {
    x += nx;
    y += ny;
}
        void imprimir()
        {
    std::cout << "(" << x << ", " << y << ")" << std::endl;
}

        T getX()
        {
    return x;
}

        T getY()
        {
    return y;
}

        void setX(T x)
{

    this->x = x;
}
        void setY(T y)
        {
    this->y = y;
}

    private:
        T x,y;
};

template<class T>
class PointArray
{
    public:
        PointArray()
        {
           this->points = new Point<T>[size];
           this->size = 0;
        }

        PointArray(const Point<T> pts[], const int size)
        {
           this->points = new Point<T>[size];
           this->size = size;
           for(int i = 0; i < size; i++){
              points[i] = pts[i];
           }
        }

        PointArray(const PointArray<T> &o)
        {
           this->points = new Point<T>[size];
           this->size = o.size;
           for(int i = 0; i < size; i++){
              points[i] = o.points[i];
           }
        }

        ~PointArray()
        {
           delete[] points;
        }


        void imprimir()
        {
           for(int i = 0; i < size; i++){
           points[i].imprimir();
           }
        }

        int getSize()
        {
           return size;
        }

        void clear()
        {
           resize(0);
        }

    void remove(const int pos)
    {
    for(int i = pos; i < size; i++){
        points[i] = points[i+1];
    }
    resize(size - 1);
    }

    void insert(const int pos, const Point<T> &p)
    {
	resize(size+1);
    for(int i = size-1; i > pos; i--)
        points[i] = points[i-1];

	    points[pos] = p;
    }

    void push_back(const Point<T> &p)
    {
    resize(size + 1);
    this->points[size - 1] = p;
    }

    private:
        int size;
        Point<T> *points;
    void resize(int newSize)
    {
    Point<T> *pts = new Point<T>[newSize];
    int minSize = (newSize > size)? size : newSize;
    for(int i = 0; i < minSize; i++)
        pts[i] = points[i];

    delete[] points;
    size = newSize;
    points = pts;
}
};


int main () {

    Point<int> a(2, 3);
    cout << "Point int: ";
    a.imprimir();
    cout << endl;

    Point<double> b(3.5, 6.7);
    cout << "Point double: ";
    b.imprimir();
    cout << endl;

    Point<float> c(4.56546456, 5.43242354);
    cout << "Point float: ";
    c.imprimir();
    cout << endl;

    Point<string> d("7abc", "8xyz");
    cout << "Point string: ";
    d.imprimir();
    cout << endl;


    Point<int> pt[5];
    for(int i = 0; i < 5; i++){
        pt[i].setX(i);
        pt[i].setY(i+3);
    }
    cout << "El arreglo es: " << endl;
    for(int i = 0; i < 5; i++){
        pt[i].imprimir();
    }

    cout << endl;

    cout << "El PointArray es: " << endl;
    PointArray<int> newPt(pt, 5);
    newPt.imprimir();
    cout << endl;

/*
    PointArray<int> new2Pt = newPt;
    cout << "El PointArray es: ";
    new2Pt.imprimir();
    cout << endl;
*/


    newPt.insert(2, a);

    cout << "Luego de anadir otro elemento: " << endl;
    newPt.imprimir();
    cout << endl;

    newPt.remove(1);

    cout << "Luego de eliminar un elemento: " << endl;
    newPt.imprimir();
    cout << endl;




  return 0;
}
