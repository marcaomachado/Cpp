#include "usuario.hpp"

Usuario::Usuario(const std::string& login, const std::string& password) {
  // TODO: Implemente este metodo
  this->login = login;
  this->password = password;
  }

std::string Usuario::getLogin() const {
  // TODO: Implemente este metodo
  return this->login;
}

std::string Usuario::getPassword() const {
  // TODO: Implemente este metodo
  return this->password;
}

void Usuario::setPassword(const std::string& password) {
  // TODO: Implemente este metodo
  this->password = password;
}

void Usuario::setLogin(const std::string& login) {
  // TODO: Implemente este metodo
  this->login = login;
}