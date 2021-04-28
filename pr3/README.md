#### Отчет по практической работе №3 «Односвязные списки» по дисциплине «Технологии и методы программирования»

Cтудент гр. 729-1  
____ ____ Безрукова А.О.  
19.03.21

Принял  
Преподаватель КИБЭВС  
____ ____ Перминов П. В.  
19.03.21


##### 1 Введение

Цель работы: Изучить принципы с односвязными списками на языке программирования С.

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
4. считывает k1, k2, k3 (|k| <= 2147483647) и выводит "1", если в списке существует элемент с таким значением и "0", если нет (выводить через пробел, например "1 0 1");
5. считывает m, |m| <= 2147483647 и вставляет его в конец списка;
6. выводит содержимое списка, используя функцию print;
7. считывает t, |t| <= 2147483647 и вставляет его в начало списка;
8. выводит содержимое списка, используя функцию print;
9. считывает j и x (0 < j <= 2147483647, |x| <= 2147483647) и вставляет значение x после j-ого элемента списка;
10. выводит содержимое списка, используя функцию print;
11. считывает z, |z| <= 2147483647 и удаляет первый элемент (при его наличии), хранящий значение z из списка;
12. выводит содержимое списка, используя функцию print;
13. очищает список.

##### 2 Ход работы

##### 2.1 Теория

Односвязный список - динамическая структура данных, состоящая из узлов, каждый из которых содержит как собственно данные, так и ссылку на следующий узел списка.
Список задается ссылками на его узлы: начальный и конечный.

Основные действия, производимые над списком:
1. Инициализация списка
2. Добавление узла в список
3. Удаление узла из списка
4. Вывод элементов списка

Создание списка:

    typedef struct node {
	      int value;          // значение, которое хранит узел
	      struct node *next;  // ссылка на следующий элемент списка
        } node;

##### 2.2 Программа

Код программы:

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
          			free(current);
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

            //clean(&l);

	return 0;
    };

input | output
--- | ---
5|
1 2 3 2 4| 1 2 3 2 4
2 5 1 | 1 0 1    
5 | 1 2 3 2 4 5    
7 | 7 1 2 3 2 4 5    
3 0 | 7 1 2 0 3 2 4 5
2 | 7 1 0 3 2 4 5 |  

Результат работы программы представлен на рисунке 1.

![2](/pr3/pic/1.png)

<center>Рисунок 1 - Результат работы пограммы  </center>


Результаты проверки тестов pipeline представлен на рисунке 2

![4](/pr3/pic/2.png)

<center>Рисунок 2 - Pipeline  </center>

##### 2.3 Окончание работы

Для того, чтобы загрузить файлы из локального репозитория нужно выполнить следующие команды:

    git add <названия новых файлов>

    git commit -master

    git push origin master

Если нужно добавить измениения из удаленного репозитория в локальный, то нужно использовать команду:

    git pull


##### 3 Заключение

В ходе выполнения практической работы были получены новые знания о работе с односвязными списками в языке программирования С.
