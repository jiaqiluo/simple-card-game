// Jiaqi Luo
// cs163, hw2
// card.h
// this file contains the declearation of the card_type ADT

using namespace std;

class card_type {
public:
  card_type();
  ~card_type();
  // create a new card with the data: question_source( as the question)
  // and answer_source( as the answer)
  int create_card(char *question_source, char *answer_source);
  // repace the current card with the card copy_from
  int copy_card(card_type &copy_from);
  // copy the data in this card to another card
  int get_card(card_type &current);
  int display_card();
  int display_question();
  int display_answer();
  // judge wheher the user enters the currnt answer,
  // return 1 if it is correct,
  // otherwise return 0
  int evaluate(char *user_answer);

private:
  char *question;
  char *answer;
};
