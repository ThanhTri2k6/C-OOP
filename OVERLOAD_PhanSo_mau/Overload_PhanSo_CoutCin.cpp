#include <bits/stdc++.h>

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
    void Set(long t, long m)
    {
        if (m)
        {
            Tu = t;
            Mau = m;
            UocLuoc();
        }
    }

    PhanSo(long t = 0, long m = 1)
    {
        Set(t, m);
    }


   friend PhanSo operator+ (PhanSo a, PhanSo b)
   {
       return PhanSo(a.Tu * b.Mau + a.Mau * b.Tu, a.Mau * b.Mau);
   }
   friend PhanSo operator- (PhanSo a, PhanSo b)
   {
       return PhanSo(a.Tu * b.Mau - a.Mau * b.Tu, a.Mau * b.Mau);
   }
   friend PhanSo operator* (PhanSo a, PhanSo b)
   {
       return PhanSo(a.Tu * b.Tu, a.Mau * b.Mau);
   }
   friend PhanSo operator/ (PhanSo a, PhanSo b)
   {
       return PhanSo(a.Tu * b.Mau, a.Mau * b.Tu);
   }
   PhanSo operator- () const
   {
       return PhanSo(-Tu, Mau);
   }
   friend istream& operator>> (istream& is, PhanSo &p)
   {
       is >> p.Tu >> p.Mau;
       while (!p.Mau)
       {
           cout << "\nNhap lai mau so: ";
           is >> p.Mau;
       }
       p.UocLuoc();
       return is;
   }
   friend ostream& operator<< (ostream& os, PhanSo p)
   {
       os << p.Tu;
       if (p.Tu != 0 && p.Mau !=1)
        os << "/" << p.Mau;
       return os;
   }
};

int main()
{
    PhanSo a, b;
    cout << "\nNhap phan so a: "; cin >> a;
    cout << "\nNhap phan so b: "; cin >> b;

    cout << a << " + " << b << " = " << a + b << "\n";
    cout << a << " - " << b << " = " << a - b << "\n";
    cout << a << " * " << b << " = " << a * b << "\n";
    cout << a << " / " << b << " = " << a / b << "\n";

    return 0;
}

