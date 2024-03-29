//陥託据 壕伸 尻柔

//朝球 限蓄奄
//4楳 5伸 20舌 朝球
//朝球 0腰 ~ 19腰
//朝球 砧 舌 識澱, 限生檎 及増精 辰稽 煽舌, 堂軒檎 鎧遂 硝形爽壱 陥獣
//乞窮 朝球 限蓄檎 曽戟

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define col 4	
#define low 5	
//朝球 走亀 (4*5)
//朝球 骨是 0~19
//けけけけけ
//けけけけけ
//けけけけけ
//けけけけけ

void initCardArray();				//朝球 走亀 壕伸 -1生稽 段奄鉢
void initCardNames();				//朝球 戚硯 壕伸 段奄鉢
void shuffleCade();				//沓棋生稽 朝球 戚硯聖 朝球 走亀人 尻衣
int getEmptyposition();				//壕伸税 推社亜 段奄鉢吉 雌殿檎 骨是鎧 沓棋廃 舛呪, 焼艦檎 0 鋼発
int conv_position_x(int position);		//朝球 走亀税 舛呪葵聖 護 楳昔走 鋼発
int conv_position_y(int position);		//朝球 走亀税 舛呪葵聖 護 伸昔走 鋼発
void printCards();				//砺什闘遂 舛岩 窒径
void printQuestion();				//巴傾戚嬢亜 左澗 庚薦 窒径
int foundAllCard();				//乞窮 朝球亜 限仲然生檎 0, 焼艦檎 1 鋼発


int arrayCard[col][low];	//朝球 走亀 壕伸
int checkCard[col][low];	//及増微 朝球 溌昔遂, 限秩 朝球 1, 公限秩 朝球 0
const char* strCard[10];	//朝球 戚硯 隔聖 庚切伸 壕伸

int main() {

	srand(time(NULL));

	initCardArray();
	initCardNames();
	shuffleCade();

	int failCounter = 0;	//叔鳶判呪 朝錘闘, 原走厳拭 鋼発

	printf("\n=====================砺什闘遂=======================\n");
	printCards();
	printf("====================================================\n");


	while (true) {
		int select1 = 0;	//坦製 脊径閤聖 呪
		int select2 = 0;	//陥製 脊径閤聖 呪

		printQuestion();

		printf("湛腰属 朝球 識澱 : ");
		scanf_s("%d", &select1);
		printf("砧腰属 朝球 識澱 : ");
		scanf_s("%d", &select2);

		if (select1 == select2)
			continue;

		//脊径閤精 呪研 楳, 伸稽 痕発
		int firstSelect_x = conv_position_x(select1);
		int firstSelect_y = conv_position_y(select1);

		int secondSelect_x = conv_position_x(select2);
		int secondSelect_y = conv_position_y(select2);

		if (
			(checkCard[firstSelect_x][firstSelect_y] == 0
				&& checkCard[secondSelect_x][secondSelect_y] == 0)
			//識澱廃 朝球級戚 限蓄走 省精 雌殿戚壱,
			&&
			(arrayCard[firstSelect_x][firstSelect_y] == arrayCard[secondSelect_x][secondSelect_y])
			//砧 鎧遂弘戚 旭生檎
			)
		{
			printf("collect %s \n", strCard[arrayCard[firstSelect_x][firstSelect_y]]);
			checkCard[firstSelect_x][firstSelect_y] = 1;
			checkCard[secondSelect_x][secondSelect_y] = 1;
		}
		else {
			printf("wrong\n");
			printf("%d %s \n", select1, strCard[arrayCard[firstSelect_x][firstSelect_y]]);
			printf("%d %s \n", select2, strCard[arrayCard[secondSelect_x][secondSelect_y]]);

			failCounter++;
		}

		if (foundAllCard()) {
			printf("finish, %d time\n", failCounter);
			return 0;
		}
	}
}

void initCardArray() {

	for (int i = 0; i < col; i++) {
		for (int j = 0; j < low; j++) {
			arrayCard[i][j] = -1;
		}
	}
}

void initCardNames() {

	strCard[0] = "拭戚什";
	strCard[1] = "先";
	strCard[2] = "蹄";
	strCard[3] = "天";
	strCard[4] = "繕朕";

	strCard[5] = "馬闘";
	strCard[6] = "什凪戚什";
	strCard[7] = "適稽獄";
	strCard[8] = "陥戚焼";
	strCard[9] = "収切";

}

void shuffleCade() {

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 2; j++) {
			int position = getEmptyposition();
			int x = conv_position_x(position);
			int y = conv_position_y(position);

			arrayCard[x][y] = i;
		}
	}
}

int getEmptyposition() {

	while (true)
	{
		int randPosition = rand() % 20;	//0~19
		int x = conv_position_x(randPosition);
		int y = conv_position_y(randPosition);

		if (arrayCard[x][y] == -1) {

			return randPosition;
		}
	}
	return 0;
}

int conv_position_x(int x) {

	return x / low;
}

int conv_position_y(int y) {

	return y % low;
}

void printCards() {

	for (int i = 0; i < col; i++) {
		for (int j = 0; j < low; j++) {
			printf("%10s", strCard[arrayCard[i][j]]);

		}
		printf("\n");
	}
}

void printQuestion() {

	int seq = 0;

	printf("\n====================================================\n");
	for (int i = 0; i < col; i++) {
		for (int j = 0; j < low; j++) {

			if (checkCard[i][j] != 0) {
				printf("%10s", strCard[arrayCard[i][j]]);
			}
			else {
				printf("%10d", seq);
			}
			seq++;
		}
		printf("\n");
	}
	printf("====================================================\n");
}

int foundAllCard() {

	for (int i = 0; i < col; i++) {
		for (int j = 0; j < low; j++) {

			if (checkCard[i][j] == 0) {
				return 0;
			}
		}
	}

	return 1;
}