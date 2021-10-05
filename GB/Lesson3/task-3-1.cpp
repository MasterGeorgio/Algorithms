// Les Tree.cpp : Defines the entry point for the console application.
//
#include <QCoreApplication>


//#include "stdafx.h"

#include <iostream>
#include <math.h>

using namespace std;

/// Euclid's algorithm for node search
uint64_t AlgEvklid (uint64_t a, uint64_t b);

/// Binary multiplication of numbers module
uint64_t Multy(uint64_t a,
               uint64_t b,
               uint64_t m);

/// Exponentiation module
uint64_t Pows(uint64_t a,
              uint64_t b,
              uint64_t m);


/// Method brute force
void MethodBruteForce(uint64_t ullVal)
{
    cout << "The method brute force:\n";

    // For acseleration
    if (ullVal == 2)
    {
        cout << "The value " << ullVal << " is useful\n";
        return;
    }
    else if (!(ullVal & 1)) // check
    {
        cout << "The value " << ullVal << " is not useful\n";
        return;
    }

    uint64_t ullStop = pow(ullVal, 0.5);

    bool bRes = true;
    for (uint64_t i = 3; i <= ullStop; i += 2)
    {
        if (ullVal % i == 0)
        {
            bRes = false;
            break ;
        }
    }

    if (bRes)
        cout << "The value " << ullVal << " is useful\n";
    else
        cout << "The value " << ullVal << " is not useful\n";
}


/// Test Ferma
void MethodFerma(uint64_t ullVal)
{
    cout << "The method Ferma:\n";

    if (ullVal <= 2)
    {
        cout << "The value " << ullVal << " is useful\n";
        return ;
    }

    srand(time(NULL));
    /// Пусть n - простое
    bool bRes = true;
    for (size_t i = 0; i < 100; i++)
    {
        uint64_t a = (rand() % (ullVal - 2)) + 2;
        // Проверка 1 требования
        if (AlgEvklid(a, ullVal) != 1)
            bRes = false;
        // Проверка 2 требования
        if (Pows(a, ullVal - 1, ullVal) != 1)
            bRes = false;

		if (!bRes)
			break;
    }

    if (bRes)
        cout << "The value " << ullVal << " is useful\n";
    else
        cout << "The value " << ullVal << " is not useful\n";
}


/// 1 task
void Task_3_-1(uint64_t ullVal = 2063)
{
    cout << "\nTask 4:\n";

    // Method brute force
    MethodBruteForce(ullVal);

    // Test Ferma
    MethodFerma(ullVal);
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

	/*
	Testing
	// Not useful
    Task_3_1(100);
	// Is useful
    Task_3_1(2063);
	// Is useful
    Task_3_1(43);
	*/

    // 1 task
    Task_3_1();

	system("pause");
	return 0;
}

// Euclid's algorithm for node search
uint64_t AlgEvklid (uint64_t a, uint64_t b)
{
    if (b == 0)
        return a;

    return AlgEvklid(b, a % b);
}

/// Binary multiplication of numbers module
uint64_t Multy(uint64_t a,
               uint64_t b,
               uint64_t m)
{
    // a^1 = a
    if (b == 1)
        return  a;

    // Parity check
    if (b & 0x01)
        return (Multy(a, b - 1, m) + a) % m;

    uint64_t n = Multy(a, b >> 1, m);
    return (n << 1) % m;
}

/// Exponentiation module
uint64_t Pows(uint64_t a,
              uint64_t b,
              uint64_t m)
{
    if (b == 0)
        return  1;

    // Parity check
    if (b & 0x01)
        return Multy(Pows(a, b - 1, m), a, m) % m;

    uint64_t n = Pows(a, b >> 1, m);
    return Multy(n, n, m) % m;
}
