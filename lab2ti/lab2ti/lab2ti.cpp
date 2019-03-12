// lab2ti.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>

#include "pch.h" 
#include <iostream> 
#include <string.h> 
#include <stdlib.h> 

int randomSent(char sent[], char alp[])
{
	for (int i = 0; i < 30; i++)
	{
		int k = rand() % 8;
		sent[i] = alp[k];
	}
	return 0;
}

int binaryEncrypt(char sent[],char binary[])
{
	int count = 0;
	for (int i = 0; i < 30; i++)
	{
		int temp = int(sent[i]);
		int mod;
		int lastElement = count + 3;
		for (int j = count; j < lastElement; j++)
		{
			mod = temp % 2;
			binary[j] = mod;
			temp /= 2;
		}
		count += 3;
	}
	return 0;
}
int Decrypt(char binary[],char sent[],char alph[])
{ 
	
	int count = 0;
	
	for (int i = 0; i < 30; i++)
	{
		
			
			int mod;
			int lastElement = count + 3;
			int stpcount = 0;
			int k = 7;
			while (k >= 0) 
			{
				int temp = int(alph[k]);
				for (int j = count; j < lastElement; j++)
				{

					mod = temp % 2;
					temp /= 2;
					if (binary[j] == mod)
					{
						//printf("%d - %d k= %d ", binary[j], mod,k);
						stpcount++;
						if (stpcount == 3)
						{
							printf("%c", alph[k]);
							k = -1;
						}
					}
					else
						--k;
					
				}
				
			}
			count += 3;
			
	}
	return 0;
}
int randomErr(char binary[])
{
	//if (rand() < RAND_MAX / 10)
	//{
		for (int i = 0; i < 30; i++)
		{
			int k = rand() % 30;
			if (binary[k] == '1')
				binary[k] = 0;
			else
				binary[k] = 1;
			// 10% probability
		}
	//}
	return 0;
}
int main()
{

	int r = rand();
	char sent[30];
	char binary[90] = {};
	char alp[8] = { 'a','b', 'c', 'd', 'e', 'f', 'g', 'h' };
	randomSent(sent, alp);
	binaryEncrypt(sent, binary);

	for (int i = 0; i < 30; i++)
	{
		printf("%c", sent[i]);
	}
	printf("\n");

	for (int i = 0; i < 90; i++)
		printf("%d ", binary[i]);

	randomErr(binary);
	printf("\n");
	for (int i = 0; i < 90; i++)
		printf("%d ", binary[i]);
	Decrypt(binary, sent,alp);
	return 0;
}