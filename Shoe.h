#pragma once

#include "common.h"

//�J�[�h�V���[�N���X
class Shoe {

private:
	//��{�I�ɃJ�[�h�V���[��private
	int _cardShoe[CARD]; //�J�[�h�z��
	int _cardNum; //�J�[�h����

	void CardShoe();
	void _shuffle();

public:
	enum SHOW_TYPE
	{
		CARD_ONLY,
		ALL
	};

	//�R���X�g���N�^
	Shoe();

	//�J�[�h��1�����o��
	int takeCard();

	//�J�[�h�V���[��\��(�f�o�b�O�p)
	void showShoe(SHOW_TYPE type = CARD_ONLY) const;
};

