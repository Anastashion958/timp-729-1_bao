#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
	int size;
	int value;          // значение, которое хранит узел 
	struct node *next;  // ссылка на следующий элемент списка
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

void vvod(list* l, int n)
{
    node* l1 = (node*) malloc(sizeof(node));
    l1->value = n;
    l1->next = 0;
    if(l->head == 0)
    {
       l->head = l1;
       l->tail = l1;
       return;
    }
    l->tail->next = l1;
    l->tail = l1;
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

// вставка значения в конец списка, вернуть 0 если успешно
int push_back(list *l, int value)
{
	node *l1 = l;
	while (l1->next != NULL) 
	{
		l1 = l1->next;
	}
	l1->next = (node*)malloc(sizeof(node));
	l1->next->value = value;
	l1->next->next = NULL;
	return 0;
}

// вставка значения в начало списка, вернуть 0 если успешно
int push_front(list *l, int value)
{
	node *l1;
	l1 = (node*)malloc(sizeof(node));
	l1->value = value;
	l1->next = l->head;
	l->head = l1;

	return 0;
}

// вставка значения после указанного узла, вернуть 0 если успешно
int insert_after(list *l, int value, int value1)
{
	int i = 0;
    node *l1;
	l1 = (node*)malloc(sizeof(node));
    l1->value = value1; 
    l1->next = NULL;
    node *current = l->head;
    for(i = 1; i < value; i++)
	{
		current = current->next;
	}
    if (value == 0)
	{
     	l1->next = l;
     	l = l1;
		return 0;
    }
    else 
	{
    	if (current->next != NULL)
		{
			l1->next = current->next;
		} 
    	current->next = l1;
		return 0;
	}  
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
    		if (current == l) 
			{
        		if (l1->next == NULL) 
				{
         			free(current);
					break;
        		}

       			l = current->next;
        		free(current);
        		current = l;
				break;
      		}
      		else 
			{
        		if (current->next != NULL) 
				{
         			l1->next = current->next;
          			free(current);
            		current = l1->next;
					break;
        		}
        		else 
				{
             		l1->next = NULL;
          		+	free(current);
          			break;
        		}
      	   }
    	}
    l1 = current;
    current = l1->next;
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
    	if (current == l) 
		{
        	if (l1->next == NULL) 
			{
         		free(current);
        	}

       		l = current->next;
        	free(current);
        	current = l;
      	}
      	else 
		{
        	if (current->next != NULL) 
			{
         		l1->next = current->next;
          		free(current);
            	current = l1->next;
        	}
        	else 
			{
             	l1->next = NULL;
          		free(current);
        	}
      	}
    l1 = current;
    current = l1->next;
	}
}

int main() {

	int n = 0, n1 = 0, k1 = 0, k2 = 0, k3 = 0, m = 0, t = 0, j = 0, x = 0, z = 0;

	scanf("%d", &n);

		list l;
		init(&l);
		//is_empty(&l);

		for(int i = 0; i < n; i++)
		{
		scanf("%d", &n1);
		vvod(&l, n1);
		}

		print(&l);

		scanf("%d%d%d", &k1, &k2, &k3);
		
			find(&l, k1);
			find(&l, k2);
			find(&l, k3);
			printf("\n");

		scanf("%d", &m);
		
			push_back(&l, m);
			print(&l);

		scanf("%d", &t);

			push_front(&l, t);
			print(&l);

		scanf("%d%d", &j, &x);
		
			insert_after(&l, j, x);
			print(&l);

		scanf("%d", &z);
		
			remove_node(&l, z);
			print(&l);


	return 0;
};
