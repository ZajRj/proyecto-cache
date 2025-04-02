#include "CacheMapeoDirecto.hpp"
#include <iostream>

CacheMapeoDirecto::CacheMapeoDirecto(int tamano_cache, int tamano_bloque, bool mostrar_accesos) :
    CacheBase(tamano_cache, tamano_bloque, mostrar_accesos),
    etiquetas(numero_bloques, -1) {}

void CacheMapeoDirecto::acceder(uint32_t direccion) {
    
    uint32_t direccion_bloque = direccion / tamano_bloque;
    uint32_t indice = direccion_bloque % numero_bloques;
    uint32_t etiqueta = direccion_bloque / numero_bloques;
    
    if (mostrar_accesos) {
        std::cout << "Acceso a dirección: " << direccion 
                 << " (Bloque: " << direccion_bloque 
                 << ", Índice: " << indice 
                 << ", Etiqueta: " << etiqueta << ") - ";
    }
    
    if (etiquetas[indice] == etiqueta) {
        aciertos++;
        if (mostrar_accesos) std::cout << "Acierto!" << std::endl;
    } else {
        fallos++;
        etiquetas[indice] = etiqueta;
        if (mostrar_accesos) std::cout << "Fallo! (Etiqueta anterior: " << etiquetas[indice] << ")" << std::endl;
    }
}