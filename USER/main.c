#include "sys.h"
#include "delay.h"
//#include "usart.h"
#include "led.h"

#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "sha3.h"


#define ITM_PORT8(n)         (*(volatile unsigned char *)(0xe0000000 + 4*(n)))
#define ITM_PORT16(n)        (*(volatile unsigned short *)(0xe0000000 + 4*(n)))
#define ITM_PORT32(n)        (*(volatile unsigned long *)(0xe0000000 + 4*(n)))
#define DEMCR                (*(volatile unsigned long *)(0xE000EDFC))
#define TRCENA               0X01000000

struct __FILE { int handle; /* Add whatever needed */ };
FILE __stdout;
FILE __stdin;

int fputc(int ch, FILE *f)
{
    if(DEMCR & TRCENA)
    {
        while(ITM_PORT32(0) == 0);                                                                                                                                                                                                                                                                                      
        ITM_PORT8(0) = ch;
    }
    return ch;
}


typedef enum
{
    SHA3_TEST_PASSED = 0,
    SHA3_TEST_FAILS,
    SHA3_TEST_NOT_IMPLEMENTED
}sha3_test_result_t;

unsigned char buf[5] = {0x11,0x22,0x33,0x44,0x55};

//---------------------------------------------------------------------
static void print_test_info(uint32_t test_num, sha3_test_result_t res)
{
    printf("\n ************print_test_info*********************** \n");
    //TODO
}

//---------------------------------------------------------------------
static void print_test_result(uint32_t test_num, sha3_test_result_t res)
{
    printf("\n ************************************************* \n");
    if (SHA3_TEST_PASSED == res)
    {
        printf("\n *************  SHA3 TEST %d PASSED  ************* \n", test_num);
    }
    else if (SHA3_TEST_FAILS == res)
    {
        printf("\n *************  SHA3 TEST %d FAILED  ************* \n", test_num);
    }
    else
    {
        printf("\n ********  SHA3 TEST %d NOT_IMPLEMENTED  ********* \n", test_num);
    }
    printf("\n ************************************************** \n");
}

//-------------------------------------------------------------------
//   TESTS
//--------------------------------------------------------------------

static sha3_test_result_t sha3_null_string_test(sha3_hash_modes_t sha3_mode, uint32_t repeat_num)
{
    sha3_test_result_t test_res = SHA3_TEST_FAILS;

    const uint8_t input_str[] = "abc";

    uint8_t output_str[SHA3_512_HASH_LEN] = {0};

    //TODO add test vectors
    const uint8_t output_reference_res_sha3_224[SHA3_224_HASH_LEN] = {0};
    const uint8_t output_reference_res_sha3_256[SHA3_256_HASH_LEN] = {0};
    const uint8_t output_reference_res_sha3_384[SHA3_384_HASH_LEN] = {0};
    const uint8_t output_reference_res_sha3_512[SHA3_512_HASH_LEN] = {0};

    sha3_status_t res  = SHA3_ERROR;

    int i = 0;

    for(i = 0; i < repeat_num; i++)
    {
        res = SHA3(sha3_mode, input_str, (uint32_t)strlen((const char *)input_str), output_str);

        if(SHA3_ERROR == res)
        {
            return SHA3_TEST_FAILS;
        }

        switch (sha3_mode)
        {
            case SHA3_224:
                if(!memcmp(output_reference_res_sha3_224, output_str, SHA3_224_HASH_LEN))
                {
                    test_res = SHA3_TEST_PASSED;
                }
                else
                {
                    test_res = SHA3_TEST_FAILS;
                }
                break;
            case SHA3_256:
                if(!memcmp(output_reference_res_sha3_256, output_str, SHA3_256_HASH_LEN))
                {
                    test_res = SHA3_TEST_PASSED;
                }
                else
                {
                    test_res = SHA3_TEST_FAILS;
                }
                break;
            case SHA3_384:
                if(!memcmp(output_reference_res_sha3_384, output_str, SHA3_384_HASH_LEN))
                {
                    test_res = SHA3_TEST_PASSED;
                }
                else
                {
                    test_res = SHA3_TEST_FAILS;
                }
                break;
            case SHA3_512:
                if(!memcmp(output_reference_res_sha3_512, output_str, SHA3_512_HASH_LEN))
                {
                    test_res = SHA3_TEST_PASSED;
                }
                else
                {
                    test_res = SHA3_TEST_FAILS;
                }
                break;
            default:
                test_res = SHA3_TEST_FAILS;
                break;

        }

        if(SHA3_TEST_FAILS == test_res)
        {
            print_test_result(i, test_res);
            return test_res;
        }
    }

    print_test_result(i, test_res);
    return test_res;
}

//---------------------------------------------------------------------
static sha3_test_result_t sha3_ancronim_string_test(sha3_hash_modes_t sha3_mode, uint32_t repeat_num)
{
    sha3_test_result_t test_res = SHA3_TEST_FAILS;

    const uint8_t input_str[] = "The quick brown fox jumps over the lazy dog";

    uint8_t output_str[SHA3_512_HASH_LEN] = {0};

    //TODO add test vectors
    const uint8_t output_reference_res_sha3_224[SHA3_224_HASH_LEN] = {0};
    const uint8_t output_reference_res_sha3_256[SHA3_256_HASH_LEN] = {0};
    const uint8_t output_reference_res_sha3_384[SHA3_384_HASH_LEN] = {0};
    const uint8_t output_reference_res_sha3_512[SHA3_512_HASH_LEN] = {0};

    sha3_status_t res  = SHA3_ERROR;

    int i = 0;

    for(i = 0; i < repeat_num; i++)
    {
        res = SHA3(sha3_mode, input_str, (uint32_t)strlen((const char *)input_str), output_str);

        if(SHA3_ERROR == res)
        {
            return SHA3_TEST_FAILS;
        }

        switch (sha3_mode)
        {
            case SHA3_224:
                if(!memcmp(output_reference_res_sha3_224, output_str, SHA3_224_HASH_LEN))
                {
                    test_res = SHA3_TEST_PASSED;
                }
                else
                {
                    test_res = SHA3_TEST_FAILS;
                }
                break;
            case SHA3_256:
                if(!memcmp(output_reference_res_sha3_256, output_str, SHA3_256_HASH_LEN))
                {
                    test_res = SHA3_TEST_PASSED;
                }
                else
                {
                    test_res = SHA3_TEST_FAILS;
                }
                break;
            case SHA3_384:
                if(!memcmp(output_reference_res_sha3_384, output_str, SHA3_384_HASH_LEN))
                {
                    test_res = SHA3_TEST_PASSED;
                }
                else
                {
                    test_res = SHA3_TEST_FAILS;
                }
                break;
            case SHA3_512:
                if(!memcmp(output_reference_res_sha3_512, output_str, SHA3_512_HASH_LEN))
                {
                    test_res = SHA3_TEST_PASSED;
                }
                else
                {
                    test_res = SHA3_TEST_FAILS;
                }
                break;
            default:
                test_res = SHA3_TEST_FAILS;
                break;

        }

        if(SHA3_TEST_FAILS == test_res)
        {
            print_test_result(i, test_res);
            return test_res;
        }
    }

    print_test_result(i, test_res);
    return test_res;
}

//---------------------------------------------------------------------
static sha3_test_result_t sha3_sream_test(sha3_hash_modes_t sha3_mode)
{
    //TODO
    return SHA3_TEST_NOT_IMPLEMENTED;
}
unsigned char* test_ip(unsigned char *data,int len){

	unsigned char a[] ={0,0,0,0,0};
	unsigned char c[] ={0,0,0,0,0};
	unsigned char *b;
	unsigned char i;
	memcpy(&c[0],data,5);
	for(i=0;i<5;i++)
	{
		a[i] = *(data +i);
		b = data ;
		
		printf("a[%d]=%x      ",i,a[i]);
		printf("c[%d]=%x      ",i,c[i]);
		printf("[%x] = %x\n",b+i,*(b+i));
		
	}
	
	
	return data;
}
int main(void)
{ 
  unsigned char g[] = {0,0,0,0,0};
	unsigned char j;
	unsigned char *k;
	delay_init(168);		  //初始化延时函数
	LED_Init();		        //初始化LED端口
	
  /**下面是通过直接操作库函数的方式实现IO控制**/	
	
	while(1)
	{
	GPIO_ResetBits(GPIOF,GPIO_Pin_9);  //LED0对应引脚GPIOF.9拉低，亮  等同LED0=0;
	GPIO_SetBits(GPIOF,GPIO_Pin_10);   //LED1对应引脚GPIOF.10拉高，灭 等同LED1=1;
	delay_ms(500);  		   //延时300ms
	GPIO_SetBits(GPIOF,GPIO_Pin_9);	   //LED0对应引脚GPIOF.0拉高，灭  等同LED0=1;
	GPIO_ResetBits(GPIOF,GPIO_Pin_10); //LED1对应引脚GPIOF.10拉低，亮 等同LED1=0;
	delay_ms(500);                     //延时300ms
		
		k = test_ip(buf,5);
		for(j=0;j<5;j++)
	{
		g[j] = *(test_ip(buf,5) +j);
		printf("[%x] = %x     ",k+j,*(k+j));
		printf("g[%d] = %x\n",j,g[j]);
		
	}
   // sha3_null_string_test(SHA3_256, 1);
   // sha3_ancronim_string_test(SHA3_256, 1);
		
		
		
		
		
	}
}



 



