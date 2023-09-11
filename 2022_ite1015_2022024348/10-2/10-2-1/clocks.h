#ifndef __CLOCK_H__
#define __CLOCK_H__
#include "clock_time.h"
class Clock
{
	public:
		Clock(int hour, int minute, int second, double driftPerSecond);
		void reset();
		void tick();
		virtual void displayTime() = 0;
	protected:
		ClockTime _clockTime;
		double _driftPerSecond;
		double _totalDrift;
};
class NaturalClock:public Clock
{
	public:
		NaturalClock(int hour, int minute, int second, double driftPerSecond);
};
class SundialClock:public NaturalClock
{
	public:
		SundialClock(int hour, int minute, int second);
		void displayTime();
};
class MechanicalClock:public Clock
{
	public:
		MechanicalClock(int hour, int minute, int second, double driftPerSecond);
};
class CuckooClock:public MechanicalClock
{
	public:
		CuckooClock(int hour, int minute, int second);
		void displayTime();
};
class GrandFatherClock:public MechanicalClock
{
	public:
		GrandFatherClock(int hour, int minute, int second);
		void displayTime();
};	
class DigitalClock:public Clock
{
	public:
		DigitalClock(int hour, int minute, int second, double driftPerSecond);
};
class WristClock:public DigitalClock
{
	public:
		WristClock(int hour, int minute, int second);
		void displayTime();
};
class QuantumClock:public Clock
{
	public:
		QuantumClock(int hour, int minute, int second, double driftPerSecond);
};
class AtomicClock:public QuantumClock
{
	public:
		AtomicClock(int hour, int minute, int second);
		void displayTime();
};
#endif
