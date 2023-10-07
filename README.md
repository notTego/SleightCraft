# SleightCraft - Now You See Me Themed Card Manipulation Program

## General Functionality

In this project, users have access to a variety of commands to demonstrate their sleight of hand skills in front of the Four Horsemen, with the goal of being recruited for their next show. The available commands include:

- Create and add a deck to the deck list.
- Delete a deck from the deck list.
- Delete a certain card from a specific deck.
- Add a specified number of cards to a particular deck.
- Display the number of decks currently in the list.
- Show the number of cards in a specific deck.
- Shuffle a designated deck by switching its later half with its former half.
- Merge two decks into one and add it to the list.
- Split one deck into two starting with a certain card.
- Reverse the order of cards in a deck.
- Show the cards in a specific deck.
- Show the cards in all decks present in the list.
- Free the entire list and exit the program.

These commands can be found in the [commands.c] source code. Most of them are implemented using helper functions from [misc.c] to enhance readability and comprehension.

## Main Function Implementation

To maintain a cleaner and more organized main function, the project uses a hash function to convert commands into integers, allowing them to be used in a switch statement. Additionally, these hashes are tagged with their corresponding commands in an enum ([hash.c] and [hash.h]) for improved clarity.

## Shuffle Implementation

The shuffle function (`shuffle(deck)` in [misc.c]) takes a specific deck and splits it in half, then switches the positions of the two halves as follows:

- It finds the first card of the second half.
- It iterates through the deck, starting from its head until the last card of the first half.
- Each card from the first half is removed and added to the end of the deck.

## Reverse Implementation

The reverse function (`reverse(deck)` in [misc.c]) reverses a given deck with the following steps:

- It finds the last card in the deck.
- Starting from the penultimate card, it traverses the list backward.
- Each card is added after the last one and removed from its original position.

## What Could Have Been Done Differently?

For commands like "DEL_CARD," which require inputs of different types (index_deck/index_card) compared to "MERGE_DECKS" (index_deck/index_deck), the project reads the first input in the main function and the second one in functions from [commands.c]. An alternative approach could have involved reading all inputs in the main function and then forwarding them to the respective function.

## What I've Learned

This project significantly boosted my confidence in using debugging tools such as gdb and valgrind. Previously, memory leaks and segfaults were a major source of frustration for me. :)