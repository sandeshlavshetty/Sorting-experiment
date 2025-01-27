#include <bits/stdc++.h>
using namespace std;
#include <chrono> // Include the chrono library

void swap(int*a, int*b){
    int temp =*a;
    *a = *b;
    *b = temp;
}



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

void heapifyUp(vector<int> &v,int index){
    cout<<"HeapifyUp"<<endl;
    while(index!=0 && v[(index-1)/2]<v[index]){
        swap(&v[(index-1)/2],&v[index]);
        index = (index-1) / 2;
    }
}

void heapifyDown(vector<int> &v,int index,int heapSize){
    //cout<<"heapifyDown"<<endl;
    int largest = index;
    int left = 2*index+1;
    int right = 2*index+2;

    if(left < heapSize && v[left] > v[largest] )
        largest = left;
    if(right < heapSize && v[right] > v[largest])
        largest = right;
    if (largest != index){
        swap(&v[index],&v[largest]);
        heapifyDown(v,largest,heapSize);
    }
}
auto build_heap(vector<int>&v){
    //cout<<"build_heap"<<endl;
    int heapSize= v.size();
    int last_parent = (heapSize/2)-1;
    for(int i=last_parent;i>=0;i--)
            heapifyDown(v,i,heapSize);
    
    return v;
}

void heap_sort(vector<int> &arr){
    //cout<<"Heap_sort time"<<endl;
    int count = 0;
    int heapSize=arr.size();
    vector<int> v=build_heap(arr);
    for(int i=heapSize-1; i>0;i--){
        int x=v[0];
        v[0]=v[i];
        heapifyDown(v,0,heapSize);
        heapSize--;
        v[i]=x;
        count++;
    }
    // for(int i=0;i<=count;i++){
    //     printf("%d ",v[i]);
    // }
    // printf("\n");
    return;
}

int part(vector<int> &v,int li,int ui){
    int start = li;
    int end = ui;
    int pivot = v[start];
    while(start<end){
        while(v[start]<=pivot)
            start++;
        while(v[end]>pivot)
            end--;
        if(start<end)
            swap(v[start],v[end]);
    }
    swap(v[end],v[li]);
    return end;
}


void quick_sort(vector<int> &v,int li,int ui){
    int loc;
    if(li<ui){
        loc=part(v,li,ui);
        quick_sort(v,li,loc-1);
        quick_sort(v,loc+1,ui);
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

float heap_time(vector<int> &v)
{

    // Heap Sort
    auto heapSortStart = chrono::high_resolution_clock::now();
    heap_sort(v);
    auto heapSortEnd = chrono::high_resolution_clock::now();
    auto heapSortDuration = chrono::duration_cast<chrono::milliseconds>(heapSortEnd - heapSortStart);
    cout << "Heap sort time: " << heapSortDuration.count() << " milliseconds" << endl;
    // print_vec(v);
    return heapSortDuration.count();
}

float quick_time(vector<int> &v)
{
    int n=v.size();
    // Quick Sort
    auto quickSortStart = chrono::high_resolution_clock::now();
    quick_sort(v,0,n);
    auto quickSortEnd = chrono::high_resolution_clock::now();
    auto quickSortDuration = chrono::duration_cast<chrono::milliseconds>(quickSortEnd - quickSortStart);
    cout << "Qucik sort time: " << quickSortDuration.count() << " milliseconds" << endl;
     //print_vec(v);
    return quickSortDuration.count();
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
        cout<<"Exp for:- "<<filename<<endl;
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
        // 4. heap sort
        v = original_data;
        float h_time = heap_time(v);
        // 5. quick sort
        v = original_data;
        float q_time = quick_time(v);
        o_data << "Exp" + to_string(i + 1) << "," << b_time << "," << s_time << "," << i_time <<","<<h_time<<","<<q_time<< endl;
    }
    return 0;
}