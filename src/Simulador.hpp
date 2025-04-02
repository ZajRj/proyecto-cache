#ifndef SIMULADOR_HPP
#define SIMULADOR_HPP

#include "CacheBase.hpp"
#include <vector>
#include <memory>
#include <string>

void comparar_caches(
    const std::vector<uint32_t>& direcciones, 
    bool mostrar_detalles = false);

#endif // SIMULADOR_HPP
