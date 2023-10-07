// Copyright 2022 Marin Vladimir 312CA

#include "/home/student/Desktop/SD - Tema1/hash.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "./structs.h"

// in order to use switch (case) instead of cascading ifs, we'll
// make use of a polynomial rolling hashing function to assign
// to each instruction string a different and unique integer

// time complexity: O(N)
int string_hash(char *str)
{
	int p = 31, m = 1e9 + 9;
	long long p_pow = 1, hash_val = 0;

	for (size_t i = 0; i < strlen(str); i++) {
		hash_val = (hash_val + (str[i] - 'a' + 1) * p_pow) % m;
		p_pow = (p_pow * p) % m;
	}
	return (hash_val % m + m) % m;
}
