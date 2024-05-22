#include <stdio.h>
#define MAX_LIST_SIZE 100

typedef int element;
typedef struct{
	element array[MAX_LIST_SIZE];
	int size;
} ArrayListType;

init(ArrayListType* L) {
	L->size = 0;
}

void error(char* message) {
	fprintf(stderr, "%s\n", message);
}

int is_full(ArrayListType* L) {
	// if (L->size >= MAX_LIST_SIZE) return 1;
	// else return 0;
	return (L->size == MAX_LIST_SIZE);
}

void insert(ArrayListType* L, int pos, element item) {
	if (!is_full(L) && (pos >= 0) && (pos <= L->size)) {
		for (int i = L->size - 1; i >= pos; i = i - 1) {
			L->array[i + 1] = L->array[i];
		}
		L->array[pos] = item;
		L->size = L->size + 1;
	}
}

void insert_last(ArrayListType* L, element item) {
	if (L->size == MAX_LIST_SIZE) {
		error("리스트 오버플로우");
	}
	L->array[L->size++] = item;
}

void insert_first(ArrayListType* L, element item) {
	insert(L, 0, item);
}

void clear(ArrayListType* L) {
	init(L);
}

element get_entry(ArrayListType* L, int pos) {
	if (pos > 0 && pos < L->size)
		return L->array[pos];
	else
		error("위치 오류");
}

int get_length(ArrayListType* L) {
	return L->size;
}

int is_empty(ArrayListType* L) {
	return(L->size == 0);
}

void print_list(ArrayListType* L) {
	int i;
	for (i = 0; i < L->size; i++) {
		printf("&d -> ", L->array[i]);
	}
	printf("NULL\n");
}

element delete(ArrayListType* L, int pos) {
	if (pos < 0 || pos >= L->size)
		error("위치 오류");
	else {
		element item = L->array[pos];
		for (int i = pos; i < (L->size - 1); i++) {
			L->array[i] = L->array[i + 1];
		}
		L->size = L->size - 1;
		return item;
	}
}

int main() {

	ArrayListType list;

	init(&list);
	int choice;
	

	while (1) {
		printf("\n메뉴:\n");
		printf("1. 리스트에 추가\n");
		printf("2. 리스트에서 삭제\n");
		printf("3. 리스트 출력\n");
		printf("0. 프로그램 종료\n");
		printf("선택: ");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			if (is_full(&list)) {
				printf("리스트가 꽉 찼습니다.\n");
			}
			else {
				int num;
				int pos;
				printf("숫자를 입력하세요: ");
				scanf("%d", &num);
				printf("추가할 위치를 입력하세요: ");
				scanf("%d", &pos);
				insert(&list, pos, num);
				printf("삽입 완료, 데이터 이동 횟수: ");
				int count_add = (get_lengh(&list)-pos)+1;
				printf("%d", count_add);
			}
			break;
			
		case 2:
			if (is_empty(&list)) {
				printf("리스트가 비어있습니다.\n");
			}
			else {
				int num;
				printf("삭제할 위치를 입력하세요: ");
				scanf("%d", &num);
				delete(&list, num);
				printf("삭제 완료, 데이터 이동횟수: ");
				int count_sub = (get_lengh(&list) - pos);
				printf("%d", count_sub);
				
			break;

		case 3:
			print_list(&list);
			break;
			
		case 0:
			printf("프로그램 종료\n");
			return 0;

		default:
			printf("잘못된 선택입니다. 다시 시도하세요.\n");
		}
	}

}
