#include "GeneradorAccesos.hpp"
#include <random>
#include <algorithm>

std::vector<uint32_t> generar_accesos_memoria(
    int numero_accesos, 
    double localidad_espacial, 
    double localidad_temporal) {
    
    std::vector<uint32_t> direcciones;
    
    std::random_device dispositivo_aleatorio;
    std::mt19937 generador(dispositivo_aleatorio());
    std::uniform_real_distribution<> distribucion(0.0, 1.0);
    
    uint32_t bloque_actual = 0;
    
    for (int i = 0; i < numero_accesos; ++i) {
        if (distribucion(generador) < localidad_temporal && !direcciones.empty()) {

            std::uniform_int_distribution<> distribucion_temp(0, std::min(10, (int)direcciones.size() - 1));
            int indice = direcciones.size() - 1 - distribucion_temp(generador);
            direcciones.push_back(direcciones[indice]);

        } else if (distribucion(generador) < localidad_espacial) {
            
            std::uniform_int_distribution<> distribucion_desplazamiento(1, 4);
            uint32_t desplazamiento = distribucion_desplazamiento(generador) * 4;
            direcciones.push_back(bloque_actual * 64 + desplazamiento);

        } else {

            std::uniform_int_distribution<> distribucion_dir(0, 1024 * 1024);
            bloque_actual = distribucion_dir(generador) / 64;
            direcciones.push_back(distribucion_dir(generador));
            
        }
    }
    
    return direcciones;
}