// Copyright 2022 Marin Vladimir 312CA

#ifndef _HOME_STUDENT_DESKTOP_SD___TEMA1_STRUCTS_H_
#define _HOME_STUDENT_DESKTOP_SD___TEMA1_STRUCTS_H_

typedef struct dll_card {
	void* value;  // [1,14]
	void* suit;  // HEART, CLUB, DIAMOND, SPADE

	struct dll_card *next, *prev;
}dll_card;

/* Deck as a ll of cards*/
typedef struct dll_deck {
	int size;  // number of cards in deck
	dll_card *head;  // pointer towards the first card in the deck

	struct dll_deck *next, *prev;
}dll_deck;

/* List of card decks */
typedef struct dll_list {
	int size;  // number of decks in list

	dll_deck *head;  // pointer towards the first deck in list
} dll_list;

#endif  // _HOME_STUDENT_DESKTOP_SD___TEMA1_STRUCTS_H_
