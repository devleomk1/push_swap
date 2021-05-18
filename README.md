# push_swap
이 프로젝트를 통해 스택에 있는 데이터를 정렬할 수 있습니다. 제한된 명령 집합을 사용하여 다음을 수행합니다. 가능한 최저 작업 수 성공하려면 다양한 유형의 알고리즘을 조작하고 최적화된 데이터 정렬에 가장 적합한 솔루션을 선택해야 합니다.

## 사용 가능한 명령:
아래 이동 명령만 사용 가능합니다.
- `sa`,`sb`(swap a) : Stack a(b)의 상단(Top) 두 개 원소의 위치를 바꾼다. 만약 Stack 원소 갯수가 1개 이하면 수행하지 않는다.
- `ss`: **sa**와 **sb**를 동시에 수행한다.
- `pa`, `pb`(push a, b)
    1. Take the first element at the top of **b** and put it at the top of **a**.
    2. Do nothing if **b** is empty.
- `ra`, `rb`(rotate a, b)
    1. Shift up all elements of stack **a**(b) by 1.
    2. The first element becomes the last one.
- `rr` : ra와 rb를 동시에 수행한다.
- `rra`, `rrb`(reverse rotate a, b)
    1. Shift down all elements of stack a by 1.
    2. The last element becomes the first one.
- `rrr` : **rra**와 **rrb**를 동시에 수행한다.

At the end, stack b must empty empty and all integers must be in stack a, sorted in ascending order.
