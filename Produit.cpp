#include "Produit.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// CONSTRUCTEURS
Produit::Produit(string nomproduit, string description, int nombre, float prix) : _nomproduit(nomproduit), _description(description), _nombre(nombre), _prix(prix) {}
Produit::Produit() {}

// GETTERS
string Produit::nomproduit() const {
    return _nomproduit; }

string Produit::description() const {
    return _description; }

int Produit::nombre() const {
    return _nombre; }

float Produit::prix() const {
    return _prix; }

// SETTERS
void Produit::setNomproduit(const string &nomproduit) {
    _nomproduit = nomproduit;
}

void Produit::setDescription(const string &description) {
    _description = description;
}

void Produit::setPrix(float prix) {
    _prix = prix;
}

//fct changement de quantité
void Produit::chgmtquantite(int nvl_quantite) {
    _nombre = nvl_quantite;
}

//affichage d'un produit
void Produit::affichproduit() {
    cout << "__________PRODUIT__________" << endl;
    cout << "Nom : " << _nomproduit << endl;
    cout << "Description : " << _description << endl;
    cout << "Nombre : " << _nombre << endl;
    cout << "Prix : " << _prix << " euros" << endl;
    cout << "____________________________" << endl;
}

//SETTER
void Produit::setNombre(int nombre) {
    _nombre = nombre;
}

// SURCHARGE OPERATEUR <<
void Produit::afficher(ostream &flux) const {
    flux << _nomproduit << endl;
    flux << _description << endl;
    flux << _nombre << endl;
    flux << _prix << endl ;
}