#include <iostream>
#include <stdexcept>
#include <cmath>
using namespace std;

class Polynomial
{
private:
    int *coeff;   // Dynamic array to store coefficients
    int capacity; // Capacity of the array (polynomial degree + 1)

    // Resize the internal array to accommodate higher degree terms.
    void resize(int newCapacity)
    {
        int *newCoeff = new int[newCapacity];
        // Initialize new array with zeros.
        for (int i = 0; i < newCapacity; i++)
            newCoeff[i] = 0;
        // Copy existing coefficients to the new array.
        for (int i = 0; i < capacity; i++)
            newCoeff[i] = coeff[i];
        // Free old array and update pointers.
        delete[] coeff;
        coeff = newCoeff;
        capacity = newCapacity;
    }

public:
    // Default constructor: creates a polynomial with degree 0 (constant 0)
    Polynomial() : capacity(10)
    {
        coeff = new int[capacity];
        for (int i = 0; i < capacity; i++)
            coeff[i] = 0;
    }

    // Parameterized constructor: create polynomial with initial capacity (degree capacity-1)
    Polynomial(int cap) : capacity(cap)
    {
        if (cap <= 0)
            throw invalid_argument("Capacity must be positive");
        coeff = new int[capacity];
        for (int i = 0; i < capacity; i++)
            coeff[i] = 0;
    }

    // Copy constructor for deep copying.
    Polynomial(const Polynomial &other) : capacity(other.capacity)
    {
        coeff = new int[capacity];
        for (int i = 0; i < capacity; i++)
            coeff[i] = other.coeff[i];
    }

    // Assignment operator for deep copying.
    Polynomial &operator=(const Polynomial &other)
    {
        if (this == &other)
            return *this;
        delete[] coeff;
        capacity = other.capacity;
        coeff = new int[capacity];
        for (int i = 0; i < capacity; i++)
            coeff[i] = other.coeff[i];
        return *this;
    }

    // Destructor to free allocated memory.
    ~Polynomial()
    {
        delete[] coeff;
    }

    // Set the coefficient for a given exponent (term insertion/update)
    // If exponent >= capacity, the internal array is resized.
    void setCoefficient(int exponent, int coefficient)
    {
        if (exponent < 0)
            throw invalid_argument("Exponent must be non-negative");
        if (exponent >= capacity)
            resize(exponent + 1);
        coeff[exponent] = coefficient;
    }

    // Get the coefficient for a given exponent.
    // Returns 0 if exponent is outside the current capacity.
    int getCoefficient(int exponent) const
    {
        if (exponent < 0)
            throw invalid_argument("Exponent must be non-negative");
        return (exponent < capacity) ? coeff[exponent] : 0;
    }

    // Remove a term by setting its coefficient to zero.
    void removeTerm(int exponent)
    {
        if (exponent < 0)
            throw invalid_argument("Exponent must be non-negative");
        if (exponent < capacity)
            coeff[exponent] = 0;
    }

    // Polynomial addition: adds corresponding coefficients.
    Polynomial operator+(const Polynomial &other) const
    {
        int maxCap = (capacity > other.capacity) ? capacity : other.capacity;
        Polynomial result(maxCap);
        for (int i = 0; i < maxCap; i++)
        {
            int sum = this->getCoefficient(i) + other.getCoefficient(i);
            result.setCoefficient(i, sum);
        }
        return result;
    }

    // Polynomial subtraction: subtracts corresponding coefficients.
    Polynomial operator-(const Polynomial &other) const
    {
        int maxCap = (capacity > other.capacity) ? capacity : other.capacity;
        Polynomial result(maxCap);
        for (int i = 0; i < maxCap; i++)
        {
            int diff = this->getCoefficient(i) - other.getCoefficient(i);
            result.setCoefficient(i, diff);
        }
        return result;
    }

    // Polynomial multiplication.
    // The degree of the resulting polynomial is the sum of the degrees.
    Polynomial operator*(const Polynomial &other) const
    {
        int resultCap = (capacity - 1) + (other.capacity - 1) + 1;
        Polynomial result(resultCap);
        // Multiply each term of the first polynomial with each term of the second.
        for (int i = 0; i < capacity; i++)
        {
            for (int j = 0; j < other.capacity; j++)
            {
                int current = result.getCoefficient(i + j);
                result.setCoefficient(i + j, current + this->getCoefficient(i) * other.getCoefficient(j));
            }
        }
        return result;
    }

    // Evaluate the polynomial at a given value of x.
    int evaluate(int x) const
    {
        int result = 0;
        int power = 1; // x^0 initially.
        for (int i = 0; i < capacity; i++)
        {
            result += coeff[i] * power;
            power *= x;
        }
        return result;
    }

    // Print the polynomial in human-readable form.
    void print() const
    {
        bool firstTerm = true;
        for (int i = capacity - 1; i >= 0; i--)
        {
            int c = coeff[i];
            if (c != 0)
            {
                // Handle sign and formatting.
                if (!firstTerm)
                {
                    cout << (c > 0 ? " + " : " - ");
                    c = abs(c);
                }
                else
                {
                    if (c < 0)
                    {
                        cout << "-";
                        c = abs(c);
                    }
                    firstTerm = false;
                }
                // Print coefficient (omit 1 if not constant term)
                if (i == 0 || c != 1)
                    cout << c;
                if (i > 0)
                {
                    cout << "x";
                    if (i > 1)
                        cout << "^" << i;
                }
            }
        }
        if (firstTerm)
            cout << "0";
        cout << endl;
    }
};

//---------------------------------------------------------
// MAIN FUNCTION: Demonstrating the Polynomial class usage.
//---------------------------------------------------------
int main()
{
    try
    {
        // Create a polynomial: p(x) = 2 + 3x + 4x^2
        Polynomial poly1;
        poly1.setCoefficient(0, 2);
        poly1.setCoefficient(1, 3);
        poly1.setCoefficient(2, 4);
        cout << "Polynomial 1: ";
        poly1.print();

        // Create another polynomial: q(x) = -1 + 2x^2 + x^3
        Polynomial poly2;
        poly2.setCoefficient(0, -1);
        poly2.setCoefficient(2, 2);
        poly2.setCoefficient(3, 1);
        cout << "Polynomial 2: ";
        poly2.print();

        // Addition: r(x) = p(x) + q(x)
        Polynomial sum = poly1 + poly2;
        cout << "\nSum (p + q): ";
        sum.print();

        // Subtraction: s(x) = p(x) - q(x)
        Polynomial diff = poly1 - poly2;
        cout << "\nDifference (p - q): ";
        diff.print();

        // Multiplication: t(x) = p(x) * q(x)
        Polynomial prod = poly1 * poly2;
        cout << "\nProduct (p * q): ";
        prod.print();

        // Evaluate polynomial at a given value, e.g., x = 2.
        int value = 2;
        cout << "\np(2) = " << poly1.evaluate(value) << "\n";

        // Remove a term from poly1 (e.g., remove the x term)
        poly1.removeTerm(1);
        cout << "\nPolynomial 1 after removing x term: ";
        poly1.print();
    }
    catch (const exception &ex)
    {
        cout << "Exception: " << ex.what() << "\n";
    }

    return 0;
}
