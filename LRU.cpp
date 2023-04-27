#include <iostream>

using namespace std;
int main()
{
    int nopages, nofaults, page[20], count = 0;
    cout << "\nEnter no of pages: ";
    cin >> nopages;
    cout << "\nEnter the Reference String:-" << endl;
    for (int i = 0; i < nopages; i++)
    {
        cin >> page[i];
    }
    cout << "\nEnter the Number of frames: ";
    cin >> nofaults;
    int frame[nofaults], fcount[nofaults];
    for (int i = 0; i < nofaults; i++)
    {
        frame[i] = -1;
        fcount[i] = 0;
    }
    cout << endl;
    for (int i = 0; i < nopages; i++)
    {
        int flag = 0;
        for (int j = 0; j < nofaults; j++)
        {
            if (page[i] == frame[j])
            {
                flag = 1;
                fcount[j] = i + 1;
            }
        }
        cout << page[i] << "->";
        if (flag == 0)
        {
            int min = 0, k = 0;
            while (k < nofaults - 1)
            {
                if (fcount[min] > fcount[k + 1])
                    min = k + 1;
                k++;
            }
            frame[min] = page[i];
            fcount[min] = i + 1;
            count++;
            for (int j = 0; j < nofaults; j++)
            {
                cout << frame[j] << " ";
            }
        }
        cout << endl;
    }
    cout << "\nPage Fault:" << count << endl
         << endl;
    return 0;
}