/*************************************
*
*Pedro Caetano Batista Neto
*Trabalho 1
*Professor(a): Diego Rubert
*/


#include <stdio.h>
#include <stdlib.h>

typedef struct
{
 int numero;
 int ultrapass;
} Capivara;
void merge(Capivara arr[], int l, int m, int r)
{
 int i, j, k;
 int n1 = m - l + 1;
 int n2 = r - m;
 Capivara L[n1], R[n2];
 for (i = 0; i < n1; i++)
  L[i] = arr[l + i];
 for (j = 0; j < n2; j++)
  R[j] = arr[m + 1 + j];

 i = 0;
 j = 0;
 k = l;
 while (i < n1 && j < n2)
 {
  if (L[i].ultrapass > R[j].ultrapass)
  {
   arr[k] = L[i];
   i++;
  }
  else if (L[i].ultrapass < R[j].ultrapass)
  {
   arr[k] = R[j];
   j++;
  }
  else
  {
   if (L[i].numero < R[j].numero)
   {
    arr[k] = L[i];
    i++;
   }
   else
   {
    arr[k] = R[j];
    j++;
   }
  }
  k++;
 }

 while (i < n1)
 {
  arr[k] = L[i];
  i++;
  k++;
 }

 while (j < n2)
 {
  arr[k] = R[j];
  j++;
  k++;
 }
}

void mergeSort(Capivara arr[], int l, int r)
{
 if (l < r)
 {
  int m = l + (r - l) / 2;
  mergeSort(arr, l, m);
  mergeSort(arr, m + 1, r);
  merge(arr, l, m, r);
 }
}

int main()
{
 int n;
 scanf("%d", &n);

 Capivara *capivaras = malloc(n * sizeof(Capivara));
  for (int i = 0; i < n; i++)
 {
  capivaras[i].numero = i + 1;
  capivaras[i].ultrapass = 0;
 }
 int ultrapassagem;
 while (scanf("%d", &ultrapassagem) != EOF)
 {
  for (int i = ultrapassagem - 1; i < n; i++)
  {
   capivaras[i].ultrapass++;
  }
 }
 mergeSort(capivaras, 0, n - 1);
 for (int i = 0; i < n; i++)
 {
  printf("%d ", capivaras[i].numero);
 }
 printf("\n");
 for (int i = 0; i < n; i++)
 {
  printf("%d ", i + 1);
 }
 printf("\n");
 free(capivaras);
 return 0;
}
