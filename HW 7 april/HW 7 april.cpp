#include <iostream>

const int N = 3;
const int M = 4;

extern "C" 
{
    void _fastcall CreateVectorB(unsigned int A[][M], int N, int M, int* B);
    void __fastcall IntToOct(int, char*);
    int __stdcall FindSaddlePoints(int matrix[][M], int N, int M, int* results);
    int __fastcall IsMin(int matrix[][M], int m ,int v, int N, int M);
    int __fastcall IsMax(int matrix[][M], int m, int v, int N, int M);
}
int main()
{
    int matrix[N][M] = 
    {
        {3,0,7,0},
        {0,3,9,4},
        {4,0,7,0} 
    };

    int* B = new int[M];
   /* for (int i = 0; i < M; i++)
    {
        int zero_count = 0;
        for (int j = 0; j < N; j++)
        {
            if (matrix[j][i] == 0)
                ++zero_count;
        }
        B[i] = zero_count;
    }*/
    _asm
    {
        mov eax, B
        push eax
        push M

        lea ecx, matrix    
        mov edx, N             

        call CreateVectorB

        pop ebx
        pop ebx
    }

    for (int i = 0; i < M; i++)
        std::cout << '[' << B[i] << ']';
    std::cout << '\n';
    int number = 0x2A;
    char str[12];
    IntToOct(number, str);
    std::cout << "IntToOct = " << str << '\n';
}