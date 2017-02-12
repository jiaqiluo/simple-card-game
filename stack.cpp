// Jiaqi Luo
// cs163, hw2
// stack.cpp
// this file contains all the functions of the stack ADT
#include "stack.h"
#include <cctype>
#include <cstring>
#include <iostream>

stack::stack() {
  top_index = 0;
  head = NULL;
}

stack::~stack() {
  s_node *temp;
  while (head != NULL) {
    temp = head->next;
    delete[] head->card;
    delete head;
    head = temp;
  }
}

// this fucntion push a new card( which is the to_add as argument)
// in the top of the stack and move the top_index to the next position,
// if the sub-list if full, create a new node and reset the to_index to 1,
// finally return 1 if success, otherwise return 0
int stack::push(card_type &to_add) {
  if (head == NULL) {
    top_index = 0;
    head = new s_node;
    head->card = new card_type[MAX];
    head->next = NULL;
    head->card[top_index].copy_card(to_add);
    ++top_index;
    return 1;
  } else if (top_index < 5) {
    head->card[top_index].copy_card(to_add);
    ++top_index;
    return 1;
  } else {
    top_index = 0;
    s_node *temp = new s_node;
    temp->card = new card_type[MAX];
    temp->card[top_index].copy_card(to_add);
    ++top_index;
    temp->next = head;
    head = temp;
    return 1;
  }
  return 0;
}

// this function deletes the card at the top of the stack,
// and decrease the top_index,
// if the current sub_list is empty after deleting, delete the
// empty list. Finally return 1 if success, otherwise return 0
int stack::pop(card_type &to_pop) {
  if (head == NULL) {
    return 0;
  } else if (top_index > 0) {
    --top_index;
    head->card[top_index].get_card(to_pop);
    return 1;
  } else if (top_index == 0) {

    s_node *temp = head->next;
    temp->card[4].get_card(to_pop);
    delete[] head->card;
    delete head;
    head = temp;
    top_index = 5;
    return 1;
  }
  return 0;
}

// this function displays the question in the card
// at the top of the stack by invoking display_question
// in card_type ADT, finally return 1 if success, otherwise
// return 0
int stack::peek() {
  if (!head)
    return 0;
  else if (top_index > 0) {
    head->card[top_index - 1].display_question();
    return 1;
  }
  s_node *temp = head->next;
  if (temp != NULL) {
    temp->card[4].display_question();
    return 1;
  }
  return 0;
}

// this function displays all the card in the stack
// in a reversed order
int stack::displayall() {
  int current = top_index;
  for (s_node *temp = head; temp != NULL; temp = temp->next) {
    for (int i = current; i > 0; --i) {
      temp->card[i - 1].display_question();
      temp->card[i - 1].display_answer();
    }
    current = 5;
  }
  return 1;
}
