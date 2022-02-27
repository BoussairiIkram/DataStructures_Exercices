// Serie1/Exercice 1 :
#include<iostream>
#include<cmath>

using namespace std;

//Declration du type complexe:

typedef struct Complexe{
	float re;
	float img;
}Complexe;

//1- Procedure Lire nombre complexe :
void LireComplexe(Complexe *c){
	cout<< "Donnez la partie réel : ";
	cin>> c->re;
	
	cout<< "Donnez la partie Imaginaire : ";
	cin >> c->img;
}

//2- Fonction Produit de deux Nombre complexe :
Complexe ProduitComplexe(Complexe a, Complexe b){
	return  {(a.re*b.re-a.img*b.img),(a.img*b.re+a.re*b.img)};
}

//3- Fonction retourne Module d'un nombre complexe :

float ModuleComplexe(Complexe c){
	return sqrt(pow(c.re,2)+pow(c.img,2));
}

//4- Fonction Afficher Nombre Complexe ai+b :
void Afficher(Complexe c){
	if(c.img!=0){
		if(c.re!=0){
			if(c.re>0) cout<< c.img << "i+"<< c.re<< endl;
			else    cout<< c.img << "i"<< c.re<< endl;
		}
		else{
			cout << c.img <<"i" <<endl;
		}
	}
	else {
		cout << c.re << endl;
	}
}



int main(){
	Complexe a,b,Produit;
	
	LireComplexe(&a);
	Afficher(a);
	cout << "Module est "<< ModuleComplexe(a) << endl;
	
	LireComplexe(&b);
	Afficher(b);
	cout << "Module est "<< ModuleComplexe(b) << endl;

	
	Produit=ProduitComplexe(a,b);
	Afficher(Produit);
	cout << "Module est "<< ModuleComplexe(Produit) << endl;

	return 0;
}
