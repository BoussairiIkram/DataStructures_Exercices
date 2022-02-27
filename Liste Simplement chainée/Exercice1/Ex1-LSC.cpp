#include<iostream>

using namespace std;

typedef struct List{
	int Data;
	struct List *Next;
}List;

List* InsererFin(List *Tete, int x){
	List *New= new List,*ptr=Tete;
	
	New->Data=x;
	New->Next=NULL;
	
	if(Tete==NULL) return New;
	
	while(ptr->Next!=NULL){
		ptr=ptr->Next;
	}
	
	ptr->Next=New;
	
	return Tete;	
}

List* InsererPlusieurFin(List *Tete){
	int N,el;
	
	cout << "Entrer le nombre d'element que vous voulez à inserer : " ;
	cin>> N;
	
	for(int i=0;i<N;i++){
		cout<< "Entrer le Numbre " << i+1 << ": " ;
		cin >> el;
		Tete=InsererFin(Tete,el);
	}
	
	return Tete;
}

List* InsererTete(List *Tete,int x){
	List *New= new List;
	
	New->Data=x;
	New->Next=Tete;
	
	return New;
}

List* InsererPlusierTete(List *Tete){
	int N,el;
	
	cout << "Entrer le nombre d'element que vous voulez à inserer : " ;
	cin>> N;
	
	for(int i=0;i<N;i++){
		cout<< "Entrer le Numbre " << i+1 << ": " ;
		cin >> el;
		Tete=InsererTete(Tete,el);
	}
	
	return Tete;
}

List* SupprimerFin(List *Tete){
	List *ptr=Tete;
	
	if(Tete==NULL) return Tete;
	if(Tete->Next==NULL)  
	{
	  delete Tete; 
	  return NULL;	
	}
	
	
	while(ptr->Next->Next != NULL){
		ptr=ptr->Next; 
	}


	delete ptr->Next;
	
	ptr->Next =NULL;
	
	return Tete;
}

List* SupprimerDebut(List *Tete){
	List *ptr=Tete->Next;
	
	if(Tete==NULL) return Tete;
	
	delete Tete;
	
	return ptr;
	
}

List* SupprimerPremierEl(List *Tete, int el){
	List *ptr=Tete,*Temp;
	
	if(Tete==NULL) return Tete;
	if(Tete->Data == el) {
		return SupprimerDebut(Tete);
	}
	
	while(ptr->Next!=NULL && ptr->Next->Data!=el ){
		ptr=ptr->Next;
	}
	
	if(ptr->Next==NULL) return Tete;
	
	Temp=ptr->Next;
	ptr->Next=Temp->Next;
	
	delete Temp;
	
	return Tete;
	
}

List* SupprimerOccEl(List *Tete, int el){
	List *ptr=Tete,*Temp;
	
	while(ptr!=NULL){
		if(Tete->Data==el)
		{  Tete=SupprimerDebut(Tete);
		   ptr=Tete;
			 } 	
		else if(ptr->Next!=NULL && ptr->Next->Data==el){
			Temp=ptr->Next;
			ptr->Next=Temp->Next;
		
			delete Temp;	
		}
		else{
		  	ptr=ptr->Next;	
		}
	}
	
	return Tete;
	
}

List* TrierList(List *Tete){
	List *ptr1=Tete,*ptr2=Tete->Next;
	int Temp;
	
	while(ptr1!=NULL){
	  ptr2=ptr1->Next;
	  while(ptr2!=NULL){
	  	if(ptr1->Data > ptr2->Data){
			Temp=ptr1->Data;
			ptr1->Data=ptr2->Data;
			ptr2->Data=Temp;
		}
		ptr2=ptr2->Next;	  	   	
	}
	ptr1=ptr1->Next;	
		
}
	
	return Tete;
}

void Afficher(List *Tete){
    List *ptr=Tete;
    
	while(ptr!=NULL){
		cout<< ptr->Data << "->";
		
		ptr=ptr->Next;
	}
	
	cout << "NULL\n" ;
}







int main(){
	List *Tete=NULL;
	
 	Afficher(Tete);
 	
 	//1- l'ajout :
 	
 	//Inserer à la fin :
	Tete=InsererFin(Tete,-12);
	Afficher(Tete);
	// Inserer Plusieur à la fin :
	Tete=InsererPlusieurFin(Tete,-12);
	Afficher(Tete);
	//Inserer au debut :
	Tete=InsererTete(Tete,-12);
	Afficher(Tete);
	//Inserer Plusier au debut :
	Tete=InsererPlusierTete(Tete);
	Afficher(Tete);
	
	//Supprimer un element ç la fin de la liste :
	Tete=SupprimerFin(Tete);
	Afficher(Tete);
	
	//2- La suppression :
	
	// Sypprimer element au debut de la liste :
	Tete=SupprimerDebut(Tete);
	Afficher(Tete);	
	//Supprimer Un element donnée :
	Tete=SupprimerPremierEl(Tete,12);
	Afficher(Tete);
	// Supprimer les occurence d'un element donnée :
	Tete= SupprimerOccEl(Tete,12);
	Afficher(Tete);
	
	// 3- Triage :
	
	// Trier la liste :
	Tete=TrierList(Tete);
	Afficher(Tete);
	
	
	return 0;
}
