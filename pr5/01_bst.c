#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Структура для хранения узла дерева.
// Необходимо хранить ссылки на потомков, предка и некоторое значение
typedef struct node {
	int key;
	struct node *left;
	struct node *right;
	struct node *parent;
} node;

// Структура для хранения дерева.
// Хранит ссылку на корень дерева и количество элементов в дереве
typedef struct tree {
	struct node *root;
	int size;
} tree;

// Инициализация дерева
void init(tree* t) {
	t->root = NULL;
	t->size = 0;
}

// очередь
typedef struct node1 {
	struct node* tr;
	struct node1* next;
} node1;

typedef struct queue {
	struct node1* head;
	struct node1* tail;
} queue;


void print_queue(queue *q) {
	node1* tmp = q->head; 
	while(tmp != NULL) 
	{
		if(tmp->tr == NULL)
		{
			printf("_ ");
		}
		else
		{
			printf("%d ", tmp->tr->key); 
		}
		tmp = tmp->next;
	}
	printf("\n");
}

void push_in_queue(queue *q, node *key) { 
	node1 *tmp;
	tmp = malloc(sizeof(node1)); 
	tmp->tr = key;
	tmp->next = NULL; 
	if(q->tail != NULL) 
	{
		q->tail->next = tmp;
		q->tail = tmp;
	}  
	else 
	{
		q->head = q->tail = tmp;
	}
}

node* pop_out_queue(queue *q) {
	node1 *tmp = q->head;
	node* n = q->head->tr; 
	q->head = q->head->next; 
	if(q->head == NULL)
	{
		q->tail = NULL;
	}
	free(tmp);

	return(n);
}

int control(queue *q) {
	node1* tmp = q->head; 
	while(tmp != NULL) {
		if(tmp->tr != NULL)
		{
			return 0; 
		}
		tmp = tmp->next;
	}
	return 1;
}

// Удалить все элементы из дерева
void clean(node *d) {
	if (d == NULL)
		return;
	if(d ->left != NULL)
	{
		clean(d ->left);
	}
	else if (d ->right != NULL)
	{
		clean(d ->right);
	}
	if (d -> key)
	{
		free(d);
	}		
}

// Поиск элемента по значению. Вернуть NULL если элемент не найден
node* find(tree* t, int key, bool b) {
	node* tmp = t->root;
	while(tmp != NULL) {
		if(tmp->key == key)
				break;
		if(key > tmp->key) {
			if(tmp->right == NULL) {
				if(b == true)
				{
					printf("-\n");
				}
				return 0;
			}
			tmp = tmp->right;
		}
		else {
			if(tmp->left == NULL) {
				if(b == true)
				{
					printf("-\n");
				}
				return 0;
			}
			tmp = tmp->left;
		}
	}
	if(b == true)
	{
    	if(tmp->parent != NULL)
    	{
        	printf("%d ", tmp->parent->key);
    	}
    	else
    	{
        	printf("_ ");
    	}
	
		if(tmp->left == NULL)
		{
			printf("_ ");
		}
		else
		{
			printf("%d ", tmp->left->key);
		}
		
		if(tmp->right == NULL)
		{
			printf("_ ");
		}
		else
		{
			printf("%d ", tmp->right->key);
		}
	printf("\n");					
	}
	return tmp;
}

// Вставка значения в дерево:
// 0 - вставка выполнена успешно
// 1 - элемент существует
// 2 - не удалось выделить память для нового элемента
int insert(tree* t, int key){
	node* tmp = malloc(sizeof(node));
	if(tmp == NULL) {
		return 2;
	}
	tmp->key = key;
	tmp->left = NULL;
	tmp->right = NULL;
	if(t->root == NULL) {
		t->root = tmp;
	} else {
		node* current = t->root;
		node* prev = NULL;
		int check;
		while(current != NULL){
			prev = current;
			if(key < current->key) {
				current = current->left;
				check = 1;
			} else if(key == current->key) {
				return 1;
			} else {
				current = current->right;
				check = 0;
			}
		} if(check) {
			prev->left = tmp;
			tmp->parent = prev;
		} else {
			prev->right = tmp;
			tmp->parent = prev;
		}
	} 
	t->size++; 
	return 0;
}

node* min(node *x)
{
	if (x -> left == NULL)
     return x;
  return min(x -> left);
}

node *succ(node *root)
{
node *p = root, *l = NULL;
// Если есть правое поддерево, то ищем минимальный элемент в этом поддереве
if (p -> right != NULL)
l = min(p -> right);
return l;
/* Правое дерево пусто, идем по родителям до тех пор,
пока не найдем родителя, для которого наше поддерево
левое */
l = p -> parent;
while ((l != NULL) && (p == l -> right))
{
p = l;
l = l -> parent;
}
return l;
}

// Удалить элемент из дерева:
// 0 - удаление прошло успешно
// 1 - нет элемента с указанным значением
int remove_node(tree* t, int key) {
// Поиск удаляемого узла по ключу
	node *p = t -> root, *l = NULL, *m = NULL;
	l = find(t, key, false);
	if(l != NULL)
	{
		// 1 случай
		if ((l -> left == NULL) && (l -> right == NULL))
		{
			if(l -> parent != NULL)
			{
			m  = l -> parent;
			if (l == m -> right)
			{
				m -> right = NULL;
			} 
			else
			{
				m -> left = NULL;
			} 
			}
			else
			{
				t->root = NULL;
			}
			t->size = t->size - 1;
			free(l);
			return 0;
		}
		// 2 случай, 1 вариант - поддерево справа
		if ((l -> left == NULL) && (l -> right != NULL))
		{
			if(l -> parent != NULL)
			{
				 m = l -> parent;
				if (l == m -> right) 
				{
					m -> right = l -> right;
					l -> right -> parent = m;
				}	
				else
				{
					m -> left = l -> right;
					l -> right -> parent = m;
				} 
			}
			else
			{
				t->root = l->right;
			}
			t->size = t->size - 1;
			free(l);
			return 0;
		}
		// 2 случай, 2 вариант - поддерево слева
		if ((l -> left != NULL) && (l -> right == NULL))
		{
			if(l -> parent != NULL)
			{
				m = l -> parent;
				if (l == m -> right)
				{
					m -> right = l -> left;
					l -> left -> parent = m;
				} 
				else 
				{
					m -> left = l -> left;
					l -> left -> parent = m;
				}
			}
			else
			{
				t->root = l->left;
			}	
			t->size = t->size - 1;
			free(l);
			return 0;
		}	
		// 3 случай
		if ((l -> left != NULL) && (l -> right != NULL))
		{
			m = succ(l);
			l -> key = m -> key;
			if (m -> right == NULL)
			{
				m -> parent -> left = NULL;
			}
			else 
			{
				m -> parent -> right = m -> right;
				m -> right -> parent = m -> parent;
			}	
			t->size = t->size - 1;
			free(m);
			return 0;
		}
	}
return 1;
}

// Выполнить левое вращение поддерева, корнем которого является n:
// 0 - успешно выполненная операция
// 1 - вращение невозможно
int rotate_left(tree* t) {
	node* l = t->root;
	if(l != NULL)
	{
	node *p = l->right;
	if(p != NULL)
	{
		node *a = l ->left;
		node *b = l->right ->left;
		node *c = l->right->right;

		t ->root = p;
		p->left = l;
		l->left = a;
		l ->right = b;
		p ->right = c;
	}
	else
	{
		return 1;
	}
	return 0;		
	}
	else
	{
		return 1;
	}
}


// Выполнить правое вращение поддерева, корнем которого является n:
// 0 - успешно выполненная операция
// 1 - вращение невозможно
int rotate_right(tree* t) {
	node* l = t->root;
	if(l != NULL)
	{
	node *p = l->left;
	if(p != NULL)
	{
		node *a = l ->right;
		node *b = l->left ->right;
		node *c = l->left->left;

		t ->root = p;
		p->right = l;
		l->right = a;
		l ->left = b;
		p ->left = c;
	}
	else
	{
		return 1;
	}
	return 0;
	}
	else
	{
		return 1;
	}
}

// Вывести все значения дерева t, аналогично функции print
void print_tree(tree* t, queue* q)
{
	node* tmp = t->root;
	queue* tmp_q;
	tmp_q = malloc(sizeof(queue)); 
	if(tmp == NULL) {
		printf("-");
        printf("\n");
		return;
	} 
	push_in_queue(q, tmp); 
	print_queue(q); 
	for(;;) {  
		while(q->tail != NULL) {
			tmp = pop_out_queue(q);
			push_in_queue(tmp_q, tmp);
		} 
		while(tmp_q->tail != NULL) {
			tmp = pop_out_queue(tmp_q);
			if(tmp == NULL) {
				push_in_queue(q, NULL);
				push_in_queue(q, NULL);
			}
			else {
				push_in_queue(q, tmp->left);
				push_in_queue(q, tmp->right);
			}
		} 
		if(control(q)) {
			while(q->tail != NULL)
				pop_out_queue(q);

			break;
		}

		print_queue(q);
	}
}

int main()
{
	int a = 0, m1 = 0, m2 = 0, m3 = 0;
	tree *t;
    queue *q;

	t = malloc(sizeof(tree));
	init(t);
	q = malloc(sizeof(queue));

	for (int i = 0; i < 4; ++i) {
		scanf("%d", &a);
		insert(t, a);
	}

	print_tree(t, q);
	printf("\n");
	
	for (int i = 0; i < 3; ++i) {
		scanf("%d", &a);
		insert(t, a);
	}

	print_tree(t, q);
	printf("\n");

	scanf("%d", &m1);
	find(t, m1, true);
	printf("\n");

	scanf("%d", &m2);
	find(t, m2, true);
	printf("\n");

	scanf("%d", &m3);
	remove_node(t, m3);
	print_tree(t, q);
	printf("\n");	

	rotate_left(t);
	while(rotate_left(t) != 1)
	{
		rotate_left(t);
	}
	print_tree(t, q);
	printf("\n");

	rotate_right(t);
	while(rotate_right(t) != 1)
	{
		rotate_right(t);
	}
	print_tree(t, q);
	printf("\n");

	printf("%d\n", t->size);
	printf("\n");

	node *n = t->root;
	clean(n);
	t->root = NULL;
	print_tree(t, q);

	return 0;
}
