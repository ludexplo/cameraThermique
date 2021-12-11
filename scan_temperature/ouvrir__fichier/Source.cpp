/* Lire un fichier et afficher la température du fichier */
#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#define TAILLE_BUF 4 /* valeur quelconque (en général, beaucoup plus grande) */


void ScanDegre(float, int*);

int main() {
	FILE* pFile;
	unsigned short* buffer;
	size_t result;
	short int i, nombre_de_valeur = TAILLE_BUF;
	float degre, somme=0;
	int total_moyenne, tour = 0, analyse[6] = { 0,0,0,0 };
	
	
	pFile = fopen("C:/Users/henry/Desktop/scan_temperature/ouvrir__fichier/x64/Debug/Lepton_Capture5.tiff","rb");
	if (pFile == NULL) { fputs("Fichier introuvable", stderr); exit(1); }

	//taille du fichier:
	fseek(pFile, 0,SEEK_END);
	int lSize = ftell(pFile);
	rewind(pFile);

	// allocation de la mémoire pour contenir le fichier entier:
	buffer = (unsigned short*)malloc(sizeof(char) * lSize);
	if (buffer == NULL) { fputs("Memory error", stderr); exit(2); } 

	// copie du fichier dans le buffer:
	result = fread(buffer, 1, lSize, pFile);
	if (result != lSize) { fputs("erreur de lecture", stderr); exit(3); }

	/* le fichier est maintenant chargé dans la mémoire tampon. */
	
	
	for (i = 4; i < 160*120; i++)
	{
		nombre_de_valeur = fread(buffer, sizeof(short int), TAILLE_BUF, pFile);
	;

		degre = (buffer[i] - 27315)/100;
		somme += degre;
		ScanDegre(degre, &analyse[0]);
		

	}


	printf("%d ", analyse[0]);
	printf("%d ", analyse[1]);
	printf("%d ", analyse[2]);
	printf("%d ", analyse[3]);
	printf("%d ", analyse[4]);
	// sont-ils regroupés?
 
	

	fclose(pFile);
	free(buffer);

	return 0;
}

void ScanDegre(float degre, int*analyse) {
	

	if ((degre <= 40)) {
		printf("tout va bien\n");
		//cas 1
	}
	else if (degre >= 41 && degre <= 50) {
		printf("echauffement suspect\n");
		//cas 2
	}
	else if (degre >=100)
	{
		printf("alerte incendie\n");
		//cas 3
	}

	// compter le nombre de 'pixel' > 30°  > 40 > 50  > 60  > 70 
	if (degre >= 30 && degre <=40)
	{
		analyse[0] += 1;
	}
	if (degre >= 40 && degre <=50)
	{
		analyse[1] += 1;
	}
	if (degre >= 50 && degre <=60)
	{
		analyse[2] += 1;
	}
	if (degre >= 60 && degre <=70)
	{
		analyse[3] += 1;
	}
	if (degre >= 70)
	{
		analyse[4] += 1;
	}
	printf("%f degre\n ", degre);

}