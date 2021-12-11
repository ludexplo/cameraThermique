#pragma warning(disable : 4996)
#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <math.h>


void ScanDegre(float, int*);

using namespace std;
using namespace cv;

int main()
{
  
    FILE* pFile = new FILE;
    unsigned short* buffer;
    float degre, somme = 0, alpha, beta, numero_ligne,numero_colonne;
    size_t result, nombre_de_valeur = 160 * 120;
    int total_moyenne, tour = 0, analyse[6] = { 0,0,0,0 };
    short int i;
    int numero_de_case;
    

    

    pFile = fopen("C:/Users/henry/Desktop/programme de surveilance v1/x64/Debug/Lepton_Capture5.tiff", "rb");
    new unsigned short[160 * 120];
    buffer = (unsigned short*)malloc(160 * 120 * 2);
    nombre_de_valeur = fread(buffer, sizeof(short int), 160 * 120, pFile);

    for (i = 4; i < (160 * 120) - 1; i++)
    {




        degre = (buffer[i] - 27315) / 100;
        somme += degre;
        ScanDegre(degre, &analyse[0]);
        numero_de_case = i - 3;
        numero_ligne = (numero_de_case - 1) / 160 + 1;
        numero_colonne = (numero_de_case - 1) % 160 + 1;
        printf("\n position: colonne=%f ligne=%f", numero_colonne, numero_ligne);
        printf("     T=  %f \n ", degre);

        alpha = 180 / 3.14 * atan((60 - numero_ligne + 1) / 60 * tan(22.0 / 180 * 3.14));
        beta = 180 / 3.14 * atan((80 - numero_colonne + 1) / 80 * tan(28.5 / 180 * 3.14));
        
        printf("\n  angles: alpha=%f beta=%f  \n", alpha, beta);
        




    }
    printf("\n resultats: cas1=%d cas2=%d cas3=%d", analyse[0], analyse[1], analyse[2]);
    
    return 0;
}




void ScanDegre(float degre, int* analyse) {


    float temperature_basse = 20.0, temperature_moyenne = 25.0, temperature_haute = 35.0;
    if ((degre <= temperature_basse)) {
        analyse[0] += 1;
    }
    else if (degre > temperature_basse && degre <= temperature_haute) {
        analyse[1] += 1;
    }
    else if (degre > temperature_haute)
    {
        analyse[2] += 1;
    }


}
