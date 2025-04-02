#include "CacheVias.hpp"
#include <algorithm>
#include <iostream>

CacheAsociativoVias::CacheAsociativoVias(int tamano_cache, int tamano_bloque, int vias, bool mostrar_accesos) :
    CacheBase(tamano_cache, tamano_bloque, mostrar_accesos),
    vias(vias),
    numero_conjuntos(numero_bloques / vias),
    conjuntos(numero_conjuntos) {}

void CacheAsociativoVias::acceder(uint32_t direccion) {

    uint32_t direccion_bloque = direccion / tamano_bloque;

    uint32_t indice_conjunto = direccion_bloque % numero_conjuntos;
    
    uint32_t etiqueta = direccion_bloque / numero_conjuntos;
    
    if (mostrar_accesos) {
        std::cout << "Acceso a dirección: " << direccion 
                 << " (Bloque: " << direccion_bloque 
                 << ", Conjunto: " << indice_conjunto 
                 << ", Etiqueta: " << etiqueta << ") - ";
    }
    
    auto& conjunto = conjuntos[indice_conjunto];
    auto it = std::find(conjunto.begin(), conjunto.end(), etiqueta);
    
    if (it != conjunto.end()) {
        conjunto.erase(it);
        conjunto.push_front(etiqueta);
        aciertos++;
        if (mostrar_accesos) std::cout << "Acierto!" << std::endl;
    } else {
        fallos++;
        if (mostrar_accesos) std::cout << "Fallo!";
        
        if (conjunto.size() == vias) {
            uint32_t etiqueta_lru = conjunto.back();
            conjunto.pop_back();
            mapa_etiquetas.erase(etiqueta_lru);
            if (mostrar_accesos) std::cout << " Reemplazando etiqueta " << etiqueta_lru;
        }
        
        conjunto.push_front(etiqueta);
        if (mostrar_accesos) std::cout << std::endl;
    }
    
    mapa_etiquetas[etiqueta] = conjunto.begin();
}