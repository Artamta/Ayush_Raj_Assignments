#include <iostream>
#include <chrono>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

void bubblesort(vector<int> &a)
{
    int n = a.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
            }
        }
    }
}

void insertionsort(vector<int> &a)
{
    int n = a.size();
    for (int i = 1; i < n; i++)
    {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

void selectionsort(vector<int> &a)
{
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[min_index])
            {
                min_index = j;
            }
        }
        swap(a[i], a[min_index]);
    }
}

void printarray(const vector<int> &a, ofstream &outputFile)
{
    for (int i : a)
    {
        outputFile << i << " ";
    }
    outputFile << endl;
}

void measure_sorting_time(const string &filename, vector<int> &a, void (*sort_func)(vector<int> &), const string &sort_name, int i)
{
    vector<int> b = a;
    auto start = chrono::high_resolution_clock::now();
    sort_func(b);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    cout << "Time taken by " << sort_name << " for " << filename << ": " << duration.count() << " seconds" << endl;

    ofstream outputFile(sort_name + "_sorted_" + to_string(i) + ".txt");
    printarray(b, outputFile);
    outputFile.close();
}

int main()
{
    for (int i = 1; i <= 6; i++)
    {
        string filename = "input" + to_string(i) + ".txt";
        ifstream inputFile(filename);
        if (!inputFile)
        {
            cerr << "Error opening file: " << filename << endl;
            return 1;
        }

        vector<int> a;
        int value;
        while (inputFile >> value)
        {
            a.push_back(value);
        }

        inputFile.close();

        measure_sorting_time(filename, a, selectionsort, "selection_sort", i);
        measure_sorting_time(filename, a, insertionsort, "insertion_sort", i);
        measure_sorting_time(filename, a, bubblesort, "bubble_sort", i);
    }

    return 0;
}