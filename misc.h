// Copyright 2022 Marin Vladimir 312CA

#include "./structs.h"

#ifndef _HOME_STUDENT_DESKTOP_SD___TEMA1_MISC_H_
#define _HOME_STUDENT_DESKTOP_SD___TEMA1_MISC_H_

dll_list* create_list();

dll_deck* create_deck();

dll_card* create_card(void* value, void* suit);

void add_deck_to_list(dll_list* list, dll_deck* newDeck);

void add_card_to_deck(dll_deck* deck, dll_card* newCard);

void free_deck(dll_deck** pp_list);

dll_deck* remove_nth_deck(dll_list* list, int n);

void print_cards(dll_deck* deck);

void print_all(dll_list *list);

dll_card *remove_nth_card(dll_deck* list, int n);

dll_deck* find_deck(dll_list* list, int index);

void free_all(dll_list* list);

void reverse(dll_deck *deck);

void shuffle(dll_deck *deck);

dll_deck *merged(dll_deck *deck1, dll_deck *deck2);

void insert_deck_after_nth(dll_deck *prev, dll_deck *newNode);

void sort(dll_deck *deck);

void add_card_func(dll_deck* list, dll_card* new_data);

#endif  // _HOME_STUDENT_DESKTOP_SD___TEMA1_MISC_H_
