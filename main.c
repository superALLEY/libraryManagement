#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <windows.h>
#include <dos.h>
#include <time.h>
#include <conio.h>

#define tmax 1000

//les livre
typedef struct livre {
    int id;

    char titre[20];

    char auteur[20];

    char categorie[20];

    int note;

    int nbr;

    bool disponibilite;
} livre;

typedef struct liste_livre{

livre info;

struct liste_livre* next;

}liste_livre;

//les avis

typedef struct avis {

    char Avis[50];

    int livre_id;


} avis;

//les adherents

typedef struct adherent {
    int id;

    char nom[20];

    char prenom[20];

    char formation[20];

    avis avis_livre[tmax];

    int longue;

} adherent;

typedef struct liste_adherent{

adherent info;

struct liste_adherent* next;

}liste_adherent;

//les emprunts

typedef struct emprunt {

    int id;

    int id_livre;

    char date_emprunt[50];

}emprunt;

typedef struct liste_emprunt{

emprunt info;

struct liste_emprunt* next;

}liste_emprunt;


typedef struct listeglobale{

liste_adherent A ;

liste_emprunt  E ;

liste_livre    L ;

}listeglobale;

//********************************************//

        //empty list

liste_adherent* empty_adherent_list(){


   liste_adherent* tete=NULL;

   return tete;
}

liste_emprunt* empty_emprunt_list(){


   liste_emprunt* tete=NULL;

   return tete;
}

liste_livre* empty_livre_list(){


   liste_livre* tete=NULL;

   return tete;
}

        //deallocating

void deallocate_adhernt(liste_adherent** root){

liste_adherent* curr=*root;

while(curr != NULL){

    liste_adherent* aux=curr;

    curr = curr->next;

    free(aux);

}*root=NULL;

}

void deallocate_livre(liste_livre** root){

liste_livre* curr=*root;

while(curr != NULL){

    liste_livre* aux=curr;

    curr = curr->next;

    free(aux);

}*root=NULL;

}

void deallocate_emprunt(liste_emprunt** root){

liste_emprunt* curr=*root;

while(curr != NULL){

    liste_emprunt* aux=curr;

    curr = curr->next;

    free(aux);

}*root=NULL;

}

        //counting elements

int count_element_adherent(liste_adherent* root){
    int x=0,c=0;

    for(liste_adherent* curr = root;curr!= NULL;curr=curr->next){

        x++;

    }

    return x;
}

int count_element_livre(liste_livre* root){

    int x=0,c=0;

    for(liste_livre* curr = root;curr!= NULL;curr=curr->next){

        x++;

    }

    return x;
}

int count_element_emprunt(liste_emprunt* root){

    int x=0,c=0;

    for(liste_emprunt* curr = root;curr!= NULL;curr=curr->next){

        x++;

    }

    return x;
}

        //saerch

bool search_element(liste_adherent* root,int value){




    for(liste_adherent* curr = root;curr!= NULL;curr=curr->next){

      if(curr->info.id == value){

        return true;

      }

    }

    return false;
}

        //print list
void print_list_adherent(liste_adherent** root){



    for(liste_adherent* curr=root;curr!=NULL;curr=curr->next){

        printf("\n{\tnom : %s | prenom %s | formation %s | numero id %d  \t}\n",curr->info.nom,curr->info.prenom,curr->info.formation,curr->info.id);

    }

    printf("\nveuillez clicker sur nimporte quel numero pour continue ");

}

void print_list_emprunt(liste_emprunt* root){



    for(liste_emprunt* curr=root;curr!=NULL;curr=curr->next){

        printf("\nnum id de livre : %d |num id d adherent %d | date d emprunt %s \n",curr->info.id_livre,curr->info.id,curr->info.date_emprunt);

    }

    printf("\nveuillez clicker sur nimporte quel numero pour continue ");getch();

}

void print_list_livre(liste_livre* root){



    for(liste_livre* curr=root;curr!=NULL;curr=curr->next){

        printf("\n{\tle titre de livre : %s | l auteur %s | categorie %s | num id %d \t}\n",curr->info.titre,curr->info.auteur,curr->info.categorie,curr->info.id);

    }printf("\nveuillez clicker sur nimporte quel numero pour continue ");getch();

    }

//les fonctions d'edition




        //insertion

void insert_adherent(liste_adherent** root,adherent value){

 liste_adherent* new_node = malloc(sizeof(liste_adherent));

 if(new_node == NULL){

        exit(3);
    }

  new_node->next=*root;

    new_node->info=value;

    *root=new_node;
}

void insert_livre(liste_livre** root,livre value){

 liste_livre* new_node = malloc(sizeof(liste_livre));

 if(new_node == NULL){

        exit(3);
    }

    value.disponibilite=true;

    value.nbr=0;
    value.note=0;

    new_node->next=*root;

    new_node->info=value;

    *root=new_node;
}

void insert_emprunt(liste_emprunt** root1,liste_adherent* root2,liste_livre** root3){
system("cls");
int value, id,i;

printf("veuillez saisir votre num id : ");

scanf("%d",&value);

 if(search_element(root2,value)){

    printf("veuillez saisir le num id de livre : ");

    scanf("%d",&id);

     for(liste_livre* curr = root3;curr!= NULL && i==1;curr=curr->next){

      if(curr->info.id == id){

        curr->info.disponibilite=false;

        i=2;

      }

}


int d;



    liste_emprunt* new_node = malloc(sizeof(liste_emprunt));

        if(new_node == NULL){

        exit(3);

         }

      time_t currentTime;

      char *currentTimeString;

      currentTime=time(NULL);

      if(currentTime == ((time_t)-1)){

        return 1;

      }else{

        currentTimeString=ctime(&currentTime);

        if(currentTimeString==NULL){

         return 2;

        }

    }

     new_node->next=*root1;

     new_node->info.id_livre=id;

     new_node->info.id=value;

     strcpy(new_node->info.date_emprunt,currentTimeString);


     *root1=new_node;

        system("color 0A");

     printf("\n\n\tinsertion termine \n\n\tclicker sur nimporte quel numero pour retourner");getch();;

 }else{

    system("cls");system("color 0c");

    printf("\ncet emprunt nest pas un adherent\n");

    printf("\n\n\tinsertion echouee \n\n\tclicker sur nimporte quel numero pour retourner");getch();

 }
}

        //avis d adherent

void insert_adherent_avis(liste_adherent** root,int livre_id){

      int id;

      printf("\nveuillez saisir le num id d adherent : ");

      scanf("%d",&id);

    for(liste_adherent* curr = root;curr!= NULL;curr=curr->next){

      if(curr->info.id == id){

            if(curr->info.longue%100 > 1 || curr->info.longue%100<1) {curr->info.longue=0;}



            char aviS[100];


            printf("\t\tveuillez donner votre avis sur ce livre : ");

            scanf("%s",&aviS);

            curr->info.avis_livre[curr->info.longue].livre_id=livre_id;

            strcpy(curr->info.avis_livre[curr->info.longue].Avis,aviS);

            curr->info.longue++;


      }

    }


return;

}

void delete_adherent_avis(liste_adherent** root){

       int id;

       int id_livre;


      printf("veuillez saisir le num id d adherent :\n");

      scanf("%d",&id);

     for(liste_adherent* curr = root;curr!= NULL;curr=curr->next){


      if(curr->info.id == id){

            if(curr->info.longue ==NULL) {return;}

             int id;

      printf("veuillez saisir le num id de livre :\n");

      scanf("%d",&id_livre);

            for(int i=0;i<=tmax;i++){

                  if(curr->info.avis_livre[i].livre_id==id_livre){

                     if(i== tmax){

                        curr->info.avis_livre[i].livre_id=curr->info.avis_livre[i].livre_id-1;

                     }else if(i==0){

                        for(int j=0;j<curr->info.longue;j++){

                            curr->info.avis_livre[i]=curr->info.avis_livre[i+1];

                        }

                     }else{

                         for(int j=i;j<curr->info.longue;j++){

                            curr->info.avis_livre[i]=curr->info.avis_livre[i+1];

                        }
                    }

                    return;

                }

            }

        }

    }




}


        //enlever

//emprunt

void enlever_emprunt(liste_emprunt** root,liste_adherent** root2,liste_livre** root3){

    system("cls");

    int value;

    printf("veuillez saisir le numero id de livre : ");

    scanf("%d",&value);

    if(*root == NULL){

        return;

    }

int i=1;

int k=0;

    insert_adherent_avis(*root2,value);




      for(liste_livre* curr = *root3;curr!= NULL && i==1;curr=curr->next){

                    if(curr->info.id == value ){


                        printf("\t\tveuillez noter le livre sur 10 :");

                         scanf("%d",&k);

                         curr->info.note=(k+curr->info.note*curr->info.nbr)/(curr->info.nbr+1);

                        curr->info.nbr++;

                         curr->info.disponibilite=true;

                         i=12;


                    }

                }


         if((*root)->info.id_livre== value){

        liste_emprunt* to_remove = *root;

        *root=(*root)->next;

        free(to_remove);}

        return ;



int j=1;
    for(liste_emprunt* curr=*root;curr->next!=NULL;curr=curr->next){

        if(curr->next->info.id_livre == value){


               liste_emprunt* to_remove= curr->next;

            curr->next=curr->next->next;

            free(to_remove);

            return ;

                }



        }





}
//adherent
void enlever_adherent(liste_adherent** root,int value){

    if(*root == NULL){

        return;
    }

    if((*root)->info.id == value){


        liste_adherent* to_remove = *root;

        *root=(*root)->next;

        free(to_remove);

        return enlever_adherent(root,value);;
    }
    for(liste_adherent* curr=*root;curr->next!=NULL;curr=curr->next){

        if(curr->next->info.id == value){

            liste_adherent* to_remove= curr->next;

            curr->next=curr->next->next;

            free(to_remove);

            return enlever_adherent(root,value);
        }


    }


}
//livre
void enlever_livre(liste_livre** root,int value){


    if(*root == NULL){

        return;
    }

    if((*root)->info.id == value){

        liste_livre* to_remove = *root;

        *root=(*root)->next;

        free(to_remove);

        return enlever_livre(root,value);
    }
    for(liste_livre* curr=*root;curr->next!=NULL;curr=curr->next){

        if(curr->next->info.id == value){

            liste_livre* to_remove= curr->next;

            curr->next=curr->next->next;

            free(to_remove);

            return enlever_livre(root,value);
        }


    }


}


        //les tries

//tri livres

void tri_livre(liste_livre** root,int type) {

liste_livre *courant, *precedent, *temp;

int permuter = 1;

switch(type){

 case 1 :

    if (*root == NULL) {

        return;
    }



    while (permuter) {

        permuter = 0;

        courant = *root;

        precedent = NULL;

        while (courant->next != NULL) {

            if (strcmp(courant->info.titre, courant->next->info.titre) > 0) {

                temp = courant->next;

                courant->next = temp->next;

                temp->next = courant;

                if (precedent == NULL) {

                    *root = temp;

                } else {

                    precedent->next = temp;
                }

                precedent = temp;

                permuter = 1;

            } else {

                precedent = courant;

                courant = courant->next;
            }
        }
    }return;

  case 2 :

    if (*root == NULL) {

        return;

    }



    while (permuter) {

        permuter = 0;

        courant = *root;

        precedent = NULL;


        while (courant->next != NULL) {

            if (strcmp(courant->info.categorie, courant->next->info.categorie) > 0) {

                temp = courant->next;

                courant->next = temp->next;

                temp->next = courant;


                if (precedent == NULL) {

                    *root = temp;

                } else {

                    precedent->next = temp;
                }

                precedent = temp;

                permuter = 1;

            } else {

                precedent = courant;

                courant = courant->next;

            }
        }
    } return;

  case 3 :

    if (*root == NULL) {

        return;
    }



    while (permuter) {

        permuter = 0;

        courant = *root;

        precedent = NULL;


        while (courant->next != NULL) {

            if (strcmp(courant->info.auteur, courant->next->info.auteur) > 0) {

                temp = courant->next;

                courant->next = temp->next;

                temp->next = courant;


                if (precedent == NULL) {

                    *root = temp;

                } else {

                    precedent->next = temp;
                }

                precedent = temp;

                permuter = 1;

            } else {

                precedent = courant;

                courant = courant->next;
            }
        }
    } return;
  }
}

//tri des adherents

void tri_adherent(liste_adherent** root) {

    liste_adherent *courant, *precedent, *temp;

    if (*root == NULL) {

        return;
    }

    int permuter = 1;

    while (permuter) {

        permuter = 0;

        courant = *root;

        precedent = NULL;

        while (courant->next != NULL) {

            if (strcmp(courant->info.nom, courant->next->info.nom) > 0) {

                temp = courant->next;

                courant->next = temp->next;

                temp->next = courant;

                if (precedent == NULL) {

                    *root = temp;

                } else {

                    precedent->next = temp;

                }

                precedent = temp;

                permuter = 1;

            } else {

                precedent = courant;

                courant = courant->next;

            }
        }
    }
}

//search
bool search_adherent_nom(liste_adherent* root){

    char value[20];

    printf("veuillez saisir le nom d adherent : ");

    scanf("%s",&value);

    int x=0;

    for(liste_adherent* curr = root;curr!= NULL;curr=curr->next){

      if(strcmp(curr->info.nom,value)==0){

        return true;

      }

    }

    return false;
}

bool search_adherent_id(liste_adherent* root){

    int value;

    printf("veuillez saisir le num id d adherent : ");

    scanf("%d",&value);

    int x=0;

    for(liste_adherent* curr = root;curr!= NULL;curr=curr->next){

      if(curr->info.id==value){

        return true;

      }

    }

    return false;
}

bool search_livre_titre(liste_livre* root){

    char value[20];

    printf("veuillez saisir le titre de livre : ");

    scanf("%s",&value);

    int x=0;

    for(liste_livre* curr = root;curr!= NULL;curr=curr->next){

      if(strcmp(curr->info.titre,value)==0){

        return true;
      }

    }

    return false;
}

bool search_livre_id(liste_livre* root){

    int value;

    printf("veuillez saisir le id de livre : ");

    scanf("%d",&value);

    int x=0;

    for(liste_livre* curr = root;curr!= NULL;curr=curr->next){

      if(curr->info.id == value){

        return true;
      }

    }

    return false;
}

bool search_livre_auteur(liste_livre* root){

    char value[20];

    printf("veuillez saisir le nom dauteur");

    scanf("%s",&value);

    int x=0;

    for(liste_livre* curr = root;curr!= NULL;curr=curr->next){

      if(strcmp(curr->info.auteur,value)==0){

        return true;

      }

    }

    return false;
}


        //file management







void serialize_adherent(liste_adherent* root){

    FILE* list_adherent=fopen("list_adherent.txt","w");

    if(list_adherent==NULL){

        exit(1);
    }
    for(liste_adherent* curr=root;curr!=NULL;curr=curr->next){

            fprintf(list_adherent," %d, %s, %s, %s, \n",curr->info.id,curr->info.nom,curr->info.prenom,curr->info.formation);
    }
    fclose(list_adherent);
}

void serialize_emprunt(liste_emprunt* root){

    FILE* list_emprunt=fopen("liste_emprunt.txt","w");

    if(list_emprunt==NULL){


        exit(1);
    }
    for(liste_emprunt* curr=root;curr!=NULL;curr=curr->next){

           fprintf(list_emprunt," %d, %d, %s",curr->info.id_livre,curr->info.id,curr->info.date_emprunt);
    }
    fclose(list_emprunt);
}

void serialize_livre(liste_livre* root){

    FILE* list_livre=fopen("liste_livre.txt","w");

    if(list_livre==NULL){

        exit(1);
    }
    for(liste_livre* curr=root;curr!=NULL;curr=curr->next){

            fprintf(list_livre," %d, %s, %s, %s, \n",curr->info.id,curr->info.titre,curr->info.categorie,curr->info.auteur);
    }
    fclose(list_livre);
}

//**************deserialize


liste_adherent* deserialize_livre() {

    FILE* list_livre = fopen("liste_livre.txt", "r");

    if (list_livre == NULL) {
        return;
    }

    liste_livre* head = NULL;

    liste_livre* current = NULL;

    char line[200];


    while (fgets(line, sizeof(line), list_livre) != NULL) {

        char* token = strtok(line, ",");

        int id = atoi(token);

        token = strtok(NULL, ",");

        char titre[50];

        strcpy(titre, token);

        token = strtok(NULL, ",");

        char categorie[50];

        strcpy(categorie, token);

        token = strtok(NULL, ",");

        char auteur[50];

        strcpy(auteur, token);



        liste_livre* newNode = (liste_livre*)malloc(sizeof(liste_livre));

        newNode->info.id = id;

       strcpy(newNode->info.titre, titre);

       strcpy(newNode->info.categorie, categorie);

       strcpy(newNode->info.auteur, auteur);

        newNode->next = NULL;


        if (head == NULL) {

            head = newNode;

            current = newNode;

        } else {

            current->next = newNode;

            current = newNode;
        }
    }

    fclose(list_livre);

    return head;
}


//void deserialize_adherent(liste_adherent** root){
//
//
//     FILE* list_adherent=fopen("list_adherent.txt","r");
//
//    if(list_adherent==NULL){
//
//        exit(2);
//
//    }
//    adherent AD;
//
//
//    int val;
//
//    char nom[20],prenom[20],formation[20];
//
//            while(fscanf(list_adherent,"%d, %s, %s, %s,",&val,&nom,&prenom,&formation) > 0){
//
//          AD.id=val;
//
//          strcpy(AD.nom,nom);
//
//          strcpy(AD.formation,formation);
//
//          strcpy(AD.prenom,prenom);
//
//          insert_adherent(root,AD);
//
//    }
//
//    fclose(list_adherent);
//
//}

liste_adherent* deserialize_adherent() {

    FILE* list_adherent = fopen("list_adherent.txt", "r");

    if (list_adherent == NULL) {

        return;
    }

    liste_adherent* head = NULL;

    liste_adherent* current = NULL;

    char line[200];  //



    while (fgets(line, sizeof(line), list_adherent) != NULL) {



        char* token = strtok(line, ",");


        int id = atoi(token);

        token = strtok(NULL, ",");

        char nom[50];

        strcpy(nom, token);

        token = strtok(NULL, ",");

        char prenom[50];

        strcpy(prenom, token);

        token = strtok(NULL, ",");

        char formation[50];

        strcpy(formation, token);


       liste_adherent* newNode = (liste_adherent*)malloc(sizeof(liste_adherent));

        newNode->info.id = id;


        strcpy(newNode->info.nom, nom);

        strcpy(newNode->info.prenom, prenom);

        strcpy(newNode->info.formation, formation);

        newNode->next = NULL;


        // If this is the first node, set it as the head

        if (head == NULL) {

            head = newNode;

            current = newNode;
        } else {

            // Otherwise, add the new node to the end of the list

            current->next = newNode;

            current = newNode;
        }
    }

    fclose(list_adherent);

    return head;  // Return the head of the linked list
}




//void deserialize_livre(liste_livre** root){
//
//
//     FILE* list_livre=fopen("list_livre.txt","r");
//
//    if(list_livre==NULL){
//
//        exit(2);
//
//    }
//    livre AD;
//
//
//    int val;
//
//    char nom[20],prenom[20],formation[20];
//
//            while(fscanf(list_livre,"%d, %s, %s, %s,",&val,&nom,&prenom,&formation) > 0){
//
//          AD.id=val;
//
//          strcpy(AD.titre,nom);
//
//          strcpy(AD.categorie,formation);
//
//          strcpy(AD.auteur,prenom);
//
//          insert_livre(root,AD);
//
//
//    }
//
//    fclose(list_livre);
//
//}



void deserialize_emprunt(liste_emprunt** root) {

    FILE* list_emprunt = fopen("liste_emprunt.txt", "r");

    if (list_emprunt == NULL) {

       return;
    }

    char line[100];

    while (fgets(line, sizeof(line), list_emprunt)) {

        liste_emprunt* new_node = malloc(sizeof(liste_emprunt));

        new_node->next = NULL;


        char* token = strtok(line, ",");

        new_node->info.id_livre = atoi(token);


        token = strtok(NULL, ",");

        new_node->info.id = atoi(token);


        token = strtok(NULL, ",");

        strcpy(new_node->info.date_emprunt, token);

        if (*root == NULL) {

            *root = new_node;

        } else {

            liste_emprunt* curr = *root;

            while (curr->next != NULL) {

                curr = curr->next;
            }

            curr->next = new_node;
        }
    }

    fclose(list_emprunt);
}

//void deserialize_emprunt(liste_emprunt** root){
//
//
//     FILE* list_emprunt=fopen("liste_emprunt.txt","r");
//
//    if(list_emprunt==NULL){
//
//        exit(2);
//
//    }
//    emprunt AD;
//
//
//    int val;
//
//    char nom[20],prenom[20],formation[20];
//
//            while(fscanf(list_emprunt,"%d, %s,",&val,&nom) > 0){
//
//          AD.id_livre=val;
//
//          strcpy(AD.date_emprunt,nom);
//
//    }
//    fclose(list_emprunt);
//
//}


int diffPlusQue7Jours(char date1[], char date2[]) {

    struct tm tm1, tm2;


    time_t time1, time2;

    double diff;


    memset(&tm1, 0, sizeof(struct tm));

    sscanf(date1, "%*s %*s %d %d:%d:%d %d", &tm1.tm_mday, &tm1.tm_hour, &tm1.tm_min, &tm1.tm_sec, &tm1.tm_year);

    tm1.tm_year -= 1900;

    tm1.tm_mon = 0;

    time1 = mktime(&tm1);


    memset(&tm2, 0, sizeof(struct tm));

    sscanf(date2, "%*s %*s %d %d:%d:%d %d", &tm2.tm_mday, &tm2.tm_hour, &tm2.tm_min, &tm2.tm_sec, &tm2.tm_year);

    tm2.tm_year -= 1900;

    tm2.tm_mon = 0;

    time2 = mktime(&tm2);


    diff = difftime(time1, time2);


    if (diff > 7*24*3600) {

        return 1;

    } else {

        return 0;
    }
}


bool aviss(liste_livre* root){









    for(liste_livre* curr = root;curr!= NULL;curr=curr->next){

      if(curr->info.note>=5){








                               if(curr->info.note>=11){curr->info.note=6;}

                                printf("\n{ titre : %s | auteur : %s | num id %d | note : %d }\n",curr->info.titre,curr->info.auteur,curr->info.id,curr->info.note);












      }

    }

    return true;
}


bool unique_livre(liste_livre* root){

    for(liste_livre* curr = root;curr!= NULL;curr=curr->next){
            for(liste_livre* currr = root;currr!= NULL;currr=currr->next){
                    if(curr->info.id==currr->info.id){
                        return false;
                    }
            }
    }

    return true;
}




bool unique_adherent(liste_adherent* root){

    for(liste_adherent* curr = root;curr!= NULL;curr=curr->next){
            for(liste_adherent* currr = root;currr!= NULL;currr=currr->next){
                    if(curr->info.id==currr->info.id){
                        return false;
                    }
            }
    }

    return true;
}



int main(){



int id,nbr,type;

int gerer,option;

liste_adherent* Adherent=empty_adherent_list();

liste_livre* Livre=empty_livre_list();

liste_emprunt* Emprunt=empty_emprunt_list();

adherent ADherent;

livre LIvre;

emprunt EMprunt;

Adherent=deserialize_adherent();

deserialize_emprunt(&Emprunt);

Livre=deserialize_livre();


while(gerer!=0){

printf("bibliotheque universitaire !\n");

system("COLOR 0B");

printf("\n\tque voulez vous faire? , choisissez le nombre correspondant :\n");

printf("\t\t1\t: gerer les adherents\n");

printf("\t\t2\t: gerer les emprunts\n");

printf("\t\t3\t: gerer les livres\n");

printf("\t\t4\t: verifie les personnes en retards\n");

printf("\t\t0\t: quitter\n");


scanf("%d",&gerer);



switch(gerer){

    case 1:system("cls");

        system("color 0B");

        printf("bibliotheque universitaire !\n\n");

        printf("\tgerer les emprunts!");

        printf("\n\tque voulez vous faire? , choisissez le nombre correspondant :\n");

        printf("\t\t1\t: ajouter un adherent\n");

        printf("\t\t2\t: supprimer un adherent\n");

        printf("\t\t3\t: trie les adherents\n");

        printf("\t\t4\t: afficher les la liste des adherents\n");

        printf("\t\t5\t: afficher le nombre des adherents\n");

         printf("\t\t6\t: chercher un adherent\n");

        printf("\t\t9\t: retour\n");

        printf("\t\t0\t: quitter\n");


        scanf("%d",&option);switch(option){


            case 1:

                 system("cls");

                 printf("veuillez saisir le nom de nouveau adherent : ");

                 scanf("%s",&ADherent.nom);

                 printf("veuillez saisir le prenom de nouveau adherent : ");

                 scanf("%s",&ADherent.prenom);

                 printf("veuillez saisir la formation de nouveau adherent : ");

                 scanf("%s",&ADherent.formation);

                 printf("veuillez saisir le num id de nouveau adherent : ");

                 scanf("%d",&ADherent.id);


               system("cls"); printf("\n\n\tinsertion de le nouveau adherent en cours...");sleep(3);

                insert_adherent(&Adherent,ADherent);

               system("color 0A");system("cls");printf("\n\n\tinsertion termine \n\n\tclicker sur nimporte quel numero pour retourner");getch();break;



            case 2:


                 system("cls");

                 printf("veuillez saisir le num id de l adherent que vous voudrais enlever : ");

                 scanf("%d",&id);


                system("cls"); printf("\n\n\tsuppression de le nouveau adherent en cours...");sleep(3);

                enlever_adherent(&Adherent,id);

                system("color 0A");system("cls");printf("\n\n\tsuppression termine \n\n\tclicker sur nimporte quel numero pour retourner");getch();break;

            case 3:

                system("cls"); printf("\n\n\ttri de la liste des adherents en cours...");sleep(3);

                tri_adherent(&Adherent);

               system("color 0A");system("cls");printf("\n\n\ttrie termine \n\n\tclicker sur nimporte quel numero pour retourner");getch();break;

            case 4:

                system("cls"); printf("\n\n\taffichage en cours...\n");sleep(3);

                print_list_adherent(Adherent);

                getch();

               system("color 0A");system("cls");printf("\n\n\taffichage termine \n\n\tclicker sur nimporte quel numero pour retourner");getch();;break;

            case 5:

                system("cls"); printf("\n\n\tcalcule de nombre des adherents en cours...");sleep(3);

                nbr=count_element_adherent(Adherent);

               system("color 0A");system("cls");printf("\n\n\tcalcule termine le nombre des adherents est :%d \n\n\tclicker sur nimporte quel numero pour retourner",nbr);getch();;break;


                 case 6:

                 system("cls");

                 printf("voullez vous chercher d adherent avec son id ou son nom?\n\n\t\t1:\tid\n\t\t2:\tnom\n");

                 scanf("%d",&id);

                    if(id==1){

                  system("cls");

                  if(search_adherent_id(Adherent) )   {

                        printf("element existe\n");

                        }else{system("color 0A");

                       system("color 0C"); printf("element n existe\n");}

                  }else{if( search_adherent_nom(Adherent)){ printf("element existe\n");}

                        else{

                        system("color 0C"); printf("element n existe\n");}

                        }

             printf("\n\n\tclicker sur nimporte quel numero pour retourner");getch();break;

            case 9:

               break;


            case 0:

                gerer=0;break;

            default:printf("veuillez saisir le nombre correspondant a votre choix correctement\nclicker sur nimporte quel numero pour reessayer");getch();

            }break;


    case 2 :system("cls");

        system("color 0B");

        printf("bibliotheque universitaire !\n\n");

        printf("\tgerer les emprunts!");

        printf("\n\tque voulez vous faire? , choisissez le nombre correspondant :\n");

        printf("\t\t1\t: ajouter un emprunt\n");

        printf("\t\t2\t: supprimer un emprunt\n");


        printf("\t\t3\t: afficher le nombre des emprunts\n");

        printf("\t\t4\t: afficher la liste des emprunts\n");






        printf("\t\t9\t: retour\n");

        printf("\t\t0\t: quitter\n");


        scanf("%d",&option);switch(option){

            case 1:

                system("cls");

                insert_emprunt( &Emprunt,Adherent, &Livre);

               system("color 0A");system("cls");break;


            case 2:

                system("cls");

                enlever_emprunt(&Emprunt,&Adherent, &Livre);

                system("cls"); printf("\n\n\tsuppression de le nouveau emprunt en cours...");sleep(3);



               system("color 0A");system("cls");printf("\n\n\tsuppression termine \n\n\tclicker sur nimporte quel numero pour retourner");getch();break;

            case 3:

                system("cls"); printf("\n\n\tcalcule de nombre des emprunts en cours...");sleep(3);

                nbr=count_element_emprunt(Emprunt);

               system("color 0A");system("cls");printf("\n\n\tcalcule termine le nombre des emprunts est :%d \n\n\tclicker sur nimporte quel numero pour retourner",nbr);getch();;break;



            case 4:

                system("cls"); printf("\n\n\taffichage de la liste des emprunts en cours...");sleep(3);

                print_list_emprunt(Emprunt);

               system("color 0A");system("cls");printf("\n\n\taffichage termine \n\n\tclicker sur nimporte quel numero pour retourner");getch();;break;

//            case 5:
//
//                system("cls"); printf("\n\n\taffichage de la liste des emprunts en cours...");sleep(3);
//
//               system("color 0A");system("cls");printf("\n\n\taffichage termine \n\n\tclicker sur nimporte quel numero pour retourner");getch();;break;

            case 9:

                ;break;

            case 0:

                gerer=0;break;

            default:printf("veuillez saisir le nombre correspondant a votre choix correctement\nclicker sur nimporte quel button pour reessayer");getch();

            };break;

    case 3 :system("cls");

        system("color 0B");

        printf("bibliotheque universitaire !\n\n");

        printf("\tgerer les livres!");

        printf("\n\tque voulez vous faire? , choisissez le nombre correspondant :\n");

        printf("\t\t1\t: ajouter un livre\n");

        printf("\t\t2\t: supprimer un livre\n");

        printf("\t\t3\t: trie les livres\n");

        printf("\t\t4\t: afficher la liste des livres\n");

        printf("\t\t5\t: afficher le nombre des livres\n");

        printf("\t\t6\t: chercher un livre\n");

        printf("\t\t7\t: afficher  les livres avec des avis positives\n");


        printf("\t\t9\t: retour\n");

        printf("\t\t0\t: quitter\n");

        scanf("%d",&option);switch(option){

            case 1:

            system("cls");

                 printf("veuillez saisir le titre de nouveau livre : ");

                 scanf("%s",&LIvre.titre);

                 printf("veuillez saisir le nom dauteur de nouveau auteur : ");

                 scanf("%s",&LIvre.auteur);

                 printf("veuillez saisir la categorie de nouveau livre : ");

                 scanf("%s",&LIvre.categorie);

                 printf("veuillez saisir le num id de nouveau livre : ");

                 scanf("%d",&LIvre.id);

                insert_livre(&Livre,LIvre);

                system("cls"); printf("\n\n\tinsertion de le nouveau livre en cours...");sleep(3);



               system("color 0A");system("cls");printf("\n\n\tinsertion termine \n\n\tclicker sur nimporte quel numero pour retourner");getch();;break;

            case 2:

                 system("cls");

                 printf("veuillez saisir le num id de livre : ");

                 scanf("%d",&id);

                 system("cls");

                 enlever_livre(&Livre,id);

                 system("cls"); printf("\n\n\tsuppression de le nouveau livre en cours...");sleep(3);


               system("color 0A");system("cls");printf("\n\n\tsuppression termine \n\n\tclicker sur nimporte quel numero pour retourner");getch();break;

            case 3:
            do {
                 system("cls");

                 printf("veuillez saisir le type de tri\n1: tri par titre \n2: tri par categorie\n3: tri par auteur \n");

                 scanf("%d",&id);}while(id !=1 && 2!= id && id!=3);


                system("cls"); printf("\n\n\ttrie de la liste des livres en cours...");sleep(3);

                tri_livre(&Livre,id);

               system("color 0A");system("cls");printf("\n\n\ttrie termine \n\n\tclicker sur nimporte quel numero pour retourner");getch();;break;

            case 4:


            system("cls");

                printf("\n\n\taffichage de la liste des livre en cours...\n");sleep(3);



                 print_list_livre(Livre);

               system("cls");break;

            case 5:

                system("cls"); printf("\n\n\tcalcule de nombre des livres en cours...");sleep(3);

                nbr=count_element_livre(Livre);

               system("color 0A");system("cls");printf("\n\n\tcalcule termine le nombre des livres est :%d \n\n\tclicker sur nimporte quel numero pour retourner",nbr);getch();;break;


                case 6:

                 system("cls");

                 printf("voullez vous chercher le livre  avec son id ou son titre?\n\n\t\t1:\tid\n\t\t2:\tnom\n");

                 scanf("%d",&id);

                    if(id==1){

                    system("cls");

                  if(search_livre_id(Livre) )   {

                        system("color 0A");

                        printf("element existe\n");

                        }else{printf("element n existe\n");}

                  }else{if( search_livre_titre(Livre)){ printf("element existe\n");}

                        else{

                         system("color 0C");

                        printf("element n existe pas\n");}

                        }

            printf("\n\n\tclicker sur nimporte quel numero pour retourner");getch();break;


            case 7:
                        system("cls");
                        printf("en cours..");sleep(2);

                        aviss(Livre);

                        printf("\n\n\tclicker sur nimporte quel numero pour retourner");getch();
                ;break;

            case 9:

                ;break;

            case 0:

                gerer=0;break;

            default:printf("veuillez saisir le nombre correspondant a votre choix correctement\nclicker sur nimporte quel button pour reessayer");getch();

            };break;

    case 4 :
          system("cls");

          char emp[30];

          for(liste_emprunt* curr=Emprunt;curr!=NULL;curr=curr->next){

          strcpy(emp,curr->info.date_emprunt);

          char hi[30];

                time_t currentTime;

                char *currentTimeString;

                currentTime=time(NULL);

               if(currentTime == ((time_t)-1)){

                printf("impossible d'obtenir la date actuelle\n");

                break;

                }else{

            currentTimeString=ctime(&currentTime);

           if(currentTimeString==NULL){

           printf("impossible d'obtenir la date actuelle\n");

          }else{

            strcpy(hi,currentTimeString);

         }

         }

          int i = diffPlusQue7Jours(hi,emp);

          if(i==1){printf("lemprunt de num id  : %d est en retard !\n",curr->info.id);}else{printf("lemprunt de num id  : %d n est pas en retard !\n",curr->info.id);}

          }printf("\n\n\tclicker sur nimporte quel numero pour retourner");getch();
        ;break;

     case 0: gerer=0;break;

    default : printf("veuillez saisir le nombre correspondant a votre choix correctement\nclicker sur nimporte quel button pour reessayer");getch();break;

        }

system("cls");


}

serialize_adherent(Adherent);

serialize_emprunt(Emprunt);

serialize_livre(Livre);

deallocate_adhernt(&Adherent);

deallocate_emprunt(&Emprunt);

deallocate_livre(&Livre);

return 1001;}





