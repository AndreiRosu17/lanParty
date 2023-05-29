#include "header.h"


int main(int argc, char *argv[]){
  
  FILE *cerinta, *iesire, *intrare;
  int task1, task2, task3, task4, task5;
  int Nr_Echipe=0, no_teams=1;

  Echipa *head;
  head=(Echipa*)malloc(sizeof(Echipa));
  head=NULL;

  cerinta = fopen(argv[1], "r");
  intrare = fopen(argv[2], "r");
  iesire = fopen(argv[3], "w");
  if (intrare == NULL) {
    printf("Fisierul intrare nu a putut sa fie deschis1\n");
  }
  if (iesire == NULL) {
    printf("Fisierul iesire nu a putut sa fie deschis2\n");
  }
  if (cerinta ==NULL){
    printf("Fisierul cerinta nu a putut sa fie deschis3\n");
  }
  
  fscanf(cerinta, "%d %d %d %d %d", &task1, &task2, &task3, &task4, &task5);

  fscanf(intrare, "%d", &Nr_Echipe);

  for(int i=0;i<Nr_Echipe;i++){
    MakeList(&head, intrare);
  }
  
  if((task1) && task2==0)
    ScriereLista(head, iesire);
  
  nr_jucatori(&no_teams, &Nr_Echipe);  ///functia returneaza numarul de echipe necesare pentru cerinta 2, adica 2 la o putere n si sa fie mai mic decat numarul de echipe initiale
  
  while(no_teams!=Nr_Echipe){
    ListaTask2(&head);///functie care sa elimine echipa
    Nr_Echipe--;
  }

  if((task2) && task3==0){
    ScriereLista(head, iesire);
  }
  
  if((task3) && task4==0){
    while(no_teams!=Nr_Echipe){
    ListaTask2(&head);///functie care sa elimine echipa
    Nr_Echipe--;
  }

    Queue *q = createQueue();

    enQueue(q, &head, iesire); ///adaug in coada si in acelasi timp fac afisarea;
    int nr_runda=1;
    fprintf(iesire, "\n--- ROUND NO:%d\n", nr_runda);

    Echipa *t;
    t=(Echipa*)malloc(2*sizeof(Echipa));

    Stiva *stivaCastigatori, *stivaPierzatori;
    stivaCastigatori = stivaPierzatori = NULL;

    JOC(iesire, &stivaCastigatori, &stivaPierzatori, &no_teams, &q, t); ///fac afisarea de meciuri si memorez pierzatorii si castigatorii;

    no_teams = no_teams/2;
    fprintf(iesire, "\nWINNERS OF ROUND NO:%d\n", nr_runda);
    
    enQueue2(q, &stivaCastigatori, iesire, 2);
    
    while(no_teams>1){
      nr_runda++;
      enQueue2(q, &stivaCastigatori, iesire, 2);
      fprintf(iesire, "\n--- ROUND NO:%d\n", nr_runda);
      JOC(iesire, &stivaCastigatori, &stivaPierzatori, &no_teams, &q, t);
      fprintf(iesire, "\nWINNERS OF ROUND NO:%d\n", nr_runda);
      
      no_teams = no_teams/2; 
    }
    fprintf(iesire, "%-34s-  %.2f\n", stivaCastigatori->nume, stivaCastigatori->score);
  }
  if((task4) && task5==0){
    while(no_teams!=Nr_Echipe){
    ListaTask2(&head);///functie care sa elimine echipa
    Nr_Echipe--;
  }

    Queue *q = createQueue();

    enQueue(q, &head, iesire);
    int nr_runda=1;
    fprintf(iesire, "\n--- ROUND NO:%d\n", nr_runda);

    Echipa *t;
    t=(Echipa*)malloc(2*sizeof(Echipa));

    Stiva *stivaCastigatori, *stivaPierzatori, *copie;
    stivaCastigatori = stivaPierzatori = NULL;

    JOC(iesire, &stivaCastigatori, &stivaPierzatori, &no_teams, &q, t);

    no_teams = no_teams/2;
    fprintf(iesire, "\nWINNERS OF ROUND NO:%d\n", nr_runda);
    
    enQueue2(q, &stivaCastigatori, iesire, 2);
    
    while(no_teams>1){
      nr_runda++;
      enQueue2(q, &stivaCastigatori, iesire, 2);
      fprintf(iesire, "\n--- ROUND NO:%d\n", nr_runda);
      JOC(iesire, &stivaCastigatori, &stivaPierzatori, &no_teams, &q, t);
      fprintf(iesire, "\nWINNERS OF ROUND NO:%d\n", nr_runda);
      no_teams = no_teams/2; 
    }
    fprintf(iesire, "%-34s-  %.2f\n", stivaCastigatori->nume, stivaCastigatori->score);

     
  }
}
