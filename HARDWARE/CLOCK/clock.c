#include "clock.h"
#include "stdlib.h"


pClock pthis;

void Clock_Print(void);
void Clock_Add(void);

// ����һ��ʱ�Ӷ��󲢷���ָ��
pClock Clock_Create(void){
    // �����ڴ��ʱ�ӽṹ��ָ��
    pClock clock_c = (pClock)malloc(sizeof(pClock));
    
    // ����ڴ�����Ƿ�ɹ�
    if(clock_c == NULL)
        return NULL;
    
    // ��ʼ��ʱ�ӵ�ʱ���֡���
    clock_c->Second = 0;
    clock_c->Minute = 0;
    clock_c->Hour = 0;
    

    clock_c->pClock_Add = Clock_Add;
    clock_c->pClock_Print = Clock_Print;
    
    // ����ǰʱ�Ӷ���ָ�븳ֵ��ȫ��ָ��pthis
    pthis = clock_c;
    return clock_c;
}

// ����һ����������ʱ�Ӷ��󲢷���ָ��
pClock Clock_CreateWithArgs(uint8_t Second,uint8_t Minute,uint8_t Hour)
{
    // ����һ��ʱ�Ӷ���
    pClock clock_c = Clock_Create();
    if(clock_c == NULL)
        return NULL;

    Count = Second;
    clock_c->Second = Second;
    clock_c->Minute = Minute;
    clock_c->Hour = Hour;
    
    return clock_c;
}

// ��ӡ��ǰʱ��ʱ��
void Clock_Print(void)
{
    // ��OLED����ʾʱ���֡���
	OLED_ShowString(1, 1, "current time");
    OLED_ShowNum(2,1,pthis->Hour,2);
    OLED_ShowString(2, 3, ":");
    OLED_ShowNum(2,4,pthis->Minute,2);
    OLED_ShowString(2, 6, ":");
    OLED_ShowNum(2,7,pthis->Second,2);
	OLED_ShowString(3, 1, "good night");
}

// ����ʱ�ӵ�����������ʱ���֡���
void Clock_Add(void)
{
    // ��Countֵ��������
    pthis->Second = Count;
    if(pthis->Second == 60)
    {
        // �����ﵽ60ʱ�����ӷ��Ӳ���������
        pthis->Minute ++;
        pthis->Second = 0;
        Count = 0;
        
        if(pthis->Minute == 60)
        {
            // ���Ӵﵽ60ʱ������Сʱ�����÷���
            pthis->Hour ++;
            pthis->Minute = 0;
            
            if(pthis->Hour == 24)
            {
                // Сʱ�ﵽ24ʱ������Сʱ
                pthis->Hour = 0;
            }
        }
    }
}
