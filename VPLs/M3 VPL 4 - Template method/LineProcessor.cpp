#include <math.h>
#include <iostream>
#include <regex>
#include <string>
#include <vector>

#include "LineProcessor.hpp"

void LinePrinter::processaLinha(const std::string& str) {
  std::cout << str << std::endl;
}

bool ContadorPopRural::linhaValida(const std::string& str) const {
  // Neste exemplo usaremos expressoes regulares para verificar se uma linha
  // eh valida ou nao.
  //
  // Esta expressao regular eh formada por cinco partes. Cada uma dessas
  // partes eh um dos tres tipos de padrao regular abaixo:
  //
  // \\w+ eh qualquer palavra com um ou mais digitos, letras e sublinhas (_)
  // \\s* eh qualquer sequencia de zero ou mais espacos (inclui tab)
  // \\d+ eh qualquer sequencia de um ou mais digitos
  std::regex regularExpr("\\w+\\s*\\d+\\s*\\d+");

  // A funcao regex_match vai retornar verdadeiro se a string str casa-se com
  // a expressao regular que acabamos de criar:
  return std::regex_match(str, regularExpr);
}

void ContadorPopRural::processaLinha(const std::string& str) {
  //
  // Em geral eh mais facil ler dados de uma string se a string eh transformada
  // em um objeto do tipo stringstream:
  std::stringstream ss(str);
  //
  // Iremos ler os dados da string nestas tres variaveis abaixo:
  std::string nomePais;
  unsigned populacao, percUrbana;
  //
  // Como sabemos que a linha contem string int int, podemos fazer a leitura
  // facilmente usando o operador de streaming:
  ss >> nomePais >> populacao >> percUrbana;
  //
  // Note que precisamos arredondar o valor que serah impresso. O arredondamento
  // serah feito via a funcao floor. Ou seja, decimais serao sempre
  // arredondados para baixo:
  unsigned popRural = floor(populacao - (populacao * (percUrbana / 100.0)));
  //
  // Uma vez encontrados os valores que precisam ser impressos, seguimos o
  // modelo do enunciado do exercicio:
  std::cout << popRural << " pessoas vivem no campo no " << nomePais
            << std::endl;
}

bool ContadorNumNaturais::linhaValida(const std::string& str) const {
  std::regex regularExpressionNumNaturais("(\\d+|\\s*)*");
  return std::regex_match(str, regularExpressionNumNaturais);
}

void ContadorNumNaturais::processaLinha(const std::string& str) {
  int total = 0;
  int temp = 0;
  std::string tempString = "";
  for (int i = 0; i < str.size(); i++) {
    if (str[i] != ' ') {
      tempString.push_back(str[i]);
    }
    if (str[i] == ' ' || i == str.size() - 1) {
      total += std::stoi(tempString);
      tempString.clear();
    }
  }
  std::cout << total << std::endl;
}

bool LeitorDeFutebol::linhaValida(const std::string& str) const {
  std::regex regularExpressionLeitorDeFutebol(
      "\\s*\\w+\\s+\\d+\\s+\\w+\\s+\\d+");
  return std::regex_match(str, regularExpressionLeitorDeFutebol);
}

void LeitorDeFutebol::processaLinha(const std::string& str) {
  std::stringstream ss(str);
  std::string time1, time2;
  unsigned int gols1, gols2;
  ss >> time1 >> gols1 >> time2 >> gols2;
  if (gols1 == gols2) {
    std::cout << "Empate" << std::endl;
  } else if (gols1 > gols2) {
    std::cout << "Vencedor: " << time1 << std::endl;
  } else {
    std::cout << "Vencedor: " << time2 << std::endl;
  }
}

void ContadorDePalavras::processaLinha(const std::string& str) {
  unsigned int totalPalavras = 0;
  bool achouEspaco = false;
  int i = 0;
  for (i; i < str.size(); i++) {
    if (str[i] != ' ') {
      break;
    }
  }
  for (i; i < str.size(); i++) {
    if (str[i] == ' ' && !achouEspaco) {
      totalPalavras++;
      achouEspaco = true;
    } else {
      achouEspaco = false;
    }
  }
  totalPalavras++;

  std::cout << totalPalavras << std::endl;
}

bool InversorDeFrases::linhaValida(const std::string& str) const {
  std::regex regularExpressionInversorDeFrases("([a-zA-Z]+\\s*)*");
  return std::regex_match(str, regularExpressionInversorDeFrases);
}

void InversorDeFrases::processaLinha(const std::string& str) {
  int tempInicial = 0, tempSize = 0;
  for (int i = str.size() - 1; i >= 0; i--) {
    if (str[i] != ' ') {
      tempSize++;
    } else {
      tempInicial = i + 1;
      std::string tempString = str.substr(tempInicial, tempSize);
      std::cout << tempString << " ";
      tempSize = 0;
    }
  }
  std::string tempString = str.substr(0, tempSize);

  std::cout << tempString << std::endl;
}

bool EscritorDeDatas::linhaValida(const std::string& str) const {
  std::string dateFormat = "\\s*\\d\\d?/\\d\\d?/\\d{4}";
  std::regex regularExpressionEscritorDeDatas("\\s*\\d\\d?/\\d\\d?/\\d{4}");
  return std::regex_match(str, regularExpressionEscritorDeDatas);
}

void EscritorDeDatas::processaLinha(const std::string& str) {
  int position1, position2, monthNumber;
  std::string monthString;
  position1 = str.find('/');
  position2 = str.rfind('/');
  monthString = str.substr(position1 + 1, (position2 - position1 - 1));

  monthNumber = std::stoi(monthString);
  std::vector<std::string> months = {"Null", "Jan", "Fev", "Mar", "Abr",
                                     "Mai",  "Jun", "Jul", "Ago", "Set",
                                     "Out",  "Nov", "Dez"};

  std::cout << months[monthNumber] << std::endl;
}