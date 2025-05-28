#include <iostream>

using namespace std;

long UCLN(long x, long y)
{
    long r;
    x = abs(x);
    y = abs(y);
    if (x == 0 || y == 0)   return 1;
    while ((r = x % y) != 0)
    {
        x = y;
        y = r;
    }
    return y;
}

class PhanSo
{
    long Tu, Mau;
    void UocLuoc()
    {
        long x = UCLN(Tu, Mau);
        Tu /= x;
        Mau /= x;
        if (Mau < 0)    Mau = -Mau, Tu = -Tu;
        if (Tu == 0)    Mau = 1;
    }
public:
    PhanSo()
    {

    }

    void Set(long t, long m)
    {
        if (m)
        {
            Tu = t;
            Mau = m;
            UocLuoc();
        }
    }

    PhanSo(long t, long m)
    {
        Set(t, m);
    }

    void Xuat() const
    {
        cout << Tu;
        if (Tu != 0 && Mau != 1)
            cout << "/" << Mau;
    }

    // Overloading
    PhanSo operator+(PhanSo b) const
    {
        return PhanSo(Tu * b.Mau + Mau * b.Tu, Mau * b.Mau);
    }

    PhanSo operator+ (long b) const
    {
        return PhanSo(Tu + b * Mau, Mau);
    }

    friend PhanSo operator+ (int a, PhanSo b)
    {
        return PhanSo(a * b.Mau + b.Tu, b.Mau);
    }

};

int main()
{
    cout << "\n1. Khoi tao phan so: \n";
    PhanSo a(2, 3), b(4, 1), c(0, 1), d, e, f, g;

    cout << "\n2. Xuat cac phan so: \n";
    a.Xuat(); cout << "\t";
    b.Xuat(); cout << "\t";
    c.Xuat(); cout << endl;

    cout << "\n3. operator+(PhanSo) \n";
    e = a + b;
    cout << "\t e = a + b = "; e.Xuat();

    cout << "\n4. operator+(long) \n";
    f = c + 3;
    cout << "\t f = c + 3 = "; f.Xuat();

    cout << "\n6. operator+(int, PhanSo) \n";
    g = 3 + a;
    cout << "\t g = 3 + a = "; g.Xuat();

    return 0;
}

