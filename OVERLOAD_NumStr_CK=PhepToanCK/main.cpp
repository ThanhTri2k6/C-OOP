#include <bits/stdc++.h>

using namespace std;

class NumStr
{
    char *s;
public:
    NumStr()
    {

    }
    NumStr(char *p)
    {
        s = strdup(p);
    }

    operator double()
    {
        return atof(s);
    }

    friend ostream& operator<< (ostream& os, NumStr &ns)
    {
        return os << ns.s;
    }
};

int main()
{
    NumStr s1("123.45"), s2("34.12");
    cout << "s1 = " << s1 << "\n";  // Xuat 's1 = 123.45'ra cout
    cout << "s2 = " << s2 << "\n";  // Xuat 's2 = 34.12' ra cout
    cout << "s1 + s2 = " << s1 + s2 << "\n";
        // Xuat 's1 + s2 = 157.57' ra cout
    cout << "s1 + 50 = " << s1 + 50 << "\n";
        // Xuat 's1 + 50 = 173.45' ra cout
    cout << "s1 * 2 = " << s1 * 2 << "\n";
        // Xuat 's1 * 2 = 246.9' ra cout
    cout << "s1 / 2 = " << s1 / 2 << "\n";
        // Xuat 's1 / 2 = 64.725' ra cout

    return 0;
}
