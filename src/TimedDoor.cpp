// Copyright 2021 Ivan Razzhivin
#include "TimedDoor.h"
#include <iostream>

TimedDoor::TimedDoor(unsigned int _sec)
  : open(false), sec(_sec) {
  dtAdapter = new DoorTimeAdapter(*this);
}

void TimedDoor::lock() {
  open = false;
}

void TimedDoor::unlock() {
  open = true;
  Timer timer;
  timer.registerTimer(*dtAdapter, sec);
}

bool TimedDoor::isOpen() {
  return open;
}

void TimedDoor::throwState() {
  if (isOpen()) {
    throw std::string("the door is opened!");
  } else {
    throw std::string("the door is closed!");
  }
}

void TimedDoor::DoorTimeOut() const {
  throw std::string("close the door!");
}

DoorTimeAdapter::DoorTimeAdapter(TimedDoor& _tDoor)
  : tDoor(_tDoor) {
}

void DoorTimeAdapter::Timeout() const {
  tDoor.DoorTimeOut();
}

void Timer::registerTimer(const DoorTimeAdapter & _dtAdapter,
                          unsigned int _sec) {
  sleep(_sec);
  _dtAdapter.Timeout();
}

void Timer::sleep(unsigned int _sec) {
  std::this_thread::sleep_for(std::chrono::seconds(_sec));
}
}