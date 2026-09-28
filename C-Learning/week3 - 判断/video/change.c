#include <stdio.h>

int main()
{
    //变量初始化
	int price = 0;
	int money = 0;
	
	//输入数据
	printf("请输入购买的金额：（元）");
	scanf("%d", &price);
	printf("请输入支付的票面：（元）");
	scanf("%d", &money);
	
	//计算找零
	int change = money - price;
	
	//判断钱是否足够
	if (change >= 0) {
		printf("需找零%d元。", change);
	} else {
		printf("您的钱不够！");
	}
	
	return 0;
}