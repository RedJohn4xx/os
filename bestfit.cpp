#include <iostream>

using namespace std;
int main()
{
    int frag[20], b[20], p[20], nb, np, temp, lowest = 9999;
    static int barray[20], parray[20];
    cout << "\nEnter the number of partitions: ";
    cin >> nb;
    cout << "Enter the number of processes: ";
    cin >> np;
    cout << "\nEnter the size of the partitions:-" << endl;
    for (int i = 0; i < nb; i++)
    {
        cin >> b[i];
    }
    cout << "\nEnter the size of the processes :-" << endl;
    for (int i = 0; i < np; i++)
    {
        cin >> p[i];
    }
    for (int i = 0; i < np; i++)
    {
        for (int j = 0; j < nb; j++)
        {
            if (barray[j] != 1)
            {
                temp = b[j] - p[i];
                if (temp >= 0)
                {
                    if (lowest > temp)
                    {
                        parray[i] = j;
                        lowest = temp;
                    }
                }
            }
        }
        frag[i] = lowest;
        barray[parray[i]] = 1;
        lowest = 10000;
    }
    cout << "\nProcess_no\tProcess_size\tPartition_no\tPartition_size\t Fragment";
    for (int i = 0; i < np; i++)
        cout << "\n"
             << i + 1 << "\t\t" << p[i] << "\t\t\t" << parray[i] + 1 << "\t\t" << b[parray[i]] << "\t\t" << frag[i];
    return 0;
}