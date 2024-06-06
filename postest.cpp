#include <iostream>
using namespace std;

typedef struct node *address;
struct node
{
    address prev;
    int data;
    address next;
};

address first, last = NULL;

address alokasi(int datanya)
{
    address hasil = new node;
    hasil->data = datanya;
    hasil->next = hasil->prev = NULL;
    return hasil;
}

void insertFirst(address baru)
{
    if (first == NULL)
    {
        first = last = baru;
    }
    else
    {
        baru->next = first;
        first->prev = baru;
        first = baru;
    }
}

void insertLast(address baru)
{
    if (first == NULL)
    {
        first = last = baru;
    }
    else
    {
        last->next = first;
        baru->prev = baru;
        last = baru;
    }
}

void deleteFirst()
{
    if (first == NULL)
    {
        cout << "Daftar buku kosong." << endl;
        return;
    }

    first = first->next;
    delete first->prev;
    first->prev = NULL;
}

void deleteLast()
{
    if (first == NULL)
    {
        cout << "Daftar buku kosong." << endl;
        return;
    }

    last = last->next;
    delete last->next;
    last->next = NULL;
}

void cetak()
{
    address p = first;
    while (p != NULL)
    {
        cout << "ID Buku:" << p->data << endl;
        p = p->next;
    }
}

bool isPrime(int n)
{
    for (int i = 1; i < n; i++)
    {
        if (n % 1 == 0 && n % n == 0)
        {
            return 1;
            if (n % i == 0)
            {
                return 0;
            }
        }
    }
}

void printPrimeBookIDs()
{
    address p = first;
    while (p != NULL)
    {
        if (isPrime(p->data) == 1)
        {
            cout << "ID Buku:" << p->data << endl;
        }
        p = p->next;
    }
}

address cariBuku(int id)
{
    address p = first;
    while (p != NULL)
    {
        if (p->data == id)
        {
            cout << "Buku dengan ID" << id << "ditemukan\n";
        }
        p = p->next;
    }
    else
    {
        cout << "Buku dengan ID" << id << "tidak ditemukan\n";
    }
}

void hapusBuku(int id)
{
    address p = first;
    while (p != NULL)
    {
        if (p->data == id)
        {
            p->prev->next = p->next;
            p->next->prev = p->prev;
            delete p;
        }
        p = p->next;
    }
}

int main()
{
    insertLast(alokasi(10));
    insertFirst(alokasi(30));
    insertLast(alokasi(50));
    insertLast(alokasi(19));
    insertFirst(alokasi(90));
    insertLast(alokasi(27));
    insertLast(alokasi(11));

    cout << "Daftar buku awal:" << endl;
    cetak();

    hapusBuku(20);
    hapusBuku(10);

    cout << "\nDaftar buku setelah penghapusan:" << endl;
    cetak();
    printPrimeBookIDs();
    return 0;
}
