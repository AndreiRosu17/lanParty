# Introducere
Acest program numit LAN Party ajuta la organizarea unui turneu de jocuri intre studentii care au dorit sa participe la aceasta activitate organizata de LSAC. Programul a fost implementat in limbajul de programare C. 

## Partea de cod

#### Main
La inceput am facut un header in care aveam la inceput 2 struct-uri, unul cu detaliile echipei (nume, score, numar jucatori, un sturct de jucatori si un next care sa ma duca la detaliile urmatoarei echipe) si un struct de jucatori(nume, prenume, score si un next care sa ma duca la detaliile urmatorului jucator);

Pentru fiecare task pe care am reusit sa il fac am decis sa citesc din fiserul d.in numarul de echipe, iar dupa am facut o functie care sa citeasca echipele si jucatorii, functia o sa ma ajute 
la urmatoarele task-uri;

In implementarea functiei de mai sus m-am gandit asa: am dorit sa creez o lista, care la inceput era NULL si am mai creat un node de echipa, am citit numarul de jucatori, numele echipei, iar dupa am luat un for de la 0 la numarul de jucatori in care am o functie care citeste detaliile jucatorului, iar la finalul finalul functiei de citire pentru jucatori aveam next care sa imi creeze un nod nou pentru jucatori. In for am calculat si punctajul total al echipei, iar la finalul functiei aveam next pentru echipa sa treaca la alta noua sa citeasca informatii noi.

#### Task 1
Pentru Task1 am facut o functie pentru care se foloseste de lista creata in main;
Am luat un head care sa fie inceputul listei, iar in functie am un while pana cand head este NULL, iar la fiecare pas afiseaza numele fiecari echipe.

#### Task 2
Pentru task 2 am facut o functie care sa imi elimine echipele cu cel mai mic punctaj pana raman cel mai mare numar la o putere de a lui 2, dar mai mic fata de numarul de echipe;
M-am folosit de functie care sa elimine echipele, iar in functie am alta functie de eliberare a memoriei penru echipele ramase.
M-am folosit de functia de la task 1 pentru afisarea echipelor ramase.

#### Task 3
La inceput m-am folosit de tot ce am facut la task 2;
Am facut 3 struct-uri: primul contine un struct la echipa team1 si team2 ((pentru a disputa meciul), si un next care sa treaca la citirea uramatoarelor 2 echipe), un struct cu nod pentru coada sa retin inceputul si finalul cozii si un struct pentru stiva in care retin numele si punctajul. De ultimul struct ma folosesc sa memorez echipele castigatoare si pierzatoare;
Am o functie de creare coada in care sunt adaugata toate echipele ce urmeaza sa intre in joc si cu tot cu punctaj (punctajul initial nu il afisez);
Apoi am o functie pentru disputarea meciurilor, iar echipa care castiga este adugata in stiva cu ecipe castigatoare, iar la cele pierzatoare la fel, doar ca in stiva cu echipe pierzatoare.
Din stiva cu echipe castigatoare le bag din nou in coada si le afisez cu tot cu punctaj si repet pana cand aflu echipa castigatoare. 

# Implementare
Implementarea codului meu este una relativ eficienta, rapida, dar care mananca, presupun eu, destul de multa memorie. 

# Opinie personala 
Tema mi s-a parut una destul de interesanta, care a reusit sa imi puna mintea la contributie. Am reusit sa ma familiarizez cu liste, cozi si stive. 


