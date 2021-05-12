/**
 * @file scuola.cpp
 *
 * @version 01.01 2020-11-12
 *
 * @brief https://training.olinfo.it/#/task/scuola/statement
 *
 * @ingroup scuola
 * (Note: this needs exactly one @defgroup somewhere)
 *
 * @author Castellani Davide
 *
 * Contact: contacts@castellanidavide.it
 *
 */

// Includes
#include <bits/stdc++.h>
using namespace std;

#define DEBUG

// Variabiles
int N, P, my_index;

// Main code
int main()
{
    // Cncomment the following lines if you want to read/write from files
#ifndef DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // DEBUG

    // Input
    cin >> N >> P;

    if (P == 1)
    {
        vector < vector <int> > used (N, vector <int> (N, false));
        for (int i = 0; i < N; ++i)
        {
            vector <int> taked (N, false);
            for (int j = i; j < N + i; ++j)
            {
                my_index = 0;

                while(taked[my_index] || used[j % N][my_index])
                    my_index++;
                taked[my_index] = true;
                used[j % N][my_index] = true;
                cout << (j % N) + 1 << " " << my_index + 1;
                if (j != N + i - 1)
                    cout << " ";
            }
            cout << endl;
        }
    }
    else    // P = 2
    {
        vector < vector <int> > used (N, vector <int> (N, false));
        for (int i = 0; i < N; ++i)
        {
            vector <int> taked (N, false);
            for (int j = i; j < N + i; ++j)
            {
                if (!taked[j % N])
                {
                    my_index = 0;

                    while(taked[my_index] || taked[j % N] || used[j % N][my_index])// || (j % N) != i)
                        my_index++;

                    taked[my_index] = true;
                    taked[j % N] = true;
                    used[j % N][my_index] = true;
                    used[my_index][j % N] = true;
                    if (i != 0)
                    {
                        cout << (j % N) + 1 << " " << my_index + 1;
                        if (j != N + i - 1)
                            cout << " ";
                    }
                }
            }
            if (i != 0)
                cout << endl;
        }
    }

    // End
    return 0;
}
