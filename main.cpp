#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

void SelectSort (int *A, int n, int z);
int Srav (struct spravka x, struct spravka y, int z);
void BSearch_name(struct spravka A[], int *arr, int size, char *key);
void BSearch_city(struct spravka A[], int *arr, int size, char *key);
void BSearch_surname(struct spravka A[], int *arr, int size, char *key);
void BSearch_phone(struct spravka A[], int *arr, int size, char *key);


struct spravka
{
    char sir[10];
    char name[13];
    char city[12];
    char phone[16];
};
struct spravka abonent[5];


void Swap (int &x, int &y)
{
    int t=x; x=y; y=t;
}

void spis ()
{
    strcpy (abonent[0].sir, "Unadenko");
    strcpy (abonent[1].sir, "Balashov");
    strcpy (abonent[2].sir, "Kyndamon");
    strcpy (abonent[3].sir, "Anagon");
    strcpy (abonent[4].sir, "Dayarkin");

    strcpy (abonent[0].name, "Anatoliy");
    strcpy (abonent[1].name, "Vadim");
    strcpy (abonent[2].name, "Ilia");
    strcpy (abonent[3].name, "Erick");
    strcpy (abonent[4].name, "Saveliy");

    strcpy (abonent[0].city, "Moskva");
    strcpy (abonent[1].city, "Parish");
    strcpy (abonent[2].city, "Berlin");
    strcpy (abonent[3].city, "Piter");
    strcpy (abonent[4].city, "Novosibirsk");

    strcpy (abonent[0].phone, "8-800-555-35-35");
    strcpy (abonent[1].phone, "8-999-133-72-28");
    strcpy (abonent[2].phone, "8-900-148-80-00");
    strcpy (abonent[3].phone, "8-915-915-91-55");
    strcpy (abonent[4].phone, "8-988-888-88-88");
}

int main()
{
    spis ();
    int i, n=5;
    int A[5], B[5], C[5], V[5];
    for (i=0; i<n; i++)
    {
        A[i]=i;
        B[i]=i;
        C[i]=i;
        V[i]=i;
    }
    SelectSort (A,n,0);
    SelectSort (B,n,1);
    SelectSort (C,n,2);
    SelectSort (V,n,3);
    for (i=0; i<n; i++)
    {
        printf ("%s ", abonent[i].sir);
        printf ("%s ", abonent[i].name);
        printf ("%s ", abonent[i].city);
        printf ("%s ", abonent[i].phone);
        printf("\n");
    }
    printf("\n Sort for name\n\n");
    for (i=0; i<n; i++)
    {
        printf ("%s ", abonent[A[i]].name);
        printf ("%s ", abonent[A[i]].sir);
        printf ("%s ", abonent[A[i]].city);
        printf ("%s ", abonent[A[i]].phone);
        printf("\n");
    }
    printf("\n Sort for city\n\n");
    for (i=0; i<n; i++)
    {
        printf ("%s ", abonent[B[i]].city);
        printf ("%s ", abonent[B[i]].sir);
        printf ("%s ", abonent[B[i]].name);
        printf ("%s ", abonent[B[i]].phone);
        printf("\n");
    }


    ///////////////////// 5 +

    printf("\n\n");
    char key1[5],key2[16];
    cout << "Enter first KEY: ";
    cin >> key1;
    cout << "\nEnter second KEY " << key1 << ": ";
    cin >> key2;


    n=5;
    if(strcmp ("name",key1)==0)
    {
        BSearch_name(abonent,A,n,key2);
    }
    if(strcmp ("city",key1)==0)
    {
        BSearch_city(abonent,B,n,key2);
    }
    if(strcmp ("surname",key1)==0)
    {
        BSearch_surname(abonent,C,n,key2);
    }
    if(strcmp ("phone",key1)==0)
    {
        BSearch_phone(abonent,V,n,key2);
    }

}

void BSearch_name(struct spravka A[], int *arr, int size, char *key){
    int L=0, R=size-1;
    int m;
    while (L < R){
        m = (L+R)/2;
        if (strcmp(A[arr[m]].name, key)<0) L = m+1;
        else R = m;
    }
    if (strcmp(A[arr[R]].name, key) == 0){
        printf ("%s ", A[arr[R]].name);
        printf ("%s ", A[arr[R]].sir);
        printf ("%s ", A[arr[R]].city);
        printf ("%s ", A[arr[R]].phone);
        printf("\n");
    }
    else
        cout << "Record with the given key was not found in the directory \n";
}

void BSearch_city(struct spravka A[], int *arr, int size, char *key){
    int L=0, R=size-1;
    int m;
    while (L < R){
        m = (L+R)/2;
        if (strcmp(A[arr[m]].city, key)<0) L = m+1;
        else R = m;
    }
    if (strcmp(A[arr[R]].city, key) == 0){
        printf ("%s ", A[arr[R]].city);
        printf ("%s ", A[arr[R]].name);
        printf ("%s ", A[arr[R]].sir);
        printf ("%s ", A[arr[R]].phone);
        printf("\n");
    }
    else
        cout << "Record with the given key was not found in the directory \n";
}

void BSearch_surname(struct spravka A[], int *arr, int size, char *key){
    int L=0, R=size-1;
    int m;
    while (L < R){
        m = (L+R)/2;
        if (strcmp(A[arr[m]].sir, key)<0) L = m+1;
        else R = m;
    }
    if (strcmp(A[arr[R]].sir, key) == 0){
        printf ("%s ", A[arr[R]].sir);
        printf ("%s ", A[arr[R]].name);
        printf ("%s ", A[arr[R]].city);
        printf ("%s ", A[arr[R]].phone);
        printf("\n");
    }
    else
        cout << "Record with the given key was not found in the directory \n";
}

void BSearch_phone(struct spravka A[], int *arr, int size, char *key){
    int L=0, R=size-1;
    int m;
    while (L < R){
        m = (L+R)/2;
        if (strcmp(A[arr[m]].phone, key)<0) L = m+1;
        else R = m;
    }
    if (strcmp(A[arr[R]].phone, key) == 0){
        printf ("%s ", A[arr[R]].phone);
        printf ("%s ", A[arr[R]].name);
        printf ("%s ", A[arr[R]].sir);
        printf ("%s ", A[arr[R]].city);
        printf("\n");
    }
    else
        cout << "Record with the given key was not found in the directory \n";
}


void SelectSort (int *A, int n, int z) {
    int i, j ,k, t;
    for (i=0; i<(n-1); i++) {
        k=i;
        for (j=i+1; j<n; j++) {
            if (Srav(abonent [A[j]], abonent [A[k]], z)) k=j;
        }
        if (k!=i) {
            Swap (A[i], A[k]);
        }
    }
}

int Srav (struct spravka x, struct spravka y, int z) {
    int i;
    switch (z)
    {
        case 0: i=strcmp (x.name, y.name); if (i<0) return 1;
    else return 0; break;

        case 1: i=strcmp (x.city, y.city); if (i<0) return 1;
    else return 0; break;

        case 2: i=strcmp (x.sir, y.sir); if (i<0) return 1;
    else return 0; break;

        case 3: i=strcmp (x.phone, y.phone); if (i<0) return 1;
    else return 0; break;
    }
}