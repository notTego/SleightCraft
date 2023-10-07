// Copyright 2022 Marin Vladimir 312CA

#ifndef _HOME_STUDENT_DESKTOP_SD___TEMA1_HASH_H_
#define _HOME_STUDENT_DESKTOP_SD___TEMA1_HASH_H_

#include <stdio.h>
#include "./structs.h"

int string_hash(char *str);

// assign tags for each hash for easier comprehension
enum hashes {
	// string_hash("<command>")
	ADD_DECK = 698599102,
	DEL_DECK = 698606824,
	DEL_CARD = 307424748,
	ADD_CARDS = 724030085,
	DECK_NUMBER = 543629329,
	DECK_LEN = 236190409,
	SHUFFLE_DECK = 55840194,
	MERGE_DECKS = 719905457,
	SPLIT_DECK = 368666336,
	REVERSE_DECK = 267297579,
	SHOW_DECK = 657148777,
	SHOW_ALL = 108936866,
	SORT_DECK = 657062504,
	EXIT = 999620139
};

#endif  // _HOME_STUDENT_DESKTOP_SD___TEMA1_HASH_H_
