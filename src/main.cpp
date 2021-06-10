// Copyright 2021 Ivan Razzhivin
#include <iostream>
#include <string>
#include "TimedDoor.h"

int main() {
  TimedDoor* timedDoor1 = new TimedDoor(5);  // make door with timer
  try {
    timedDoor.unlock();
    timedDoor1->throwState();
  } catch (std::string notice1) {
    std::cout << notice1 << std::endl;  // opened
  }
  TimedDoor* timedDoor2 = new TimedDoor(5);
  try {
    timedDoor2->unlock();
  } catch (std::string notice2) {
    std::cout << notice2 << std::endl;  // close
  }
  TimedDoor* timedDoor3 = new TimedDoor(5);
  try {
    timedDoor3->lock();
    timedDoor3->throwState();
  } catch (std::string notice3) {
    std::cout << notice3 << std::endl;  // closed
  }
  return 0;
}
