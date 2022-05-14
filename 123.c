#include<stdio.h>
#include<stdbool.h>
#define MaxSize 50
typedef struct{
	int data[MaxSize];
	int length;
}SqList;
void ListInit(SqList *L){
	L->length = 0;
	for (int i = 0; i < MaxSize; i++)
		L->data[i] = 0;

}
bool ListInsert(SqList* L, int i, int e) {
	if (i<1 || i>L->length + 1)
	{

		return false;
	}
	if (L->length >= MaxSize)
		return false;
	for (int j = L->length; j >= i; j--)
	{
		L->data[j] = L->data[j - 1];
	}
	L->data[i - 1] = e;
	L->length++;
	return true;
}

void List_Printf(SqList* L) {
	for (int i = 0; i < L->length; i++)
		printf("%d  ", L->data[i]);
	printf("\n顺序表的长度为%d\n\n\n", L->length);
}
void SqList_Delete_s_t(SqList *L, int s, int t) {
	if (L->length == 0 || s >= t)
		return 0;
	int i = 0, j = 0;
	for (i; i < L->length; i++) {
		if (L->data[i] >=s && L->data[i] <= t)
			j++;
		else
			L->data[i - j] = L->data[i];
	}
	L->length -= j;
	return true;
}
int main()
{
	SqList list;
	SqList *L=&list;
	ListInit(L);
	ListInsert(L, 1, 7);
	ListInsert(L, 2, 2);
	ListInsert(L, 3, 6);
	ListInsert(L, 4, 4);
	ListInsert(L, 5, 5);
	int value=0;
	int* a = &value;
	SqList_Delete_s_t(L,3, 5);
	List_Printf(L);
	return 0;
}
