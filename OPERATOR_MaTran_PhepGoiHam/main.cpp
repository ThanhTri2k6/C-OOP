#include <bits/stdc++.h>

using namespace std;

class MATRIX
{
    float **M;
    int row, col;
public:
    MATRIX(int r, int c)
    {
        M = new float* [r];
        for (int i = 0; i < r; i++)
            M[i] = new float[c];
        row = r;
        col = c;
    }
    ~MATRIX()
    {
        for (int i = 0; i < col; i++)
            delete[] M[i];
        delete[] M;
    }

    float& operator() (int i, int j)
    {
        return M[i][j];
    }
};

int main()
{
    cout << "\nCho ma tran 2x3\n";
    MATRIX a(2, 3);
    int i, j;
    for (i = 0; i < 2; i++)
        for (j = 0; j < 3; j++)
            cin >> a(i, j);

    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 3; j++)
            cout << a(i, j) << " ";
        cout << endl;
    }
    return 0;
}
