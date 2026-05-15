#include <iostream>
#include <string>
using namespace std;

class Matrix
{
    public:
        int rows;
        int cols;
        double** data;
        
        // Constructor (rows/cols)
        Matrix(int r, int c) : rows(r), cols(c)
        {
            if (r <= 0 || c <= 0)
            {
                rows = 0;
                cols = 0;
                data = nullptr;
            }
            else
            {
                data = new double*[rows];
                for (int i = 0; i < rows; i++)
                {
                    data[i] = new double[cols];
                    for (int j = 0; j < cols; j++)
                        data[i][j] = 0;
                }
            }
        }

        // Destructor
        ~Matrix()
        {
            if (data != nullptr)
            {
                for (int i = 0; i < rows; i++)
                    delete[] data[i];
                delete[] data;
            }
        }

        // Constructor (Deep Copy)
        Matrix(const Matrix& other) : rows(other.rows), cols(other.cols)
        {
            if (other.data == nullptr)
            {
                data = nullptr;
            }
            else
            {
                data = new double*[rows];
                for (int i = 0; i < rows; i++)
                {
                    data[i] = new double[cols];
                    for (int j = 0; j < cols; j++)
                        data[i][j] = other.data[i][j];
                }
            }
        }

        // Assignment operator
        Matrix& operator=(const Matrix& other)
        {
            if (this == &other) return *this;
            
            // Free old memory
            if (data != nullptr)
            {
                for (int i = 0; i < rows; i++)
                    delete[] data[i];
                delete[] data;
            }

            rows = other.rows;
            cols = other.cols;

            if (other.data == nullptr)
            {
                data = nullptr;
            }
            else
            {
                data = new double*[rows];
                for (int i = 0; i < rows; i++)
                {
                    data[i] = new double[cols];
                    for (int j = 0; j < cols; j++)
                        data[i][j] = other.data[i][j];
                }
            }
            return *this;
        }

        void add(const Matrix& other)
        {
            if (rows != other.rows || cols != other.cols)
                throw string("incorrect sizes");

            for (int i = 0; i < rows; i++)
                for (int j = 0; j < cols; j++)
                    data[i][j] += other.data[i][j];
        }

        void multiply(const Matrix& other)
        {
            if (cols != other.rows)
                throw string("incorrect sizes");

            // Create temporary matrix
            double** newdata = new double*[rows];
            for (int i = 0; i < rows; i++)
            {
                newdata[i] = new double[other.cols];
                for (int j = 0; j < other.cols; j++)
                {
                    newdata[i][j] = 0;
                    for (int k = 0; k < cols; k++) 
                        newdata[i][j] += data[i][k] * other.data[k][j];
                }
            }

            // Free memory
            if (data != nullptr)
            {
                for (int i = 0; i < rows; i++)
                    delete[] data[i];
                delete[] data;
            }

            // Set variables
            data = newdata;
            cols = other.cols;
        }

        Matrix transpose()
        {
            Matrix result(cols, rows);
            for (int j = 0; j < cols; j++)
            {
                for (int i = 0; i < rows; i++)
                    result.data[j][i] = data[i][j];
            }
            return result;
        }




        
        // Utility functions
        void print()
        {
            if (data == nullptr) return;
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                    cout << data[i][j] << "\t";
                cout << endl;
            }
            cout << endl;
        }

        void fill(double value)
        {
            for (int i = 0; i < rows; i++)
                for (int j = 0; j < cols; j++)
                    data[i][j] = value;
        }

        // Create an identity Matrix of dimension size
        static Matrix identity(int size)
        {
            Matrix result(size, size); // Matrix full of 0
            for (int i = 0; i < size; i++)
                result.data[i][i] = 1;
            return result;
        }

                



        // Operator Overloading
        Matrix operator+(const Matrix& other)
        {
            if (rows != other.rows || cols != other.cols)
                throw string("Incorrect sizes");

            Matrix result(rows, cols);
            // On copie d'abord l'actuelle dans result
            for(int i=0; i<rows; i++)
                for(int j=0; j<cols; j++)
                    result.data[i][j] = data[i][j];
            
            result.add(other);
            return result;
        }

        Matrix operator*(const Matrix& other)
        {
            if (cols != other.rows) // Corrigé : pour A*B, A.cols doit être égal à B.rows
                throw string("Incorrect sizes");

            Matrix result = *this; // On part d'une copie de l'objet actuel
            result.multiply(other);
            return result;
        }

        double* operator[](const int n)
        {
            if (n < 0 || n >= rows)
                throw string("Incorrect index");

            return data[n];
        }
};



