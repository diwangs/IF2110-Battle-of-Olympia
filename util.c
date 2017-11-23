#include "util.h"
#include "boolean.h"

boolean stringSame(char * str1, char * str2){
	return 1;
}

int KataToInt(Kata K)
{
	int result=0;
	int multi=1;

	for (int i = K.Length-1; i >= 0; i--) {
		result += (K.TabKata[i] - '0') * multi;
		multi *= 10;
	}

	return result;
}


