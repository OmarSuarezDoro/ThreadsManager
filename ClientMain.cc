
#include "src/ThreadsManager.h"

std::mutex mutex;

void pepe(int p , int p2) {
  while (true) {
    mutex.lock();
    std::cout << "El hilo le llega " << p << " - " << p2 << std::endl;
    sleep(5);
    mutex.unlock();
  }
}

int main() {
  ThreadsManager manager;
  manager.AddThread(pepe, 1 , 2);
  return 0;
}
