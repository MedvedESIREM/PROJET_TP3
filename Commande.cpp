#include <iostream>
#include <string>
#include "Commande.h"
using namespace std;

// CONSTRUCTEUR
Commande::Commande(const Client &client, const vector<Produit> &l_produit, bool livree) : _client(client),
                                                                                        _l_produit(l_produit),
                                                                                        _livree(livree) {}
Commande::Commande() {}

// GETTERS
const Client &Commande::client() const {
    return _client; }

const std::vector<Produit> &Commande::l_produit() const {
    return _l_produit; }

bool Commande::livree() const {
    return _livree; }

// SETTER
void Commande::setLivree(bool livree) {
    _livree = livree;
}

void Commande::setClient(const Client &client) {
    _client = client;
}

void Commande::setLProduit(const vector<Produit> &lProduit) {
    _l_produit = lProduit;
}


// SURCHARGE OPERATEUR <<
void Commande::afficher(ostream &flux) const {
    _client.afficher(flux);
    for (auto i = _l_produit.begin(); i != _l_produit.end(); ++i)
        (*i).afficher(flux);
    if (_livree)
        flux << "LIVREE" << endl;
    else
        flux << "NON LIVREE" << endl;
}

//affichage d'une commande
void Commande::affichcommande() {
    cout << endl << "_________________COMMANDE_________________" << endl;
    cout  << "-CLIENT : " << endl;
    _client.affichclient();
    cout << "-PRODUIT(S) : " << endl;
    for (auto i = _l_produit.begin(); i != _l_produit.end(); ++i)
        (*i).affichproduit();
    cout << "-STATUT : ";
    if (_livree)
        cout << "LIVREE" << endl;
    else
        cout << "NON LIVREE" << endl;
    cout << "__________________________________________" << endl;
}


