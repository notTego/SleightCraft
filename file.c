// Copyright 2022 Marin Vladimir 312CA

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "./structs.h"
#include "./commands.h"
#include "./hash.h"
#include "./misc.h"

#define LENMAX 15  // max length of command name

int main()
{
	dll_list* list = create_list();

	char command[LENMAX], trash;
	int code = 0;  // hash code for each command
	int number, number2, loop = 1;
	int ok;

	while (loop) {
		scanf("%s", command);
		code = string_hash(command);
		number = 0;
		number2 = 0;

		switch (code) {
		case ADD_DECK:
			ok = 1;
			trash = '\0';
			scanf("%d", &number);

			scanf("%c", &trash);
			if (trash != '\n') {
				do {
					scanf("%c", &trash);
				} while (trash != '\n');
				ok = 0;
			}

			if(ok) {
				add_deck(list, number);
			} else {
				printf("Invalid command. Please try again.\n");
			}
			break;

		case DEL_DECK:
			ok = 1;
			trash = '\0';
			scanf("%d", &number);

			scanf("%c", &trash);
			if (trash != '\n') {
				do {
					scanf("%c", &trash);
				} while (trash != '\n');
				ok = 0;
			}

			if(ok) {
				del_deck_func(list, number);
			} else {
				printf("Invalid command. Please try again.\n");
			}
			break;

		case DEL_CARD:
			scanf("%d", &number);
			del_card(list, number);
			break;

		case ADD_CARDS:
			scanf("%d", &number);
			add_cards(list, number);
			break;

		case DECK_NUMBER:
			ok = 1;
			trash = '\0';

			scanf("%c", &trash);
			if (trash != '\n') {
				do {
					scanf("%c", &trash);
				} while (trash != '\n');
				ok = 0;
			}

			if(ok) {
				deck_number(list);
			} else {
				printf("Invalid command. Please try again.\n");
			}
			break;

		case DECK_LEN:
			ok = 1;
			trash = '\0';
			scanf("%d", &number);

			scanf("%c", &trash);
			if (trash != '\n') {
				do {
					scanf("%c", &trash);
				} while (trash != '\n');
				ok = 0;
			}

			if(ok) {
				deck_len(list, number);
			} else {
				printf("Invalid command. Please try again.\n");
			}
			break;

		case SHUFFLE_DECK:
			ok = 1;
			trash = '\0';
			scanf("%d", &number);

			scanf("%c", &trash);
			if (trash != '\n') {
				do {
					scanf("%c", &trash);
				} while (trash != '\n');
				ok = 0;
			}

			if(ok) {
				shuffle_deck(list, number);
			} else {
				printf("Invalid command. Please try again.\n");
			}
			break;

		case MERGE_DECKS:
			ok = 1;
			trash = '\0';
			scanf("%d", &number);
			scanf("%d", &number2);

			scanf("%c", &trash);
			if (trash != '\n') {
				do {
					scanf("%c", &trash);
				} while (trash != '\n');
				ok = 0;
			}

			if(ok) {
				merge_decks(list, number, number2);
			} else {
				printf("Invalid command. Please try again.\n");
			}
			break;

		case SPLIT_DECK:
			scanf("%d", &number);
			split_deck(list, number);
			break;

		case REVERSE_DECK:
			ok = 1;
			trash = '\0';
			scanf("%d", &number);

			scanf("%c", &trash);
			if (trash != '\n') {
				do {
					scanf("%c", &trash);
				} while (trash != '\n');
				ok = 0;
			}

			if(ok) {
				reverse_deck(list, number);
			} else {
				printf("Invalid command. Please try again.\n");
			}
			break;

		case SHOW_DECK:
			ok = 1;
			trash = '\0';
			scanf("%d", &number);

			scanf("%c", &trash);
			if (trash != '\n') {
				do {
					scanf("%c", &trash);
				} while (trash != '\n');
				ok = 0;
			}

			if(ok) {
				show_deck(list, number);
			} else {
				printf("Invalid command. Please try again.\n");
			}
			break;

		case SHOW_ALL:
			ok = 1;
			trash = '\0';

			scanf("%c", &trash);
			if (trash != '\n') {
				do {
					scanf("%c", &trash);
				} while (trash != '\n');
				ok = 0;
			}

			if(ok) {
				show_all(list);
			} else {
				printf("Invalid command. Please try again.\n");
			}
			break;

		case SORT_DECK:
			ok = 1;
			trash = '\0';
			scanf("%d", &number);

			scanf("%c", &trash);
			if (trash != '\n') {
				do {
					scanf("%c", &trash);
				} while (trash != '\n');
				ok = 0;
			}

			if(ok) {
				sort_deck(list, number);
			} else {
				printf("Invalid command. Please try again.\n");
			}
			break;

		case EXIT:
			free_all(list);
			loop = 0;
			break;

		default:
			do {
				scanf("%c", &trash);
			} while (trash != '\n');
			printf("Invalid command. Please try again.\n");
			break;
		}
	}
	return 0;
}

