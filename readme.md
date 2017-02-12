#Programming
##Problem Statement  
We are going to think about the fundamentals of what might be needed to play a card game. Most games have a deck of cards (even the Game of Thrones board game!). Some decks are similar to a queue, where cards are placed at the bottom of the deck and players select from the top. Other decks, such as discard piles, act more like a stack – where players place cards on the top and other players can retrieve those top card(s). Your job for this second program will be to simulate some basic deck-of-cards functionality using **queues** and **stacks**.

**The game**…For our program, the application will be a modified trivial pursuit game. Each card will have a question on it. There will be two decks of cards. The deck of unanswered questions and the discard deck. The player selects a card. With this “modified” game, the player can select the card from the deck of unanswered questions or from the top of the discard pile. The question is displayed and the player answers the question displayed. If the question is answered correctly, the card is placed at the bottom of the deck. If the question is answered incorrectly it is placed on the top of the discard pile. For every correct answer, the player gets 1 point. A score of 5 wins the game.

##Data Structures

Your deck must be implemented using a **queue ADT** implemented with a **circular linked list**. Your queue must implement a dequeue, enqueue, and displayall. Enqueue will be used to placed correctly answered questions back into the deck, at the rear. Dequeue will be used when the player selects a card from the front of the deck. Displayall is just for testing purposes.

Your discard pile must be implemented using a **stack ADT** implemented with a **linear linked list of arrays**. Each element of the array will be card. Each array should hold no more than 5 cards. Your stack must implement a *push*, *pop*, and *displayall*, and *peek*. Push will be used after a player incorrectly answers a question. Pop will be used when a player selects the discarded question. Peek will be used so the player can find out if they like that discarded question or if they will risk going to the deck for a question that has not been revealed! Displayall is just for testing purposes.

The deck should be built originally from an external data file called **trivial.txt**. The format should be **question?answer\n** for each question!

Please keep in mind that because we are creating ADTs, the user of the program must not be aware that stacks and queues are being used – this is the job of the application program (your test program)! Make sure to thoroughly test each of the stack and queue functions!
