#ifndef GENERADOR_ACCESOS_HPP
#define GENERADOR_ACCESOS_HPP

#include <vector>
#include <cstdint>

std::vector<uint32_t> generar_accesos_memoria(
    int numero_accesos, 
    double localidad_espacial = 0.9, 
    double localidad_temporal = 0.7);

#endif // GENERADOR_ACCESOS_HPP