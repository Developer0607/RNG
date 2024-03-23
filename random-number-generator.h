#pragma once

#include "resource.h"


char InFileName[100]="RNG.ini";


int p = -1;

int Rand_Min, Rand_Max, Rand_Mod;

void init() {
	//FILE* p;
	freopen(InFileName,"r",stdin);
	cin >> Rand_Min >> Rand_Max;

	if (Rand_Min <= 0 || Rand_Max <= Rand_Min) {
		MessageBoxA(NULL,"Invalid input!","Error",MB_ICONERROR);
		PostQuitMessage(1);
	}
	Rand_Mod = (Rand_Max - Rand_Min);
}

LPCSTR num2str(int p) {
	char tmpstr[10];
	char str[10];
	int i = 0, j = 0;
	while (p) {
		tmpstr[i] = p % 10;
		p /= 10;
		i++;
	}
	while (i) {
		i--;
		str[j] = tmpstr[i] + '0';
		j++;
	}
	str[j] = 0;
	LPCSTR res = str;
	return res;
}
