# Random Number Sorting Experiment

This project is an experiment to generate random numbers, sort them using three different sorting algorithms, and evaluate their performance in terms of execution time. The project is implemented in C++ and consists of two main components:

- **Random_gen.cpp**: Generates random numbers and stores them in text files.
- **Main.cpp**: Sorts the generated numbers using Bubble Sort, Selection Sort, and Insertion Sort, and records the execution time for each algorithm.

---

## Project Structure

### 1. **Random_gen.cpp**
This program generates random numbers and writes them to separate text files.

- **File Details**:
  - `file1.txt`: Contains 1000 random numbers ranging from 1 to 100.
  - `file2.txt`: Contains 2000 random numbers.
  - `file3.txt`: Contains 2000 random numbers.
  - `file4.txt`: Contains 2000 random numbers.
  - `file5.txt`: Contains 2000 random numbers.

- **How it works**:
  - Prompts the user for the number of random integers for each file.
  - Generates random numbers in the specified range.
  - Saves the numbers to corresponding text files, separated by commas.

### Code Example:
```cpp
#include <bits/stdc++.h>
using namespace std;

int random_number(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

int main() {
    for (int i = 0; i < 5; i++) {
        string filename = "file" + to_string(i+1) + ".txt";
        ofstream o_data(filename, ios::app);
        if (!o_data) {
            cout << "Error creating output file" << endl;
            return 1;
        }
        int min = 1, max = 100;
        long int n;
        cout << "Enter number of random integers for " << filename << ": ";
        cin >> n;
        for (int i = 0; i < n; i++) {
            o_data << random_number(min, max);
            if (i != n - 1) {
                o_data << ", ";
            }
        }
        o_data << endl;
        o_data.close();
    }
    return 0;
}
```

---

### 2. **Main.cpp**
This program reads the random numbers from the generated files, sorts them using three algorithms, and records the execution time in `output.txt`.

- **Sorting Algorithms**:
  - Bubble Sort
  - Selection Sort
  - Insertion Sort

- **Process**:
  1. Fetches random numbers from each file.
  2. Applies each sorting algorithm to the data.
  3. Records the execution time for each sorting method in milliseconds.
  4. Outputs the results to `output.txt`.

- **Output Format**:
  - `output.txt` contains experiment results in CSV format:
    ```csv
    Exp no., Bubble Sort (ms), Selection Sort (ms), Insertion Sort (ms)
    Exp1, 15, 20, 10
    Exp2, 30, 40, 25
    ...
    ```

### Code Example:
```cpp
#include <bits/stdc++.h>
using namespace std;
#include <chrono>

void bubble_sort(vector<int> &v) { ... }
void selection_sort(vector<int> &v) { ... }
void insertion_sort(vector<int> &v) { ... }
vector<int> numberfetch(const string &filename) { ... }

int main() {
    ofstream o_data("output.txt", ios::app);
    o_data << "Exp no., Bubble Sort (ms), Selection Sort (ms), Insertion Sort (ms)\n";
    for (int i = 0; i < 5; i++) {
        string filename = "file" + to_string(i + 1) + ".txt";
        vector<int> original_data = numberfetch(filename);

        vector<int> v = original_data;
        float b_time = bubble_time(v);

        v = original_data;
        float i_time = insertion_time(v);

        v = original_data;
        float s_time = selection_time(v);

        o_data << "Exp" + to_string(i + 1) << "," << b_time << "," << s_time << "," << i_time << "\n";
    }
    return 0;
}
```

---

## How to Run

1. **Compile the programs**:
   ```bash
   g++ Random_gen.cpp -o Random_gen
   g++ Main.cpp -o Main
   ```

2. **Generate random files**:
   ```bash
   ./Random_gen
   ```
   Enter the number of random integers for each file when prompted.

3. **Run the sorting program**:
   ```bash
   ./Main
   ```

4. **View the results**:
   - Generated files: `file1.txt`, `file2.txt`, `file3.txt`, `file4.txt`, `file5.txt`
   - Output: `output.txt`

---

## Output Example

**Content of `output.txt`**:
```csv
Exp no., Bubble Sort (ms), Selection Sort (ms), Insertion Sort (ms)
Exp1, 15, 20, 10
Exp2, 30, 40, 25
Exp3, 45, 60, 35
Exp4, 60, 80, 50
Exp5, 75, 100, 65
```

---

## Excel Visualization
![Bubble sort execution time(ms), selection sort execution time(ms) and insertion sort execution time(ms)](https://github.com/user-attachments/assets/1064a2c8-f960-4220-aa1c-ef806d028081)


---

## Dependencies
- C++ compiler (e.g., GCC)
- Standard Template Library (STL)

---

## File structure 
![image](https://github.com/user-attachments/assets/b28354ef-30e9-4a6b-87ac-d1f485717b2a)


## License
This project is licensed under the MIT License.

