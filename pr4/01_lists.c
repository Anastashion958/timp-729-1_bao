#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
	int value;          // значение, которое хранит узел 
	struct node *next;  // ссылка на следующий элемент списка
	struct node *prev;  // ссылка на предыдущий элемент списка
} node;

typedef struct list {
	struct node *head;  // начало списка
	struct node *tail;  // конец списка
} list;

void init(list *l){
    l->head = 0;
    l->tail = 0;
}

bool is_empty(list *l)
{
bool b = false;
node *l1 = l;
	if(l->head == 0)
	{
		b = true;
		printf("Пустой\n");
		return b;
	}
	else
	{
		printf("Не пустой\n");
	}

}

// вставка значения в конец списка, вернуть 0 если успешно
int push_back(list* l, int n)
{
    node* l1 = (node*) malloc(sizeof(node));
    l1->value = n;
    l1->next = 0;
	l1->prev = l->tail;
    if (l->tail) {
        l->tail->next = l1;
    }
    l->tail = l1;
 
    if (l->head == NULL) {
        l->head = l1;
    }
	return 0;
}

// вывод
void print(list *l)
{
    for(node* l1 = l->head; l1; l1 = l1->next)
	{
		printf("%d ", l1->value);
	}
	printf("\n");
}

// вывести все значения из списка в обратном порядке через пробел,
// после окончания вывода перейти на новую строку
void print_invers(list *l)
{
    for(node* l1 = l->tail; l1; l1 = l1->prev)
	{
		printf("%d ", l1->value);
	}
	printf("\n");
}

// поиск элемента по значению. вернуть NULL если элемент не найден
void find(list *l, int k)
{
	bool b;
	b = false;

    for(node* l1 = l->head; l1; l1 = l1->next)
	{
		if(l1->value == k)
			{
				b = true;
				printf("%d ", 1);
				break;
			}
	}
	if(b == false)
	{
		printf("%d ", 0);
	}
}

// вставка значения в начало списка, вернуть 0 если успешно
int push_front(list *l, int value)
{
	node *l1 = (node*) malloc(sizeof(node));
    l1->value = value;
    l1->next = l->head;
    l1->prev = NULL;
    if (l->head) {
        l->head->prev = l1;
    }
    l->head = l1;

	return 0;
}

// вставка значения после указанного узла, вернуть 0 если успешно
int insert_after(list *l, int value, int value1)
{
 	int i = 0;
    node *l1;
    node *current = l->head;
    for(i = 1; i < value; i++)
	{
		current = current->next;
	}
    if (value == 0)
	{
     	l1->next = l;
		l1->prev = NULL;
     	l = l1;
		return 0;
    }
    l1 = (node*)malloc(sizeof(node));
    l1->value = value1; 
    l1->next = current->next;
	l1->prev = current;
	if (current->next) {
        current->next->prev = l1;
    }
    current->next = l1;
	if (current->prev == NULL) {
        l->head = current;
    }
    if (current->next == NULL) {
        l->tail = current;
    }
     return 0; 
}

// вставка значения перед указанным узлом, вернуть 0 если успешно
int insert_before(list *l, int value, int value1)
{
  	int i = 0;
    node *l1;
    node *current = l->head;
    for(i = 1; i < (value - 1); i++)
	{
		current = current->next;
	}
    if (value == 0)
	{
     	l1->next = l;
		l1->prev = NULL;
     	l = l1;
		return 0;
    }
    l1 = (node*)malloc(sizeof(node));
    l1->value = value1; 
    l1->next = current->next;
	l1->prev = current;
	if (current->next) {
        current->next->prev = l1;
    }
    current->next = l1;
	if (current->prev == NULL) {
        l->head = current;
    }
    if (current->next == NULL) {
        l->tail = current;
    }
     return 0; 
}

// удалить первый элемент из списка с указанным значением, 
// вернуть 0 если успешно
int remove_node(list *l, int value)
{
	node *l1;
	node *current = l->head;
 
	while(current) 
	{
    	if (current->value == value) 
		{
    		if (current->prev) {
        	current->prev->next = current->next;
    		}
    		if (current->next) {
        	current->next->prev = current->prev;
    		}
    		l1 = current->value;
 
    		if (current->prev == NULL) {
        	l->head = current->next;
    		}
    		if (current->next == NULL) {
        	l->tail = current->prev;
   			}
 
    		free(current);
			return 0; 
    	}
    l1 = current;
    current = l1->next;
	}
	return 0;
}

// удалить последний элемент из списка с указанным значением, 
// вернуть 0 если успешно
int remove_last(list *l, int value)
{
node *l1;
	node *current = l->tail;
 
	while(current) 
	{
    	if (current->value == value) 
		{
    		if (current->prev) {
        	current->prev->next = current->next;
    		}
    		if (current->next) {
        	current->next->prev = current->prev;
    		}
    		l1 = current->value;
 
    		if (current->prev == NULL) {
        	l->head = current->next;
    		}
    		if (current->next == NULL) {
        	l->tail = current->prev;
   			}
 
    		free(current);
			return 0;
    	}
    l1 = current;
    current = l1->prev;
	}
	return 0;
}

// удалить все элементы из списка
void clean(list *l)
{
node *l1;
	node *current = l->head;
 
	while(current) 
	{
    		if (current->prev) {
        	current->prev->next = current->next;
    		}
    		if (current->next) {
        	current->next->prev = current->prev;
    		}
    		l1 = current->value;
 
    		if (current->prev == NULL) {
        	l->head = current->next;
    		}
    		if (current->next == NULL) {
        	l->tail = current->prev;
   			}
 
    		free(current);
    l1 = current;
    current = l1->next;
	}
}
int main() {

	int n = 0, n1 = 0, k1 = 0, k2 = 0, k3 = 0, m = 0, t = 0, j = 0, x = 0, u = 0, y = 0, z = 0, r = 0;

	scanf("%d", &n);

		list l;
		init(&l);
		//is_empty(&l);

		for(int i = 0; i < n; i++)
		{
		scanf("%d", &n1);
		push_back(&l, n1);
		}
		print(&l);
		
	scanf("%d%d%d", &k1, &k2, &k3);
		
		find(&l, k1);
		find(&l, k2);
		find(&l, k3);
		printf("\n");

	scanf("%d", &m);
		
		push_back(&l, m);
		print_invers(&l);

	scanf("%d", &t);

		push_front(&l, t);
		print(&l);

	scanf("%d%d", &j, &x);
		
		insert_after(&l, j, x);
		print_invers(&l);

	scanf("%d%d", &u, &y);
		
		insert_before(&l, u, y);
		print(&l);

	scanf("%d", &z);
		
		remove_node(&l, z);
		print_invers(&l);
	
	scanf("%d", &r);
		
		remove_last(&l, r);
		print(&l);


	return 0;
};
