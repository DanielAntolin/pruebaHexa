#include <iostream>
#include "hexa.h"

using namespace std;

int main()
{
    hexa preuba ;
    std::vector<unsigned char> array = preuba.generar_mensaje(CABECERA,ESTACION_DEST,HABILITAR_MOVIMIENTO,SIN_ARGUMENTO);
    if(preuba.validad_respuesta(array,HABILITAR_MOVIMIENTO)){
        std::cout<<"Todo bien";
    }
    else{
        std::cout<<"Todo mal";
    }
}
