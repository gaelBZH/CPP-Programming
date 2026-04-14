#include <iostream>
#include "matrix.cpp"

int main()
{
    Matrix zero(4,5);
    cout << "================= zero-default Matrix 4*5 : =================" << endl;
    zero.print();

    Matrix a(2, 3);
    double values[2][3] = {{1, 2, 3}, {4, 5, 6}};
    for(int i=0; i<2; i++)
        for(int j=0; j<3; j++)
            a.data[i][j] = values[i][j];

    cout << "================= Matrix A : =================" << endl;
    a.print();

    Matrix a_copy = a;
    cout << "================= Deep Copy of A : =================" << endl;
    a_copy.print();

    Matrix b = a + a;
    cout << "================= B = A + A : =================" << endl;
    b.print();

    Matrix c = a.transpose();
    cout << "================= Transposed Matrix C = A^-1 : =================" << endl;
    c.print();

    Matrix product = b * c;
    cout << "================= B * C : =================" << endl;
    product.print();

    Matrix d = Matrix(4,6);
    d.fill(42);
    cout << "================= 42-Filled Matrix : =================" << endl;
    d.print();

    Matrix e = identity(4);
    cout << "================= Indendity Matrix 4x4 : =================" << endl;
    e.print();

    cout << "================= Indexes : =================" << endl;


    cout << "A[1][2] = " << a[1][2] << endl << endl;

    cout << "================= EXCEPTIONS : =================" << endl;

    try{
        cout << "Expected Exception : Index out of range :" << endl;
        cout << "A[42][0] = " << a[42][0];
    }
    catch (string e) {
        cout << "Error: " << e << endl;
    }

    try{
        cout << "\nExpected Exception : Sum matrixes of different sizes :" << endl;
        cout << "A+C = ";
        (a + c).print();
    }
    catch (string e) {
        cout << "Error: " << e << endl;
    }

    try{
        cout << "\nExpected Exception : Product of matrixes of different sizes :" << endl;
        cout << "A*A = ";
        (a * a).print();
    }
    catch (string e) {
        cout << "Error: " << e << endl;
    }
    

    return 0;
}