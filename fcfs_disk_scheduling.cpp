#include <iostream>

using namespace std;
void FCFS(int arr[], int head, int size)
{
    int seek_count = 0;
    for (int i = 0; i < size; i++)
    {
        seek_count += abs(arr[i] - head);
        head = arr[i];
    }
    cout << "\nTotal number of operations = " << seek_count << endl;
    cout << "\nSeek Sequence is" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl
         << endl;
}
int main()
{
    int size;
    cout << "Enter size of Request Sequence: ";
    cin >> size;
    int arr[size];
    cout << "Enter Request Sequence:-" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    int head;
    cout << "Enter head: ";
    cin >> head;
    FCFS(arr, head, size);
    return 0;
}