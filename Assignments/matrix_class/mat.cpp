#include <iostream>
#include <stdexcept>

using namespace std;

class Matrix
{
private:
    int rows, cols;
    int **data;

    // Allocates memory for the matrix data.
    void allocateData()
    {
        data = new int *[rows];
        for (int i = 0; i < rows; i++)
        {
            data[i] = new int[cols];
        }
    }

    // Deallocates the memory.
    void deallocateData()
    {
        for (int i = 0; i < rows; i++)
        {
            delete[] data[i];
        }
        delete[] data;
        data = nullptr;
    }

public:
    // Constructor: creates a rows x cols matrix and initializes all elements to zero.
    Matrix(int r, int c) : rows(r), cols(c)
    {
        if (r <= 0 || c <= 0)
            throw invalid_argument("Rows and columns must be positive");
        allocateData();
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                data[i][j] = 0;
    }

    // Copy constructor for deep copying.
    Matrix(const Matrix &other) : rows(other.rows), cols(other.cols)
    {
        allocateData();
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                data[i][j] = other.data[i][j];
    }

    // Assignment operator for deep copying.
    Matrix &operator=(const Matrix &other)
    {
        if (this == &other)
            return *this;
        deallocateData();
        rows = other.rows;
        cols = other.cols;
        allocateData();
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                data[i][j] = other.data[i][j];
        return *this;
    }

    // Destructor to free allocated memory.
    ~Matrix()
    {
        deallocateData();
    }

    // Access operator to get or set elements (with bounds checking)
    int &operator()(int i, int j)
    {
        if (i < 0 || i >= rows || j < 0 || j >= cols)
            throw out_of_range("Matrix index out of range");
        return data[i][j];
    }

    // Const version for read-only access.
    const int &operator()(int i, int j) const
    {
        if (i < 0 || i >= rows || j < 0 || j >= cols)
            throw out_of_range("Matrix index out of range");
        return data[i][j];
    }

    // Print the matrix.
    void print() const
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << data[i][j] << " ";
            }
            cout << "\n";
        }
    }

    // Addition of two matrices (dimensions must match).
    Matrix operator+(const Matrix &other) const
    {
        if (rows != other.rows || cols != other.cols)
            throw invalid_argument("Matrix dimensions must match for addition");
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                result.data[i][j] = data[i][j] + other.data[i][j];
        return result;
    }

    // Subtraction of two matrices.
    Matrix operator-(const Matrix &other) const
    {
        if (rows != other.rows || cols != other.cols)
            throw invalid_argument("Matrix dimensions must match for subtraction");
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                result.data[i][j] = data[i][j] - other.data[i][j];
        return result;
    }

    // Multiplication of matrices.
    Matrix operator*(const Matrix &other) const
    {
        if (cols != other.rows)
            throw invalid_argument("Matrix multiplication dimension mismatch");
        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < other.cols; j++)
            {
                result.data[i][j] = 0;
                for (int k = 0; k < cols; k++)
                {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }

    // Remove a row at the given index.
    void removeRow(int rowIndex)
    {
        if (rowIndex < 0 || rowIndex >= rows)
            throw out_of_range("Row index out of range");
        int newRows = rows - 1;
        int **newData = new int *[newRows];
        for (int i = 0, newI = 0; i < rows; i++)
        {
            if (i == rowIndex)
                continue; // Skip the row to be removed.
            newData[newI] = new int[cols];
            for (int j = 0; j < cols; j++)
                newData[newI][j] = data[i][j];
            newI++;
        }
        deallocateData();
        rows = newRows;
        data = newData;
    }

    // Remove a column at the given index.
    void removeColumn(int colIndex)
    {
        if (colIndex < 0 || colIndex >= cols)
            throw out_of_range("Column index out of range");
        int newCols = cols - 1;
        int **newData = new int *[rows];
        for (int i = 0; i < rows; i++)
        {
            newData[i] = new int[newCols];
            for (int j = 0, newJ = 0; j < cols; j++)
            {
                if (j == colIndex)
                    continue; // Skip the column to be removed.
                newData[i][newJ++] = data[i][j];
            }
        }
        deallocateData();
        cols = newCols;
        data = newData;
    }

    // Insert a row at a specified index.
    // If rowData is nullptr, the new row is initialized with zeros.
    void insertRow(int rowIndex, const int *rowData = nullptr)
    {
        if (rowIndex < 0 || rowIndex > rows)
            throw out_of_range("Row index out of range");
        int newRows = rows + 1;
        int **newData = new int *[newRows];
        for (int i = 0, newI = 0; i < newRows; i++)
        {
            newData[i] = new int[cols];
            if (i == rowIndex)
            {
                // Insert the new row.
                for (int j = 0; j < cols; j++)
                    newData[i][j] = (rowData != nullptr) ? rowData[j] : 0;
            }
            else
            {
                // Copy an existing row.
                int oldRow = (i < rowIndex) ? i : i - 1;
                for (int j = 0; j < cols; j++)
                    newData[i][j] = data[oldRow][j];
            }
        }
        deallocateData();
        rows = newRows;
        data = newData;
    }

    // Insert a column at a specified index.
    // If colData is nullptr, the new column is initialized with zeros.
    void insertColumn(int colIndex, const int *colData = nullptr)
    {
        if (colIndex < 0 || colIndex > cols)
            throw out_of_range("Column index out of range");
        int newCols = cols + 1;
        int **newData = new int *[rows];
        for (int i = 0; i < rows; i++)
        {
            newData[i] = new int[newCols];
            for (int j = 0, newJ = 0; j < newCols; j++)
            {
                if (j == colIndex)
                {
                    newData[i][j] = (colData != nullptr) ? colData[i] : 0;
                }
                else
                {
                    newData[i][j] = data[i][newJ++];
                }
            }
        }
        deallocateData();
        cols = newCols;
        data = newData;
    }

    // Get number of rows.
    int getRows() const { return rows; }
    // Get number of columns.
    int getCols() const { return cols; }
};

//---------------------------------------------------------
// Demonstration of the Matrix class functionality.
//---------------------------------------------------------
int main()
{
    try
    {
        // Create a 3x3 matrix and initialize it.
        Matrix m(3, 3);
        m(0, 0) = 1;
        m(0, 1) = 2;
        m(0, 2) = 3;
        m(1, 0) = 4;
        m(1, 1) = 5;
        m(1, 2) = 6;
        m(2, 0) = 7;
        m(2, 1) = 8;
        m(2, 2) = 9;

        cout << "Original 3x3 Matrix:\n";
        m.print();

        // Matrix arithmetic operations.
        Matrix m2 = m + m; // Addition
        cout << "\nMatrix after addition (m + m):\n";
        m2.print();

        Matrix m3 = m * m2; // Multiplication (3x3 * 3x3)
        cout << "\nMatrix after multiplication (m * m2):\n";
        m3.print();

        // Remove a row and then a column.
        m.removeRow(1); // Remove the second row.
        cout << "\nMatrix after removing row 1:\n";
        m.print();

        m.removeColumn(0); // Remove the first column.
        cout << "\nMatrix after removing column 0:\n";
        m.print();

        // Insert a new row.
        int newRow[2] = {100, 200}; // Note: Current matrix is 2x2.
        m.insertRow(1, newRow);
        cout << "\nMatrix after inserting a new row at index 1:\n";
        m.print();

        // Insert a new column.
        int newCol[3] = {300, 400, 500}; // Now matrix is 3x2; new column requires 3 elements.
        m.insertColumn(2, newCol);
        cout << "\nMatrix after inserting a new column at index 2:\n";
        m.print();
    }
    catch (const exception &ex)
    {
        cout << "Exception: " << ex.what() << "\n";
    }

    return 0;
}
