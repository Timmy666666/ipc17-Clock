#include "clock.h"
#include "stdlib.h"


pClock pthis;

void Clock_Print(void);
void Clock_Add(void);

// 创建一个时钟对象并返回指针
pClock Clock_Create(void){
    // 分配内存给时钟结构体指针
    pClock clock_c = (pClock)malloc(sizeof(pClock));
    
    // 检查内存分配是否成功
    if(clock_c == NULL)
        return NULL;
    
    // 初始化时钟的时、分、秒
    clock_c->Second = 0;
    clock_c->Minute = 0;
    clock_c->Hour = 0;
    

    clock_c->pClock_Add = Clock_Add;
    clock_c->pClock_Print = Clock_Print;
    
    // 将当前时钟对象指针赋值给全局指针pthis
    pthis = clock_c;
    return clock_c;
}

// 创建一个带参数的时钟对象并返回指针
pClock Clock_CreateWithArgs(uint8_t Second,uint8_t Minute,uint8_t Hour)
{
    // 创建一个时钟对象
    pClock clock_c = Clock_Create();
    if(clock_c == NULL)
        return NULL;

    Count = Second;
    clock_c->Second = Second;
    clock_c->Minute = Minute;
    clock_c->Hour = Hour;
    
    return clock_c;
}

// 打印当前时钟时间
void Clock_Print(void)
{
    // 在OLED上显示时、分、秒
	OLED_ShowString(1, 1, "current time");
    OLED_ShowNum(2,1,pthis->Hour,2);
    OLED_ShowString(2, 3, ":");
    OLED_ShowNum(2,4,pthis->Minute,2);
    OLED_ShowString(2, 6, ":");
    OLED_ShowNum(2,7,pthis->Second,2);
	OLED_ShowString(3, 1, "good night");
}

// 增加时钟的秒数并更新时、分、秒
void Clock_Add(void)
{
    // 将Count值赋给秒数
    pthis->Second = Count;
    if(pthis->Second == 60)
    {
        // 秒数达到60时，增加分钟并重置秒数
        pthis->Minute ++;
        pthis->Second = 0;
        Count = 0;
        
        if(pthis->Minute == 60)
        {
            // 分钟达到60时，增加小时并重置分钟
            pthis->Hour ++;
            pthis->Minute = 0;
            
            if(pthis->Hour == 24)
            {
                // 小时达到24时，重置小时
                pthis->Hour = 0;
            }
        }
    }
}
