/**
 * Autor: Omar Suárez Doro
 * Correo: noexdevpen@gmail.com
 * Fecha: 31/8/2023
 * Archivo ThreadsManager.h: Declaración de clase
 */

#include <iostream>
#include <thread>
#include <mutex>
#include <map>
#include <unistd.h>

#pragma once

#include "../ConfigFiles/resources.h"


class ThreadsManager {
 public:
  ThreadsManager(bool silence_execution = false);
  template<typename T, typename... Args> void AddThread(T function, Args... args);
 private:
  bool silence_ = false;
  std::map<std::thread::id, std::thread> thread_map_;
};

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
  std::cout << PrintMessage(PERFECT, "A new thread was successfully created.")  << std::endl;
  std::thread new_thread(function, args...);
  new_thread.join();
  thread_map_.emplace(new_thread.get_id(), std::move(new_thread));
  std::cout << thread_map_.count(new_thread.get_id()) << std::endl;
}



