#include "fila.h"

struct No {
  int chave;
  No* proximo;
};

Fila::Fila() {
  primeiro_ = nullptr;
  ultimo_ = nullptr;
}

void Fila::Inserir(int k) {
  No* atual = new No;
  atual->chave = k;
  atual->proximo = nullptr;

  if (primeiro_ == nullptr){
    primeiro_ = atual;
    ultimo_ = atual;
  }
  else{
    ultimo_->proximo = atual;
    ultimo_ = atual;
  }
}

void Fila::RemoverPrimeiro() {
  try{
    if (primeiro_ == nullptr) throw ExcecaoFilaVazia();
    No* temp = primeiro_->proximo;
    delete primeiro_;
    primeiro_ = temp;
  }
  catch (ExcecaoFilaVazia()){

  }
}

int Fila::primeiro() const {
  try{
    if (primeiro_ == nullptr) throw ExcecaoFilaVazia();
    return primeiro_->chave;
  }
  catch (ExcecaoFilaVazia()){
  }
}

int Fila::ultimo() const {
  try{
    if (primeiro_ == nullptr) throw ExcecaoFilaVazia();
      return ultimo_->chave;
  }
  catch (ExcecaoFilaVazia()){
  }
}

int Fila::tamanho() const {
  if (primeiro_ == nullptr)
  {
    return 0;
  }
  No* temp = primeiro_;
  int count = 1;
  while(temp != ultimo_)
  {
    temp = temp->proximo;
    count++;
  }
  return count;
}