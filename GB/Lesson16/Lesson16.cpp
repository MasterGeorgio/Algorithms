
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

// This is to ignore first 32 of charters, that disvisible
enum eTEXTformat {
	eNoUsing,
	eUsing
};

/// Cesar encode text
void CesarEncode(
	char   *pcMessage,
	size_t dwSize,
	int    nKey,
	eTEXTformat format = eNoUsing) {
	
	for (size_t i = 0; i < dwSize; i++)
	{
		pcMessage[i] = pcMessage[i] + nKey;

		// Offset to left or to rigth
		if (format && pcMessage[i] < 0x20)
			pcMessage[i] += 0x20 * (1 - 2*((uint32_t)nKey >> 31));
	}
}

/// Cesar decode text
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

	char *mass = new char[17];
	//char mass[17];
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
	free(mass);
}
//-----------------


//-----------------
// Task 16.2
//-----------------
enum eModeMeshing {
	eEncode,
	eDecode
};

/*
   \fn       void Meshing(char   *pcMessage,
	                      size_t dwSize,
	                      int    *nKey,
	                      int    nColumn,
	                      eModeMeshing mode = eEncode)
	\brief   Meshing input the text using key
	\param   pcMessage (IN/OUT) - source text
	         dwSize    (IN)     - size text
			 nKey      (IN)     - array value for meshing by columns
			 mode      (IN)     - mode work this function (encode/decode)
	\remark  dwSize must be a multiple of nColumn
*/
void Meshing(
	char   *pcMessage,
	size_t dwSize,
	int    *nKey,
	int    nColumn,
	eModeMeshing mode = eEncode) {

	char *tmp = new char[nColumn];

	for (size_t j = 0; j < dwSize / nColumn; j++)
	{
		memcpy(tmp, &pcMessage[nColumn * j], nColumn);

		for (size_t i = 0; i < nColumn; i++)
		{
			if (mode == eEncode)
				pcMessage[nColumn * j + i      ] = tmp[nKey[i]];
			else
				pcMessage[nColumn * j + nKey[i]] = tmp[i];
		}
	}

	free(tmp);
}

// Òask 16.2
void task16_2()
{
	// Control example
	// Open  text: 12345678
	// Close text: 31427586
    // Open  text: 12345678

	int nColumn = 4;
	printf("Task 16.2\n");

	char aucMass[] = {
		'1', '2', '3', '4',
		'5', '6', '7', '8','\0' };

	int *aucKey = new int[nColumn];
	aucKey[0] = 2;
	aucKey[1] = 0;
	aucKey[2] = 3;
	aucKey[3] = 1;

	printf("Open  text: %s\n", aucMass);
	Meshing(aucMass, sizeof (aucMass) - 1, aucKey, nColumn);
	printf("Close text: %s\n", aucMass);
	Meshing(aucMass, sizeof(aucMass) - 1, aucKey, nColumn, eDecode);
	printf("Open  text: %s\n", aucMass);

	printf("\n");
	free(aucKey);
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