// ImpPolymophismWithCProgramingLanguage.cpp : 定义控制台应用程序的入口点。

#include "stdafx.h"
#include <iostream>

typedef void(*Eat)();
typedef void(*Play)();

typedef struct s_VPtrTable
{
    Eat pEat;
    Play pPlay;
}VPtrTable;

typedef struct BaseStruct
{
    VPtrTable vpTable;
    int age;
}Base;

typedef struct s_DerivedA
{
    Base base;
    int age;
}DerivedA;

void EatA()
{
    printf("I am EatA!\n");
}

void PlayA()
{
    printf("I am PlayA!\n");
}

typedef struct s_DerivedB
{
    Base base;
    int age;
}DerivedB;

void EatB()
{
    printf("I am EatB!\n");
}

void PlayB()
{
    printf("I am PlayB!\n");
}

int main()
{
    DerivedA oDerivedA = DerivedA();
    oDerivedA.base.vpTable.pEat = EatA;
    oDerivedA.base.vpTable.pPlay = PlayA;
    oDerivedA.base.age = 20;
    oDerivedA.age = 30;

    DerivedB oDerivedB = DerivedB();
    oDerivedB.base.vpTable.pEat = EatB;
    oDerivedB.base.vpTable.pPlay = PlayB;
    oDerivedB.base.age = 40;
    oDerivedB.age = 50;

    Base* pBase = NULL;

    pBase = (Base*)&oDerivedA;
    if (!pBase)
    {
        return -1;
    }
    printf("DeriveA call A pBase->age:%d\n", pBase->age);
    pBase->vpTable.pEat();
    pBase->vpTable.pPlay();

    pBase = NULL;
    pBase = (Base*)&oDerivedB;
    if (!pBase)
    {
        return -1;
    }
    printf("\nDeriveB call B pBase->age:%d\n", pBase->age);
    pBase->vpTable.pEat();
    pBase->vpTable.pPlay();

    system("pause");
    return 0;
}



