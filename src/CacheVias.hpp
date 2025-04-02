#ifndef CACHE_VIAS_HPP
#define CACHE_VIAS_HPP

#include "CacheBase.hpp"
#include <list>
#include <unordered_map>

class CacheAsociativoVias : public CacheBase {
private:
    int vias;
    int numero_conjuntos;
    std::vector<std::list<uint32_t>> conjuntos;
    std::unordered_map<uint32_t, std::list<uint32_t>::iterator> mapa_etiquetas;
    
public:
    CacheAsociativoVias(int tamano_cache, int tamano_bloque, int vias, bool mostrar_accesos = false);
    void acceder(uint32_t direccion) override;
};

#endif // CACHE_ASOCIATIVO_VIAS_HPP