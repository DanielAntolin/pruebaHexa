#ifndef HEXA_H
#define HEXA_H
#include <vector>
#include <iostream>
#include <iomanip>
#include <sys/types.h>
// Constantes para caracteres especiales
static const int16_t CABECERA = 0x71A2;
// Destinatarios
 const unsigned char ALUMNO_DEST = 0x09;
 const unsigned char ESTACION_DEST = 0xFA;

// Comandos
 const int16_t HABILITAR_MOVIMIENTO = 0xFA01;


// Argumentos
 const char SIN_ARGUMENTO = 0XD9;

 // Reespuesta
 const char RES_OK = 0xF4;
  const char RES_NOK = 0xFA;
class hexa
{
public:
    hexa();
    std::vector< unsigned char>generar_mensaje(int16_t  cabecera,unsigned char destinatario, int16_t comando, unsigned char argumento);
    bool validad_respuesta(std::vector<unsigned char> array, int16_t comando);
};

#endif // HEXA_H
