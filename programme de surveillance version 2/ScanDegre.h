#pragma once
#ifndef SCANDEGRE_H
#define SCANDEGRE_H

enum reponse_cas { dessous, dedans, dessus };
enum reponse_niveau {normal, chaud, tres_chaud, trop_chaud, alerte_incendie};

class scan
{

	public:
		//reponse_cas test_temp(temp);
		scan();
		void ScanDegre(float, int*);

};

#endif // !SCANDEGRE_H

