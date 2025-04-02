# Makefile para simulador de caché

# Compilador y opciones
CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -O3
LDFLAGS := 

# Directorios
SRCDIR := src
OBJDIR := obj
BINDIR := bin

# Archivos fuente (nombres exactos según tu estructura)
SOURCES := $(SRCDIR)/CacheBase.cpp \
           $(SRCDIR)/CacheMapeoDirecto.cpp \
           $(SRCDIR)/CacheVias.cpp \
           $(SRCDIR)/GeneradorAccesos.cpp \
           $(SRCDIR)/Simulador.cpp \
           $(SRCDIR)/main.cpp

OBJECTS := $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SOURCES))
EXECUTABLE := $(BINDIR)/simulador_cache

# Regla principal
all: directories $(EXECUTABLE)

# Crear directorios necesarios
directories:
	@mkdir -p $(OBJDIR)
	@mkdir -p $(BINDIR)

# Regla de compilación
$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

# Regla para archivos objeto
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Dependencias específicas
$(OBJDIR)/CacheMapeoDirecto.o: $(SRCDIR)/CacheMapeoDirecto.hpp $(SRCDIR)/CacheBase.hpp
$(OBJDIR)/CacheVias.o: $(SRCDIR)/CacheVias.hpp $(SRCDIR)/CacheBase.hpp
$(OBJDIR)/GeneradorAccesos.o: $(SRCDIR)/GeneradorAccesos.hpp
$(OBJDIR)/Simulador.o: $(SRCDIR)/Simulador.hpp $(SRCDIR)/CacheBase.hpp $(SRCDIR)/CacheMapeoDirecto.hpp $(SRCDIR)/CacheVias.hpp
$(OBJDIR)/main.o: $(SRCDIR)/Simulador.hpp $(SRCDIR)/GeneradorAccesos.hpp

# Solución para el warning de signo
$(OBJDIR)/CacheVias.o: CXXFLAGS += -Wno-sign-compare

# Limpieza
clean:
	rm -rf $(OBJDIR) $(BINDIR)

# Recompilar todo
rebuild: clean all

# Instrucciones para el usuario
.PHONY: all clean rebuild directories