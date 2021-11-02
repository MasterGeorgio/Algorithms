
#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <stdint.h>
#include <Windows.h>


//-----------------
// Task 16.1
//-----------------
void printMass(char *pucData, size_t dwSize)
{
	for (size_t i = 0; i < dwSize; i++)
		printf("0x%02X, ", (uint8_t)pucData[i]);

	printf("\n");
}

enum eTEXTformat {
	eNoUsing,
	eUsing
};

void CesarEncode(
	char   *pcMessage,
	size_t dwSize,
	int    nKey,
	eTEXTformat format = eNoUsing) {
	
	for (size_t i = 0; i < dwSize; i++)
	{
		pcMessage[i] = pcMessage[i] + nKey;

		if (format && pcMessage[i] < 0x20)
			pcMessage[i] += 0x20 * (1 - 2*((uint32_t)nKey >> 31));
	}
}

void CesarDecode(
	char   *pcMessage,
	size_t dwSize,
	int    nKey,
	eTEXTformat format = eNoUsing) {

	CesarEncode(
		pcMessage,
		dwSize,
		0 - nKey,
		format);
}


//-----------------
void task16_1()
{
	printf("Task 16.1\n");

	//char *mass = new char[17];
	char mass[17];
	int nKey = 3;

	gets_s(mass, 17);
	// In abcdef
	printf("Open  text: %s\n", mass);

	// Out efghi
	CesarEncode(mass, strlen(mass), nKey, eUsing);
	printf("Close text: %s\n", mass);
	printMass(mass, strlen(mass));

	CesarDecode(mass, strlen(mass), nKey, eUsing);
	// Out abcdef
	printf("Open  text: %s\n", mass);

 	printf("\n");
}
//-----------------


//-----------------
// Task 16.2
//-----------------
void task16_2()
{
	printf("Task 16.2\n");
	printf("\n");
}
//-----------------

int main()
{
	setlocale(0, "");
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// Òask 16.1
	task16_1();

	// Òask 16.2
	task16_2();

	system("pause");
	return 0;
}