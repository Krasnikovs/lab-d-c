/*
Gustavs Krasnikovs, gk24018
C1. Virkni a(1..n) sauc par monotonu, ja a(1)<=a(2)<=...<=a(n) vai a(1)>=a(2)>=...>=a(n).
Dots veselu skaitļu masīvs A(m). Noskaidrot garāko tajā sastopamo monotono virkni. 
Izveidot un izmantot funkciju, kas nosaka masīvā sastopamās monotonas virknes garumu, sākot no elementa ar indeksu i.
Programma izveidota: 
*/
#include <iostream>
using namespace std;

int* mono(int A[8], int i, int sizeOfArr) {
    int count = 0;
    int rev_count = 0;
    int* mono_run = new int;
    int* rev_mono_run = new int;
    int* longest_mono_run = new int;
    int* longest_rev_mono_run = new int;

    for (int j = i; j < sizeOfArr; j++) {
        if (j == sizeOfArr - 1) {
            longest_mono_run = mono_run;
        } else if (A[i] <= A[i + 1]) {
            mono_run[i] = A[i];
            count++;
            continue;
        } else if (A[i] > A[i + 1]) {
            longest_mono_run = mono_run;
            int longest_count = count;
            count = 0;
        }

    }

    for (int j = i; j < sizeOfArr; j++) {
        if (A[i] >= A[i + 1]) {
            rev_mono_run[rev_count] = A[i];
            rev_count++;
            continue;
        } else if (A[i] < A[i + 1]) {
            longest_rev_mono_run = rev_mono_run;
            int longest_rev_count = rev_count;
            rev_count = 0;
        }

        cout << count << rev_count << endl;
    }

    if (count >= rev_count) {
        return longest_mono_run;
    } else {
        return longest_rev_mono_run;
    }
}

int main() {
    int length;
    int* A = new int;

    int i = 0;

    cout << "Ievadiet virknes garumu: ";
    cin >> length;

    for (int i = 0; i < length; i++) {
        cout << "Ievadiet velamo vertibu: ";
        cin >> A[i];
    }

    // int sizeOfArr = sizeof(A)/sizeof(A[0]);

    int* mono_run = mono(A, i, length);

    int sizeOfMono = sizeof(mono_run)/sizeof(mono_run[0]);

    for (int i = 0; i < sizeOfMono; i++) {
        cout << mono_run[i] << endl;
    }

    return 0;
}

/*
Testa plans


*/