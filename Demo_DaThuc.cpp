#include <bits/stdc++.h>

using namespace std;

class DaThuc
{
    vector<float> HeSo;
    int Bac = HeSo.size()- 1;
public:
    // Ham khoi tao mac dinh de tao mot da thuc co bac bang 0
    DaThuc()
    {
        HeSo.push_back(0);
    }
    // Ham khoi tao da thuc co bac n
    DaThuc(int n)
    {
        HeSo.resize(n + 1);
    }

    friend istream& operator>> (istream& is, DaThuc &dt)
    {
        if (dt.Bac != 0)
        {
            cout << "Nhap he so tu bac " << dt.Bac << " den bac 0: ";
            for (int i = 0; i <= dt.Bac; i++)
                is >> dt.HeSo[i];
        }
        else
        {
            cout << "\Nhap he so bac 0: ";  is >> dt.HeSo[0];
        }

    }

    friend ostream& operator<< (ostream& os, DaThuc &dt)
    {

    }

};

int main()
{
    cout << "\nTest 1: Cau 1. Tao du lieu da thuc:\n";
    DaThuc a, b(1);

    cout << "\nTest 2: Cau 2: Nhap da thuc bang >>: \n";
    cout << "\t + Nhap da thuc a: \n";    cin >> a;
    cout << "\t + Nhap da thuc b: \n";    cin >> b;



    return 0;
}
