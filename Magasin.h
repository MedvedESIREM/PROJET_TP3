#ifndef C___TP2_MAGASIN_H
#define C___TP2_MAGASIN_H

#include <iostream>
#include <string>
#include <vector>
#include "Produit.h"
#include "Client.h"
#include "Commande.h"

using namespace std;

class Magasin {
public:

    // TEST SURCHARGE
    void test_surcharge();

    Magasin();

    // GETTERS
    const vector<Produit> &getProduit() const;

    //NOUVEAU PRODUIT
    void addproduit();

    //AFFICHAGE DE TOUS LES PRODUITS
    void displayproduits();

    //PUSH BACK PRODUIT
    void ajout_produit_mag_ext(Produit anciensproduits);

    //PUSH BACK CLIENT
    void ajout_client_mag_ext(Client nv_client);

    //PUSH BACK COMMANDE
    void ajout_commande_mag_ext(Commande nvl_commande);

    //METHODE DEMANDE DU NOM
    void demande_nom_produit();

    //METHODE CHGMT STOCK SUIVANT NOM
    void changement_quantite();

    //METHODE SUPPRESSION PRODUIT SUIVANT NOM
    void supprimer_produit();

    //METHODE SUPPRESSION CLIENT SUIVANT NOM
    void supprimer_client();

    //__________________ Q4 + Q5 ______________________________

    //METHODE AJOUT PRODUIT SUIVANT CLIENT
    void ajout_produit_client();

    // CHANGER LE NOMBRE DE PRODUIT DANS PANIER DE CLIENT
    void changer_nombre_produit_client();

    //METHODE VIDER LE PANIER DANS CLIENT
    void vider_panier_client();

    // MODIFIER LA QUANTITE D'UN PRODUIT DANS PANIER DE CLIENT
    void modif_stock_produit_client();

    // SUPPRIMER UN PRODUIT DANS PANIER DE CLIENT
    void supprimer_produit_client();

    //METHODE ADD CLIENT
    void addclient();

    //AFFICHAGE DE TOUS LES CLIENTS
    void displayclients();

    //METHODE AFFICHAGE D'UN CLIENT A PARTIR DE NOM OU ID
    void afficher_client_avec_nom_id();

    //__________________ Q7 ______________________________

    // METHODE ADD COMMANDE
    void addcommande();

    //AFFICHAGE DE TOUS LES CLIENTS
    void displaycommandes();

    //METHODE AFFICHAGE DE TOUTES LES COMMANDES D'UN CLIENT
    void displaycommandes_client();

    //METHODE CHANGEMENT DU STATUT D'UNE COMMANDE
    void changement_statut_commande();

    //__________________ Q8 ______________________________

    // ENREGISTRER LES INFORMATIONS DANS UN FICHIER (FLUX)
    void enregisrer_fichier();

    // LIRE LES INFORMATIONS DANS UN FICHIER (FLUX)
    void lire_fichier();

private:
    vector<Produit> _produit;
    vector<Client> _client;
    vector<Commande> _commande;

};

#endif //C___TP2_MAGASIN_H
