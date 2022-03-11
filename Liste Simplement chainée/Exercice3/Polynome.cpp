#include<stdio.h>
#include<stdlib.h>

typedef struct Monome{
	int deg;
	float coef;
}Monome;

typedef struct Polynome{
	Monome Data;
	struct Polynome *Next;
}Polynome;

//Polynome* CreationP(){
//	return (Polynome*) malloc(sizeof(Polynome));
//}

void AfficherPolynome(Polynome *Tete){
	Polynome *ptr=Tete;
	
	while(ptr!=NULL){
		printf("%3.f x^%d + ",ptr->Data.coef,ptr->Data.deg);
		ptr=ptr->Next;
	}
	
	printf(" -> NULL\n");
}

Polynome* InsertionMonome(Polynome *Tete, int deg, float coef){
	Polynome *New= (Polynome*) malloc(sizeof(Polynome));
	Polynome *ptr=Tete;
//Nouveau Monome :	
	New->Data.coef=coef;
	New->Data.deg=deg;
//Cas d'une liste vide :
	if(Tete==NULL) {
		New->Next=NULL;
		return New;
	} 
// Cas que deg de tete > deg à inserer:
    if(Tete->Data.deg > deg){
    	New->Next=Tete;
    	return New;
	}
	else if(Tete->Data.deg == deg){
		Tete->Data.coef+=coef;
		return Tete;
	}
// les autres cas :	
//Etape 1 :  chercher le plus grand element < deg :	
	while(ptr->Next!=NULL && ptr->Next->Data.deg < deg){
		ptr=ptr->Next;
	}
//Etape 2 : Distaction des cas :
// 1er cas : deg à ajouter et le plus grand dans a liste :	
	if(ptr->Next==NULL){
		ptr->Next=New;
		New->Next=NULL;
	}
// 2eme cas : Si les deg sont egaux :
	else if(ptr->Next->Data.deg == deg){
		ptr->Next->Data.coef+=coef;
	}
// 3eme cas : Si la plus grand deg dans la liste < deg à ajouter :
	else{
	New->Next=ptr->Next;
	ptr->Next=New;	}

//Faire appel à la fonction qui supprime les monomes qui on un coeff egale à 0.
		return Tete;
      
}

int main(){
	Polynome *P=NULL;

	AfficherPolynome(P);
	
	P=InsertionMonome(P,5,3);
	P=InsertionMonome(P,8,2);
	P=InsertionMonome(P,7,12);
	P=InsertionMonome(P,6,3);
	P=InsertionMonome(P,9,3);
	P=InsertionMonome(P,1,3);
	P=InsertionMonome(P,3,3);
	P=InsertionMonome(P,1,3);
	P=InsertionMonome(P,9,3);
	P=InsertionMonome(P,7,-13);
	P=InsertionMonome(P,2,3);
	P=InsertionMonome(P,0,3);
	P=InsertionMonome(P,2,3);
	P=InsertionMonome(P,0,13);

	AfficherPolynome(P);
				
	return 0;
}
