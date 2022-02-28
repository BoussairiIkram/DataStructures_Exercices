#include<iostream>
#include<cstring>

using namespace std;

//1- Declaration de la structure :
struct noeud{
	char Data;
	struct noeud *Next;
};

//2- Redefinition de type struct noeaud: 
typedef struct noeud car;

//3-Fonction ajoute un caractere à la fin :
car* AjouterEnFin(car *T, char x){
	car *New= new car, *ptr=T;
	
	New->Data=x;
	New->Next=NULL;
	
	if(T==NULL) return New;
	
	while(ptr->Next!=NULL){
		ptr=ptr->Next;
	}
	
	ptr->Next=New;
	
	return T;
}

//4- Fonction ajoute un caractere au debut :
car* AjoutEnTete(car *T, char x){
	car *New= new car;
	
	New->Data=x;
	New->Next=T;
	
	return New;
}

//5- Fonction compte le nombre d'element de la liste :
int Longueur(car *T){
	car *ptr=T;
	int i(0);
	
	while(ptr!=NULL){
		ptr=ptr->Next;
		i++;
	}
	
	return i;
}

//6-Fonction convertie une chaine de caractere X en une liste chaine:
car* ConvertChaineToListeChainee(char X[]){
	car *New=NULL;
	int LgChaine= strlen(X);
	
	for(int i=0;i<LgChaine;i++){
		New = AjouterEnFin(New,X[i]);
	}
	
	return New;	
}

//7-Fonction convertie une list chainee T en une chaine de caractére :
char* ConvertListeChaineeTochaine(car *T){
	car *ptr=T;
	const int LgList=Longueur(T);
	char *X= new char[LgList+1];
	
	for(int i=0;i<LgList;i++){
		X[i]=ptr->Data;
		ptr=ptr->Next;
	}
	
	return X;
}

//8- Fonction return l'inverse une chaine T :
car* InverseListeChainee(car *T){
	 car *New=NULL,*ptr=T;
	 
	 while(ptr!=NULL){
	 	New= AjoutEnTete(New,ptr->Data);
	 	ptr=ptr->Next;
	 }
	 
	 return New;
}

//9- Fonction verifie l'existence d'un element :
bool Exist(car *T, char x){
	car *ptr=T;
	
	while(ptr!=NULL){
		if(ptr->Data==x) return true;
		ptr=ptr->Next;
	}
	
	return false;
}

//10- Fonction met en minuscule les alphabet
void Minuscule_ListChainee(car *T){
	car *ptr=T;
	
	while(ptr!=NULL){
		if(ptr->Data<='z' && ptr->Data>='a') ptr->Data-='a'-'A';
		//ptr->data = (char)((int)ptr->data - 32);
		ptr=ptr->Next;
	}
}

//11- Fonction compare deux liste chainee :
//Solusion 1:
bool Mth1_ComparerListeChaineeOrdreRespecte(car *A, car *B){
	car *ptrA=A,*ptrB=B;
	
	if(Longueur(A)!=Longueur(B)) return false;
	
	while(ptrA!=NULL){
		if(ptrA->Data!= ptrB->Data) return false;
		ptrA=ptrA->Next;
		ptrB=ptrB->Next;
	}
	
	return true;
}
//Solution 2:
bool Mth2_ComparerListeChaineeOrdreRespecte(car *A, car *B){
	
	if(strcmp(ConvertListeChaineeTochaine(A),ConvertListeChaineeTochaine(B))==0) return true;
	
      return false;
}

//12- Fonction compare deux liste chainee differente ordre :
bool ComparerListesChaineesOrdreQuelcoque(car *A, car *B){
	car *ptrA=A;
	
	if(Longueur(A)!=Longueur(B)) return false;
	
	while(ptrA!=NULL){
		if(!Exist(B,ptrA->Data)) return false;
		ptrA=ptrA->Next;
	}
	
	return true;
}

void AfficherList(car *T){
	car *ptr=T;
	
	while(ptr!=NULL){
		cout << ptr->Data << " -> " ;
		
		ptr=ptr->Next;
	}
	
	cout<< "NULL\n";
}

//Test :
int main(){
	 car *c=NULL,*T=NULL;
	 char Chaine[15]="Hello world";

	
	AfficherList(c);
	cout<< "Longeur = "<< Longueur(c)<< endl;
	
	c=AjouterEnFin(c,'o');	
	c=AjouterEnFin(c,'k');
	AfficherList(c);
	
	c=AjoutEnTete(c,'o');
	c=AjoutEnTete(c,'l');
	AfficherList(c);
	
	cout<< "Longeur = "<< Longueur(c)<< endl;

    T= ConvertChaineToListeChainee(Chaine);
    AfficherList(T);
    
    
	char *Chaine2= new char[Longueur(c)+1];
	Chaine2=ConvertListeChaineeTochaine(c);
    cout << Chaine2 << endl;
    
    car *Inverse=InverseListeChainee(c);
    AfficherList(Inverse);
    
   if(Exist(c,'o')) cout << "O Exist dans le mot LOOK Exist\n" ;
   else cout << "O n'exist pas dans le mot LOOK Exist\n";
   
   if(Exist(c,'M')) "M exist dans le mot LOOK Exist\n" ;
   else cout << "M n'exist pas dans le mot LOOK Exist\n";
	
    Minuscule_ListChainee(c);
    AfficherList(c);
    
    if(Mth1_ComparerListeChaineeOrdreRespecte(c,T)) cout << "Les deux liste sont identique\n";
    else cout << "Les deux liste sont differentes\n";
    
    if(Mth2_ComparerListeChaineeOrdreRespecte(c,c)) cout << "Les deux liste sont identique\n";
    else cout << "Les deux liste sont differentes\n";
    
   
     Minuscule_ListChainee(Inverse);
    
     
     if(ComparerListesChaineesOrdreQuelcoque(c,Inverse)) cout << "Les deux liste ont les meme alphabets mais de differente ordre\n";
    else cout << "Les deux liste n'ont pas les meme alphabets\n";
    
   
	
	
	
	
	return 0;
}


