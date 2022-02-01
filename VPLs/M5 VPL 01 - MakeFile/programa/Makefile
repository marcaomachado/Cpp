CXX	:= g++
CXX_FLAGS	:= -std=c++11 -Wall
TARGET	:= vpl_execution

BUILD	:= build
SRC	:= src
INCLUDE	:= include

$(TARGET): $(BUILD)/Funcionario.o $(BUILD)/Pessoa.o $(BUILD)/Professor.o $(BUILD)/main.o
	$(CXX) $(CXX_FLAGS) -o $(TARGET) $^

$(BUILD)/Funcionario.o: $(INCLUDE)/Funcionario.hpp $(SRC)/entidades/Funcionario.cpp
	$(CXX) $(CXX_FLAGS) -I $(INCLUDE)/ -c $(SRC)/entidades/Funcionario.cpp -o $(BUILD)/Funcionario.o

$(BUILD)/Pessoa.o: $(INCLUDE)/Pessoa.hpp $(SRC)/entidades/Pessoa.cpp
	$(CXX) $(CXX_FLAGS) -I $(INCLUDE)/ -c $(SRC)/entidades/Pessoa.cpp -o $@

$(BUILD)/Professor.o: $(INCLUDE)/Professor.hpp $(SRC)/entidades/Professor.cpp
	$(CXX) $(CXX_FLAGS) -I $(INCLUDE)/ -c $(SRC)/entidades/Professor.cpp -o $@

$(BUILD)/main.o: $(INCLUDE)/Funcionario.hpp $(INCLUDE)/Pessoa.hpp $(INCLUDE)/Professor.hpp $(SRC)/main.cpp
	$(CXX) $(CXX_FLAGS) -I $(INCLUDE)/ -c $(SRC)/main.cpp -o $@



clean:
	del /f $(BUILD)\*