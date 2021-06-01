#include "../include/push_swap.h"

void sort_quick(int mode, struct D_NODE *left, struct D_NODE *right )
{
	// key_node : pivot를 나타냄, right값을 가짐.
	// 링크드리스트이기때문에 배열과 같이 index를 나타내는 부분이 없음.
	// -> 그래서 nleft, nright, nTotal 값으로 index를 check.
	// 해당 index는 list_count() 함수로 구함.

	struct D_NODE *Key_node, *left_node, *right_node;
	int nleft=1,nright, nTotal;

	nTotal = list_count(right,left,right);
	nright = nTotal-1;

	// 정렬 해야되는 노드 수가 1개일경우 재귀함수 종료
	if(nright <= 0)	return;

	Key_node =  right;
	left_node = left;
	right_node = right->list.pre_node;

	while(1)
	{
		//mode 1 : 오름차순 정렬
		//mode 2 : 내림차순 정렬
		if(mode ==1)
		{
			// key값을 기준으로 left 값과 right값 비교하면서 이동
			while( left_node->number < Key_node->number)
			{
				left_node = left_node->list.next_node;
				nleft++;
			}
			while( right_node->number > Key_node->number)
			{
				if(nright <=1 || right_node->list.pre_node ==NULL )
					break;
				right_node = right_node->list.pre_node;
				nright--;
			}
		}else if(mode== 2)
		{
			while( left_node->number > Key_node->number)
			{
				left_node = left_node->list.next_node;
				nleft++;
			}
			while( right_node->number < Key_node->number)
			{
				if(nright <=1 || right_node->list.pre_node ==NULL )
					break;
				right_node = right_node->list.pre_node;
				nright--;
			}
		}

		// while 종료 조건
		if(nleft >= nright)
			break;
		// 정렬
		swap_node(left_node, right_node);

		left_node = left_node->list.next_node;
		nleft++;
		right_node = right_node->list.pre_node;
		nright--;
	}

	// 기준이 되는 key을 변경
	swap_node(Key_node, left_node);

	// key(pivot) 값을 기준으로 왼쪽 리스트 정렬시 재귀
	if(left_node->list.pre_node != NULL && nleft-1 > 0)
		if(left_node->list.next_node != left && left->list.pre_node !=left_node)
			sort_quick(mode, left, left_node->list.pre_node);

	// key(pivot) 값을 기준으로 오른쪽 리스트 정렬시 재귀
	if(left_node->list.next_node != NULL && nleft < nTotal )
		if((left_node->list.pre_node != right) &&  (right->list.next_node != left_node))
			sort_quick(mode, left_node->list.next_node, right);

}
