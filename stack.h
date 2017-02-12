// Jiaqi Luo
// cs163, hw2
// stack.h
// This file contains the declearation of the queue ADT
#include "queue.h"
// the size of each array
int const MAX = 5;

struct s_node {
  card_type *card;
  s_node *next;
};

class stack {
public:
  stack();
  ~stack();
  // add a card(which is the argument) at the top of the stack
  int push(card_type &to_add);
  // remove the card(which is the argument) at the top of the stack
  int pop(card_type &to_pop);
  // display the card at the top of the stack
  int peek();
  // display all the cards in the stack
  int displayall();

private:
  s_node *head;
  int top_index;
};
