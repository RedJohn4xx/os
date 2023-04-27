#include <iostream>

using namespace std;
int main()
{
    int RQ[100], i, j, n, TotalHeadMoment = 0, initial, size, move;
    cout << "\nEnter the number of Requests: ";
    cin >> n;
    cout << "Enter the Requests sequence:-" << endl;
    for (i = 0; i < n; i++)
        cin >> RQ[i];
    cout << "Enter initial head position: ";
    cin >> initial;
    cout << "Enter the head movement direction for high 1 and for low 0: ";
    cin >> move;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (RQ[j] > RQ[j + 1])
            {
                int temp;
                temp = RQ[j];
                RQ[j] = RQ[j + 1];
                RQ[j + 1] = temp;
            }
        }
    }
    int index;
    for (i = 0; i < n; i++)
    {
        if (initial < RQ[i])
        {
            index = i;
            break;
        }
    }
    if (move == 1)
    {
        for (i = index; i < n; i++)
        {
            TotalHeadMoment = TotalHeadMoment + abs(RQ[i] - initial);
            initial = RQ[i];
        }
        for (i = index - 1; i >= 0; i--)
        {
            TotalHeadMoment = TotalHeadMoment + abs(RQ[i] - initial);
            initial = RQ[i];
        }
    }
    else
    {
        for (i = index - 1; i >= 0; i--)
        {
            TotalHeadMoment = TotalHeadMoment + abs(RQ[i] - initial);
            initial = RQ[i];
        }
        for (i = index; i < n; i++)
        {
            TotalHeadMoment = TotalHeadMoment + abs(RQ[i] - initial);
            initial = RQ[i];
        }
    }
    cout << "\nTotal head movement is " << TotalHeadMoment << endl
         << endl;
    return 0;
}