#include <iostream>
#include <string>
using namespace std;

// Create the class Matrix containing:
class Matrix
{
    private:
        // In the section private:
        // static two-dimensional array with size of 3x3 storing floating-point numbers and variable storing the size of the array
        const int size = 3;
        float a[3][3];
    public:
        // In the section public:
        // the constructor - in which we complete the array with zeros.
        Matrix()
        {
            for (int i = 0; i < size; i++)
                for (int j = 0; j < size; j++)
                    a[i][j] = 0;
        }

        // the method loadData() loading data from the keyboard, used to complete the matrix.
        void loadData()
        {
            cout << "Please input " << size*size << " numbers in order to fill the Matrix :\n";
            for (int i = 0; i < size; i++)
                for (int j = 0; j < size; j++)
                    cin >> a[i][j];
        }

        // the method write() writing the matrix contents (each line must be written in a separate line, 
        void write()
        {
            cout << ("=============== Matrix : ===============\n");
            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                    cout << a[i][j] << " ";
                cout << "\n";
            }
            cout << ("========================================\n");
        }

        // Write the friend function addMatrixes adding two objects of the class Matrix and
        // returning the pointer to the new object of the class Matrix as the result. 
        // The result of adding the matrixes is stored in the newly created object.
        friend Matrix* addMatrixes(Matrix m1, Matrix m2); 
};

Matrix* addMatrixes(Matrix m1, Matrix m2)
{
    Matrix* result = new Matrix;
    for (int i = 0; i < m1.size; i++)
        for (int j = 0; j < m1.size; j++)
            result->a[i][j] = m1.a[i][j] + m2.a[i][j];
    return result;
}

int main()
{
    // By means of the operator new, in the program you must create two objects and
    // for each of them you must call the method loadData() and write().
    Matrix* first = new Matrix;
    first->loadData();
    first->write();

    Matrix* second = new Matrix;
    second->loadData();
    second->write();

    // Next, call the function addMatrixes and the method write
    // for the new object containing the result of adding matrixes.
    Matrix* result = addMatrixes(*first, *second);
    result->write();
    return 0;
}