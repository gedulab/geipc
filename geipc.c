#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#define NUM 512
int a[NUM][NUM];
int b[NUM][NUM];
int c[NUM][NUM];

int gil_multiply1(int msize, int a[][NUM], int b[][NUM], int c[][NUM])
{
        int i, j, k;
        for( i = 0; i< msize;i++)
                for(j = 0; j< msize;j++)
                        for(k = 0; k < msize; k++)
                        {
                        c[i][j] = c[i][j] + a[i][k] * b[k][j];
                        }
        return 0;
}
int gil_multiply2(int msize, int a[][NUM], int b[][NUM], int c[][NUM])
{
	int i, j, k;
	for( i = 0; i< msize;i++)
		for(k = 0; k < msize; k++)
	                for(j = 0; j< msize;j++)
			{
			c[i][j] = c[i][j] + a[i][k] * b[k][j];
			}
	return 0;
}	
// i + i+1 +...
int gil_sum(int end)
{
	register int sum = 0, start = 0;
	do {
		sum += start++;
	} while(start < end);

	return sum;
}
int gil_pure(int argc, const char* argv[])
{
	register uint64_t start = 0, sum = 0;
	register uint64_t end = argc > 2 ? atoi(argv[2]) : 0x7ffffffff;
	do {
		sum += start++;
	} while (start < end);

	return (int)sum;
}
int gil_balance(int argc, const char* argv[])
{
        register uint64_t start = 0, sum = 0;
        uint64_t end = argc > 2 ? atoi(argv[2]) : 0x7ffffffff;
        do {
                sum += start++;
        } while (start < end);

        return (int)sum;
}


int usage(const char* err)
{
	if(err) puts(err);
	printf("geipc %d.%d - labs to study IPC\n"
		"geipc <labname>\n"
		"\t-1 - matrix multiplication with cross row access\n"
		"\t-2 - matrix multiplication without cross row access\n"
		"\t-s - sum in registers with const end\n"
		"\t-p - sum in registers with specified end\n"
		"\t-b - sum in register and stack var\n",
	0, 1);
	return -1;	
}

int main(int argc, const char* argv[])
{
	int ret = 0;
	if(argc < 2) {
		return usage("missing lab name");
	}
	switch(argv[1][1]) {
	case '1':
		ret = gil_multiply1(NUM, a, b, c);
		break;
	case '2':
                ret = gil_multiply2(NUM, a, b, c);
                break;
	case 's':
		ret = gil_sum(0x7fffffff);
		break;
	case 'p':
		ret = gil_pure(argc, argv);
		break;
        case 'b':
                ret = gil_balance(argc, argv);
                break;
	
	}
	return ret;
}

