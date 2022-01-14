#include "Client.h"
#include <iostream>
#include <string>
#include <vector>
#include "Produit.h"

using namespace std;

// CONSTRUCTEUR
Client::Client(const string &id, const string &prenom, const string &nom) :_id(id), _prenom(prenom), _nom(nom) {}
Client::Client() {}

// GETTERS
string Client::id() const {
    return _id; }

string Client::nom() const {
    return _nom; }

string Client::prenom() const {
    return _prenom; }

vector<Produit> Client::panier() const {
    return _panier; }

// SETTER
void Client::setPanier(const vector<Produit> &panier) {
    _panier = panier;
}

void Client::setId(const string &id) {
    _id = id;
}

void Client::setPrenom(const string &prenom) {
    _prenom = prenom;
}

// VIDER PANIER DU CLIENT
void Client::vider_panier(){
    _panier.clear();
}

void Client::setNom(const string &nom) {
    _nom = nom;
}

// SURCHARGE OPERATEUR <<
void Client::afficher(ostream &flux) const {
    flux << _id << endl;
    flux <<  _prenom << endl;
    flux <<  _nom << endl;
    if (_panier.empty()){
        flux << "VIDE" << endl ;
    }
    else{
        flux << "PANIER" << endl;
        for (auto i = _panier.begin(); i != _panier.end(); ++i){
            (*i).afficher(flux);
        }
    }
    // CHANGE : PERMETTRA PLUS TARD A AVOIR UNE TRANSITION ENTRE CHAQUE CLIENT
    flux << "CHANGE" << endl;
}

//affichage d'un client
void Client::affichclient() {
    cout << "_____________CLIENT_____________" << endl;
    cout << "ID: " << _id << endl;
    cout << "Prenom : " << _prenom << endl;
    cout << "Nom: " << _nom << endl;
    cout << "Panier : ";
    if (_panier.empty())
        cout << "VIDE" << endl;
    else{
        cout << endl;
        for (auto i = _panier.begin(); i != _panier.end(); ++i)
            (*i).affichproduit();
    }
    cout << "________________________________" << endl;
}

// CHANGER LE NOMBRE D'UN PRODUIT DANS PANIER
void Client::modif_stock_produit_dans_client(vector <Produit> v) {
    affichclient();
    bool test_nom = false; // TEST DE VALIDITE DE PRODUIT
    string nomproduit;
    cout << endl << "De quel produit voulez-vous changer la quantite ?" << endl;
    getline(cin, nomproduit);
    getline(cin, nomproduit);
    for (auto j = _panier.begin(); j != _panier.end(); ++j)
        if (nomproduit == (*j).nomproduit()){
            test_nom = true;
            cout << "Quelle est la nouvelle quantite ?" << endl;
            bool test_quant = false;
            while (!test_quant) {
                int nv_quantite;
                cin >> nv_quantite;
                for (auto k = v.begin(); k!= v.end(); ++k)
                if (nomproduit == (*k).nomproduit())
                    if (nv_quantite <= (*k).nombre() && nv_quantite > 0){
                    (*j).chgmtquantite(nv_quantite);
                    cout << "Il y a maitenant " << (*k).nombre() << " " << (*k).nomproduit() << " dans votre panier ! Felicitations "<< endl;
                    test_quant = true;
                    }
                else{
                    cout << "Mais ca va pas ou quoi ? Il n'y a que " << (*k).nombre() << " " << (*k).nomproduit() << " en reserve ! "<< endl;
                    cout << "On se calme et on choisis une autre valeur :" << endl;
                }
            }
        }
    // SI LE PRODUIT N'EST PAS DANS LE PANIER
    if (!test_nom)
        cout << "Le produit n'est pas dans votre panier, retour au menu" << endl;
}

// SUPPRIMER UN PRODUIT DANS PANIER DE CLIENT
void Client::supprimer_produit_dans_client() {
    string nomproduit;
    cout << "Bonjour " << _id << " !" << endl;
    // SI LE PANIER EST VIDE
    if (_panier.empty())
        cout << "Il n'y a pas d'article dans votre panier, ahahah... qu'il est rigolo.." << endl;
    else {
    cout << endl << "quel produit cherchez vous dans votre panier ? On va le retirer !" << endl;
    getline(cin, nomproduit); //getline fainéant
    getline(cin, nomproduit); //getline qui veut fonctionner
    for (auto j = _panier.begin(); j != _panier.end(); ++j)
        if (nomproduit == (*j).nomproduit()){
            cout << "Suppression de " << nomproduit << " !" << endl;
            _panier.erase(j);
            --j;
        }
        }
}

// AJOUT D'UN PRODUIT DANS PANIER DE CLIENT
bool produit_existant_panier = false;
void Client::ajout_produit(string nomproduit, Produit nv_produit) {
    for (auto j = _panier.begin(); j != _panier.end(); ++j){
        if (nomproduit == (*j).nomproduit()){
            (*j).chgmtquantite((*j).nombre() + 1);
            cout << "Etant donne que " << nomproduit << " est deja dans votre panier, il y en a maintenant 1 de plus !" << endl;
            produit_existant_panier = true;
        }
    }
    if (!produit_existant_panier) {
        _panier.push_back(nv_produit);
        cout << "Ajout de " << nomproduit << " dans votre panier !" << endl;
        for (auto j = _panier.begin(); j != _panier.end(); ++j) {
            if (nomproduit == (*j).nomproduit()) {
                (*j).chgmtquantite(1);
            }
        }
    }
}

// VALIDER UNE COMMANDE STOCK
bool Client::valider_commande_stock(vector <Produit> v) {
    bool test_stock = true; // TEST SI LE STOCK EN MAGASIN EST SUFFISANT
    for (auto j = _panier.begin(); j != _panier.end(); ++j) {
        for (auto k = v.begin(); k != v.end(); ++k){
            if ((*j).nomproduit() == (*k).nomproduit()){
                // SI LE STOCK N'EST PAS SUFFISANT
                if ((*j).nombre() > (*k).nombre()){
                    cout << "Le produit " << (*k).nomproduit() << " a un stock de " << (*k).nombre() << " en magasin !" << endl;
                    cout << "Vous en demandez " << (*j).nombre() << " ! C'est trop, la commande ne peut etre valide..." << endl;
                    cout << endl;
                    test_stock = false;
                }
            }
        }
    }
return test_stock;
}

