#include "direction.h"

// LCD�� ǥ���Ǵ� ��ֹ��� ������ ���� ǥ���ϴ� ���

/*######################################### DEFINE #########################################*/

#define arrSize 1000 // ������ trace �迭 ũ��
#define ROBOT_TRACE_SPEED 10 // LCD�� ǥ���� �κ��� ���� �ӵ�
#define OB_LCD_DST 5

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
void Show_LCD_Obstacle_LEFT(robot* rbt_ptr);
void Show_LCD_Obstacle_RIGHT(robot* rbt_ptr);
void Show_LCD_Obstacle_FORWARD(robot* rbt_ptr);

// LCD�� robot�� ���� �ٶ󺸴� ������ ���ڷ� ���
void Show_LCD_Robot_Direction(robot* rbt_ptr);

// LCD�� robot�� �����¿� ������ ������ �°� ���
void Show_LCD_FB_Displacement(robot* rbt_ptr);
void Show_LCD_LR_Displacement(robot* rbt_ptr);

// LCD�� robot�� ������ ���� drawcircle ����� �̿��Ͽ� ���
void Record_LCD_Robot_Trace(robot* rbt_ptr);

void Record_Trace_Array(robot* rbt_ptr);

/*###################################### FUNCTION DEFINITION END ######################################*/


/*###################################### GLOBAL VARIABLE ######################################*/

Trace robot_trace_array[arrSize];
int trace_index;// �κ� ������ �ٲ� �� �����ϴ� index. �ᱹ Trace �����!


clock_t start; // ���� ��ȯ�� ���� ���� ������ �ð�
clock_t end; // ���� ��ȯ�� �Ϸ��ϴ� ������ �ð�

/*###################################### GLOBAL VARIABLE END ######################################*/