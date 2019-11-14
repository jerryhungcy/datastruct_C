#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n_value, list[100], change = 0;
	
	scanf("%d", &n_value);		// 輸入資料群個數  
	for(int i = 0; i < n_value; i++)
		scanf("%d", &list[i]);
	for(int i = 0; i < n_value; i++)
		for(int j = 0; j < n_value; j++)
			if(list[i + j] > list[i + j + 1] && (i + j + 1) < n_value)
			{				
				int tmp = list[i + j];
				list[i + j] = list[i + j + 1];
				list[i + j + 1] = tmp;
				
				for(int x = i + j + 1; x > 0; x--)
					if(list[x - 2] > list[x - 1])
					{
						int tmp = list[x - 1];
						list[x - 1] = list[x - 2];
						list[x - 2] = tmp;						
					}					
				change++;
				if(change <= 2)
					for(int k = 0; k < change + 1; k++)
					{
						if(k != change)
							printf("%d ", list[k]);
						else
							printf("%d\n", list[k]);
					}
			}
	for(int m = 0; m < n_value; m++)
	{
		if(m != n_value - 1)
			printf("%d ", list[m]);
		else
			printf("%d\n", list[m]);
	}
    //system("pause");
    return 0;
}