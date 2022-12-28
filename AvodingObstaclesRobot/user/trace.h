#include "direction.h"

// LCD�� ǥ���Ǵ� ��ֹ��� ������ ���� ǥ���ϴ� ���

/*######################################### DEFINE #########################################*/

#define arrSize 1000 // ������ trace �迭 ũ��
#define ROBOT_TRACE_SPEED 10 // LCD�� ǥ���� �κ��� ���� �ӵ�

/*######################################### DEFINE END #########################################*/


/*###################################### TYPEDEF STRUCT ######################################*/

typedef struct Trace {
    Direction dir; // ����
    int time;
    int pos_x;
    int pos_y;
}Trace;

/*###################################### TYPEDEF STRUCT END ######################################*/


/*###################################### FUNCTION DEFINITION ######################################*/

// �νĵ� ��ֹ��� �κ��� ������ ��������� ǥ����.
void Show_LCD_Obstacle_LEFT(robot* rbt);
void Show_LCD_Obstacle_RIGHT(robot* rbt);
void Show_LCD_Obstacle_FORWARD(robot* rbt);

// LCD�� robot�� ���� �ٶ󺸴� ������ ���ڷ� ���
void Show_LCD_Robot_Direction(robot* rbt);

// LCD�� robot�� �����¿� ������ ������ �°� ���
void Show_LCD_FB_Displacement(robot* rbt);
void Show_LCD_LR_Displacement(robot* rbt);

// LCD�� robot�� ������ ���� drawcircle ����� �̿��Ͽ� ���
void Record_LCD_Robot_Trace(robot* rbt);

void Record_Trace_Array(robot* rbt);

/*###################################### FUNCTION DEFINITION END ######################################*/


/*###################################### GLOBAL VARIABLE ######################################*/

Trace robot_trace_array[arrSize];
int trace_index;// �κ� ������ �ٲ� �� �����ϴ� index. �ᱹ Trace �����!


clock_t start; // ���� ��ȯ�� ���� ���� ������ �ð�
clock_t end; // ���� ��ȯ�� �Ϸ��ϴ� ������ �ð�

/*###################################### GLOBAL VARIABLE END ######################################*/