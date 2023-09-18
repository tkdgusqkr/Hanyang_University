#include "minimal_fighter.h"

MinimalFighter::MinimalFighter()
{
	mHp=0;
	mPower=0;
	mStatus=Invalid;
}
MinimalFighter::MinimalFighter(int _hp,int _power)
{
	mHp=_hp;
	mPower=_power;
	if(mHp)
	{
		mStatus=Alive;
	}
	else
	{
		mStatus=Dead;
	}
}

int MinimalFighter::hp()
{
	return mHp;
}
int MinimalFighter::power()
{
	return mPower;
}
FighterStatus MinimalFighter::status()
{
	return mStatus;
}
void MinimalFighter::setHp(int _hp)
{
	mHp=_hp;
}
void MinimalFighter::hit(MinimalFighter *_enemy)
{
	mHp-=_enemy->mPower;
	_enemy->mHp-=mPower;
	if(mHp<=0)
	{
		mStatus=Dead;
	}
	if(_enemy->mHp<=0)
	{
		_enemy->mStatus=Dead;
	}
}
void MinimalFighter::attack(MinimalFighter *_enemy)
{
	int tmp=mPower;
	mPower-=_enemy->mHp;
	_enemy->mHp-=tmp;
	if(mHp<=0)
	{
		mStatus=Dead;
	}
	if(_enemy->mHp<=0)
	{
		_enemy->mStatus=Dead;
	}
}
void MinimalFighter::fight(MinimalFighter *_enemy)
{
	while(mHp && _enemy->mHp)
	{
		--mHp;
		--_enemy->mHp;
	}
	if(mHp<=0)
	{
		mStatus=Dead;
	}
	if(_enemy->mHp<=0)
	{
		_enemy->mStatus=Dead;
	}
}
