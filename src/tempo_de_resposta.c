// tempo_de_resposta.c (Roland Teodorowitsch; 31/03/2022)

#include <stdlib.h>
#include <stdio.h>
#include <math.h>


#define MAX_N 26

typedef struct {
	int c;
	int p;
	int d;
	int r;
	char s;
} task_t;



void bubble_sort(task_t t[], int n)
{
	int i, j;
	for (i = 0; i < n-1; i++) {
		for (j = i+1; j < n; j++) {
			if (t[i].d > t[j].d) {
				task_t tmp = t[i];
				t[i] = t[j];
				t[j] = tmp;
			}
		}
	}
}

int calculate_i(task_t tasks[], int r, int k)
{
	if (k==0) 
		return ceil((double) r/tasks[k].p) * tasks[k].c;
	else
		return ceil((double) r/tasks[k].p) * tasks[k].c + calculate_i(tasks, r, k-1);
}

// int calculate_rec_r(task_t tasks[], int t, int i)
// {
// 	if (t==0||i==0) return tasks[t].c;
	
// 	int prev_r = calculate_rec_r(tasks, t, i-1);

// 	// int interf_sum = 0;
	
// 	// int k;
// 	// for (k=0; k<t; k++)
// 	// 	interf_sum += ceil((double) prev_r/tasks[k].p) * tasks[k].c;

// 	// int this_r = tasks[t].c + interf_sum;
// 	int this_r = tasks[t].c + calculate_i(tasks, prev_r, t-1);

// 	return (this_r == prev_r) ? this_r : calculate_rec_r(tasks, t, i+1);

// }

int calculate_rec_r(task_t tasks[], int t, int i)
{
	int r = tasks[t].c;
	int prev_r = 0;
	
	while(prev_r != r)
	{
		prev_r = r;
		int sum_i = 0; 
		int k;
		for (k=0; k<t; k++)
			sum_i += ceil((double) prev_r/tasks[k].p) * tasks[k].c;
		r = tasks[t].c + sum_i;
	}

	return r;
}

void calculate_r(task_t tasks[], int t)
{
	tasks[t].r = calculate_rec_r(tasks, t, 0);
	tasks[t].s = (tasks[t].r <= tasks[t].d) ? 'S' : 'N';
}

void test_schedule_rt(task_t tasks[], int tsize)
{
	bubble_sort(tasks, tsize);
	int i;
	for (i=0; i<tsize; i++)
		calculate_r(tasks, i);
}

int main() {
	int i, n, t;
	task_t tasks[MAX_N];
	
	while (1) {
		// LEITURA
		scanf("%d%d",&n,&t);
		if (n==0 || t==0)
			break;
		for (i=0; i<n; ++i) {
			scanf("%d%d%d",&tasks[i].c,&tasks[i].p,&tasks[i].d);
		}

		test_schedule_rt(tasks, n);
		
		// ESCRITA
		for (i=0; i<n; ++i)
			printf("%d %c\n",tasks[i].r,tasks[i].s);
		printf("\n");
	}
	return 0;
}