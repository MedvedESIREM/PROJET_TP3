#ifndef C___TP2_CLIENT_H
#define C___TP2_CLIENT_H

#include <ostream>
#include <string>
#include <vector>
#include "Produit.h"
using namespace std;

class Client {

public:
    // CONSTRUCTEUR
    Client(const string &id, const string &prenom, const string &nom);
    Client();

    // GETTERS
    string id() const;
    string prenom() const;
    string nom() const;
    vector<Produit> panier() const;

    // SETTER
    void setPanier(const vector<Produit> &panier);
    void setId(const string &id);
    void setPrenom(const string &prenom);
    void setNom(const string &nom);

    // SURCHARGE OPERATOR <<
    void afficher(std::ostream &flux) const;

    // CHANGER LE NOMBRE D'UN PRODUIT DANS PANIER
    void modif_stock_produit_dans_client(vector <Produit> v);

    // VIDER PANIER DU CLIENT
    void vider_panier();

    //affichage d'un client
    void affichclient();

    // MODIFIER LA QUANTITE D'UN PRODUIT DANS PANIER DE CLIENT
    void ajout_produit(string nomproduit, Produit nv_produit);

    // SUPPRIMER UN PRODUIT DANS PANIER DE CLIENT
    void supprimer_produit_dans_client();

    // VALIDER UNE COMMANDE STOCK
    bool valider_commande_stock(vector <Produit> v);

        private:
    string _id;
    string _prenom;
    string _nom;
    vector<Produit> _panier;

};

#endif //C___TP2_CLIENT_H
