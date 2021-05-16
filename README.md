# push_swap
이 프로젝트를 통해 스택에 있는 데이터를 정렬할 수 있습니다. 제한된 명령 집합을 사용하여 다음을 수행합니다. 가능한 최저 작업 수 성공하려면 다양한 유형의 알고리즘을 조작하고 최적화된 데이터 정렬에 가장 적합한 솔루션을 선택해야 합니다.

Only these moves are allowed:

- 'sa' : swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements).
- 'sb' : swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements).
- 'ss': sa and sb at the same time.
- 'pa' : push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
- 'pb' : push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
- 'ra' : rotate a - shift up all elements of stack a by 1. The first element becomes the last one.
- 'rb' : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
- 'rr' : ra and rb at the same time.
- 'rra' : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.
- 'rrb' : reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.
- 'rrr' : rra and rrb at the same time.

At the end, stack b must empty empty and all integers must be in stack a, sorted in ascending order.
