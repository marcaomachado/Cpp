#include "google_password.hpp"

#include <iostream>
using std::cout;
using std::endl;

void GooglePassword::insert(const std::string& url,
                            const std::string& login,
                            const std::string& password) {
  // TODO: Implemente este metodo
  /**
   * Lembre-se que as credenciais so podem ser inseridas com as seguintes
   * condicoes:
   * Condicao 1: A senha nao pode ter a seguencia '123456'.
   * Condicao 2: A senha nao pode ter mais do que 50 caracteres (no maximo 50).
   * Condicao 3: A senha nao pode ter menos do que 6 caracteres (no minimo 6).
   * Condicao 4: A senha nao pode ter caracteres em branco ' '.
   *
   * Exemplos de senhas invalidas:
   * 123456
   * test_123456
   * 123456_test
   * test_123456_test
   * senha test
   */
  if (checkPassword(password)) {
    m_passwords.insert(
        std::pair<std::string, Usuario>(url, Usuario(login, password)));
  }
}

void GooglePassword::remove(const std::string& url) {
  // TODO: Implemente este metodo
  m_passwords.erase(url);
}

void GooglePassword::update(const std::string& url,
                            const std::string& login,
                            const std::string& old_password,
                            const std::string& new_password) {
  // TODO: Implemente este metodo
  /**
   * Caso a url nao seja encontrada, o metodo update deve ser ignorado, ou seja,
   * este metodo nao pode inserir novas credenciais. Alem disso, as informacoes
   * do usuario so podem ser atualizadas se a senha antiga for igual a senha
   * atual. Nao esqueca de verificar se o novo password tambem e valido.
   */
  std::map<std::string, Usuario>::iterator it;
  it = m_passwords.find(url);
  if (it == m_passwords.end()) {
    return;
  }

  if (checkPassword(new_password) &&
      it->second.getPassword().compare(old_password) == 0) {
    it->second.setLogin(login);
    it->second.setPassword(new_password);
  }
}

void GooglePassword::printPasswords() {
  // TODO: Implemente este metodo
  /**
   * Exemplo de saida:
   * www.site.com: login and password
   *
   */
  cout << m_passwords.size() << endl;
  std::map<std::string, Usuario>::iterator it;
  for (it = m_passwords.begin(); it != m_passwords.end(); ++it) {
    cout << it->first << ": " << it->second.getLogin() << " and "
         << it->second.getPassword() << endl;
  }
}

bool GooglePassword::checkPassword(const std::string& password) const {
  // TODO: Implemente este metodo
  bool nonEmptyCharacters = true;
  for (int i = 0; i < password.size(); i++) {
    if (password[i] == ' ') {
      return false;
    }
  }

  if (password.find("123456") == std::string::npos && password.size() >= 6 &&
      password.size() <= 50) {
    return true;
  }

  return false;
}