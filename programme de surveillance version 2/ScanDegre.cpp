#include "ScanDegre.h"


scan::scan() {}

void scan::ScanDegre(float degre, int* analyse) {

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