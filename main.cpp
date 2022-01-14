#include "Produit.h"
#include "Magasin.h"
#include <iostream>

int main(int argc, char const *argv[]) {
    // Ajout du magasin
    Magasin magasin;

// Variable d'enclenchement de la création rapide
    bool FC = false;
    std::cout << " " << std::endl;

// Ligne de textes sympatique
    std::cout << "Initialisation du programme de Magasin..."
                 "Creation d'un nouveau Magasin...\n"
                 "\n"
                 "Bienvenue !\n"
                 "\n" << std::endl;
// Création d'un MENU
    char choice = '0';
    char choice1 = '0';
    char choice2 = '0';
    char choice3 = '0';
    char choice6 = '0';
// SI 5, ALORS FERMER LE PROGRAMME
    while (choice!='5') {
        choice = 0;
        std::cout << " " << std::endl;
        std::cout << "                               Bonjour, que voulez-vous faire?" << std::endl;
        std::cout << "                                                                                                  |---------------|" << std::endl;
        std::cout << "                                                                                                  | _- FICHIER -_ |" << std::endl;
        std::cout << "     (TEST MODE : Creation rapide de 3 CLIENTS / 4 PRODUITS / 1 COMMANDE)                         |    GESTION    |" << std::endl;
        std::cout << "                                                                                                  |      (6)      |" << std::endl;
        std::cout << "|-----------------------------------------------------------------------------------------------------------------|" << std::endl;
        std::cout << "|      _- MAGASIN -_     |   _- UTILISATEURS -_   |     _- COMMANDES -_    |   _- TEST MODE -_    |  _- SORTIE -_ |" << std::endl;
        std::cout << "| GESTION PRODUIT/CLIENT |  CREER, ESPACE CLIENT  | GESTION, ESPACE CLIENT |    CREATION RAPIDE   |     ARRET     |" << std::endl;
        std::cout << "|           (1)          |           (2)          |           (3)          |          (4)         |      (5)      |" << std::endl;
        std::cout << "|-----------------------------------------------------------------------------------------------------------------|" << std::endl;
        std::cout << std::endl;
        std::cin >> choice;
        // Forçage de la valeur à 1, 2, 3, 4 (et 5), 6
        while ((choice != '1') && (choice != '2') && (choice != '3') && (choice != '4') && (choice != '5') && (choice != '6')) {
            std::cout << " " << std::endl;
            std::cout << "                               Essayer d'entrer une vraie commande :)" << std::endl;
            std::cout << "                                                                                                  |---------------|" << std::endl;
            std::cout << "                                                                                                  | _- FICHIER -_ |" << std::endl;
            std::cout << "     (TEST MODE : Creation rapide de 3 CLIENTS / 4 PRODUITS / 1 COMMANDE)                         |    GESTION    |" << std::endl;
            std::cout << "                                                                                                  |      (6)      |" << std::endl;
            std::cout << "|-----------------------------------------------------------------------------------------------------------------|" << std::endl;
            std::cout << "|      _- MAGASIN -_     |   _- UTILISATEURS -_   |     _- COMMANDES -_    |   _- TEST MODE -_    |  _- SORTIE -_ |" << std::endl;
            std::cout << "| GESTION PRODUIT/CLIENT |  CREER, ESPACE CLIENT  | GESTION, ESPACE CLIENT |    CREATION RAPIDE   |     ARRET     |" << std::endl;
            std::cout << "|           (1)          |           (2)          |           (3)          |          (4)         |      (5)      |" << std::endl;
            std::cout << "|-----------------------------------------------------------------------------------------------------------------|" << std::endl;
            std::cout << std::endl;
            std::cin >> choice;
        }

        switch (choice){
            case '1' :
                // MAGASIN__________________________________________________________________________________________________________
                choice1 = 0;
                // SI 7, ALORS FERMER LA FENETRE
                while (choice1!='7') {
                    std::cout << std::endl;
                    std::cout << "|--------------------------------------------------------------------------|" << std::endl;
                    std::cout << "|                                _- MAGASIN -_                             |" << std::endl;
                    std::cout << "|--------------------------------------------------------------------------|" << std::endl;
                    std::cout << "|_________________PRODUIT_________________|______UTILISATEUR______|        |" << std::endl;
                    std::cout << "| AJOUTER | AFFICHER  | STOCK | SUPPRIMER | AFFICHER  | SUPPRIMER | SORTIR |" << std::endl;
                    std::cout << "|  -(1)   |   -(2)    | -(3)  |   -(4)    |   -(5)    |   -(6)    |  -(7)  |" << std::endl;
                    std::cout << "|--------------------------------------------------------------------------|" << " " << std::endl;
                    std::cin >> choice1;
                    // Forçage de la valeur à 1, 2, 3, 4, 5, 6, 7
                    while ((choice1 != '1') && (choice1 != '2') && (choice1 != '3') && (choice1 != '4') && (choice1 != '5') && (choice1 != '6') && (choice1 != '7')) {
                        std::cout << " MAUVAISE COMMANDE ! ESSAYEZ-VOUS DE CREER UN BUG ?" << std::endl;
                        std::cout << "|--------------------------------------------------------------------------|" << std::endl;
                        std::cout << "|                                _- MAGASIN -_                             |" << std::endl;
                        std::cout << "|--------------------------------------------------------------------------|" << std::endl;
                        std::cout << "|________________PRODUITS_________________|______UTILISATEURS_____|        |" << std::endl;
                        std::cout << "| AJOUTER | AFFICHER  | STOCK | SUPPRIMER | AFFICHER  | SUPPRIMER | SORTIR |" << std::endl;
                        std::cout << "|  -(1)   |   -(2)    | -(3)  |   -(4)    |   -(5)    |   -(6)    |  -(7)  |" << std::endl;
                        std::cout << "|--------------------------------------------------------------------------|" << " " << std::endl;
                        std::cin >> choice1;
                    }
                    switch (choice1) {
                        case '1' :
                            // AJOUT DE NOUVEAU(X) PRODUIT(S) DANS LE MAGASIN
                            magasin.addproduit();
                            break;
                        case '2' :
                            // AFFICHAGE DE TOUS LES PRODUITS DU MAGASIN
                            magasin.displayproduits();
                            break;
                        case '3' :
                            // CHANGEMENT DE LA QUANTITE D'UN PRODUIT
                            magasin.changement_quantite();
                            break;
                        case '4' :
                            // SUPPRIMER UN PRODUIT
                            magasin.supprimer_produit();
                            break;
                        case '5' :
                            // AFFICHER LES UTILISATEURS
                            magasin.displayclients();
                            break;
                        case '6' :
                            // SUPPRIMER UN CLIENT
                            magasin.supprimer_client();
                            break;
                        default:
                            std::cout << " " << std::endl;
                    }
                }
                break;
            case '2' :
                // UTILISATEURS_________________________________________________________________________________________________________________________________
                choice2 = 0;
                // SI 4, ALORS FERMER LA FENETRE
                while (choice2!='7') {
                    std::cout << std::endl;
                    std::cout << "|--------------------------------------------------------------------------------------------------------------|" << std::endl;
                    std::cout << "|                                                 _- UTILISATEURS -_                                           |" << std::endl;
                    std::cout << "|--------------------------------------------------------------------------------------------------------------|" << std::endl;
                    std::cout << "|              |_____________________________________ESPACE CLIENT____________________________________|        |" << std::endl;
                    std::cout << "|              |                |____________________________DANS LE PANIER___________________________|        |" << std::endl;
                    std::cout << "| CREER CLIENT | AFFICHER INFOS | AJOUTER UN PRODUIT | CHANGER LE NOMBRE | ENLEVER UN PRODUIT | VIDER | SORTIR |" << std::endl;
                    std::cout << "|     -(1)     |      -(2)      |        -(3)        |       -(4)        |        -(5)        | -(6)  |  -(7)  |" << std::endl;
                    std::cout << "|              |                |_____________________________________________________________________|        |" << std::endl;
                    std::cout << "|              |______________________________________________________________________________________|        |" << std::endl;
                    std::cout << "|--------------------------------------------------------------------------------------------------------------|" << " " << std::endl;
                    std::cin >> choice2;
                    // Forçage de la valeur à 1, 2, 3 (et 4)
                    while ((choice2 != '1') && (choice2 != '2') && (choice2 != '3') && (choice2 != '4') && (choice2 != '5') && (choice2 != '6') && (choice2 != '7')) {
                        std::cout << " MAUVAISE COMMANDE ! ARRETEZ D'ESSAYER DE CREER UN BUG SVP" << std::endl;
                        std::cout << "|--------------------------------------------------------------------------------------------------------------|" << std::endl;
                        std::cout << "|                                                 _- UTILISATEURS -_                                           |" << std::endl;
                        std::cout << "|--------------------------------------------------------------------------------------------------------------|" << std::endl;
                        std::cout << "|              |_____________________________________ESPACE CLIENT____________________________________|        |" << std::endl;
                        std::cout << "|              |                |____________________________DANS LE PANIER___________________________|        |" << std::endl;
                        std::cout << "| CREER CLIENT | AFFICHER INFOS | AJOUTER UN PRODUIT | CHANGER LE NOMBRE | ENLEVER UN PRODUIT | VIDER | SORTIR |" << std::endl;
                        std::cout << "|     -(1)     |      -(2)      |        -(3)        |       -(4)        |        -(5)        | -(6)  |  -(7)  |" << std::endl;
                        std::cout << "|              |                |_____________________________________________________________________|        |" << std::endl;
                        std::cout << "|              |______________________________________________________________________________________|        |" << std::endl;
                        std::cout << "|--------------------------------------------------------------------------------------------------------------|" << " " << std::endl;
                        std::cin >> choice2;
                    }
                    switch (choice2) {
                        case '1' :
                            // CREATION DE CLIENT
                            magasin.addclient();
                            break;
                        case '2' :
                            // AFFICHER LES INFOS DU CLIENT
                            magasin.afficher_client_avec_nom_id();
                            break;
                        case '3' :
                            // AJOUTER UN PRODUIT DANS LE PANIER DU CLIENT
                            magasin.ajout_produit_client();
                            break;
                        case '4' :
                            // CHANGER LE NOMBRE D'UN PRODUIT DANS LE PANIER DU CLIENT
                            magasin.changer_nombre_produit_client();
                            break;
                        case '5' :
                            // ENLEVER UN PRODUIT DANS LE PANIER DU CLIENT
                            magasin.supprimer_produit_client();
                            break;
                        case '6' :
                            // VIDER LE PANIER DU CLIENT
                            magasin.vider_panier_client();
                            break;
                        default:
                            std::cout << " " << std::endl;
                    }
                }
                break;
            case '3' :
                // COMMANDES______________________________________________________________________________________________________
                choice3 = 0;
                // SI 4, ALORS FERMER LA FENETRE
                while (choice3!='7') {
                    std::cout << std::endl;
                    std::cout << "|---------------------------------------------------------------------------|" << std::endl;
                    std::cout << "|                               _- COMMANDES -_                             |" << std::endl;
                    std::cout << "|---------------------------------------------------------------------------|" << std::endl;
                    std::cout << "|_________ESPACE CLIENT_________|_____________GESTION______________|        |" << std::endl;
                    std::cout << "| CREER UNE COMMANDE | AFFICHER |  VALIDER LIVRAISON  |  AFFICHER  | SORTIR |" << std::endl;
                    std::cout << "|        -(1)        |   -(2)   |        -(3)         |    -(4)    |  -(7)  |" << std::endl;
                    std::cout << "|---------------------------------------------------------------------------|" << " " << std::endl;
                    std::cin >> choice3;
                    // Forçage de la valeur à 1, 2, 3 (et 4)
                    while ((choice3 != '1') && (choice3 != '2') && (choice3 != '3') && (choice3 != '4') && (choice3 != '7')) {
                        std::cout << " Votre commande la, elle est pas bonne.. vous avez choisi de m'enerver ?" << std::endl;
                        std::cout << "|---------------------------------------------------------------------------|" << std::endl;
                        std::cout << "|                               _- COMMANDES -_                             |" << std::endl;
                        std::cout << "|---------------------------------------------------------------------------|" << std::endl;
                        std::cout << "|_________ESPACE CLIENT_________|_____________GESTION______________|        |" << std::endl;
                        std::cout << "| CREER UNE COMMANDE | AFFICHER |  VALIDER LIVRAISON  |  AFFICHER  | SORTIR |" << std::endl;
                        std::cout << "|        -(1)        |   -(2)   |        -(3)         |    -(4)    |  -(7)  |" << std::endl;
                        std::cout << "|---------------------------------------------------------------------------|" << " " << std::endl;
                        std::cin >> choice3;
                    }
                    switch (choice3) {
                        case '1' :
                            // PASSER UNE COMMANDE EN TANT QUE CLIENT
                            magasin.addcommande();
                            break;
                        case '2' :
                            // AFFICHER LA COMMANDE D'UN CLIENT
                            magasin.displaycommandes_client();
                            break;
                        case '3' :
                            // VALIDER UNE LIVRAISON EN CHANGEANT SON STATUT
                            magasin.changement_statut_commande();
                            break;
                        case '4' :
                            // AFFICHER TOUTES LES COMMANDES
                            magasin.displaycommandes();
                            break;
                        default:
                            std::cout << " " << std::endl;
                    }
                }
                break;
            case '4' :
                // TEST MODE____________________________________________________________________________________________________
                // Création rapide de 4 PRODUITS / 3 CLIENTS / 1 COMMANDE
                if (FC){
                    std::cout << "TEST MODE DEJA UTILISE !" << std::endl;
                }
                else {
                    // CREATION rapide de plusieurs utilisateurs, produits et commandes
                    std::cout << "CREATION RAPIDE DE : 3 UTILISATEURS / 4 PRODUITS / 1 COMMANDE" << std::endl;

                    //CREATION DE 4 PRODUITS
                    Produit p1("PS5", "Console de jeux videos, c'est pas bien les jeux videos", 2, 750);
                    Produit p2("Eponge", "Pratique pour poser sa regle en metal lors d'un cours", 1, 2);
                    Produit p3("Bombe", "..de peinture acrylique evidement, ils ont oublie la suite dans le nom..", 14, 5);
                    Produit p4("Pain", "Du bon pain craquant, fondant, delicieux, et.. ok j'en fait trop", 0, 1);
                    magasin.ajout_produit_mag_ext(p1);
                    magasin.ajout_produit_mag_ext(p2);
                    magasin.ajout_produit_mag_ext(p3);
                    magasin.ajout_produit_mag_ext(p4);
                    magasin.displayproduits();

                    // CREATION DE 3 UTILISATEURS
                    Client c1("SARU", "Saruman", "LE GRAND");
                    vector<Produit> panier;
                    panier.push_back(p2);
                    panier.push_back(p1);
                    Client c2("FRO", "Frodon", "SACQUET");
                    c2.setPanier(panier);
                    Client c3("LEGO", "Legolas", "VERTEFEUILLE");
                    magasin.ajout_client_mag_ext(c1);
                    magasin.ajout_client_mag_ext(c2);
                    magasin.ajout_client_mag_ext(c3);
                    magasin.displayclients();

                    // CREATION DE 1 COMMANDE
                    vector<Produit> liste_produit;
                    liste_produit.push_back(p1);
                    liste_produit.push_back(p2);
                    liste_produit.push_back(p3);
                    Commande co(c1, liste_produit, false);
                    magasin.ajout_commande_mag_ext(co);
                    magasin.displaycommandes();

                    std::cout << " " << std::endl;
                    std::cout << "CREATION RAPIDE DE : 3 UTILISATEURS / 4 PRODUITS / 1 COMMANDE" << std::endl;
                    std::cout << " " << std::endl;
                    FC = true;
                }
                break;
            case '6' :
                choice6 = 0;
                // FICHIER__________________________________________________________________________________________________________
                choice6 = 0;
                // SI 7, ALORS FERMER LA FENETRE
                while (choice6!='7') {
                    cout << endl << "(1) : SUPPRIME toutes les donnees actuelles du magasin et les remplace par celles dans les fichiers dans 'Fichiers' " << endl;
                    cout << "(2) : Enregistre toutes les donnes actuelles du magasin dans les fichiers dans 'Fichiers' en ecrasant les anciens" << endl;
                    std::cout << std::endl;
                    std::cout << "|-------------------------------|" << std::endl;
                    std::cout << "|         _- FICHIER -_         |" << std::endl;
                    std::cout << "|-------------------------------|" << std::endl;
                    std::cout << "|  LIRE  | ENREGISTRER | SORTIR |" << std::endl;
                    std::cout << "|  -(1)  |    -(2)     |  -(7)  |" << std::endl;
                    std::cout << "|-------------------------------|" << " " << std::endl;
                    std::cin >> choice6;
                    // Forçage de la valeur à 1, 2 et 7
                    while ((choice6 != '1') && (choice6 != '2') && (choice6 != '7')) {
                        std::cout << " MAUVAISE COMMANDE ! ESSAYEZ-VOUS DE CREER UN BUG ?" << std::endl;
                        cout << endl << "(1) : Supprime toutes les donnees actuelles du magasin et les remplace par celles dans les fichiers dans 'Fichiers' " << endl;
                        cout << "(2) : Enregistre toutes les donnes actuelles du magasin dans les fichiers dans 'Fichiers' en ecrasant les anciens" << endl;
                        std::cout << std::endl;
                        std::cout << "|-------------------------------|" << std::endl;
                        std::cout << "|         _- FICHIER -_         |" << std::endl;
                        std::cout << "|-------------------------------|" << std::endl;
                        std::cout << "|  LIRE  | ENREGISTRER | SORTIR |" << std::endl;
                        std::cout << "|  -(1)  |    -(2)     |  -(7)  |" << std::endl;
                        std::cout << "|-------------------------------|" << " " << std::endl;
                        std::cin >> choice6;
                    }
                    switch (choice6) {
                        case '1' :
                            // Supprime toutes les donnees actuelles du magasin et les remplace par celles dans les fichiers dans 'Fichiers'
                            magasin.lire_fichier();
                            break;
                        case '2' :
                            // Enregistre toutes les donnes actuelles du magasin dans les fichiers dans 'Fichiers' en ecrasant les anciens
                            magasin.enregisrer_fichier();
                            break;
                        default:
                            std::cout << " " << std::endl;
                    }
                }
                break;
            default:
                std::cout << " " << std::endl;
        }
    }
    return 0;
}