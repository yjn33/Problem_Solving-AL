/*
*	only iso / gnu c99
*	made by https://github.com/yjn33/Problem_Solving-AL
*	2024.12.30
*
*
*	내일배움캠프 코드카타 123번 하노이의 탑
*	
*	문제출처:
*	https://school.programmers.co.kr/learn/courses/30/lessons/12946
*/


#include <stdio.h>
#include <stdlib.h> // malloc 함수 사용


#define NULL_PTR ((void*)0) // implementation defined NULL


// 스택 구조체
typedef struct stack_node
{
	void *data; // 제네릭 포인터
	struct stack_node *link; // 자기참조 포인터

}STK_NODE;

typedef struct stack_type // 스택클래스 모사
{
	STK_NODE *top;
	
}STK;
// 스택 구조체



// 하노이탑 반복문 구조체
struct hanoi_data // 4 + 1 + 1 + 1 + 1 = 8byte
{
	int n;
	char src;
	char dest;
	char temp;
	char vst; // 메모리 정렬을 위해 int 또는 bool(c99)이 아닌 char로 방문변수 선언

};
// 하노이탑 반복문 구조체



// 프로토타입 함수 선언
//스택 프로토타입
void stk_init(STK **);
void stk_push(STK *, void*);
void *stk_pop(STK *);


//하노이탑 프로토타입
int hanoi_recursion(char, char, char, int);
void hanoi_iteration(char, char, char, int);
// 프로토타입 함수 선언


int cnt = 0; // 하노이탑 재귀함수 실행횟수 카운트를 위한 전역변수 선언


int main(void)
{
	
	//hanoi_recursion('A', 'C', 'B', 15);
	//printf("cnt %d", cnt); // 하노이탑 재귀 함수 실행횟수 카운트
	
	hanoi_iteration('A', 'C', 'B', 3);
	
	return 0;
}




int hanoi_recursion(char src, char dest, char temp, int n)
{

	if( n < 1 ) // 재귀 종료 조건: 1 미만일 경우
	{
		return 0; // 0을 리턴과 함수 탈출 후 값 폐기
	}
	
	else
	{
		hanoi_recursion(src, temp, dest, n-1); // L
		
		printf("num %d %c -> %c \n", n, src, dest);  // V
		cnt++; // 재귀함수 카운트 전역변수
		
		hanoi_recursion(temp, dest, src, n-1); // R

	}

}




void hanoi_iteration(char src, char dest, char temp, int n)
{

	if(n <= 0) // 초기 원판 n의 값 검사
	{
		printf("원판 n의 값은 1 이상이여야 합니다.\n");
		return; // 함수 종료
	}
	
	else
	{
		// 코드 들여쓰기 방지
	}
	
	
	STK *proc_stk = NULL_PTR; // 재귀함수 모사를 위한 진행 스택 선언
	stk_init(&proc_stk); // 진행 스택 초기화
	
	struct hanoi_data *curr_stk = NULL_PTR; // 진행스택에서 pop한 제네릭 포인터를 역참조 하기 위한 변수
	
	struct hanoi_data *push_stk = malloc(sizeof(struct hanoi_data)); // 하노이 구조체 변수 동적 할당
	push_stk -> src = src;
	push_stk -> dest= dest;
	push_stk -> temp = temp;
	push_stk -> n = n;
	push_stk -> vst = 0;
	
	
	stk_push(proc_stk, push_stk); // 진행스택에 하노이 구조체 변수 적재
	
	
	char vst = 0; // 방문 변수
	
	// 이진트리 LVR 중위 순회를 응용한 하노이탑 코드 
	while(proc_stk -> top) // 진행 스택이 비을때까지 반복문 진행
	{

		curr_stk = stk_pop(proc_stk); // 하노이변수 제네릭 포인터 데이터 받기
		
		// 하노이변수 구조체 변수 역참조하여 함수 지역변수에 데이터 적재
		n = curr_stk -> n;
		src = curr_stk -> src;
		dest = curr_stk -> dest;
		temp = curr_stk -> temp;
		vst = curr_stk -> vst;
		
		free(curr_stk); // 하노이 구조체 변수 할당 해제 -> 반복문 진행마다 할당 해제로 메모리 누수 방지
		
		
		if(vst == 1) // 방문변수가 1이면 원판 옮기기 실행
		{
			printf("num %d %c -> %c \n", n, src, dest);

		}
		
		
		// 스택을 활용한 중위순회 구현
		else // 방문변수가 0일경우
		{
		
			if( !(n <= 1) ) // Right node 원판 n이 1이하가 아닐경우
			{
				push_stk = malloc(sizeof(struct hanoi_data));
				push_stk -> src = temp;
				push_stk -> dest = dest;
				push_stk -> temp = src;
				push_stk -> n = n - 1;
				push_stk -> vst = 0;
					
				stk_push(proc_stk, push_stk); 
			
			}
			
			else
			{
				// 코드 들여쓰기 방지
			}
			
			// V node 원판 n의 수에 상관없이 실행
			push_stk = malloc(sizeof(struct hanoi_data));
			push_stk -> src = src;
			push_stk -> dest= dest;
			push_stk -> temp = temp;
			push_stk -> n = n;
			push_stk -> vst = 1; // 방문변수 1설정
					
			stk_push(proc_stk, push_stk); 
			
						
			if( !(n <= 1) ) // Left node 원판 n이 1이하가 아닐경우
			{
				push_stk = malloc(sizeof(struct hanoi_data));
				push_stk -> src = src;
				push_stk -> dest = temp;
				push_stk -> temp = dest;
				push_stk -> n = n - 1;
				push_stk -> vst = 0;
					
				stk_push(proc_stk, push_stk); 
			
			}
			
			else
			{
				// 코드 들여쓰기 방지
			}
		
		}

	}
	
	free(proc_stk); // 진행스택 할당 해제
	
	return; // 함수 종료
}









// 스택 ADT
void stk_init(STK **s) // 스택 초기화
{
	(*s) = malloc(sizeof(STK)); // 스택 클래스 할당
	
	if( (*s) == NULL_PTR ) // 스택 메모리 할당 실패
	{
		printf("스택 초기화를 위한 heap공간이 부족합니다. 프로그램을 종료합니다.\n");
		exit(-1); // 프로그램 종료
	
	}
	
	else // 메모리 할당 성공시
	{
		(*s) -> top = NULL_PTR; // 스택 탑 초기화
	
	}
	
	return;

}


void stk_push(STK *s, void* input_data) // 스택 push, 스택 클래스, 모든 종류의 포인터 값
{

	STK_NODE *input_node = malloc(sizeof(STK_NODE)); // 스택 노드 할당
	
	if(input_node == NULL_PTR) // 스택 노드 메모리 할당 실패
	{
		printf("스택 노드 할당을 위한 heap공간이 부족합니다. 프로그램을 종료합니다.\n");
		exit(-1); // 프로그램 종료
	
	}
	
	else // 스택 노드 메모리 할당 성공
	{
		input_node -> data = input_data; // 할당된 노드에 push한 데이터 적재
		input_node -> link = NULL_PTR; // 스택 노드 링크 초기화
		
		if(s -> top == NULL_PTR) // 스택이 비었을경우
		{
			input_node -> link = NULL_PTR;
			s -> top = input_node;
		}
		
		else // 비어있지않은 스택일경우
		{
			input_node -> link = s -> top;
			s -> top = input_node;
		
		}

	}

	return;

}


void *stk_pop(STK *s) // 스택 pop, 스택 클래스
{
	STK_NODE *remove_node = NULL_PTR; // 할당된 탑 노드를 해제하기 위한 변수
	void *rtn_data = NULL_PTR; // 탑 노드 데이터 반환 변수
	
	if(s -> top == NULL_PTR) // 스택이 비었을경우
	{
		printf("해당 스택은 비어있습니다. NULL을 반환합니다. \n");
		return NULL_PTR; // (void*)0 반환
	
	}
	
	else // 스택에 노드가 하나라도 있을경우
	{
		remove_node = s -> top; // 탑 노드
		rtn_data = s -> top -> data; // 탑 노드 데이터
		
		s -> top = s -> top -> link; // 탑노드 아래 노드로 탑 위치 변경
		free(remove_node); // 기존의 탑 노드 할당 해제
		
		return rtn_data; // 기존의 탑 노드 데이터 반환
		
	}

}



