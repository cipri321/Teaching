// Dinamica D[i][cw] - profitul maxim pe care-l putem obtine adaugand o submultime a primelor i obiecte, insumand greutatea cw
for(int i = 1; i <= N; ++i)
    for(int cw = 0; cw <= G; ++cw)
    {
        // Mai intai nu punem obiectul i.
        D[i][cw] = D[i-1][cw];
 
        // Daca acest lucru duce la o solutie curenta mai buna, adaugam obiectul i la o solutie anterioara.
        if(W[i] <= cw)
            D[i][cw] = max(D[i][cw], D[i - 1][cw - W[i]] + P[i]);
    }