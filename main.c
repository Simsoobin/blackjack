#include <stdio.h>
#include <stdlib.h>

#define N_CARDSET         1
#define N_CARD            52
#define N_DOLLAR         50


#define N_MAX_CARDNUM      13
#define N_MAX_USER         5
#define N_MAX_CARDHOLD      10
#define N_MAX_GO         17
#define N_MAX_BET         5

#define N_MIN_ENDCARD      30


//card tray object
int CardTray[N_CARDSET*N_CARD];
int cardIndex = 0;


//player info
int dollar[N_MAX_USER];                  //dollars that each player has
int n_user;                           //number of users


								 //play yard information
int cardhold[N_MAX_USER + 1][N_MAX_CARDHOLD];   //cards that currently the players hold
int cardSum[N_MAX_USER];               //sum of the cards
int bet[N_MAX_USER];                  //current betting 
int gameEnd = 0;                      //game end flag

int rnd_n = 1;

                             //card processing functions ---------------

                             //calculate the actual card number in the blackjack game
int getCardNum(int cardnum) {

}

//print the card information (e.g. DiaA)
void printCard(int cardnum) {
   char *card_s[] = {"HRT", "DIA", "CLV", "SPD"};
   char *card_n[] = { "1", "2", "3", "4", "5", "6", "7", "8"
      , "9", "10", "Jack", "Queen", "King" };
   printf("%s%s ", card_s[rand() % 4], card_n[rand()%13]); // 각 하나씩만 나오게 배열로 고치기
}


//card array controllers -------------------------------

//mix the card sets and put in the array
int mixCardTray(void) {

}

//get one card from the tray
int pullCard(void) {

}


//playing game functions -----------------------------

//player settiing
int configUser(void) {
   int n_user = 0;
   printf("Input the number of players (MAX:5): ");
   scanf("%d", &n_user);
   //입력받은 플레이어 수만큼 변수생성
   for (int i = 0; i < n_user; i++) {

   }
}


//betting
int betDollar(void) {
   int total_D = 50;
   int bet_D = 0;
   printf("------- BETTING STEP -------\n");
   printf("   -> your betting (total: $%d) : ", bet_D);
   scanf("%d", &bet_D);
   for (int i = 0; i < n_user; i++) {
      printf("   -> player%d bets $%d (out of $50)", i, rand() % N_MAX_BET + 1);
   }
   printf("----------------------------");

}


//offering initial 2 cards
void offerCards(void) {
   int i;
   //1. give two card for each players
   for (i = 0; i<n_user; i++)
   {
      cardhold[i][0] = pullCard(); // 첫 번째 카드
      cardhold[i][1] = pullCard(); // 두 번째 카드
   }
   //2. give two card for the operator
   cardhold[n_user][0] = pullCard(); // 첫 번째 카드
   cardhold[n_user][1] = pullCard(); // 두 번째 카드



   return;
}

//print initial card status
void printCardInitialStatus(void) {
   
   printf(" ----------- CARD OFFERING ---------------");
   printf(" --- server      : X ");
   printf("   -> you        : ");
   printCard(cardhold);
   printCard(cardhold);
   for (int i = 1; i <= n_user; i++) {
      printf("   -> player %d   : ", i);
      printCard(cardhold[i][0]);
      printCard(cardhold[i][1]);
   }
}

int getAction(void) {
   int userAction;
   printf("Action? (0 - go, others - stay) :");
   scanf("%d", &userAction);
   if() // 0이면 cardcnt++
   return userAction;
}


void printUserCardStatus(int user, int cardcnt) {
   int i;

   printf("   -> card : ");
   for (i = 0; i<cardcnt; i++)
      printCard(cardhold[user][i]);
   printf("\t ::: ");
}




// calculate the card sum and see if : 1. under 21, 2. over 21, 3. blackjack
int calcStepResult() { // 현재 player카드의 합산 계산 및 승패여부 판단(return)
   if (cardSum <= 21) {
      // under 21
      return 1;
   }
   else if (cardSum > 21) {
      // over 21
      printf("::: DEAD (sum:%d) --> -$%d ($%d)", /*player[i]의 sum, bet_D, player[i]의 D_sum*/);
      printf("[[[[[[[ server result is .... ....overflow!! ]]]]]]]\n");
      return gameEnd;
      // print문은 다른함수로 옮겨야하나? 아니면 승패여부 변수 만들어??

   }
   else if () {
      // blackjack
      return 1;
      // blackjack print
   }
}

int checkResult() {
   printf(" -------------------- ROUND %d result ....", rnd_n);
   printf("   -> your result : ");
   for (int i = 0; i < n_user; i++) {
      printf("   -> %d'th player's result :", n_user);
      if(player[i] )
   }
   rnd_n++;
}

int checkWinner() {

}

void printRound() {
   printf("------------------------------------------------");
   printf("------------ ROUND %d (cardIndex:%d)--------------------------", rnd_n, /**/);
   printf("------------------------------------------------");
   rnd_n++;
}



int main(int argc, char *argv[]) {
   int roundIndex = 0;
   int max_user;
   int i;

   srand((unsigned)time(NULL)); 

   //set the number of players
   configUser();


   //Game initialization --------
   //1. players' dollar

   //2. card tray
   mixCardTray();



   //Game start --------
   do {
      
      printRound();

      betDollar(); //
      offerCards(); //1. give cards to all the players

      printCardInitialStatus(); // 초기 화면 배포 현황 출 력 
      printf("\n------------------ GAME start --------------------------\n");

      //each player's turn
      for (int i = 0; i < n_user; i++) //each player
      {
         //나, p1, p2 ... 순서로 진행
         printf("... turn! -------------");
         while (!calcStepResult() || !getAction()) //do until the player dies or player says stop
         {
            //print current card status printUserCardStatus();
            printUserCardStatus(n_user, /*n_user의 카드 수*/); // 현재 turn의 player 카드 상태 출력
            //check the card status ::: calcStepResult()
            calcStepResult(); // 현재 player카드의 합산 계산 및 승패여부 판단
            //GO? STOP? ::: getAction()
            getAction(); // 현재 turn의 player에게 go/stop 여부를 한번 결정
            //check if the turn ends or not
         }
      }

      //result
      checkResult();
   } while (gameEnd == 0);

   checkWinner();


   return 0;
}
