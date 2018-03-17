#include<stdio.h>
#include"buy_book.h"
void main()
{
	unsigned i = 5, j = 0;
	int arr[5];
	for(j=0; j<i; j++){
		scanf("%d",&arr[j]);
	}
	printf("这批书本最低价格是：%f 欧元\n",Calc_Book_Cost(arr));
}

float Calc_Book_Cost(
	int book_num[]
)
{
	float book_cost = 0.0;
	/*各种组合的数量情况*/
	unsigned int x1 = 0;  
	unsigned int x2 = 0;  
	unsigned int x3 = 0;  
	unsigned int x4 = 0; 
	unsigned int x5 = 0;  
	/*排列组合之后各类书籍是否为空标志*/
	unsigned char flag_x1 = 0;
	unsigned char flag_x2 = 0;
	unsigned char flag_x3 = 0;
	unsigned char flag_x4 = 0;
	unsigned char flag_x5 = 0;
	while(1){
		book_num[0]--;
		book_num[1]--;
		book_num[2]--;
		book_num[3]--;
		book_num[4]--;
		if(book_num[0] < 0){
			flag_x1 = 1;
		}
		if(book_num[1] < 0){
			flag_x2 = 1;
		}
		if(book_num[2] < 0){
			flag_x3 = 1;
		}
		if(book_num[3] < 0){
			flag_x4 = 1;
		}
		if(book_num[4] < 0){
			flag_x5 = 1;
		}
		/*5本不同书的情况数量*/
		if(flag_x1+flag_x2+flag_x3+flag_x4+flag_x5 == 0){
			x5++;
		}
		/*4本不同书的情况数量*/
		else if(flag_x1+flag_x2+flag_x3+flag_x4+flag_x5 == 1){
			x4++;
		}
		/*3本不同书的情况数量*/
		else if(flag_x1+flag_x2+flag_x3+flag_x4+flag_x5 == 2){
			x3++;
		}
		/*2本不同书的情况数量*/
		else if(flag_x1+flag_x2+flag_x3+flag_x4+flag_x5 == 3){
			x2++;
		}
		/*1本不同书的情况数量*/
		else if(flag_x1+flag_x2+flag_x3+flag_x4+flag_x5 == 4){
			x1++;
		}
		else{
			break;
		}
	}
	/*对于“5+3”的折扣小于“4+4”的情况处理*/
	if(x5 > 0 && x3 > 0){
		if(x5 <= x3){
			x4 = x4 + 2 * x5;
			x3 = x3 - x5;
			x5 = 0;
		}
		else{
			x4 = x4 + 2 * x3;
			x5 = x5 - x3;
			x3 = 0;
		}
	}
	/*根据各种组合情况数量计算出总价钱*/
	book_cost = (x5*5*(1-DISCOUNT_FOUR) + x4*4*(1-DISCOUNT_THREE) + x3*3*(1-DISCOUNT_TWO) + x2*2*(1-DISCOUNT_ONE) + x1)*BOOK_PRICE;
	return book_cost;
} 