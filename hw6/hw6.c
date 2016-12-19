#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define NUM_RANKS 13
#define NUM_SUITS 4
#define NUM_CARDS 5

//external variables
int num_rank[20];
int num_suit[20];

char r[20]; //save number part
char s[20]; //save suit part

int num_in_rankp1[13], num_in_suitp1[4], num_in_rankp2[13], num_in_suitp2[4], num_in_rankp3[13], num_in_suitp3[4], num_in_rankp4[13], num_in_suitp4[4];
bool p1straight, p1flush, p1four, p1three, p2straight, p2flush, p2four, p2three, p3straight, p3flush, p3four, p3three, p4straight, p4flush, p4four, pthree;
int pairs1, pairs2, pairs3, pairs4;

int p1stat, p2stat, p3stat, p4stat;

//prototypes
void read_cards(void);
void analyze(void);
void stats(void);
void winner_checker(void);
void print_results(void);


//main function
int main () {
  read_cards(void);
  analyze(void)
}

//read_card function
void read_cards(void) {
  int crand[52];
  int i, temp, randI;

  srand(time(NULL));

  for (i = 1; i < 53; i++) {     // fill array
    crand[i - 1] = i;
    printf("%d,", crand[i - 1]);
  }
  printf("\n done with population \n");
  printf("here is the final array\n");

  for (i = 0; i < 52; i++) {    // shuffle array
    int temp = crand[i];
    int randI = rand() % 52;
    crand[i] = crand[randI];
    crand[randI] = temp;
  }

  for (i = 0; i < 20; i++) {    // print array
    printf("%d,",crand[i]);
  }
  printf("\n");
  //get the randomized order

  //Store the actual card for final print out
  // 1-13 --> C; 14 - 26 --> D; 27 - 39 --> H; 40 - 52 --> S//
  int ii;
  for(ii = 0, ii < 20; ii++) {
    int rr;
    int rank;
    int suit;
    rr = crand[ii] % 13;
    //rank conditions
    if(rr == 1) {
      r[ii] = '2';
      rank = 0;
    }
    if(rr == 2) {
      r[ii] = '3';
      rank = 1;
    }
    if(rr == 3) {
      r[ii] = '4';
      rank = 2;
    }
    if(rr == 4) {
      r[ii] = '5';
      rank = 3;
    }
    if(rr == 5) {
      r[ii] = '6';
      rank = 4;
    }
    if(rr == 6) {
      r[ii] = '7';
      rank = 5;
    }
    if(rr == 7) {
      r[ii] = '8';
      rank = 6;
    }
    if(rr == 8) {
      r[ii] = '9';
      rank = 7;
    }
    if(rr == 9) {
      r[ii] = 't';
      rank = 8;
    }
    if(rr == 10) {
      r[ii] = 'j';
      rank = 9;
    }
    if(rr == 11) {
      r[ii] = 'q';
      rank = 10;
    }
    if(rr == 12) {
      r[ii] = 'k';
      rank = 11;
    }
    if(rr == 13) {
      r[ii] = 'a';
      rank = 12;
    }


    //suit conditions
    // c -> 0, d -> 1, h -> 2, s -> 3
    if(crand[ii] >= 1 && crand[ii] <= 13){
      s[ii] = 'c';
      suit = 0;
    }
    if(crand[ii] >= 14 && crand[ii] <= 26){
      s[ii] = 'd';
      suit = 1;
    }
    if(crand[ii] >= 27 && crand[ii] <= 39){
      s[ii] = 'h';
      suit = 2;
    }
    if(crand[ii] >= 40 && crand[ii] <= 52){
      s[ii] = 's';
      suit = 3;
    }


    //read the value of cards to num_rank and num_suit
    num_rank[ii] = rank;
    num_suit[ii] = suit;

    if(ii >= 0 && ii <= 4) {
      num_in_rankp1[rank]++;
      num_in_suitp1[suit]++;
    }
    if(ii >= 5 && ii <= 9) {
      num_in_rankp2[rank]++;
      num_in_suitp2[suit]++;
    }
    if(ii >= 10 && ii <= 14) {
      num_in_rankp3[rank]++;
      num_in_suitp3[suit]++;
    }
    if(ii >= 15 && ii <= 19) {
      num_in_rankp4[rank]++;
      num_in_suitp4[suit]++;
    }

  }
}

//player1: 0-4, player2: 5-9, player3: 10-14, player4: 15-19
void analyze(void) {
  //shared variables
  int rank, suit;
  //p1hand
  int num_consec1 = 0;
  p1straight = false;
  p1flush = false;
  p1four = false;
  p1three = false;
  p1pairs = 0;

  /* check for flush */
  for (suit = 0; suit < NUM_SUITS; suit++)
    if (num_in_suitp1[suit] == NUM_CARDS)
      p1flush = true;
  /* check for straight */
  rank = 0;
  while (num_in_rankp1[rank] == 0) rank++;
  for (; rank < NUM_RANKS && num_in_rankp1[rank] > 0; rank++)
    num_consec1++;
  if (num_consec1 == NUM_CARDS) {
    p1straight = true;
    return;
  }
  /* check for 4-of-a-kind, 3-of-a-kind, and pairs */
  for (rank = 0; rank < NUM_RANKS; rank++) {
    if (num_in_rankp1[rank] == 4) p1four = true;
    if (num_in_rankp1[rank] == 3) p1three = true;
    if (num_in_rankp1[rank] == 2) p1pairs++;
  }

  //p2hand
  int num_consec2 = 0;
  p2straight = false;
  p2flush = false;
  p2four = false;
  p2three = false;
  p2pairs = 0;

  /* check for flush */
  for (suit = 0; suit < NUM_SUITS; suit++)
    if (num_in_suitp2[suit] == NUM_CARDS)
      p2flush = true;
  /* check for straight */
  rank = 0;
  while (num_in_rankp2[rank] == 0) rank++;
  for (; rank < NUM_RANKS && num_in_rankp2[rank] > 0; rank++)
    num_consec2++;
  if (num_consec2 == NUM_CARDS) {
    p2straight = true;
    return;
  }
  /* check for 4-of-a-kind, 3-of-a-kind, and pairs */
  for (rank = 0; rank < NUM_RANKS; rank++) {
    if (num_in_rankp2[rank] == 4) p2four = true;
    if (num_in_rankp2[rank] == 3) p2three = true;
    if (num_in_rankp2[rank] == 2) p2pairs++;
  }

  //p3hand
  int num_consec3 = 0;
  p3straight = false;
  p3flush = false;
  p3four = false;
  p3three = false;
  p3pairs = 0;

  /* check for flush */
  for (suit = 0; suit < NUM_SUITS; suit++)
    if (num_in_suitp3[suit] == NUM_CARDS)
      p3flush = true;
  /* check for straight */
  rank = 0;
  while (num_in_rankp3[rank] == 0) rank++;
  for (; rank < NUM_RANKS && num_in_rankp3[rank] > 0; rank++)
    num_consec3++;
  if (num_consec3 == NUM_CARDS) {
    p3straight = true;
    return;
  }
  /* check for 4-of-a-kind, 3-of-a-kind, and pairs */
  for (rank = 0; rank < NUM_RANKS; rank++) {
    if (num_in_rankp3[rank] == 4) p3four = true;
    if (num_in_rankp3[rank] == 3) p3three = true;
    if (num_in_rankp3[rank] == 2) p3pairs++;
  }

  //p4hand
  int num_consec4 = 0;
  p4straight = false;
  p4flush = false;
  p4four = false;
  p4three = false;
  p4pairs = 0;

  /* check for flush */
  for (suit = 0; suit < NUM_SUITS; suit++)
    if (num_in_suitp4[suit] == NUM_CARDS)
      p4flush = true;
  /* check for straight */
  rank = 0;
  while (num_in_rankp4[rank] == 0) rank++;
  for (; rank < NUM_RANKS && num_in_rankp4[rank] > 0; rank++)
    num_consec4++;
  if (num_consec4 == NUM_CARDS) {
    p4straight = true;
    return;
  }
  /* check for 4-of-a-kind, 3-of-a-kind, and pairs */
  for (rank = 0; rank < NUM_RANKS; rank++) {
    if (num_in_rankp4[rank] == 4) p4four = true;
    if (num_in_rankp4[rank] == 3) p4three = true;
    if (num_in_rankp4[rank] == 2) p4pairs++;
  }

}

//Send and save hand stats
//(Straight flush: 8, Four of a kind: 7, Full house: 6, Flush: 5, Straight: 4, Three of a kind: 3, Two pairs: 2, Pair: 1, High card: 0)
void stats(void)
{
  //player1
  if (p1straight && p1flush) {
    p1stat = 8;
  }
  else if (p1four) {
    p1stat = 7;
  }
  else if (p1three && p1pairs == 1) {
    p1stat = 6;
  }
  else if (p1flush) {
    p1stat = 5;
  }
  else if (p1straight) {
    p1stat = 4;
  }
  else if (p1three) {
    p1stat = 3;
  }
  else if (p1pairs == 2) {
    p1stat = 2;
  }
  else if (p1pairs == 1) {
    p1stat = 1;
  }
  else {
    p1stat = 0;
  }
  //player2
  if (p2straight && p2flush) {
    p2stat = 8;
  }
  else if (p2four) {
    p2stat = 7;
  }
  else if (p2three && p2pairs == 1) {
    p2stat = 6;
  }
  else if (p2flush) {
    p2stat = 5;
  }
  else if (p2straight) {
    p2stat = 4;
  }
  else if (p2three) {
    p2stat = 3;
  }
  else if (p2pairs == 2) {
    p2stat = 2;
  }
  else if (p2pairs == 1) {
    p2stat = 1;
  }
  else {
    p2stat = 0;
  }
  //player3
  if (p3straight && p3flush) {
    p3stat = 8;
  }
  else if (p3four) {
    p3stat = 7;
  }
  else if (p3three && p3pairs == 1) {
    p3stat = 6;
  }
  else if (p3flush) {
    p3stat = 5;
  }
  else if (p3straight) {
    p3stat = 4;
  }
  else if (p3three) {
    p3stat = 3;
  }
  else if (p3pairs == 2) {
    p3stat = 2;
  }
  else if (p3pairs == 1) {
    p3stat = 1;
  }
  else {
    p3stat = 0;
  }
  //player4
  if (p4straight && p4flush) {
    p4stat = 8;
  }
  else if (p4four) {
    p4stat = 7;
  }
  else if (p4three && p4pairs == 1) {
    p4stat = 6;
  }
  else if (p4flush) {
    p4stat = 5;
  }
  else if (p4straight) {
    p4stat = 4;
  }
  else if (p4three) {
    p4stat = 3;
  }
  else if (p4pairs == 2) {
    p4stat = 2;
  }
  else if (p4pairs == 1) {
    p4stat = 1;
  }
  else {
    p4stat = 0;
  }
}

//Check who wins
void winner_checker(void) {

}

//Print out final results
//char r[20] and char s[20]
//player1: 0-4, player2: 5-9, player3: 10-14, player4: 15-19
//Straight flush: 8, Four of a kind: 7, Full house: 6, Flush: 5, Straight: 4, Three of a kind: 3, Two pairs: 2, Pair: 1, High card: 0
void print_results(void) {
  int i;
  printf("P1: ");
  for(i = 0; i < 5; i++) {
    printf("%c%c", r[i], s[i]);
  }
  printf("\n");
  printf("P2: ");
  for(i = 5; i < 10; i++) {
    printf("%c%c", r[i], s[i]);
  }
  printf("\n");
  printf("P3: ");
  for(i = 10; i < 15; i++) {
    printf("%c%c", r[i], s[i]);
  }
  printf("\n");
  printf("P4: ");
  for(i = 15; i < 20; i++) {
    printf("%c%c", r[i], s[i]);
  }
  printf("\n");
  printf("Winner: ");
}
