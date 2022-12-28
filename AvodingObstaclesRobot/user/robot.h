#include "direction.h"
#include "trace.h"
#include "lcd2.h"
#include "motor.h"
#include <stdbool.h>

#define ROTATE_90DEG_DLY 14000000
#define SHORT_DLY 100000

typedef struct robot {
    Direction direction; // ������� �þ�
    bool isGo; // ���� �Ǵ� ���
    Trace* trace; // ������ �� (MAP)
    int FB; // �յ� ���� (��������� ���� �Ÿ�)
    int LR; // �¿� ���� (��ȸ��, ��ȸ�� �������)
}robot;

// �κ��� �ٶ󺸴� ���� ���¸� �������� ��ȸ���� ���·� ����
void ROBOT_ROTATE_DIR_L(robot* rbt_ptr);
// �κ��� �ٶ󺸴� ���� ���¸� �������� ��ȸ���� ���·� ����
void ROBOT_ROTATE_DIR_R(robot* rbt_ptr);


// �κ��� ������ �ٶ󺸴� �� üũ
bool ROBOT_CHK_DIR_FW(robot* rbt_ptr);

// �κ��� �Ĺ��� �ٶ󺸴� �� üũ (���� ����)
bool ROBOT_CHK_DIR_B(robot* rbt_ptr);

// �κ��� ������ �ٶ󺸴� �� üũ
bool ROBOT_CHK_DIR_L(robot* rbt_ptr);

// �κ��� ������ �ٶ󺸴� �� üũ
bool ROBOT_CHK_DIR_R(robot* rbt_ptr);


// �κ��� ������ ���� _ ����
void ROBOT_STOP();
// �κ��� ������ ���� _ ����
void ROBOT_GO(robot* rbt_ptr);


// �κ��� ��ȸ���ϴ� ���μ���
void ROBOT_TURN_R(robot* rbt_ptr);

// �κ��� ��ȸ���ϴ� ���μ���
void ROBOT_TURN_L(robot* rbt_ptr);

// ����������� ó���ϴ� ���μ���
void ROBOT_TURN_HEAD_TO_END(robot* rbt_ptr);


// ������ �Լ�
void Delay(int value);