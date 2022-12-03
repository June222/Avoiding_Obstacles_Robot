#include "stm32f10x.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_exti.h"
#include "stdio.h"
#include <stdbool.h>
#include <time.h>

#define arrSize 1000
#define GO 1
#define STOP 0
#define Arrival 17
#define TESTSIZE 36 

typedef enum {
    BACK, LEFT, FORWARD, RIGHT
}Direction;

typedef struct Trace {
    Direction dir;
    int time;
}Trace;

typedef struct robot {
    Direction direction; // ������� �þ�
    bool isGo; // ���� �Ǵ� ���
    Trace* trace; // ������ �� (MAP)
    int forwardBackward; // �յ� ���� (��������� ���� �Ÿ�)
    int leftRight; // �¿� ���� (��ȸ��, ��ȸ�� �������)
}robot;

void turnLeft(robot* rbt)
{
    rbt->direction -= 1;
    if (rbt->direction < BACK)
        rbt->direction = RIGHT;
}

void turnRight(robot* rbt) {
    rbt->direction += 1;
    if (rbt->direction > RIGHT)
        rbt->direction = BACK;
}

Trace trace2[arrSize] = { {FORWARD, 0}, };
int rbt_index = 0; // �κ� ������ �ٲ� �� �����ϴ� index. �ᱹ Trace �����!

clock_t start;
clock_t end;

int main(void)
{
    struct robot rbt = { FORWARD, GO, trace2, 0, 0 }; // �κ� ���� �ʱ�ȭ;
    start = clock(); // ������� ��� �ۼ��� �����ؾ���. 

    
    /*
    while(1){

      if (GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_12) == Bit_RESET)  {
        GPIO_ResetBits(GPIOE, GPIO_Pin_8);
        GPIO_SetBits(GPIOE, GPIO_Pin_9);

      }
      else {
        GPIO_ResetBits(GPIOE, GPIO_Pin_9);
        GPIO_SetBits(GPIOE, GPIO_Pin_8);
      }

    }
  */


}