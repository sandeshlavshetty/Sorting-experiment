#include <bits/stdc++.h>
using namespace std;
#include <chrono> // Include the chrono library

void selection_sort(vector<int> &v)
{
    int n = v.size();
    for (int i = 0; i < n - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (v[j] < v[min_idx])
            {
                min_idx = j;
            }
        }
        swap(v[i], v[min_idx]);
    }
}

void insertion_sort(vector<int> &v)
{
    int n = v.size();
    for (int i = 1; i < n; i++)
    {
        int key = v[i];
        int j = i - 1;

        while (j >= 0 && v[j] > key)
        {
            v[j + 1] = v[j];
            j = j - 1;
        }
        v[j + 1] = key;
    }
}

void bubble_sort(vector<int> &v)
{
    int n = v.size();

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (v[j] > v[j + 1])
            {
                swap(v[j], v[j + 1]);
            }
        }
    }
}

vector<int> numberfetch(const string &filename)
{
    // Open the input file
    ifstream i_data(filename);
    if (!i_data)
    {
        cout << "Error opening file" << endl;
    }

    string line;
    vector<int> v;

    while (getline(i_data, line))
    {
        // Remove extra spaces, if any, around commas
        stringstream ss(line);
        string token;

        while (getline(ss, token, ','))
        {
            // Trim potential spaces around the token
            token.erase(0, token.find_first_not_of(" \t"));
            token.erase(token.find_last_not_of(" \t") + 1);
            v.push_back(stoi(token));
        }
    }

    // // Display the numbers
    // for (size_t i = 0; i < v.size(); ++i)
    // {
    //     cout << v[i];
    //     if (i != v.size() - 1) cout << ", ";  // Print a comma except for the last number
    // }
    // cout << endl;
    return v;
}

void print_vec(vector<int> v)
{
    for (size_t i = 0; i < v.size(); ++i)
    {
        cout << v[i];
        if (i != v.size() - 1)
            cout << ", "; // Print a comma except for the last number
    }
    cout << endl;
}

float bubble_time(vector<int> &v)
{

    // Bubble Sort
    auto bubbleSortStart = chrono::high_resolution_clock::now();
    bubble_sort(v);
    auto bubbleSortEnd = chrono::high_resolution_clock::now();
    auto bubbleSortDuration = chrono::duration_cast<chrono::milliseconds>(bubbleSortEnd - bubbleSortStart);
    cout << "Bubble sort time: " << bubbleSortDuration.count() << " milliseconds" << endl;

    return bubbleSortDuration.count();
}

float selection_time(vector<int> &v)
{
    // Selection Sort
    auto selectionSortStart = chrono::high_resolution_clock::now();
    selection_sort(v);
    auto selectionSortEnd = chrono::high_resolution_clock::now();
    auto selectionSortDuration = chrono::duration_cast<chrono::milliseconds>(selectionSortEnd - selectionSortStart);
    cout << "Selection sort time: " << selectionSortDuration.count() << " milliseconds" << endl;

    return selectionSortDuration.count();
}

float insertion_time(vector<int> &v)
{
    // Insertion Sort
    // Reset to original data
    auto insertionSortStart = chrono::high_resolution_clock::now();
    insertion_sort(v);
    auto insertionSortEnd = chrono::high_resolution_clock::now();
    auto insertionSortDuration = chrono::duration_cast<chrono::milliseconds>(insertionSortEnd - insertionSortStart);
    cout << "Insertion sort time: " << insertionSortDuration.count() << " milliseconds" << endl;

    return insertionSortDuration.count();
}

int main()
{
    vector<int> original_data = numberfetch("file1.txt");
    vector<int> v = original_data;
    ofstream o_data("output.txt", ios::app);
    if (!o_data)
    {
        cout << "Error creating output file" << endl;
        return 1;
    }
    o_data << "Exp no." << "," << "bubble sort(ms)" << "," << "selection sort(ms)" << "," << "insertion sort" << endl;
    for (int i = 0; i < 5; i++)
    {
        string filename = "file" + to_string(i + 1) + ".txt";
        vector<int> original_data = numberfetch(filename);
        // 1. bubble sort
        vector<int> v = original_data;
        float b_time = bubble_time(v);
        // 2. insertion sort
        v = original_data;
        float i_time = insertion_time(v);
        // 3. selection sort
        v = original_data;
        float s_time = selection_time(v);
        o_data << "Exp" + to_string(i + 1) << "," << b_time << "," << s_time << "," << i_time << endl;
    }
    return 0;
}