#include <bits/stdc++.h>

using namespace std;

class String
{
    char *p;
public:
    String(char* s = "")    { p = strdup(s); }
    String(const String &s) { p = strdup(s.p); }
    ~String() { cout << "delete " << (void*)p << "\n";   delete[] p; }

    // Sua loi sai bang cach dinh nghia phep gan cho lop String
    String& operator= (const String &s)
    {
        if (this != &s)
        {
            delete[] p;
            p = strdup(s.p);
        }
        return *this;
    }

    void Output() const{ cout << p; }
};

int main()
{
    String a("Nguyen Van A");
    String b = a;   //Khoi dong
    String aa = "Le Van AA";
    cout << "aa = "; aa.Output(); cout << "\n";
    aa = a;     // Gan
    cout << "aa = "; aa.Output(); cout << "\n";
    return 0;
}
