#include <iostream>

using namespace std;

int merge(int angka[], int temp[], int kiri, int tengah, int kanan)
{
    int jumlah = 0;

    int i = kiri;
    int j = tengah;
    int k = kiri;
    while ((i <= tengah - 1) && (j <= kanan))
    {
        if (angka[i] <= angka[j])
            temp[k++] = angka[i++];
        else
        {
            temp[k++] = angka[j++];
            jumlah = jumlah + (tengah - i);
        }
    }

    while (i <= tengah - 1)
        temp[k++] = angka[i++];

    while (j <= kanan)
        temp[k++] = angka[j++];

    for (i=kiri; i <= kanan; i++)
        angka[i] = temp[i];

    return jumlah;
}

int urutan(int angka[], int temp[], int kiri, int kanan)
{
    int tengah, jumlah = 0;
    if (kanan > kiri)
    {
        tengah = (kanan + kiri)/2;

        jumlah  = urutan(angka, temp, kiri, tengah);
        jumlah += urutan(angka, temp, tengah+1, kanan);

        jumlah += merge(angka, temp, kiri, tengah+1, kanan);
    }

    return jumlah;
}

int jumlahSwap(int angka[], int n)
{
    int temp[n];
    return urutan(angka, temp, 0, n - 1);
}

int main(int argv, char** args)
{
    int angka[] = {4, 7, 9, 5, 8, 9, 3};
    int n = sizeof(angka)/sizeof(angka[0]);
    printf("Jumlah swap :  %d ", jumlahSwap(angka, n));
    return 0;
}
