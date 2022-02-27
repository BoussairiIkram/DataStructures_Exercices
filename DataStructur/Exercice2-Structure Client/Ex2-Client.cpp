#include<iostream>
using namespace std;

typedef struct Date{
	int jour,mois,annee;
}Date;

typedef struct Client{
	char Nom[31];
	char Compte[25];
	float Solde;
	Date D;
}sc;

//3- La fonction Afficher client :
void afficher_Client(sc p){
	cout << "Nom : "<< p.Nom <<"\n"<< "Compte : "<< p.Compte <<"\n"<< "Solde: "<< p.Solde <<"\n"<< "Date : " <<p.D.jour <<"-" <<p.D.mois<< "-"<<p.D.annee<<"\n"<<endl;
}

//4 La fonction Jeune_Client :
sc Jeune_Client(sc A, sc B){
	if(A.D.annee < B.D.annee) return B;
	else if(A.D.annee > B.D.annee) return A;
	else{
		if(A.D.mois < B.D.mois) return B;
		else if(A.D.mois > B.D.mois) return A;
		else{
			if(A.D.jour < B.D.jour) return B;
			else return A;
		}
	}
}


//5- Fonction mise à jour client :
void Mise_Ajour_Client(sc *A,float NvSolde){
	A->Solde= NvSolde;	
}

//Test :
int main(){
	sc A={"Ikram","AA023",99900.121,{10,12,2001}};
	sc B={"Hamza","BJ758",91232.9,{25,03,2000}};
	sc jeune;
	
   afficher_Client(A);
   afficher_Client(B);
   
   jeune=Jeune_Client(A,B);
   afficher_Client(jeune);
   
   Mise_Ajour_Client(&A,999990);
   afficher_Client(A);
   
	return 0;
}
