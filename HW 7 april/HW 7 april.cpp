#include <iostream>

extern "C"
{
	void __fastcall CreateVectorB(unsigned int A[][4], int N,  int M, int* B);
//	int __stdcall FindSaddlePoints(int matrix[][m], int n, int m, int* results);
}

int main()
{
	const int n = 3, m = 4;
	unsigned int matrix[n][m] = {
		{1,0,0,7},
		{0,0,3,0},
		{9,0,0,8},

	};
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			std::cout << matrix[i][j] << " ";
		std::cout << '\n';
	}
	int* B = new int[m];
	for (int i = 0; i < m; i++)
	{
		int zero_count = 0;
		for (int j = 0; j < n; j++)
		{
			if (matrix[j][i] == 0)
				++zero_count;
		}
		B[i] = zero_count;
	}
	for (int i = 0; i < m; i++)
		std::cout << B[i] << ' ';
	std::cout << '\n';
	int* V = new int[m];
	_asm
	{
		mov ecx, matrix
		xor ebx, ebx
		mov eax, V
		xor esi, esi;i
		beg1:
		cmp esi, m
			jge end1
			xor edx, edx
			xor edi, edi;j
				
			beg2:
					cmp edi,n
						jge end2
							push esi
							push edi
							imul edi,m
							imul edi, 4	
							imul esi, m
							add edi, esi
							mov ebx, matrix[edi]
							cmp ebx, 0
								jne jne1
								inc edx
							jne1:
					pop edi
					pop esi
						inc edi
						jmp beg2
				end2:
				mov [eax][esi * 4], edx
				inc esi
				jmp beg1
			end1:
				mov V, eax
	}
	for (int i = 0; i < m; i++)
		std::cout << V[i] << ' ';
}