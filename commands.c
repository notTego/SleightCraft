// Copyright 2022 Marin Vladimir 312CA

#include "/home/student/Desktop/SD - Tema1/commands.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#include "./structs.h"
#include "./misc.h"
#include "./errors.h"

#define MAX_SUIT 8

void add_deck(dll_list* list, int number)
{
	int value = 0;

	dll_deck *newDeck = create_deck();

	for (int i = 0; i < number; i++) {
		char suit[MAX_SUIT];

		scanf(" %d", &value);
		scanf(" %s", suit);

		if (!valid_card(value, suit)) {
			printf("The provided card is not a valid one.\n");
			i--;

		} else {
			// create isolated card with the given info
			dll_card *newCard = create_card(&value, suit);

			// add card at the end of newDeck
			add_card_to_deck(newDeck, newCard);

			free(newCard);
		}
	}

	// add deck at end of list
	add_deck_to_list(list, newDeck);

	printf("The deck was successfully created with %d cards.\n", number);
}


void del_deck(dll_list* list, int index)
{
	if (deck_out_bounds(list, index)) {
		printf("The provided index is out of bounds for the deck list.\n");
		return;
	}

	dll_deck *remove = remove_nth_deck(list, index);
	free_deck(&remove);
}

void del_deck_func(dll_list* list, int index)
{
	if (deck_out_bounds(list, index)) {
		printf("The provided index is out of bounds for the deck list.\n");
		return;
	}

	dll_deck *remove = remove_nth_deck(list, index);
	free_deck(&remove);

	printf("The deck %d was successfully deleted.\n", index);
}


void show_all(dll_list *list)
{
	print_all(list);
}

void show_deck(dll_list *list, int index)
{
	if (deck_out_bounds(list, index)) {
		printf("The provided index is out of bounds for the deck list.\n");
		return;
	}

	int i = 0;
	dll_deck *thr = list->head;
	while(i != index) {
		thr = thr->next;
		i++;
	}

	printf("Deck %d:\n", i);
		print_cards(thr);
}

void deck_len(dll_list *list, int index)
{
	if (deck_out_bounds(list, index)) {
		printf("The provided index is out of bounds for the deck list.\n");
		return;
	}

	int i = 0;
	dll_deck *thr = list->head;
	while(i != index) {
		thr = thr->next;
		i++;
	}

	printf("The length of deck %d is %d.\n", i, thr->size);
}

void deck_number(dll_list *list)
{
	printf("The number of decks is %d.\n", list->size);
}

void del_card(dll_list *list, int d_index)
{
	char trash = '\0';
	if (deck_out_bounds(list, d_index)) {
		printf("The provided index is out of bounds for the deck list.\n");
		do {
			scanf("%c", &trash);
		} while (trash != '\n');
		return;
	}


	int ok = 1;

	int c_index;
	scanf("%d", &c_index);

	scanf("%c", &trash);
	if (trash != '\n') {
		do {
			scanf("%c", &trash);
		} while (trash != '\n');
		ok = 0;
	}

	if(!ok) {
		printf("Invalid command. Please try again.\n");
		return;
	}


	dll_deck *thr = list->head;
	int i = 0;

	// finding the corect deck to modify
	while(i != d_index) {
		thr = thr->next;
		i++;
	}

	if (card_out_bounds(thr, c_index)) {
		printf("The provided index is out of bounds for deck %d.\n", d_index);
		return;
	}

	dll_card *delete = remove_nth_card(thr, c_index);
	free(delete->value);
	free(delete->suit);
	free(delete);

	printf("The card was successfully deleted from deck %d.\n", d_index);

	if (thr->size == 0) {
		del_deck(list, d_index);
		free(thr);
	}
}

void add_cards(dll_list *list, int d_index)
{
	char trash = '\0';

	if (deck_out_bounds(list, d_index)) {
		printf("The provided index is out of bounds for the deck list.\n");
		do {
			scanf("%c", &trash);
		} while (trash != '\n');
		return;
	}

	int ok = 1;

	int nr, value;
	scanf("%d", &nr);

	scanf("%c", &trash);
	if (trash != '\n') {
		do {
			scanf("%c", &trash);
		} while (trash != '\n');
		ok = 0;
	}

	if(!ok) {
		printf("Invalid command. Please try again.\n");
		return;
	}

	dll_deck *thr = list->head;
	int i = 0;

	// finding the corect deck to modify
	while(i != d_index) {
		thr = thr->next;
		i++;
	}


	for (int i = 0; i < nr; i++) {
		char suit[MAX_SUIT];
		int good = scanf(" %d", &value);

		if (good != 1) {
			printf("The provided card is not a valid one.\n");
			return;
		} else {
			scanf("%s", suit);
			if (!valid_card(value, suit)) {
			printf("The provided card is not a valid one.\n");
			i--;

		} else {
			// create isolated card with the given info
			dll_card *newCard = create_card(&value, suit);

			// add card at the end of d_index'th deck
			add_card_to_deck(thr, newCard);

			free(newCard);
		}
		}
	}

	printf("The cards were successfully added to deck %d.\n", d_index);
}

void reverse_deck(dll_list *list, int index)
{
	if (deck_out_bounds(list, index)) {
		printf("The provided index is out of bounds for the deck list.\n");
		return;
	}

	dll_deck *deck = find_deck(list, index);

	reverse(deck);

	printf("The deck %d was successfully reversed.\n", index);
}

void shuffle_deck(dll_list *list, int index)
{
	if (deck_out_bounds(list, index)) {
		printf("The provided index is out of bounds for the deck list.\n");
		return;
	}

	dll_deck *deck = find_deck(list, index);
	shuffle(deck);

	printf("The deck %d was successfully shuffled.\n", index);
}

void merge_decks(dll_list *list, int index1, int index2)
{
	if (deck_out_bounds(list, index1)) {
		printf("The provided index is out of bounds for the deck list.\n");
		return;
	}

	if (deck_out_bounds(list, index2)) {
		printf("The provided index is out of bounds for the deck list.\n");
		return;
	}

	dll_deck *deck1 = find_deck(list, index1);
	dll_deck *deck2 = find_deck(list, index2);
	dll_deck *merged_deck = merged(deck1, deck2);

	if (index2 > index1) {
		del_deck(list, index2);
		del_deck(list, index1);
	} else {
		del_deck(list, index1);
		del_deck(list, index2);
	}

	add_deck_to_list(list, merged_deck);

	printf("The deck %d and the deck %d were successfully merged.\n", index1,
		   index2);
}

void split_deck(dll_list *list, int d_index)
{
	char trash = '\0';

	if (deck_out_bounds(list, d_index)) {
		printf("The provided index is out of bounds for the deck list.\n");
		do {
			scanf("%c", &trash);
		} while (trash != '\n');
		return;
	}


	int ok = 1;

	int s_index;
	scanf("%d", &s_index);

	scanf("%c", &trash);
	if (trash != '\n') {
		do {
			scanf("%c", &trash);
		} while (trash != '\n');
		ok = 0;
	}

	if(!ok) {
		printf("Invalid command. Please try again.\n");
		return;
	}


	dll_deck *deck = find_deck(list, d_index);
	if (card_out_bounds(deck, s_index)) {
		printf("The provided index is out of bounds for deck %d.\n", d_index);
		return;
	}

	// redundant deck creation (one empty one full) avoided
	if (s_index == 0 || s_index == deck->size) {
		printf("The deck %d was successfully split by index %d.\n", d_index, s_index);
		return;
	}


	dll_deck *afterIndex = create_deck();
	dll_card *thr = deck->head;
	dll_card *aux;

	// get thr to position number s_index
	for (int i = 0; i < s_index; i++)
		thr = thr->next;

	// add every card starting with s_index in a new deck and remove
	// them from the current one
	while (thr) {
		aux = thr;
		add_card_to_deck(afterIndex, aux);
		thr = aux->next;
		remove_nth_card(deck, s_index);

		// free(del);
		free(aux->suit);
		free(aux->value);
		free(aux);
	}

	// insert deck afterIndex in list, after deck number d_index
	insert_deck_after_nth(deck, afterIndex);

	list->size++;

	printf("The deck %d was successfully split by index %d.\n", d_index, s_index);
}

void sort_deck(dll_list *list, int index)
{
	if (deck_out_bounds(list, index)) {
		printf("The provided index is out of bounds for the deck list.\n");
		return;
	}

	dll_deck *deck = find_deck(list, index);
	sort(deck);

	printf("The deck %d was successfully sorted.\n", index);
}
