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

    long LayTu() const
    {
        return Tu;
    }
    long LayMau() const
    {
        return Mau;
    }

    // Khai bao ham
    PhanSo Cong(PhanSo b) const
    {
        return PhanSo(Tu * b.Mau + Mau * b.Tu, Mau * b.Mau);
    }
    // Overloading
    PhanSo operator+(PhanSo b) const
    {
        return PhanSo(Tu * b.Mau + Mau * b.Tu, Mau * b.Mau);
    }

    PhanSo operator- () const
    {
        return PhanSo(-Tu, Mau);
    }

    bool operator == (PhanSo b) const
    {
        return Tu * b.Mau == Mau * b.Tu;
    }

    bool operator != (PhanSo b) const
    {
        return !(*this == b);
    }

    void Xuat() const
    {
        cout << Tu;
        if (Tu != 0 && Mau != 1)
            cout << "/" << Mau;
    }

};

int main()
{
    cout << "\n1. Khoi tao phan so: \n";
    PhanSo a(2, 4), b(9, 6), c(3, 3), d, e, f, g, h;

    cout << "\n2. Xuat cac phan so: \n";
    a.Xuat(); cout << "\t";
    b.Xuat(); cout << "\t";
    c.Xuat(); cout << endl;

    cout << "\n3. Ham cong: \n";
    d =  a.Cong(b);
    cout << "\t d = a Cong b = "; d.Xuat();

    cout << "\n4. operator+ \n";
    e = a + b;
    cout << "\t e = a + b = "; e.Xuat();

    cout << "\n5. operator- \n";
    f = -c;
    cout << "\t f = -c = "; f.Xuat();

    cout << "\n6. operator== \n";
    if (a == c)
        cout << "a va c : Bang nhau\n";
    else
        cout << "a va c: KHONG bang nhau\n";

    return 0;
}
