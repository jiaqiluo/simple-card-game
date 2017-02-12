// jiaqi Luo
// cs173, hw2
// this file contains the declearation of the queue ADT
#include "card.h"

struct q_node {
  card_type card;
  q_node *next;
};

class queue {
public:
  queue();
  ~queue();
  // add an card(which is the to_add as the argument)
  // at the rear posotion
  int enqueue(card_type &to_add);
  // delete the card at the head card of queue(ie. the card next to the rear)
  int dequeue(card_type &to_delete);
  int displayall();
  // display the question in the head card of the queue
  int display_question();

private:
  q_node *rear;
};
