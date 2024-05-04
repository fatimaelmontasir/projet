#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Product {
    int id;
    char name[100];
    char descr[100];
    char username[50];
    float prix;
    int quantity;
    int seuil;
    char entree[20];
    char sorti[20];
    struct Product *precedent;
    struct Product *suivant;
} Product;
//Initialisation d'une liste vide
Product *Initialisation(void){
	Product *e;
	e=(Product*)malloc(sizeof(Product));
	e->precedent=e;
	e->suivant=e;
	return e;	
}
void Menu(){        // affichage du menu
	    printf("MENU DE GESTION DES LIVRE\n");
	  	printf("1) Afficher tout les livers\n");
	  	printf("2) tri prix");
	  	printf("3) modificationproduit\n ");
	  	printf("4) Supprimer pa idr\n");
	  	printf("5) tri par nom\n");
	  	printf("6) rechercherProduitParUtilisateur\n ");
	  	printf("7) rechercherProduitParnom\n ");
	  	printf("8) Quitter le programme \n");
	}
Product * AjoutDebut(Product *liste, int id, char *name, char *descr, char *username, float prix, int quantity, int seuil, char *entree, char *sorti){
	Product *e;
	e=(Product*)malloc(sizeof(Product));
	 if (e != NULL) {
    e->id = id;
    strcpy(e->name, name);
    strcpy(e->descr, descr);
    strcpy(e->username, username);
    e->prix = prix;
    e->quantity = quantity;
    e->seuil = seuil;
    strcpy(e->entree, entree);
    strcpy(e->sorti, sorti);}
    e->precedent = NULL;
    e->suivant = NULL;
	e->precedent=liste;
	e->suivant=liste->suivant;
	liste->suivant->precedent=e;
	liste->suivant=e;
		return liste;
}
Product * SupprimerParId(Product *liste, int id) {
    Product *p = liste->suivant; // Commence par le premier élément
    while (p != liste) {
        if (p->id == id) {
            // Retire le produit de la liste
            p->precedent->suivant = p->suivant;
            p->suivant->precedent = p->precedent;
            free(p);
            printf("Le produit avec l'ID %d a été supprimé.\n", id);
            return liste;
        }
        p = p->suivant;
    }
    printf("Le produit avec l'ID %d n'a pas été trouvé dans la liste.\n", id);
    return liste;
}
Product *rechercherProduitParNom(Product *liste, char *nom) {
    Product *p = liste->suivant;
    while (p != liste) {
        if (strcmp(p->name, nom) == 0) {
            return p;
        }
        p = p->suivant;
    }
    return NULL;
}

// Fonction pour rechercher un produit par nom d'utilisateur
Product *rechercherProduitParUtilisateur(Product *liste, char *username) {
    Product *p = liste->suivant;
    while (p != liste) {
        if (strcmp(p->username, username) == 0) {
            return p;
        }
        p = p->suivant;
    }
    return NULL;
}
//if (fichier != NULL) {
//fseek(fichier, 0, SEEK_SET); // Déplacer le curseur au début du fichier
//fprintf(fichier, "%s %s %d\n", "Durand", "Paul", 35); // Modification des données
//fclose(fichier);
//printf("Données modifiées avec succès dans le fichier.\n");
//} else {
//printf("Erreur lors de l'ouverture du fichier pour la modification.\n");
//return 1;
//}
Product* ModifierProduit(Product *liste) {
    int id;
    printf("Saisissez l'ID du produit que vous souhaitez modifier : ");
    scanf("%d", &id);
//if (fptr != NULL) {
//	fseek(fptr, 0, SEEK_SET);
    Product *p = liste->suivant;
    while (p != liste) {
        if (p->id == id) {
            printf("Nouveau nom du produit : ");
            scanf("%s", p->name);

            printf("Nouvelle description du produit : ");
            scanf("%s", p->descr);

            printf("Nouveau prix du produit : ");
            scanf("%f", &p->prix);

            printf("Nouvelle quantité en stock du produit : ");
            scanf("%d", &p->quantity);

            printf("Nouveau seuil d'alerte du produit : ");
            scanf("%d", &p->seuil);

            printf("Nouvelle date de dernière entrée du produit : ");
            scanf("%s", p->entree);

            printf("Nouvelle date de dernière sortie du produit : ");
            scanf("%s", p->sorti);
//	fprintf(fptr,"\t%f\t%d\t%d\n",p->prix,p->seuil,p->quantity);
//	fprintf(fptr,"%s\t%s\t%s\n",p->name,p->descr,p->username);
//	fprintf(fptr,"%s\t%s\n",p->entree,p->sorti);
            return liste;
        }
        p = p->suivant;
    }
    printf("Produit avec l'ID %d non trouvé.\n", id);
    return liste;
}

// Fonction pour trier la liste par nom
Product* TriParNom(Product *liste) {
    Product *p = liste->suivant;
    while (p->suivant != liste) {
        Product *p2 = p->suivant;
        while (p2 != liste) {
            if (strcmp(p->name, p2->name) > 0) {
                // Échanger les données des produits
                int tempId = p->id;
                p->id = p2->id;
                p2->id = tempId;

                char tempName[100];
                strcpy(tempName, p->name);
                strcpy(p->name, p2->name);
                strcpy(p2->name, tempName);

                char tempDescr[100];
                strcpy(tempDescr, p->descr);
                strcpy(p->descr, p2->descr);
                strcpy(p2->descr, tempDescr);

                char tempUsername[50];
                strcpy(tempUsername, p->username);
                strcpy(p->username, p2->username);
                strcpy(p2->username, tempUsername);

                float tempPrix = p->prix;
                p->prix = p2->prix;
                p2->prix = tempPrix;

                int tempQuantity = p->quantity;
                p->quantity = p2->quantity;
                p2->quantity = tempQuantity;

                int tempSeuil = p->seuil;
                p->seuil = p2->seuil;
                p2->seuil = tempSeuil;

                char tempEntree[20];
                strcpy(tempEntree, p->entree);
                strcpy(p->entree, p2->entree);
                strcpy(p2->entree, tempEntree);

                char tempSorti[20];
                strcpy(tempSorti, p->sorti);
                strcpy(p->sorti, p2->sorti);
                strcpy(p2->sorti, tempSorti);
            }
            p2 = p2->suivant;
        }
        p = p->suivant;
    }
    return liste;
}

// Fonction pour trier la liste par prix unitaire
Product* TriParPrix(Product *liste) {
    Product *p = liste->suivant;
    while (p->suivant != liste) {
        Product *p2 = p->suivant;
        while (p2 != liste) {
            if (p->prix > p2->prix) {
                // Échanger les données des produits
                int tempId = p->id;
                p->id = p2->id;
                p2->id = tempId;

                char tempName[100];
                strcpy(tempName, p->name);
                strcpy(p->name, p2->name);
                strcpy(p2->name, tempName);

                char tempDescr[100];
                strcpy(tempDescr, p->descr);
                strcpy(p->descr, p2->descr);
                strcpy(p2->descr, tempDescr);

                char tempUsername[50];
                strcpy(tempUsername, p->username);
                strcpy(p->username, p2->username);
                strcpy(p2->username, tempUsername);

                float tempPrix = p->prix;
                p->prix = p2->prix;
                p2->prix = tempPrix;

                int tempQuantity = p->quantity;
                p->quantity = p2->quantity;
                p2->quantity = tempQuantity;

                int tempSeuil = p->seuil;
                p->seuil = p2->seuil;
                p2->seuil = tempSeuil;

                char tempEntree[20];
                strcpy(tempEntree, p->entree);
                strcpy(p->entree, p2->entree);
                strcpy(p2->entree, tempEntree);

                char tempSorti[20];
                strcpy(tempSorti, p->sorti);
                strcpy(p->sorti, p2->sorti);
                strcpy(p2->sorti, tempSorti);
            }
            p2 = p2->suivant;
        }
        p = p->suivant;
    }
    return liste;
}


void Affichage(Product* liste){
	Product *p=liste->precedent;
	printf("\n Affichage a l'envers:\n");
	while(p!=liste){
		 printf("%d\t%s\t%s\t%s\t%.2f\t%d\t%d\t%s\t%s\n", p->id, p->name, p->descr, p->username, p->prix, p->quantity, p->seuil, p->entree, p->sorti);
		p=p->precedent;
	}
}
main(){
	Product *liste=Initialisation();
	char username[30];
	char user[30];
	FILE *fptr;
	char nom1[30];
	int id, quantity, seuil;
    float prix;
    char name[100], descr[100], entree[20], sorti[20];
	int i, n;
	int id1,choix;
    printf("Veuillez saisir votre nom d'utilisateur : ");
    scanf("%s",username);
	
	printf("donner nomber de produit");scanf("%d",&n);
	
	fptr = fopen("projet.txt","w");
	for(i=0;i<n;i++){
		printf("Saisissez l'Id': ");
        scanf("%d", &id);
         printf("Veuillez saisir votre nom d'utilisateur : ");
         scanf("%s",username);
		 printf("Saisissez le nom du produit : ");
        scanf("%s",name);

        printf("Saisissez la description du produit : ");
        scanf("%s",descr);

        printf("Saisissez le prix du produit : ");
        scanf("%f",&prix);

        printf("Saisissez la quantité en stock du produit : ");
        scanf("%d",&quantity);

        printf("Saisissez le seuil d'alerte du produit : ");
        scanf("%d",&seuil);

        printf("Saisissez la date de dernière entrée du produit : ");
        scanf("%s",entree);

        printf("Saisissez la date de dernière sortie du produit : ");
        scanf("%s",sorti);

        liste=AjoutDebut(liste, id, name, descr, username, prix, quantity, seuil, entree, sorti);
    
     	
     	
	if(fptr!=NULL){
	fprintf(fptr,"%d\t%f\t%d\t%d\n",id,prix,seuil,quantity);
	fprintf(fptr,"%s\t%s\t%s\n",name,descr,username);
	fprintf(fptr,"%s\t%s\n",entree,sorti);
	}	}
printf("Quel est votre choix : ") ;
	  			scanf("%d",&choix); 
	do{
	 	   Menu(); 
	sortie:	  
			    switch(choix){ //appel des fonction
			    	case 1:Affichage(liste);;break;
		    		case 2:TriParPrix(liste);break;
			    	case 3:ModifierProduit(liste);break;
			    	case 4:
			    		printf("donner id");
			    		scanf("%d",&id1)
			    	SupprimerParId(liste, id1) ;break
			    	case 5:TriParNom(liste);break; 
				   	case 6: printf("Veuillez saisir votre nom d'utilisateur : ");
                            scanf("%s",user);   
					    rechercherProduitParUtilisateur(liste, user);break;
		    		case 7: printf("Veuillez saisir votre nom d'utilisateur : ");
    					scanf("%s",nom1);
					rechercherProduitParNom(liste, nom1) break;
					case 8:printf("Vous avez quiter le programme");break;
			    
				   default :printf("choix invalide");goto sortie;
				}
		}while(choix!=8);
			fclose(fptr);

			return 0;}
	
	
	
 // Recherche par nom
   /* char rechercheNom[100];
    printf("\nEntrez le nom du produit à rechercher : ");
    scanf("%s", rechercheNom);
    Product *produitNom = rechercherProduitParNom(liste, rechercheNom);
    if (produitNom != NULL) {
        printf("Produit trouvé :\n");
        printf("%d\t%s\t%s\t%s\t%.2f\t%d\t%d\t%s\t%s\n", produitNom->id, produitNom->name, produitNom->descr, produitNom->username, produitNom->prix, produitNom->quantity, produitNom->seuil, produitNom->entree, produitNom->sorti);
    } else {
        printf("Le produit avec le nom '%s' n'a pas été trouvé.\n", rechercheNom);
    }

    // Recherche par nom d'utilisateur
    char rechercheUtilisateur[50];
    printf("\nEntrez le nom d'utilisateur à rechercher : ");
    scanf("%s", rechercheUtilisateur);
    Product *produitUtilisateur = rechercherProduitParUtilisateur(liste, rechercheUtilisateur);
    if (produitUtilisateur != NULL) {
        printf("Produit trouvé :\n");
        printf("%d\t%s\t%s\t%s\t%.2f\t%d\t%d\t%s\t%s\n", produitUtilisateur->id, produitUtilisateur->name, produitUtilisateur->descr, produitUtilisateur->username, produitUtilisateur->prix, produitUtilisateur->quantity, produitUtilisateur->seuil, produitUtilisateur->entree, produitUtilisateur->sorti);
    } else {
        printf("Aucun produit trouvé pour l'utilisateur '%s'.\n", rechercheUtilisateur);
    }*/

