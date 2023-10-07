// Copyright 2022 Marin Vladimir 312CA

#include "/home/student/Desktop/SD - Tema1/misc.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "./structs.h"
#include "./errors.h"
#define MAX_SUIT 8

/*Create an empty list of decks*/
dll_list*
create_list()
{
	dll_list* list = malloc(sizeof(dll_list));

	list->size = 0;
	list->head = NULL;
	return list;
}

/*Create an empty deck of cards*/
dll_deck*
create_deck()
{
	dll_deck* list = malloc(sizeof(dll_deck));

	list->size = 0;
	list->head = NULL;
	list->next = NULL;
	list->prev = NULL;

	return list;
}

/*Create isolated card with given value and suit*/
dll_card*
create_card(void* value, void* suit)
{
	dll_card* card = malloc(sizeof(dll_card));

	card->value = value;
	card->suit = suit;
	card->next = NULL;
	card->prev = NULL;

	return card;
}

/*Add a deck at the end of the list
* n >= list->size to add to the end of list
*/

void
add_deck_to_list(dll_list* list, dll_deck* newDeck)
{
	int n = list->size;

	if (list == NULL)
		return;

	if (list -> size == 0) {
		newDeck->next = NULL;
		newDeck-> prev = NULL;
		list->head = newDeck;
		list->size++;

		return;
	}

	/*pointer to go through list until last element*/
	dll_deck* parc = list->head;

	if (n) {
		for (int i = 0; i < n - 1; i++)
			parc = parc->next;
	}

	if (n == list->size) {
		newDeck->next = NULL;
		parc->next = newDeck;
		newDeck->prev = parc;
		list->size++;
	}
}

/*Add card at the end of deck*/
void add_card_to_deck(dll_deck* list, dll_card* new_data)
{
	if (list == NULL)
		return;

	dll_card *last = list->head;

	// alloc node
	dll_card *new_node = malloc(sizeof(dll_card));

	// fill in NewCard with data card's info
	new_node->value = malloc(sizeof(new_data->value));
	new_node->suit = malloc(sizeof(new_data->suit));
    memcpy(new_node->value, new_data->value, sizeof(*(int*)new_data->value));
	memcpy(new_node->suit, new_data->suit, sizeof(*(char*)new_data->suit));

	// new_node will be last
	new_node->next = NULL;

	// If deck is empty, make new_node as head
	if (list->head == NULL) {
		new_node->prev = NULL;
		list->head = new_node;
		list->size++;
		return;
	}

	while (last->next)
		last = last->next;

	last->next = new_node;

	new_node->prev = last;

	list->size++;
}

void add_card_func(dll_deck* list, dll_card* new_data)
{
	if (list == NULL)
		return;

	dll_card *last = list->head;

	// alloc node
	dll_card *new_node = malloc(sizeof(dll_card));

	// fill in NewCard with data card's info
	new_node->value = malloc(sizeof(new_data->value));
	new_node->suit = malloc(sizeof(new_data->suit));
    memcpy(new_node->value, new_data->value, sizeof(*(int*)new_data->value));
	memcpy(new_node->suit, new_data->suit, sizeof(*(char*)new_data->suit));

	// new_node will be last
	new_node->next = NULL;

	// If deck is empty, make new_node as head
	if (list->head == NULL) {
		new_node->prev = NULL;
		list->head = new_node;
		list->size++;
		return;
	}

	while (last->next)
		last = last->next;

	last->next = new_node;

	new_node->prev = last;

	list->size++;

	free(new_data->value);  // new_data
	free(new_data->suit);
}





void free_deck(dll_deck** pp_list)
{
    dll_card *p = (*pp_list)->head;

	if (p == NULL)
		return;

    while ((*pp_list)->head != NULL) {
		(*pp_list)->head = (*pp_list)->head->next;
		free(p->value);
		free(p->suit);
		free(p);
		p = (*pp_list)->head;
	}

	free((*pp_list));
}


/*Removes nth deck from the list and returns a pointer to the former, to
* be free'd next
*/

dll_deck *
remove_nth_deck(dll_list* list, int n)
{
    dll_deck *prev, *curr;

    if (!list || !list->head) {
        return NULL;
    }

    if (n > list->size - 1) {
        n = list->size - 1;
    }

    curr = list->head;
    prev = NULL;
    while (n > 0) {
        prev = curr;
        curr = curr->next;
        --n;
    }

    if (prev == NULL) {
        list->head = curr->next;
    } else {
        prev->next = curr->next;
    }

    list->size--;

    return curr;
}

void print_cards(dll_deck* deck)
{
	dll_card* thr;
	if (!deck)
		return;

	char true_suit[MAX_SUIT];
	thr = deck->head;
	while(thr) {
		if (*(char*)thr->suit == 'H') {
			strcpy(true_suit, "HEART");
		} else if (*(char*)thr->suit == 'C') {
			strcpy(true_suit, "CLUB");
		} else if (*(char*)thr->suit == 'D') {
			strcpy(true_suit, "DIAMOND");
		} else if (*(char*)thr->suit == 'S') {
			strcpy(true_suit, "SPADE");
		}

		printf("\t%d %s\n", *(int*)thr->value, true_suit);
		thr = thr->next;
	}

	printf("\n");
}

void print_all(dll_list *list)
{
	dll_deck *thr;
	if (!list)
		return;

	int i = 0;
	thr = list->head;
	while (thr) {
		printf("Deck %d:\n", i);
		print_cards(thr);

		i++;
		thr = thr->next;
	}
}

dll_card *
remove_nth_card(dll_deck* deck, int n)
{
	dll_card *head = deck->head;
	dll_card *del = deck->head;

	// find card to delete
	for (int i = 0; i < n; i++)
		del = del->next;

	if (head == NULL || del == NULL)
		return NULL;

	// node to delete is head node
	if (head == del)
		deck->head = del->next;

	// only change next if deleted node is not last
	if (del->next != NULL)
		del->next->prev = del->prev;

	// only change prev if deleted node is not first
	if (del->prev != NULL)
		del->prev->next = del->next;


	deck->size--;
	return del;
}


/*
* Returns a pointer towards the index'th deck
*/
dll_deck* find_deck(dll_list* list, int index)
{
	if (deck_out_bounds(list, index)) {
		printf("The provided index is out of bounds for the deck list.\n");
		return NULL;
	}

	dll_deck *thr;
	if (!list)
		return NULL;

	int i = 0;
	thr = list->head;
	while (thr && i != index) {
		i++;
		thr = thr->next;
	}

	return thr;
}

/*
* frees all alloc'd memory
*/
void free_all(dll_list* list)
{
	if (!list)
		return;

	dll_deck *thr = list->head;

	while(thr) {
		dll_deck *copy = thr;

		thr = thr->next;
		free_deck(&copy);
	}

	free(list);
}


/*
* Reverses the deck with the given head
*/
void reverse(dll_deck *deck)
{
	dll_card *head = deck->head;
	dll_card *temp = NULL;
	dll_card *current;
	dll_card *last = head;

	while (last->next) {
		last = last->next;
	}
	int i = deck->size - 2;

	if (last == head)
		return;

	current = last->prev;

	while (current) {
		if (current == head) {
			temp = NULL;
		} else {
			temp = current->prev;
		}
		add_card_func(deck, current);
		dll_card *del = remove_nth_card(deck, i);
		i--;
		current = temp;

		free(del);
	}
}

void shuffle(dll_deck *deck)
{
	if (deck->size == 1)
		return;

	int start = deck->size / 2;

	dll_card *card = deck->head;
	int i = 0;

	while (card->next && i != start) {
		i++;
		card = card->next;
	}

	dll_card *head = deck->head;
	while (head != card) {
		add_card_func(deck, head);
		head = head->next;
		dll_card *del = remove_nth_card(deck, 0);

		free(del);
	}
}


dll_deck *merged(dll_deck *deck1, dll_deck *deck2)
{
	dll_deck *merged = create_deck();

	dll_card *card1 = deck1->head;
	dll_card *card2 = deck2->head;

	while (card1 && card2) {
		add_card_to_deck(merged, card1);
		add_card_to_deck(merged, card2);

		card1 = card1->next;
		card2 = card2->next;
	}

	while (card1) {
		add_card_to_deck(merged, card1);
		card1 = card1->next;
	}

	while (card2) {
		add_card_to_deck(merged, card2);
		card2 = card2->next;
	}

	return merged;
}


/*
*	Insert deck after a given deck in a list
*/
void insert_deck_after_nth(dll_deck *prev, dll_deck *newNode)
{
	if (prev == NULL)
		return;

	newNode->next = prev->next;
	prev->next = newNode;
	newNode->prev = prev;

	if (newNode->next)
		newNode->next->prev = newNode;
}

int priority(char suit)
{
	int priority;

	if (suit == 'C') {
		priority = 0;
	} else if (suit == 'D') {
		priority = 1;
	} else if (suit == 'S') {
		priority = 2;
	} else if (suit == 'H') {
		priority = 3;
	}

	return priority;
}


void sort(dll_deck *deck)
{
	int swapped, pr_a, pr_b;
	dll_card *thr;
	dll_card *last = NULL;

	if (deck->head == NULL)
		return;

	do {
		swapped = 0;
		thr = deck->head;

		while (thr->next != last) {
			// first value > second value
			if (*(int*)thr->value > *(int*)thr->next->value) {
				void* aux1 = thr->value;
				thr->value = thr->next->value;
				thr->next->value = aux1;

				void* aux2 = thr->suit;
				thr->suit = thr->next->suit;
				thr->next->suit = aux2;

				swapped = 1;
			} else if (*(int*)thr->value == *(int*)thr->next->value) {
				// values equal to each other, verify sign priority
				pr_a = priority(*(char*)thr->suit);
				pr_b = priority(*(char*)thr->next->suit);

				if (pr_a < pr_b) {
					void* aux1 = thr->value;
					thr->value = thr->next->value;
					thr->next->value = aux1;

					void* aux2 = thr->suit;
					thr->suit = thr->next->suit;
					thr->next->suit = aux2;

					swapped = 1;
				}
			}

			thr = thr->next;
		}
		last = thr;
	} while (swapped);
}
