#include <bits/stdc++.h>
using namespace std;

int random_number(int min, int max)
{
    return (rand() % (max - min + 1)) + min;
}

int main()
{

    // Open the output file in append mode
    for (int i = 0; i < 5; i++)
    {
        string filename = "file" + to_string(i+1) + ".txt";
        ofstream o_data(filename, ios::app);
        if (!o_data)
        {
            cout << "Error creating output file" << endl;
            return 1;
        }
        int min = 1;
        int max = 100;
        long int n;
        cout << "enter number of random integers for"<<filename<<":-";
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) // genrating random numbers
        {
            a[i] = random_number(min, max);
        }
        // saving random numbers
        for (int i = 0; i < n; i++)
            {
                o_data << a[i];
                if (i != n - 1)
                {
                    o_data << ", ";
                }
            }
            o_data << endl;
              // Close the output file
        o_data.close();
    }

    return 0;
}