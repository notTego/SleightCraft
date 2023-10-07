// Copyright 2022 Marin Vladimir 312CA

#ifndef _HOME_STUDENT_DESKTOP_SD___TEMA1_ERRORS_H_
#define _HOME_STUDENT_DESKTOP_SD___TEMA1_ERRORS_H_

int valid_card(int value, char* suit);
int deck_out_bounds(dll_list *list, int index);
int card_out_bounds(dll_deck *deck, int index);

#endif  // _HOME_STUDENT_DESKTOP_SD___TEMA1_ERRORS_H_
