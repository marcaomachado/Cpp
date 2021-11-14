#Comentários

CXX := g++ -g
OBJ := main.o Processo.o ListaProcessos.o
TARGET := programa

exe:
	@$(CXX) *.cpp -o $(TARGET)

%.o: %.cpp
	$(CXX) -c $< 

# -c gera o arquivo .o
# -c $< gera o arquivo .o a partir do arquivo .cpp que é passado para %.cpp


# all:
#	g++ -c *.cpp
#	$(CXX) -o $(TARGET) *.o

all: $(OBJ)
	@$(CXX) -o $(TARGET) $(OBJ)

#$(CXX) -o $(TARGET) *.o gera o target a partir dos arquivo *.o


clean:
	@del /f *.exe
	@del /f *.o

