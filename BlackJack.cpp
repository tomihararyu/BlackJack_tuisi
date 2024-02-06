#include <iostream> //入出力

#include "Shoe.h"
#include "Player.h"
#include "Dealer.h"

using namespace std;

//
// 試験用ブラックジャックソース
// 正常動作していない。
//見にくいけど一応完成

// ★★★★★★★★★★★★★★★★
static void showResult(Person** p,const int Pnum)
{
	cout << "============================" << endl;
	cout << "            result          " << endl;
	cout << "============================" << endl;
	cout << "============================" << endl;
	for (int i = 0; i < Pnum; i++)
	{
		cout << p[i]->nameReturn() << "のリザルト" << endl;
		p[i]->showHands();
		cout << "============================" << endl;
		p[3]->showHands();
		cout << "============================" << endl;

		if (p[i]->getScore() > p[3]->getScore()) {
			cout << p[i]->nameReturn()<<" Win!" << endl;
		}
		else if (p[i]->getScore() < p[3]->getScore()) {
			cout << p[i]->nameReturn()<<" Lose" << endl;
		}
		else {
			cout << "Push" << endl;
		}
		if (i != Pnum-1)
		{
			cout << "次の" << p[i + 1]->nameReturn() << "のリザルトに移りますよろしいですか？ yesと入力して下さい。" << endl;
			char str[16]; //文字列型
			cin >> str; //文字列を入力
			if (strcmp(str, "yes") == 0)
			{

			}
			else
			{
				cout << "debug用で一時停止する物だから何もないよ" << endl;
			}
		}
		
	}
	cout << "ゲーム終了。" << endl;
}

static void showHand(Person* p)
{
	//手札の表示
	cout << "====================" << endl;
	p->showHands();
	cout << "====================" << endl;

}

//メイン関数
int main() {

	srand((unsigned int)time(NULL));

	enum PERSON
	{
		PLAYER1, PLAYER2, PLAYER3, DEALER
	};

	//各オブジェクトの生成
	Shoe* shoe = new Shoe;
	Person* persons[] = { new Player("ryu1"),new Player("ryu2"),new Player("ryu3"), new Dealer("hosaka")};
	const int num = sizeof(persons) / sizeof(Person*);
	const int Pnum = num - 1;

	//----カードの配布 ... 初期
	cout << "====================" << endl;
	for (int i = 0; i < num; i++)
	{
		persons[i]->hit(shoe);
		showHand(persons[i]);
	}
	//プレイヤーに2枚目を配布
	
	for (int i = 0; i < Pnum; i++)
	{
		persons[i]->hit(shoe);//一人目
		showHand(persons[i]);
	}


	//ディーラーに2枚目を配布
	persons[DEALER]->hit(shoe);


	for (int i = 0; i < Pnum; i++)
	{
		// ----　勝負開始
		//プレイヤーの実行
		//バーストしているかどうか判別
		if (persons[i]->play(shoe)) {
			//バーストせずstandした

			//ディーラーの手札を表示
			showHand(persons[DEALER]);

		}
		else {
			cout << "Burst Player Lose" << endl;
		}
		cout << "====================" << endl;
	}
	//ディーラーの自動実行
	persons[DEALER]->play(shoe);

	//結果の表示
	showResult(persons,Pnum);
}