// Copyright 2022 Marin Vladimir 312CA

#include "/home/student/Desktop/SD - Tema1/errors.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "./structs.h"

// INVALID_CARD
int valid_card(int value, char* suit)
{
	if (value < 1 || value > 14)
		return 0;
	if (strstr("HEARTCLUBDIAMONDSPADE", suit) == NULL)
		return 0;
	return 1;
}

// DECK_INDEX_OUT_OF_BOUNDS
int deck_out_bounds(dll_list *list, int index)
{
	if (index >= list->size || index < 0)
		return 1;
	return 0;
}

// CARD_INDEX_OUT_OF_BOUNDS
int card_out_bounds(dll_deck *deck, int index)
{
	if (index >= deck->size || index < 0)
		return 1;
	return 0;
}
