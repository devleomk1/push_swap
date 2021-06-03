/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_lst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 16:07:11 by jisokang          #+#    #+#             */
/*   Updated: 2021/06/03 16:13:31 by jisokang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

typedef struct DNODE {
	int val;
	struct DNODE *prev, *next;
}DNODE;

void freelist(DNODE *head)
{
	DNODE *next;
	while (head) {
		next = head->next;
		free(head);
		head = next;
	}
}

void printlist(DNODE *head)
{
	printf("Qsort: ");
	while (head) {
		printf("%d ", head->val);
		head = head->next;
	}puts("");
}

void mySwap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void goQuickSort(DNODE *head, DNODE *tail, int left, int right) {
	if (left >= right) return;
	int L = left;
	int R = right + 1;
	DNODE* Lnode = head;
	DNODE* Lprev = head->prev;
	DNODE* Rnode = tail;
	DNODE* Rnext = tail->next;
	DNODE* dump = (DNODE*)malloc(sizeof(DNODE));
	Rnode->next = dump;
	dump->prev = Rnode;
	Rnode = Rnode->next;
	while (L < R) {
		do {
			L++;
			Lnode = Lnode->next;
		} while (L <= right && Lnode->val < head->val);
		do {
			R--;
			Rnode = Rnode->prev;
		} while (R > left && Rnode->val > head->val);
		if (L < R) mySwap(&Lnode->val, &Rnode->val);
	}
	mySwap(&head->val, &Rnode->val);
	free(dump);
	tail->next = Rnext;

	goQuickSort(head, Rnode->prev, left, R - 1);
	goQuickSort(Rnode->next, tail, R + 1, right);
}

DNODE *quicksort_list(DNODE *head, DNODE *tail, int size)
{
	goQuickSort(head, tail, 0, size - 1);
	return head;
}

int main()
{
	int i, N;
	int val;
	DNODE *head, *tail, *cur;

	printf("N? ");
	scanf("%d", &N);

	head = tail = NULL;
	for (i = 0; i<N; i++) {
		if (scanf("%d", &val) != 1) {
			printf("잘못된 값.\n");
			freelist(head);
			exit(0);
		}
		else {
			cur = (DNODE*) malloc(sizeof(DNODE));
			cur->val = val;
			cur->next = NULL;
			if (!head) {
				cur->prev = NULL;
				head = tail = cur;
			}
			else {
				tail->next = cur; cur->prev = tail;
				tail = cur;
			}
		}
	}
	head = quicksort_list(head, tail, N);
	printlist(head);
	freelist(head);

	return 0;
}
