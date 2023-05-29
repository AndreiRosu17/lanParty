#include "header.h"

void MakeList(Echipa **head, FILE *fp) {
  float sum = 0;

  Jucator *headPlayerList;
  headPlayerList = (Jucator *)malloc(sizeof(Jucator));
  headPlayerList = NULL;

  char *gol1;
  gol1 = (char *)malloc(sizeof(char) * 50);

  Echipa *newNode;
  newNode = (Echipa *)malloc(sizeof(Echipa));

  fscanf(fp, "%d", &newNode->Nr_Jucator);
  newNode->score = 0;

  fgetc(fp);

  if (fgets(gol1, 50, fp) != NULL) {
    newNode->TeamName = (char *)malloc(strlen(gol1) * sizeof(char));
    newNode->TeamName = strdup(gol1);
  }

  for (int i = 0; i < newNode->Nr_Jucator; i++) {
    Jucator *newTeam;
    newTeam = (Jucator *)malloc(sizeof(Jucator));
    CitesteInfoJucator(&newTeam, fp);
    newNode->score = newNode->score + newTeam->points;
    /// printf("%f ", sum);
    /*printf("%d", sum);*/
    adaugaLaFinal(&headPlayerList, &newTeam);
  }

  newNode->score = newNode->score / newNode->Nr_Jucator;
  /// printf("%f \n", newNode->score);
  newNode->nextTeam = *head;
  *head = newNode;
  (*head)->Players = headPlayerList;
}

void adaugaLaInceput(Jucator **headPlayer, Jucator **newJucator) {
  (*newJucator)->nextPlayer = *headPlayer;
  *headPlayer = *newJucator;
}

void adaugaLaFinal(Jucator **headPlayer, Jucator **newJucator) {
  Jucator *aux = *headPlayer;
  if (*headPlayer == NULL)
    adaugaLaInceput(&*headPlayer, &*newJucator);
  else {
    while (aux->nextPlayer != NULL) {
      aux = aux->nextPlayer;
    }
    aux->nextPlayer = *newJucator;
    (*newJucator)->nextPlayer = NULL;
  }
}

void CitesteInfoJucator(Jucator **jucator, FILE *fp) {
  Jucator *newPlayer;
  newPlayer = (Jucator *)malloc(sizeof(Jucator));

  char *gol2;

  gol2 = (char *)malloc(50 * sizeof(char));
  fscanf(fp, "%s", gol2);
  newPlayer->firstName = (char *)malloc(sizeof(char) * strlen(gol2));
  /// strcpy(newPlayer->firstName, gol2);
  newPlayer->firstName = strdup(gol2);

  gol2 = (char *)malloc(sizeof(char) * 50);
  fscanf(fp, "%s", gol2);
  newPlayer->secondName = (char *)malloc(sizeof(char) * strlen(gol2));
  strcpy(newPlayer->secondName, gol2);
  newPlayer->secondName = strdup(gol2);

  fscanf(fp, "%d", &newPlayer->points);
  

  (*jucator)->firstName = strdup(newPlayer->firstName);
  (*jucator)->secondName = strdup(newPlayer->secondName);
  (*jucator)->points = newPlayer->points;
  (*jucator)->nextPlayer = newPlayer;
}

void ScriereLista(Echipa *head, FILE *fout) {
  while (head != NULL) {
    fprintf(fout, "%s", head->TeamName);
    head = head->nextTeam;
  }
}

void nr_jucatori(int *no_players, int *Nr_echipe) {
  do {
    if (*no_players <= (*Nr_echipe / 2))
      *no_players = (*no_players * 2);
  } while (*no_players <= *Nr_echipe / 2);
}

void freeEchipa(Echipa **head){
  while((*head)->Players!=NULL){
    free((*head)->Players->firstName);
    free((*head)->Players->secondName);
    (*head)->Players=(*head)->Players->nextPlayer;
  }
  free((*head)->TeamName);
  free((*head));
}

void ListaTask2(Echipa **head){
  float min=100; ///egalez cu 100 deoarece media unei echipe nu poate sa fie mai mare de 10
  Echipa *copie, *anterior;
  copie=*head;
  anterior=*head;

  ///ce urmeaza in aceasta functie este de stergere nod dintr-o lista, functie luata de la curs

  while(copie!=NULL){
    if(copie->score<min)
      min=copie->score;
    copie=copie->nextTeam;
  }
  if(*head==NULL) return;
  copie=*head;
  if(copie->score==min){
    *head=(*head)->nextTeam;
    freeEchipa(&copie);
    return;
  }
  while(copie!=NULL){
    if(copie->score!=min){
      anterior=copie;
      copie=copie->nextTeam;
    }else{
      anterior->nextTeam=copie->nextTeam;
      freeEchipa(&copie);
      return;
    }
  }

}

Queue *createQueue(){
  Queue *q;
  q = (Queue*)malloc(sizeof(Queue));
  q->front=(queueNode*)malloc(sizeof(queueNode));
  q->rear=(queueNode*)malloc(sizeof(queueNode));
  q->front=q->rear=NULL;
}

void enQueue(Queue *q, Echipa **head, FILE *iesire){
  while((*head)!=NULL){
    queueNode *newNode = (queueNode*)malloc(sizeof(queueNode));
    newNode->team1.TeamName = strndup((*head)->TeamName, strlen((*head)->TeamName)-2);
    int l;
    l=strlen(newNode->team1.TeamName);
    if(newNode->team1.TeamName[l-1]==' ') newNode->team1.TeamName[l-1]='\0';

    newNode->team2.TeamName = strndup((*head)->nextTeam->TeamName, strlen((*head)->nextTeam->TeamName)-2);
    l=strlen(newNode->team2.TeamName);
    if(newNode->team2.TeamName[l-1]==' ') newNode->team2.TeamName[l-1]='\0';
    
    newNode->team1.score = (*head)->score;
    newNode->team2.score = (*head)->nextTeam->score;
    if(q->rear == NULL)
      q->rear = newNode;
    else{
      (q->rear)->next = newNode;
      (q->rear) = newNode;
    }
    if(q->front == NULL)
      q->front = q->rear;
    (*head) = (*head)->nextTeam->nextTeam;
    fprintf(iesire, "%s\n", newNode->team1.TeamName);
    fprintf(iesire ,"%s\n", newNode->team2.TeamName);
  }
}

void JOC(FILE *iesire, Stiva **stivaCastigatori, Stiva **stivaPierzatori, int *no_teams, Queue **q, Echipa *t){
  while((*q)->front!=NULL){

    fprintf(iesire, "%-33s-%33s\n", (*q)->front->team1.TeamName, (*q)->front->team2.TeamName);
    if((*q)->front->team1.score > (*q)->front->team2.score){
      (*q)->front->team1.score++;
      push(&*stivaCastigatori, (*q), 1); ///adauga castigatorii in stiva de castigatori
      push(&*stivaPierzatori, (*q), 2); ///adauga pierzatorii in stiva de pierzatori
    }else{
      (*q)->front->team2.score++;
      push(&*stivaCastigatori, (*q), 2);
      push(&*stivaPierzatori, (*q), 1);
    }
    (*q)->front=(*q)->front->next;
  }
}

void scoateSpatii(Echipa **head){
  while((*head)!=NULL){
    int l;
    l=strlen((*head)->TeamName);
    while(l>0 && ((*head)->TeamName[l-3] == ' ' || (*head)->TeamName[l-3] == '\n')){
      strncpy((*head)->TeamName, (*head)->TeamName, l-4);
      l--;
    }
    (*head)=(*head)->nextTeam;
  }
}

void push(Stiva **top, Queue *q, int nr){
  Stiva (*newNode) = (Stiva*)malloc(sizeof(Stiva));
  if(nr == 1){
    newNode->nume = strdup(q->front->team1.TeamName);
    ///printf("%s ", newNode->nume);
    newNode->score = q->front->team1.score;
    newNode->next=(*top);
    *top = newNode;
  }else if(nr==2){
    newNode->nume = strdup(q->front->team2.TeamName);
    ///printf("%s ", newNode->nume);
    newNode->score = q->front->team2.score;
    newNode->next=(*top);
    *top = newNode;
  }
}

void afisareCastigatori(FILE *iesire, Stiva **stivaCastigatori, int* no_teams){
  Stiva *copie = (Stiva*)malloc(sizeof(Stiva));
  copie = *stivaCastigatori;
  for(int i=0; i<(*no_teams);i++){
    fprintf(iesire, "%-34s-  %.2f\n", copie->nume, copie->score);
    (copie) = copie->next;
  }
}

void stergeStiva(Stiva **top){
  Stiva *aux;
  while((*top)!=NULL){
    aux=*top;
    *top = (*top)->next;
    free(aux);
  }
}

void stergeCoada(Queue **q){
  queueNode* aux;
  while((*q)->front!=NULL){
    aux = (*q)->front;
    (*q)->front = (*q)->front->next;
    free((aux)->team1.TeamName);
    free((aux)->team2.TeamName);
    free(aux);
  }
  free(*q);
}

void enQueue2(Queue *q, Stiva **top, FILE *iesire, int x){
  while((*top)!=NULL){
    queueNode *newNode = (queueNode*)malloc(sizeof(queueNode));
    newNode->team1.TeamName = strdup((*top)->nume);
    newNode->team2.TeamName = strdup((*top)->next->nume);
    
    newNode->team1.score = (*top)->score;
    newNode->team2.score = (*top)->next->score;
    if(q->rear == NULL){
      q->rear = newNode;
      }
    else{
      (q->rear)->next = newNode;
      (q->rear) = newNode;
    }
    if(q->front == NULL){
      q->front = q->rear;
      }
    (*top) = (*top)->next->next;
    fprintf(iesire, "%-34s-  %.2f\n", newNode->team1.TeamName, newNode->team1.score);
    fprintf(iesire, "%-34s-  %.2f\n", newNode->team2.TeamName, newNode->team2.score);
  }
}