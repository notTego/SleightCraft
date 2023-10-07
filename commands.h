// Copyright 2022 Marin Vladimir 312CA

#include "./structs.h"

#ifndef  _HOME_STUDENT_DESKTOP_SD___TEMA1_COMMANDS_H_
#define  _HOME_STUDENT_DESKTOP_SD___TEMA1_COMMANDS_H_

void add_deck(dll_list* list, int number);

void del_deck(dll_list* list, int index);

void del_deck_func(dll_list* list, int index);

void del_card(dll_list *list, int d_index);

void add_cards(dll_list *list, int d_index);

void deck_number(dll_list *list);

void deck_len(dll_list *list, int index);

void shuffle_deck(dll_list *list, int index);

void merge_decks(dll_list *list, int index1, int index2);

void split_deck(dll_list *list, int d_index);

void reverse_deck(dll_list *list, int index);

void show_deck(dll_list *list, int index);

void show_all(dll_list *list);

void sort_deck(dll_list *list, int index);

#endif  // _HOME_STUDENT_DESKTOP_SD___TEMA1_COMMANDS_H_
