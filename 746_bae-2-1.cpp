#include "stdafx.h"
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
using namespace std;
void Dijkstra(int s, double **a, int *p,int *o, int &k) {
	int temp;
	int imin, min;	
	system("chcp 1251");
	system("cls");
	for (int i = 0; i<s; i++)
	{
		p[i] = 10000;
		o[i] = 1;
	}
	p[0] = 0;
	do {
		imin = 10000;
		min = 10000;
		for (int i = 0; i<s; i++)
		{
			if ((o[i] == 1) && (p[i]<min))
			{ 
				min = p[i];
				imin = i;
			}
		}
		if (imin != 10000)
		{
			for (int i = 0; i<s; i++)
			{
				if (a[imin][i] > 0)
				{
					temp = min + a[imin][i];
					if (temp < p[i])
					{
						p[i] = temp;
					}
				}
			}
			o[imin] = 0;
		}
	} while (imin < 10000);
	
	int end = 4;
	o[0] = end + 1; 
	int weight = p[end]; 

	while (end > 0) 
	{
		for (int i = 0; i<s; i++) 
			if (a[end][i] != 0)  
			{
				int temp = weight - a[end][i]; 
				if (temp == p[i]) 
				{                
					weight = temp; 
					end = i;      
					o[k] = i + 1; 
					k++;
				}
			}
	}
}
int main()
{
	int SIZE = 6;
	int d[6];
	int v[6]; 
	int l = 1;
	double **x;
	x = new double*[SIZE];
	for (int i = 0; i < SIZE; i++)
		x[i] = new double[SIZE];
	ofstream fout("result.txt");
	ifstream in("matrix.txt");
	if (in.is_open()) {
		int count = 0;
		int temp;
		while (!in.eof()) {
			in >> temp;
			count++;
		}
		in.seekg(0, ios::beg);
		in.clear();
		int count_space = 0;
		char symbol;
		while (!in.eof()) {
			in.get(symbol);
			if (symbol == ' ') count_space++;
			if (symbol == '\n') break;
		}
		in.seekg(0, ios::beg);
		in.clear();
		int n = count / (count_space + 1);
		int m = count_space + 1;
		for (int i = 0; i < n; i++) x[i] = new double[m];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				in >> x[i][j];
		in.close();
	}
	else
	{
		//Если открытие файла прошло не успешно
		cout << "Файл не найден.";
	}

	Dijkstra(6, x, d, v, l);
	printf("Кратчайшие расстояния до вершин: \n");
	for (int i = 0; i < SIZE; i++) {
		printf("%d", d[i]);
		printf(" ");
		fout << d[i] << " ";
	}
	printf("\n");
	fout.close();
	system("pause");		
	getchar();
	return 0;
}


