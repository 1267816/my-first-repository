#include <stdio.h>
int main()
{
	int hour1;
	int hour2;
	int minute1;
	int minute2;
	
	scanf("%d %d", &hour1, &minute1);
	scanf("%d %d", &hour2, &minute2);
	
	int ih = hour2 - hour1;
	int im = minute2 - minute1;
	
	if (im < 0){
		im = im + 60;
		ih = ih - 1;
	}
	printf("时差是%d小时%d分\n", ih, im);
	return 0;
}