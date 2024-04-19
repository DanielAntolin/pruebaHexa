#include "hexa.h"

std::vector< unsigned char> hexa::generar_mensaje(int16_t cabecera,unsigned char destinatario, int16_t comando, unsigned char argumento) {
    std::vector<unsigned char> mensaje;
    unsigned char cabecera1 = (cabecera >> 8) & 0xFF;
    unsigned char cabecera2 = cabecera & 0xFF;


    mensaje.push_back(cabecera1);
    mensaje.push_back(cabecera2);
    mensaje.push_back(destinatario);

    unsigned char comando1 = (comando >> 8) & 0xFF;
    unsigned char comando2 = comando & 0xFF;
    mensaje.push_back(comando1);
    mensaje.push_back(comando2);
    mensaje.push_back(argumento);


    for (int i = 0;i<mensaje.size();i++) {
        int d = mensaje[i];
        std::cout << std::hex << d;
    }

    return mensaje;
}
bool hexa::validad_respuesta(std::vector<unsigned char> array, int16_t comando){
    unsigned char cabecera1 = array[0];
    unsigned char cabecer2 = array[1];
    int16_t resultado = (cabecera1 << 8) | cabecer2;
    std::cout<< "Recibido: "<<resultado;
    if(resultado != CABECERA){
         std::cout<< "error 1 ";
        return false;
    }
    unsigned char destinatario = array[2];
    if(destinatario != ALUMNO_DEST){
        std::cout<< "error 2";
        return false;
    }
    unsigned char comandoRecibido = array[3];
    if(comandoRecibido != comando ){
        std::cout<< "error 2 ";
        return false;
    }
    unsigned char respuesta = array[4];
    if(respuesta != RES_OK){
        std::cout<< "error 3 ";
        return false;
    }

    return true;
}


hexa::hexa() {

}
