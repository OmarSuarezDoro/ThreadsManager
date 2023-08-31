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



