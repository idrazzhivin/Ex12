// Copyright 2021 Ivan Razzhivin
#ifndef INCLUDE_TIMEDDOOR_H_
#define INCLUDE_TIMEDDOOR_H_

#include <string>
#include <ctime>

class Door {
 public:
    virtual bool isOpen() = 0;
    virtual void lock() = 0;
    virtual void unlock() = 0;
};

class DoorTimeAdapter;

class TimedDoor : public Door {
 private:
    bool open;
    unsigned int sec;
    DoorTimeAdapter *dtAdapter;

 public:
    explicit TimedDoor(unsigned int _sec);
    bool isOpen() override;
    void throwState();
    void lock() override;
    void unlock() override;
    void DoorTimeOut() const;
};

class TimerClient {
 public:
    virtual void Timeout() const = 0;
};

class DoorTimeAdapter : public TimerClient {
 private:
    const TimedDoor& tDoor;
 public:
    explicit DoorTimeAdapter(const TimedDoor& _tDoor);
    void Timeout() const override;
};

class Timer {
 public:
    void registerTimer(const DoorTimeAdapter & _dtAdapter, unsigned int _sec);
    void sleepTimer(unsigned int _sec);
};
#endif  // INCLUDE_TIMEDDOOR_H_
