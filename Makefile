# Universidad de La Laguna
# Escuela Superior de Ingeniería y Tecnología
# Grado en Ingeniería Informática

CXX = g++						        
CXXFLAGS = -std=c++2a -g -Wall -pedantic
LDFLAGS = # The linker options (if any)		

.PHONY: client_exec clean
	
client_exec : ClientMain.o src/ThreadsManager.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)
clean:
	@ rm -f *.o client_exec
	@ rm -f src/*.o

# The $@ and $< are called automatic variables. The variable $@ represents the name 
# of the target and $< represents the first prerequisite required to create the output file.