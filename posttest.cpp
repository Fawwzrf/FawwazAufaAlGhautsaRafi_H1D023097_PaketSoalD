#include <stdio.h>
typedef struct KHS *alamat;
struct khs
{
    int nim;
    float ip = 3.85;
};
alamat first = NULL;

void updateIP(int ipe)
{
    alamat first = new khs;
    first->nim = 023097;
    first->ip = ipe;
    return first;
}

void printKHS()
{
    alamat p = first;
    printf("NIM: %d", p->nim);
    printf("IP: %f", p->ip);
}

int main()
{

    printf("Sebelum IP diperbarui:\n");
    printKHS();
    printf("\n");

    updateIP(4.00);

    printf("Setelah IP diperbarui:\n");
    printKHS(&p);

    return 0;
}