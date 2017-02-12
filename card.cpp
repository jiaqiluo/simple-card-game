// Jiaqi Luo
// cs163, hw2
// card.cpp
// this file contains all the functions of the card_type ADT
#include "card.h"
#include <cctype>
#include <cstring>
#include <iostream>

card_type::card_type() {
  question = NULL;
  answer = NULL;
}

card_type::~card_type() {
  delete[] question;
  delete[] answer;
}

// this function receives a question (as question_source)
// and a answer(as answer_source), then copy those information
// in the current card, finally return 1
int card_type::create_card(char *question_source, char *answer_source) {
  if (question_source) {
    question = new char[strlen(question_source) + 1];
    strcpy(question, question_source);
  }
  if (answer_source) {
    answer = new char[strlen(answer_source) + 1];
    strcpy(answer, answer_source);
  }
  return 1;
}

// this function copy the qusetion and answer form anthor card
// which name is copy_from as the argument
// to the current card, finally return 1
int card_type::copy_card(card_type &copy_from) {
  if (copy_from.question) {
    question = new char[strlen(copy_from.question) + 1];
    strcpy(question, copy_from.question);
  }
  if (copy_from.answer) {
    answer = new char[strlen(copy_from.answer) + 1];
    strcpy(answer, copy_from.answer);
  }
  return 1;
}

// this function copy the data in the card
// to an outside card wiich name is current as the argument
// finally return 1
int card_type::get_card(card_type &current) {
  current.question = new char[strlen(question) + 1];
  strcpy(current.question, question);
  current.answer = new char[strlen(answer) + 1];
  strcpy(current.answer, answer);
  return 1;
}

// this funtion display the question and answer
// in this card, finally return 1
int card_type::display_card() {
  if (display_question() == 1 && display_answer() == 1)
    return 1;
  return 0;
}

// this function displays the question in
// this card, and return 1 if success,
// otehrwise return 0
int card_type::display_question() {
  if (question != NULL) {
    cout << "Q:" << question << endl;
    return 1;
  }
  return 0;
}

// this function displays the answer in
// this card, and return 1 if success,
// otherwise return0.
int card_type::display_answer() {
  if (answer != NULL) {
    cout << "A:" << answer << endl;
    return 1;
  }
}

// this function evaluate the answer from the user,
// return 1 if it exists and is the same as the answer in this card,
// otherwise return 0.
int card_type::evaluate(char *user_answer) {
  if (answer != NULL) {
    if (strcmp(answer, user_answer) == 0)
      return 1;
    else
      return 0;
  } else
    return 0;
}
