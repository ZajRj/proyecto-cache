#include "CacheBase.hpp"
#include <iostream>

CacheBase::CacheBase(int tamano_cache, int tamano_bloque, bool mostrar_accesos) :
    aciertos(0), fallos(0),
    tamano_cache(tamano_cache),
    tamano_bloque(tamano_bloque),
    numero_bloques(tamano_cache / tamano_bloque),
    mostrar_accesos(mostrar_accesos) {}

void CacheBase::imprimir_estadisticas() const {
    std::cout << "\nEstadísticas finales:" << std::endl;
    std::cout << "Aciertos: " << aciertos << " (" << get_tasa_aciertos() << "%)" << std::endl;
    std::cout << "Fallos: " << fallos << " (" << (100.0f - get_tasa_aciertos()) << "%)" << std::endl;
}

void CacheBase::precarga_espacial(uint32_t direccion, int distancia_precarga) {
    for (int i = 1; i <= distancia_precarga; ++i) {
        acceder(direccion + i * tamano_bloque);
    }
}