#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> 
#include <time.h>
#include <string.h>

typedef struct {
  char suit;
  char type;
  int value;
} Card;

int BlackJack_IDCardValue(char digit_char){
  switch (digit_char) {
    case 'A':
      return 11;
    case 'K':
    case 'J':
    case 'Q':
      return 10;
    default:
      return atoi(&digit_char);
  }
}
Card* BlackJack_CreateDeck(){
  Card* deck = (Card*)malloc(52 * sizeof(Card));
  char *types[14] = {
    "A", "K", "Q", 
    "J", "10", "9", 
    "8", "7", "6", "5",
    "4", "3", "2"
  };
  char *suites[4] = {"S", "C", "H", "D"};
  int deck_pointer = 0;
  for(int i=0; i<13;i++){
      char type = *types[i];
     for(int j=0; j<4;j++){
      char suit = *suites[j];
      deck[deck_pointer].suit = suit;
      deck[deck_pointer].type = type;
      deck[deck_pointer].value = BlackJack_IDCardValue(type);
      deck_pointer++;
    }

  }
  return deck;
};

void BlackJack_ShuffleDeck(Card* deck){
  for(int i=0;i<52;i++){
    int r = rand() % 52;
    deck[r] = deck[i];
  }
}

void BlackJack_PrintHand(Card* player_hand, bool hand_owner){
  char owner[7];
  if(hand_owner == true){
    strcpy(owner, "Player");
  }else{
    strcpy(owner, "Dealer");
  }
  int hand_sum = player_hand[0].value + player_hand[1].value;
  printf("%s Hand is: {%c%c}, {%c%c}, Total Value: %i \n", owner, player_hand[0].type, player_hand[0].suit, player_hand[1].type,player_hand[1].suit, hand_sum);
}


int BlackJack_SumHand(Card* player_hand, int player_hand_size){
  int hand_sum = 0;
  for(int i=0;i<player_hand_size;i++){
    hand_sum+=player_hand[i].value;
  }
  return hand_sum;
}
bool BlackJack_CheckBust(Card* player_hand, int player_hand_size){
  int hand_sum = BlackJack_SumHand(player_hand, player_hand_size);
  if(hand_sum > 21) {
    return true;
  }
  return false;
}


bool BlackJack_AI(){
  return true;
}

Card BlackJack_DealNextCard(Card* deck, int* taken_idxs, int taken_idx_capacity){
  
  while(true){
    int r = rand() % 52;
    for(int i=0;i<taken_idx_capacity;i++){
      if(taken_idxs[i] == r){
        i = 0;
        r = rand() % 52;
        continue;
      }
    }
    return deck[r];
  }
}

int BlackJack_Hit(Card* hand, int curr_hand_size, Card next_card){
  Card* new_hand = (Card*)realloc(hand, curr_hand_size*sizeof(Card));

  int new_hand_size = curr_hand_size+1;
  if(new_hand == NULL){
      printf("Realloc Failed");
      return 0;
    }
  int new_idx = new_hand_size-1;
  hand[new_idx] = next_card;
  return new_hand_size;
}

void BlackJack_GameLoop(Card* player_hand, Card* dealer_hand, Card* deck, int* taken_idxs){
  
  bool player_turn = true; // True is player and False is dealer
  int taken_idx_capacity = 4;
  int player_hand_capacity = 2;
  while(true){
    int current_sum = BlackJack_SumHand(player_hand, player_hand_capacity);
    if(current_sum == 21){
      printf("<<<<<You Won!!!!>>>\n");
      break;
    }
    printf("Your current hand sum is: %i\n", current_sum);
  /*
        * Both hands are already dealt
        * We need to be able to realloc the hand if they hit
        *  If they stay then it goes to the dealer
        *  Then some AI logic, for now lets do if the diff is > 5 you hit if not you stay
        *  Then final check at the end
  */
    if(player_turn == false){
      if(BlackJack_AI() == true){
        break;
      }
    }
     
    char command;
    printf("What would you like to do?  \n");
    scanf(" %c", &command);
    //printf("Your command was : %c \n", command);

    if(command == 's'){
      player_turn = false;
      continue;
    }

    if(command == 'h'){
      //Card* deck, int* taken_idxs, int taken_idx_capacity
      Card next_card = BlackJack_DealNextCard(deck, taken_idxs, taken_idx_capacity);
      printf("You draw a: %c%c\n", next_card.type, next_card.suit);
      int new_hand_size = BlackJack_Hit(player_hand, player_hand_capacity, next_card);
      if(new_hand_size == 0){
        printf("Hit Failed");
        break;
      }
      player_hand_capacity = new_hand_size;
      bool is_bust = BlackJack_CheckBust(player_hand, player_hand_capacity);
      if(is_bust == true){
        printf("Your hand is over 21, you loose");
        break;
      }
    }
    if(command != 'h' && command != 's'){
      printf("BAD COMMAND: %c\n", command);
    }
  }
}

int main() {
  srand(time(NULL));
  printf("Welcome to BlackJack!\n");
  Card* deck_of_cards = BlackJack_CreateDeck();
  BlackJack_ShuffleDeck(deck_of_cards);
  bool direction = true; // true = player, false = house
  int player_hand_size = 0;
  int dealer_hand_size = 0;
  Card* player_hand = (Card*)malloc(2*sizeof(Card));
  Card* dealer_hand = (Card*)malloc(2*sizeof(Card));
  int* taken_idxs = malloc(4 * sizeof(int));
  int taken_idxs_pointer = 0;
  while(player_hand_size + dealer_hand_size < 4){
    int r = rand() % 52;
    taken_idxs[taken_idxs_pointer] = r;
    taken_idxs_pointer+=1;
    if(direction == true){
      player_hand[player_hand_size] = deck_of_cards[r];
      direction = false;
      player_hand_size+=1;
    } else {
      dealer_hand[dealer_hand_size] = deck_of_cards[r];
      direction=true;
      dealer_hand_size+=1;
    }
  }
  BlackJack_PrintHand(player_hand, true);
  BlackJack_PrintHand(dealer_hand, false);
  //Card* player_hand, Card* dealer_hand, Card* deck, int* taken_idxs
  BlackJack_GameLoop(player_hand, dealer_hand, deck_of_cards, taken_idxs);

  // Mem clean up
  //free(deck_of_cards);
  //free(player_hand);
  //free(dealer_hand);
  return 0;
}
