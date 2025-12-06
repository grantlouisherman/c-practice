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
  while(player_hand_size < 2 && dealer_hand_size < 2){
    int r = rand() % 52;
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
  return 0;
}
