#include <stdio.h>
#define FILE_NAME "kacsirandras.txt"


int main()
{
    FILE* file_ptr = fopen(FILE_NAME, "w+");
    fprintf(file_ptr, "Nev: Kacsir Andras, Szak: Programterverzo informatikus, Neptunkod: VSG9L4");
    fclose(file_ptr);
    return 0;
}
