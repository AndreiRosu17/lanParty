#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct PlayerInfo{
  char* firstName;
  char* secondName;
  int points;
  struct PlayerInfo *nextPlayer;
}Jucator;

typedef struct TeamInfo{
  int Nr_Jucator;
  char* TeamName;
  float score;
  struct PlayerInfo* Players;
  struct TeamInfo *nextTeam;
}Echipa;

typedef struct queueNode{
  Echipa team1, team2;
  struct queueNode *next;
}queueNode;

typedef struct Q{
  queueNode *front, *rear;
}Queue;

typedef struct stiva{
  char *nume;
  float score;
  struct stiva *next;
}Stiva;

void MakeList(Echipa**, FILE*);
void CitesteInfoJucator(Jucator** , FILE* );
void ScriereLista(Echipa*, FILE*);
void adaugaLaFinal(Jucator** , Jucator** );
void adaugaLaInceput(Jucator** , Jucator** );
void nr_jucatori(int *, int *);
void StergeEchipe(Echipa**, int *);
void StergeEchipeNode(Echipa **, float );
void ListaTask2(Echipa **);
void freeEchipa(Echipa **);
void enQueue(Queue *, Echipa **, FILE*);
Queue *createQueue();
void scoateSpatii(Echipa **);
void JOC(FILE *, Stiva **, Stiva **, int *, Queue **, Echipa *);
void stergeCoada(Queue **);
void stergeStiva(Stiva **);
void afisareCastigatori(FILE *, Stiva **, int* );
void push(Stiva **, Queue *, int);
void enQueue2(Queue *, Stiva **, FILE *, int );