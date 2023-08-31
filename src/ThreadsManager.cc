/**
 * Autor: Omar Suárez Doro
 * Correo: noexdevpen@gmail.com
 * Fecha: 31/8/2023
 * Archivo ThreadsManager.c: Definición de métodos de clase ThreadManager
 */

#include "ThreadsManager.h"


std::string PrintMessage(int m_option, std::string string_to_print, std::string additional_options = "") {
  std::string result;
  switch (m_option) {
    case MESSAGE:
      result = NC + std::string("[i] ") + GRAY + string_to_print + NC;
      break;
    case QUESTION:
      result = BLUE + std::string("[?] ") + GRAY + string_to_print + NC + additional_options + GRAY + ": ";
      break;
    case WARNING:
      result = YELLOW + std::string("[!] ") + GRAY +  string_to_print + NC;
      break;
    case ERROR:
      result = RED + std::string("[-] ") + string_to_print + NC;
      break;
    case PERFECT:
      result = GREEN + std::string("[+] ") + GRAY + string_to_print + NC;
      break;
  }
  return result;
}

ThreadsManager::ThreadsManager(bool silence_execution) {
  if (silence_execution) {
    silence_ = true;
  }
}

template<typename T, typename... Args> 
void ThreadsManager::AddThread(T function, Args... args) {
  std::thread new_thread(function, args...);
  thread_map_.emplace(new_thread.get_id(), new_thread);
  new_thread.detach();
  std::cout << PrintMessage(PERFECT, "A new thread was successfully created with id: " + std::string(new_thread.get_id())) << std::endl;
}


