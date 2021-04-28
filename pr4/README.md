#### Отчет по практической работе №4 «Двусвязные списки» по дисциплине «Технологии и методы программирования»

Cтудент гр. 729-1  
____ ____ Безрукова А.О.  
19.03.21

Принял  
Преподаватель КИБЭВС  
____ ____ Перминов П. В.  
19.03.21


##### 1 Введение

Цель работы: Изучить принципы с двусвязными списками на языке программирования С.

Задание:
1. Должны быть выполнены предыдущие работы
2. Прочитать про односвязные списки на СИ
3. Написать программу
4. Настроить pipeline
5. Написать отчет по работе в разметке Markdown (README.md)
6. Залить на gitlab и убедиться, что pipeline проходит успешно
7. Защитить работу у преподавателя

Программа:
1. считывает количество элементов n, 0 < n <= 2147483647;
2. создает пустой список, считывает n элементов a, |a| <= 2147483647 и заносит их в список;
3. выводит содержимое списка, используя функцию print;
4. считывает k1, k2, k3 (|k| <= 2147483647) и выводит "1", если в списке существует элемент с таким значением и "0" если нет (выводить через пробел, например "1 0 1");
5. считывает m, |m| <= 2147483647 и вставляет его в конец списка;
6. выводит содержимое списка, используя функцию print_invers;
7. считывает t, |t| <= 2147483647 и вставляет его в начало списка;
8. выводит содержимое списка, используя функцию print;
9. считывает j и x (0 < j <= 2147483647, |x| <= 2147483647) и вставляет значение x после j-ого элемента списка;
10. выводит содержимое списка, используя функцию print_invers;
11. считывает u и y (0 < u <= 2147483647, |y| <= 2147483647) и вставляет значение y перед u-ым элементом списка;
12. выводит содержимое списка, используя функцию print;
13. считывает z, |z| <= 2147483647 и удаляет первый элемент (при его наличии), хранящий значение z из списка;
14. выводит содержимое списка, используя функцию print_invers;
15. считывает r, |r| <= 2147483647 и удаляет последний элемент (при его наличии), хранящий значение r из списка;
16. выводит содержимое списка, используя функцию print;
17. очищает список.

##### 2 Ход работы

##### 2.1 Теория

Список – это совокупность элементов, число которых
может меняться.
Структура списка похожа на модель звеньев цепи.

Список может увеличится при добавлении новых звеньев.
Причем новый элементы списка могут быть добавлены
как в начало и конец, так и в середину списка путем
разрыва соединений между звеньями, добавлением
нового звена и восстановлением соединений.

Удаление элементов списка происходит путем разрыва
соединений, удаления звена и восстановлением
соединений

Создание списка:

    typedef struct list {
	     struct node *head;  // начало списка
	      struct node *tail;  // конец списка
    } list

    typedef struct node {
	     int value;          // значение, которое хранит узел
	     struct node *next;  // ссылка на следующий элемент списка
	     struct node *prev;  // ссылка на предыдущий элемент списка
    } node;


##### 2.2 Программа

Код программы:

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

input | output
--- | ---
5|
1 2 3 2 4| 1 2 3 2 4
2 5 1 | 1 0 1    
1 | 1 4 2 3 2 1    
7 | 7 1 2 3 2 4 1  
3 0 | 1 4 2 3 0 2 1 7
5 8 | 7 1 2 0 8 3 2 4 1
2 | 1 4 2 3 8 0 1 7
1 | 7 1 0 8 3 2 4 |  

Результат работы программы представлен на рисунке 1.

![2](/pr4/pic/1.png)

<center>Рисунок 1 - Результат работы пограммы  </center>


Результаты проверки тестов pipeline представлен на рисунке 2

![4](/pr4/pic/2.png)

<center>Рисунок 2 - Pipeline  </center>

##### 2.3 Окончание работы

Для того, чтобы загрузить файлы из локального репозитория нужно выполнить следующие команды:

    git add <названия новых файлов>

    git commit -master

    git push origin master

Если нужно добавить измениения из удаленного репозитория в локальный, то нужно использовать команду:

    git pull


##### 3 Заключение

В ходе выполнения практической работы были получены знания о работе с двусвязными списками в языке программирования С.
