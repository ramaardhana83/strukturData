#include<iostream>
#include<windows.h>
#include<conio.h>
#include<unistd.h>
#include<string.h>
using namespace std;

void gotoxy(int x, int y)
{
    HANDLE hConsoleOutput;
    COORD dwCursorPosition;
    dwCursorPosition.X = x;
    dwCursorPosition.Y = y;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsoleOutput, dwCursorPosition);
}

void gudangnya(int z)
{
    for(int a=20; a>15; a--)
    {
        gotoxy(60,a); cout << 20-a;
    }
    gotoxy(50,20-z); cout << "Top -->";
}

struct gudang
{
    char nama_brg[20];
    int isidus;
} barang[5];

int top = 0;
int maks = 5;

void lambatkan()
{
    float x = 0;
    do { x = x + 0.005; } while(x <= 40000);
}

void animasi()
{
    for(int x=30; x<62; x++)
    {
        gotoxy(x,10); cout << " " << barang[top].nama_brg;
        lambatkan();
    }
    for(int x=10; x<=20-top; x++)
    {
        gotoxy(62,x); cout << barang[top].nama_brg;
        lambatkan();
        gotoxy(62,x); cout << "             ";
    }
    gotoxy(62,20-top); cout << barang[top].nama_brg;

    for(int x=30; x<75; x++)
    {
        gotoxy(x,11); cout << " " << barang[top].isidus;
        lambatkan();
    }
    for(int x=11; x<=20-top; x++)
    {
        gotoxy(75,x); cout << barang[top].isidus;
        lambatkan();
        gotoxy(75,x); cout << "    ";
    }
}

void push()
{
    if(top < maks)
    {
        gotoxy(5,10); cout << "Masukkan Nama Barang    : "; cin >> barang[top].nama_brg;
        gotoxy(5,11); cout << "Masukkan Isi Barang/Dus : "; cin >> barang[top].isidus;
        animasi();
        top++;
    }
    else
    {
        gotoxy(5,10); cout << "Sorry, Stack is FULL!!, Press Any Key to continue...";
        getch();
    }
}

void animasi1()
{
    for(int x=61; x<101; x++)
    {
        gotoxy(x,21-top); cout << " " << barang[top-1].nama_brg;
        lambatkan();
    }
    gotoxy(100,21-top); cout << "                     ";
}

void pop()
{
    if(top > 0)
    {
        gotoxy(5,10); cout << "Hasil POP adalah : " << barang[top-1].nama_brg << " - " << barang[top-1].isidus;
        animasi1();
        top--;
    }
    else
    {
        gotoxy(5,11); cout << "Sorry Stack is Empty....";
    }
    gotoxy(5,12); cout << "Press Any Key to Continue...";
    getch();
}

void display()
{
    for(int x=0; x<top; x++)
    {
        gotoxy(62,20-x); cout << barang[x].nama_brg;
        gotoxy(75,20-x); cout << barang[x].isidus;
    }
}

void specialPush()
{
    if(top < 2)
    {
        gotoxy(5,22); cout << "Fitur ini hanya bisa digunakan jika terdapat minimal 2 data di stack.";
        getch();
        return;
    }

    if(top >= maks)
    {
        gotoxy(5,22); cout << "Stack penuh! Tidak bisa menambah data baru.";
        getch();
        return;
    }

    gudangnya(top);
    display();

    gotoxy(5,10); cout << "Posisi yang tersedia untuk Special Push: ";
    for(int i = 1; i < top; i++)
        cout << i << " ";
    cout << endl;

    int pos;
    gotoxy(5,11); cout << "Ingin menaruh di posisi ke berapa? ";
    cin >> pos;

    if(pos < 1 || pos >= top)
    {
        gotoxy(5,12); cout << "Posisi tidak valid! Tidak boleh di bawah (0) atau di atas (TOP).";
        getch();
        return;
    }

    for(int i = top; i > pos; i--)
    {
        strcpy(barang[i].nama_brg, barang[i-1].nama_brg);
        barang[i].isidus = barang[i-1].isidus;
    }

    gotoxy(5,13); cout << "Masukkan Nama Barang    : "; cin >> barang[pos].nama_brg;
    gotoxy(5,14); cout << "Masukkan Isi Barang/Dus : "; cin >> barang[pos].isidus;

    top++;
    gudangnya(top);
    display();

    gotoxy(5,16); cout << "Data berhasil ditambahkan di posisi ke-" << pos << "!";
    getch();
}

void specialPop()
{
    if(top < 2)
    {
        gotoxy(5,22); cout << "Fitur ini hanya bisa digunakan jika terdapat minimal 2 data di stack.";
        getch();
        return;
    }

    gudangnya(top);
    display();

    gotoxy(5,10); cout << "Posisi yang dapat dihapus: ";
    for(int i = 0; i < top-1; i++)
        cout << i << " ";
    cout << endl;

    int pos;
    gotoxy(5,11); cout << "Hapus data di posisi ke berapa? ";
    cin >> pos;

    if(pos < 0 || pos >= top-1)
    {
        gotoxy(5,12); cout << "Posisi tidak valid! Tidak bisa menghapus posisi TOP.";
        getch();
        return;
    }

    gotoxy(5,13); cout << "Data yang dihapus: " << barang[pos].nama_brg << " - " << barang[pos].isidus;

    for(int i = pos; i < top-1; i++)
    {
        strcpy(barang[i].nama_brg, barang[i+1].nama_brg);
        barang[i].isidus = barang[i+1].isidus;
    }

    top--;
    gudangnya(top);
    display();

    gotoxy(5,15); cout << "Data berhasil dihapus dari posisi ke-" << pos << "!";
    getch();
}

int main()
{
    int pil;
    do
    {
        system("cls");
        gudangnya(top);
        display();
        gotoxy(1,1); cout << "STACK PADA STRUKTUR DATA";
        gotoxy(1,2); cout << "IMPLEMENTASI PENEMPATAN BARANG DI GUDANG (TOP: " << top << ")";
        gotoxy(1,3); cout << "1. PUSH DATA";
        gotoxy(1,4); cout << "2. POP DATA";
        gotoxy(1,5); cout << "3. SPECIAL PUSH (Tambah di posisi tengah)";
        gotoxy(1,6); cout << "4. SPECIAL POP (Hapus dari posisi tertentu)";
        gotoxy(1,7); cout << "5. EXIT";
        gotoxy(1,9); cout << "Input Pilihan Anda [1-5] : ";
        cin >> pil;

        if(pil == 1) push();
        if(pil == 2) pop();
        if(pil == 3) specialPush();
        if(pil == 4) specialPop();

    } while(pil != 5);
}
