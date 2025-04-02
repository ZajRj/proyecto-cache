#ifndef CACHE_BASE_HPP
#define CACHE_BASE_HPP

#include <cstdint>
#include <vector>

class CacheBase {
protected:
    int aciertos;
    int fallos;
    int tamano_cache;    // en bytes
    int tamano_bloque;   // en bytes
    int numero_bloques;
    bool mostrar_accesos;
    
public:
    CacheBase(int tamano_cache, int tamano_bloque, bool mostrar_accesos = false);
    
    virtual ~CacheBase() = default;
    
    virtual void acceder(uint32_t direccion) = 0;

    virtual void imprimir_estadisticas() const;
    
    void precarga_espacial(uint32_t direccion, int distancia_precarga = 1);
    
    // Getters
    int get_aciertos() const { return aciertos; }

    int get_fallos() const { return fallos; }

    float get_tasa_aciertos() const { 
        return (aciertos + fallos) > 0 ? (100.0f * aciertos / (aciertos + fallos)) : 0.0f; 
    }
};

#endif // CACHE_BASE_HPP