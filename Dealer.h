#pragma once

#include "Person.h"

//�f�B�[���[�N���X
class Dealer : public Person 
{
public:
	Dealer(const char* name);
protected:
	//�Q�[�����s
	void playBase(Shoe* shoe);

};