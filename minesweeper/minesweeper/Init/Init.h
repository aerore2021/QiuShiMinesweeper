#ifndef _Init_h

#define _Init_h

#include "graphics.h"
#include "extgraph.h"
#include "genlib.h"
#include "simpio.h"
#include "imgui.h"
#include "conio.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#include <windows.h>
#include <olectl.h>
#include <mmsystem.h>
#include <wingdi.h>
#include <ole2.h>
#include <ocidl.h>
#include <winuser.h>

#include "logic.h"

#pragma comment(lib,"winmm.lib")


#define MINESIZE 0.3    //������ӵĴ�С
#define CHECKERBOARDCOL (GetWindowWidth() / 2 -  MINESIZE * MAXCOL / 2)//�������������
#define CHECKERBOARDROW 3 * GetWindowHeight() / 4 + MAXROW * MINESIZE / 2   //�����������϶�
#define MOVEROW 2.4		//��������
#define MOVECOL 1.3		//��������
#define REFRESHRATE 20  //ˢ����
#define LINELENGTH 13
#define BEISHU1 3
#define BEISHU2 1.5
typedef enum SIGNAL {
	START = 0,    //��ʼ����Ϸ
	GAME,    //������Ϸ
	OVER,    //ʧ�ܣ�ֹͣ����
};    //�������źŸ�ֵ

typedef struct
{
	int gametime;    //��¼��Ϸʱ��
	int minenum;    //��¼�ѱ���ǵ����������Ѳ�����
	int mapnum;    //��¼��ǰ��ͼ���ڲ���
	int seednum;    //��¼��ͼ������ֵ
	bool ifSure;    //�Ƿ�ȷ��������
	bool ifSeed;    //�Ƿ�ʼ��������
}GAMESTATE;
GAMESTATE Gamestate;    //��¼��Ϸ��Ϣ

typedef enum {
	GameTimer,    //���Ƽ�ʱ����ʱ
	MineTimer,    //������Ϸ����ˢ��
	MenuTimer,    //���Ʋ˵���ť��������
} MYTIMER;

typedef struct {
	double mousex;    //��¼��굱ǰ����λ�õ�x����
	double mousey;    //��¼��굱ǰ����λ�õ�y����
	double CurrentX;    
	double CurrentY;
} MOUSESTATE;
static MOUSESTATE Mousestate;    //�����ж����״̬

typedef struct 
{
	int passive;
	bool ifUse;
	bool ifChoose;
	int deadrow;
	int deadcol;
}PASSIVE;
PASSIVE Mypassive;
//3:Al, 2:Cui, 1:02
// 
//��Ϸʧ��ʱ������ʧ�ܵĵ���
void GameOver();
//�ж��Ƿ�ʤ����������Ϸʤ��ʱ�������ɹ��ĵ���
void Win();
//�ж����ڲ�
static bool InBox(double x, double y, double x1, double x2, double y1, double y2);
//������
void AddBGM();
//�õ������Ϣ��������갴�����в���
void GetMouseButton(int x, int y, int button, int event);
//�õ���굱ǰλ��
void GetCurrentPlace();
//������
void DrawMine(double x, double y);
//��С����
void DrawFlag(double x, double y);
//������
void DrawWhiteFlag(double x, double y);
//���ͣ���ڸ����ϸ���
void TurnLight(double x, double y);
//�����׸���
void DrawGrid();
//������
void DrawChessBoard();
//����������
void DrawMenu();
//���а�
void Rank();
//���Ʋ�ͬ��ʱ��������Ӧ
void TimerEventProcess(int  timerID);
//ˢ�µ�ͼ
void Renew();
// �û��ļ����¼���Ӧ�������Բ�ͬ�İ������в�ͬ����Ӧ
void KeyboardEventProcess(int key, int event);
// �û�������¼���Ӧ����
void MouseEventProcess(int x, int y, int button, int event);
//����ͼ�ϵ����ֲ������ת��Ϊ�ַ���
void CreateString(void);
//������������
void Display(void);
//�����ײ㡢���ֲ�
void CreateMap();
//ʹ�ü���
void UseSkill();
//����Ϸ����
void DrawBackground();
//����ɫ��
void DrawFrame();
//����ɫ��02������ʯ���Ŷ�����
void Draw_ZeroTwo(bool flag);
void Draw_Cui(bool flag);
void Draw_Albedo(bool flag);
//����ɫ������
void Dwtxtbg02();
void DwtxtbgCui();
void DwtxtbgAlbedo();
//������ʱ����
void DwPlaying_02();
void DwPlaying_Al();
void DwPlaying_Cui();
//������ɫ
void CrtItat();
#endif