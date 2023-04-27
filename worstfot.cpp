#include <iostream>
using namespace std;
void worstFit(int block[], int m, int process[], int n)
{
    int allocation[n];
    for (int i = 0; i < n; i++)
    {
        allocation[i] = -1;
    }
    for (int i = 0; i < n; i++)
    {
        int wstIdx = -1;
        for (int j = 0; j < m; j++)
        {
            if (block[j] >= process[i])
            {
                if (wstIdx == -1)
                    wstIdx = j;
                else if (block[wstIdx] < block[j])
                    wstIdx = j;
            }
        }
        if (wstIdx != -1)
        {
            allocation[i] = wstIdx;
            block[wstIdx] -= process[i];
        }
    }
    cout << "\nProcess No.\tProcess Size\tBlock no.\n";
    for (int i = 0; i < n; i++)
    {
        cout << " " << i + 1 << "\t\t" << process[i] << "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1;
        else
            cout << "Not Allocated";
        cout << endl;
    }
}
// Driver code
int main()
{
    int pno, bno;
    cout << "\nEnter the number of partitions: ";
    cin >> bno;
    cout << "Enter the number of processes: ";
    cin >> pno;
    int block[bno];
    int process[pno];
    cout << "\nEnter the size of the partitions:-" << endl;
    for (int i = 0; i < bno; i++)
    {
        cin >> block[i];
    }
    cout << "\nEnter the size of the processes :-" << endl;
    for (int i = 0; i < pno; i++)
    {
        cin >> process[i];
    }
    worstFit(block, bno, process, pno);
    return 0;
}
