// Jiaqi Luo
// cs163, hw2
// queue.cpp
// this file contains all the functions of the queue ADT
#include "queue.h"
#include <cctype>
#include <cstring>

queue::queue() { rear = NULL; }

queue::~queue() {
  if (rear != NULL) {
    q_node *head = rear->next;
    rear->next = NULL;
    q_node *temp = head->next;
    while (head != NULL) {
      delete head;
      head = head->next;
    }
  }
}

// this function add a new card which name is to_add as the argument
// in the rear of the queue, and return 1 if it is successful
int queue::enqueue(card_type &to_add) {
  if (rear == NULL) {
    rear = new q_node;
    rear->card.copy_card(to_add);
    rear->next = rear;
    return 1;
  }
  q_node *temp = new q_node;
  temp->card.copy_card(to_add);
  temp->next = rear->next;
  rear->next = temp;
  rear = temp;
  return 1;
}

// this function delete a card in the start of
// the queue( ie. the card next to rear), and copy the
// deleted card to the outside by invoking get_card function,
// finally return 1 if success,
// otherwise return 0
int queue::dequeue(card_type &to_delete) {
  if (rear != NULL) {
    // only one node
    if (rear->next == rear) {
      rear->card.get_card(to_delete);
      delete rear;
      rear = NULL;
      return 1;
    }
    q_node *temp = rear->next;
    temp->card.get_card(to_delete);
    rear->next = temp->next;
    delete temp;
    return 1;
  }
  return 0;
}

// this function displays all the card in the queue
// from the start( ie. the card next to the rear)
// to the rear, finally return 1
int queue::displayall() {
  if (rear == NULL)
    return 0;
  else if (rear->next == rear) {
    rear->card.display_question();
    rear->card.display_answer();
    return 1;
  }
  q_node *temp = rear->next;
  while (temp != rear) {
    temp->card.display_question();
    temp->card.display_answer();
    temp = temp->next;
  }
  rear->card.display_question();
  rear->card.display_answer();
  return 1;
}

// this function display the question in the
// first card( ie. the card next to the rear),
// and return 1 if success,
// otherwose return 0
int queue::display_question() {
  if (rear != NULL) {
    rear->next->card.display_question();
    return 1;
  }
  return 0;
}
