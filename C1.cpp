/*
Gustavs Krasnikovs, gk24018
C1. Virkni a(1..n) sauc par monotonu, ja a(1)<=a(2)<=...<=a(n) vai a(1)>=a(2)>=...>=a(n).
Dots veselu skaitļu masīvs A(m). Noskaidrot garāko tajā sastopamo monotono virkni. 
Izveidot un izmantot funkciju, kas nosaka masīvā sastopamās monotonas virknes garumu, sākot no elementa ar indeksu i.
Programma izveidota: 
*/
#include <iostream>
using namespace std;

int mono(int A[8], int i, int sizeOfArr) {
    
    int count = 0;
    int rev_count = 0;

    for (i; i < sizeOfArr; i++) {
        if (A[i] <= A[i + 1]) {
            count += 1;
        } else if (A[i] > A[i + 1]) {
            int longest_count = count;
            count = 0;
        }

        if (A[i] >= A[i + 1]) {
            rev_count++;
        } else if (A[i] < A[i + 1]) {
            int longest_rev_count = rev_count;
            rev_count = 0;
        }

        cout << count << rev_count << endl;
    }

    if (count >= rev_count) {
        return count;
    } else {
        return rev_count;
    }
}

int main() {
    int A[] = {4, 2, 8, 1, 3, 5, 15, 0};

    int i;
    cin >> i;

    int sizeOfArr = sizeof(A)/sizeof(A[0]);

    int count = mono(A, i - 1, sizeOfArr);

    cout << count << endl;

    return 0;
}

/*
Testa plans


*/