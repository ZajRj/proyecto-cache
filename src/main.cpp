#include "Simulador.hpp"
#include "GeneradorAccesos.hpp"
#include <iostream>
#include <iomanip>

int main() {
    std::cout << "Simulador de Caché - Comparación de esquemas" << std::endl;
    
    // Generar secuencia de accesos a memoria
    auto direcciones = generar_accesos_memoria(20, 0.7, 0.5);
    
    std::cout << "\nSecuencia de direcciones generadas:" << std::endl;
    for (uint32_t dir : direcciones) {
        std::cout << std::hex << "0x" << dir << std::dec << " ";
    }
    std::cout << "\n" << std::endl;
    
    // Ejecutar con detalles para los primeros accesos
    bool mostrar_detalles = true;
    
    comparar_caches(direcciones, mostrar_detalles);
    

    
    return 0;
}