#ifndef CACHE_MAPEO_DIRECTO_HPP
#define CACHE_MAPEO_DIRECTO_HPP

#include "CacheBase.hpp"
#include <vector>

class CacheMapeoDirecto : public CacheBase {
private:
    std::vector<uint32_t> etiquetas;
    
public:
    CacheMapeoDirecto(int tamano_cache, int tamano_bloque, bool mostrar_accesos = false);
    void acceder(uint32_t direccion) override;
};

#endif // CACHE_MAPEO_DIRECTO_HPP