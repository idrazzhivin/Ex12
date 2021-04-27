// Copyright 2021 Ivan Razzhivin
#include <iostream>
#include <string>
#include "TimedDoor.h"

int main() {
  TimedDoor timedDoor(5);  // create the door
  try {
    timedDoor.unlock();
  } catch (std::string notice) {
    std::cout << notice << std::endl;  // close
  }
  return 0;
}