#include <iostream>
#include <vector>
#include <stdexcept>
#include <cmath> // for pow in polynomial evaluation if desired

using namespace std;

/*
 * ==========================================================
 *                       POLYNOMIAL CLASS
 * ==========================================================
 *
 * A simple representation:
 * - We'll store terms as (coefficient, exponent).
 * - We provide:
 *    1) addTerm(coefficient, exponent)
 *    2) print()
 *    3) evaluate(x)
 */

class Polynomial
{
private:
    // Each term: coefficient * x^exponent
    // We'll store them in a vector.
    // For simplicity, we won't automatically combine like terms
    // unless we specifically code for that.
    vector<pair<int, int>> terms; // (coefficient, exponent)

public:
    // Default constructor
    Polynomial() {}

    // Add a term to the polynomial
    void addTerm(int coeff, int exp)
    {
        // In a more advanced implementation, you might want to
        // combine terms with the same exponent or keep them sorted.
        // We'll keep it simple and just push_back.
        terms.push_back({coeff, exp});
    }

    // Print the polynomial in a readable form
    // e.g. 3x^2 + 5x^1 - 2
    void print() const
    {
        if (terms.empty())
        {
            cout << "0" << endl;
            return;
        }
        for (size_t i = 0; i < terms.size(); i++)
        {
            int coeff = terms[i].first;
            int exp = terms[i].second;

            // Handle sign
            if (i > 0 && coeff >= 0)
            {
                cout << " + ";
            }
            else if (coeff < 0)
            {
                cout << " - ";
            }

            // Print absolute value if needed
            int absCoeff = (coeff < 0) ? -coeff : coeff;

            // If exponent is 0, it's a constant term
            if (exp == 0)
            {
                cout << absCoeff;
            }
            else if (exp == 1)
            {
                cout << absCoeff << "x";
            }
            else
            {
                cout << absCoeff << "x^" << exp;
            }
        }
        cout << endl;
    }

    // Evaluate the polynomial at a given x
    // e.g. if P(x) = 3x^2 + 5, then evaluate(2) = 3*(2^2)+5=17
    double evaluate(double x) const
    {
        double result = 0.0;
        for (auto &term : terms)
        {
            double coeff = term.first;
            double exp = term.second;
            result += coeff * pow(x, exp);
        }
        return result;
    }
};

/*
 * ==========================================================
 *                  MATRIX1D CLASS (DENSE)
 * ==========================================================
 *
 * Uses a single 1D array (vector<int>) in row-major order:
 *    data[r * cols + c]   represents M[r][c]
 *
 * Operations:
 *   - constructor: (rows, cols)
 *   - set(r, c, val)
 *   - get(r, c)
 *   - print()
 */

class Matrix1D
{
private:
    int rows;
    int cols;
    vector<int> data; // store row*cols elements

public:
    // Constructor with given dimensions, default init to 0
    Matrix1D(int r, int c) : rows(r), cols(c), data(r * c, 0) {}

    // Return number of rows
    int getRows() const { return rows; }

    // Return number of columns
    int getCols() const { return cols; }

    // Set the element at (r, c) to val
    void set(int r, int c, int val)
    {
        if (r < 0 || r >= rows || c < 0 || c >= cols)
        {
            throw out_of_range("Index out of range in Matrix1D::set");
        }
        data[r * cols + c] = val;
    }

    // Get the element at (r, c)
    int get(int r, int c) const
    {
        if (r < 0 || r >= rows || c < 0 || c >= cols)
        {
            throw out_of_range("Index out of range in Matrix1D::get");
        }
        return data[r * cols + c];
    }

    // Print the matrix in row-major form
    void print() const
    {
        cout << "Matrix1D (" << rows << " x " << cols << "):\n";
        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                cout << data[r * cols + c] << " ";
            }
            cout << endl;
        }
    }
};

/*
 * ==========================================================
 *             SPARSE MATRIX CLASS (VECTOR OF TRIPLETS)
 * ==========================================================
 *
 * We'll store only nonzero elements in a vector of
 * (row, col, value).
 * For example, if the matrix is mostly zeros,
 * this saves space.
 */

struct SparseEntry
{
    int row;
    int col;
    int value;
};

class SparseMatrix
{
private:
    int rows;
    int cols;
    vector<SparseEntry> entries; // store nonzero elements

public:
    // Constructor
    SparseMatrix(int r, int c) : rows(r), cols(c) {}

    // Insert a nonzero value at (r, c)
    // If we already had a value at (r, c), we might
    // either update it or add a new entry. We'll keep it simple:
    // just push_back if nonzero.
    // (In a real implementation, we'd check if (r,c) is already present.)
    void insert(int r, int c, int val)
    {
        if (r < 0 || r >= rows || c < 0 || c >= cols)
        {
            throw out_of_range("Index out of range in SparseMatrix::insert");
        }
        if (val == 0)
            return; // skip zero
        SparseEntry e;
        e.row = r;
        e.col = c;
        e.value = val;
        entries.push_back(e);
    }

    // Print the sparse matrix as triplets
    void print() const
    {
        cout << "SparseMatrix (" << rows << " x " << cols << ") with "
             << entries.size() << " nonzero entries:\n";
        for (auto &e : entries)
        {
            cout << "(row=" << e.row << ", col=" << e.col
                 << ", val=" << e.value << ")\n";
        }
    }

    // Optional: getValue(r, c)
    // We'll do a simple linear search in this example
    int getValue(int r, int c) const
    {
        for (auto &e : entries)
        {
            if (e.row == r && e.col == c)
            {
                return e.value;
            }
        }
        return 0; // if not found
    }
};

int main()
{
    /*
     * ======================
     *  DEMO: POLYNOMIAL
     * ======================
     */
    cout << "=== POLYNOMIAL DEMO ===\n";
    Polynomial p;
    p.addTerm(3, 2);  // 3x^2
    p.addTerm(-2, 1); // -2x^1
    p.addTerm(5, 0);  // +5

    cout << "Polynomial p: ";
    p.print(); // e.g. "3x^2 - 2x + 5"

    double val = p.evaluate(2.0);
    cout << "p(2.0) = " << val << endl; // 3*(2^2) - 2*2 + 5 = 12 - 4 + 5 = 13

    /*
     * ======================
     *  DEMO: MATRIX1D (DENSE)
     * ======================
     */
    cout << "\n=== MATRIX1D DEMO ===\n";
    Matrix1D mat(3, 3); // 3x3 matrix
    mat.set(0, 0, 1);
    mat.set(0, 1, 2);
    mat.set(1, 1, 5);
    mat.set(2, 2, 9);
    mat.print();

    cout << "Element at (2,2) = " << mat.get(2, 2) << endl;

    /*
     * ======================
     *  DEMO: SPARSE MATRIX
     * ======================
     */
    cout << "\n=== SPARSE MATRIX DEMO ===\n";
    SparseMatrix sm(4, 5); // 4 rows, 5 columns
    sm.insert(0, 1, 10);
    sm.insert(1, 3, 5);
    sm.insert(3, 4, 7);
    // Suppose the rest are zeros
    sm.print();

    cout << "Value at (1,3) = " << sm.getValue(1, 3) << endl; // should be 5
    cout << "Value at (2,2) = " << sm.getValue(2, 2) << endl; // should be 0

    return 0;
}
