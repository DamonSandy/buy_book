#include<stdio.h>
#include"buy_book.h"
void main()
{
	unsigned i = 5, j = 0;
	int arr[5];
	for(j=0; j<i; j++){
		scanf("%d",&arr[j]);
	}
	printf("�����鱾��ͼ۸��ǣ�%f ŷԪ\n",Calc_Book_Cost(arr));
}

float Calc_Book_Cost(
	int book_num[]
)
{
	float book_cost = 0.0;
	/*������ϵ��������*/
	unsigned int x1 = 0;  
	unsigned int x2 = 0;  
	unsigned int x3 = 0;  
	unsigned int x4 = 0; 
	unsigned int x5 = 0;  
	/*�������֮������鼮�Ƿ�Ϊ�ձ�־*/
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
		/*5����ͬ����������*/
		if(flag_x1+flag_x2+flag_x3+flag_x4+flag_x5 == 0){
			x5++;
		}
		/*4����ͬ����������*/
		else if(flag_x1+flag_x2+flag_x3+flag_x4+flag_x5 == 1){
			x4++;
		}
		/*3����ͬ����������*/
		else if(flag_x1+flag_x2+flag_x3+flag_x4+flag_x5 == 2){
			x3++;
		}
		/*2����ͬ����������*/
		else if(flag_x1+flag_x2+flag_x3+flag_x4+flag_x5 == 3){
			x2++;
		}
		/*1����ͬ����������*/
		else if(flag_x1+flag_x2+flag_x3+flag_x4+flag_x5 == 4){
			x1++;
		}
		else{
			break;
		}
	}
	/*���ڡ�5+3�����ۿ�С�ڡ�4+4�����������*/
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
	/*���ݸ�������������������ܼ�Ǯ*/
	book_cost = (x5*5*(1-DISCOUNT_FOUR) + x4*4*(1-DISCOUNT_THREE) + x3*3*(1-DISCOUNT_TWO) + x2*2*(1-DISCOUNT_ONE) + x1)*BOOK_PRICE;
	return book_cost;
} 