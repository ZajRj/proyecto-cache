#include "Simulador.hpp"
#include "CacheMapeoDirecto.hpp"
#include "CacheVias.hpp"
#include <iostream>
#include <utility>
#include <memory>

void comparar_caches(const std::vector<uint32_t>& direcciones, bool mostrar_detalles) {
    std::vector<std::pair<std::string, std::unique_ptr<CacheBase>>> caches;
    
  

    caches.emplace_back("Mapeo Directo (8KB)", std::make_unique<CacheMapeoDirecto>(8 * 1024, 64, mostrar_detalles));
        
    caches.emplace_back("4-vías (4KB)", std::make_unique<CacheAsociativoVias>(4 * 1024, 64, 4, mostrar_detalles));
    
    
    for (auto& [nombre, cache] : caches) {
        std::cout << "\nProbando: " << nombre << std::endl;

        static uint32_t ultima_dir = 0;
        
        for (uint32_t dir : direcciones) {
            cache->acceder(dir);
            

            if (abs((int)(dir - ultima_dir)) <= 64) {
                cache->precarga_espacial(dir,1);
            }
            ultima_dir = dir;
        }
        
        cache->imprimir_estadisticas();
    }
}