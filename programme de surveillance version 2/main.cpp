#pragma warning(disable : 4996)
#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <math.h>

#include "ScanDegre.h"

using namespace std;
using namespace cv;

int main()
{

// FICHIER

    remove("C:/Users/henry/Desktop/programme de surveillance version 2/x64/Debug/Lepton_Capture.tiff");
    FILE* pFile = new FILE;
    unsigned short* buffer;
    float degre, somme = 0, alpha, beta;
    size_t result, nombre_de_valeur = 160 * 120;
    int total_moyenne, tour = 0, analyse[6] = { 0,0,0,0 };
    short int i;
    int numero_de_case;
    int numero_ligne;
    int numero_colonne;

    
   
// VIDEO

    VideoCapture cap;
    Mat frame(160,120,CV_16U), new_frame(160,120,CV_16U);
    cap.open(0);
    int deviceID = 0;             // 0 = ouverture de  la caméra par défaut 
    int apiID = CAP_ANY;      // 0 = détection de l'API par défaut
    // ouvrir la caméra à l'aide de l'Api sélectionnée
    cap.open(deviceID, apiID);
    vector<int> compression_params;
    compression_params.push_back(IMWRITE_TIFF_COMPRESSION);
    compression_params.push_back(0);
    // vérifier si la caméra est bien ouvert
    if (!cap.isOpened()) {
        cerr << "Erreur! impobossible d'ouvrir la caméracamera\n";
        return -1;
    }


    for (;;)
    {
        // en attente d'une 'frame' pour la stocker et pouvoir la lire
        cap.read(frame);
        //vérifier c'est cela a fonctionner
        if (frame.empty()) {
            cerr << "ERREUR frame non lue! \n";
            break;
        }


        //redimensionner la fenêtre pour la résolution de la caméra
        resizeWindow("Display frame", 160, 120);
        //montrer en direct la fenêtre en direct avec une clé d'attente 
        imshow("Display frame", frame);

        if (waitKey(5) >= 0)
            break;



    }

    

    while (0)
    {
        cap.read(frame);

        imshow("Display frame", frame);
        waitKey(10);
    }

   imwrite("C:/Users/henry/Desktop/programme de surveillance version 2/x64/Debug/Lepton_Capture.tiff", frame, compression_params);
    pFile = fopen("C:/Users/henry/Desktop/programme de surveillance version 2/x64/Debug/Lepton_Capture.tiff", "rb");
    new unsigned short[160 * 120];
    buffer = (unsigned short*)malloc(160 * 120 * 2);
    nombre_de_valeur = fread(buffer, sizeof(short int), 160 * 120, pFile);

    scan Scantemperature;

    for (i = 4; i < (160 * 120) -1; i++)
    {

        degre = (buffer[i] - 27315) / 100;
        somme += degre;
        Scantemperature.ScanDegre(degre, &analyse[0]);
        numero_de_case = i-3;
        numero_ligne = (numero_de_case-1) / 160 + 1;
         numero_colonne =  (numero_de_case-1) % 160 + 1;
         printf("\n position: colonne=%d ligne=%d", numero_colonne, numero_ligne);
         printf("     T=  %f \n ", degre);

         alpha = 180 / 3.14 * atan((60 - numero_ligne + 1) / 60 * tan(22.0 / 180 * 3.14));
         beta = 180 / 3.14 * atan((80 - numero_colonne + 1) / 80 * tan(28.5 / 180 * 3.14));
         printf("\n  angles: alpha=%f beta=%f \n", alpha, beta);

    }
    printf("\n résultats: cas1=%d cas2=%d cas3=%d", analyse[0], analyse[1], analyse[2]);
  
   
    return 0;
}