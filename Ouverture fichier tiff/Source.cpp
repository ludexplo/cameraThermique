#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream  fichier("C:/Users/henry/Desktop/Ouverture fichier tiff/Lepton_Capture5.tiff");

    if (fichier)

    {
        //L'ouverture s'est bien passée, on peut donc lire

        string ligne; //Une variable pour stocker les lignes lues

        while (getline(fichier, ligne)) //Tant qu'on n'est pas à la fin, on lit
        {
            cout << ligne << endl;
            //Et on l'affiche dans la console
           
        }

    }
    else
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
    }

    return 0;
};