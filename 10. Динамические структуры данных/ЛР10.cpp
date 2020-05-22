// лаба 11.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>
#include <stack>
#include <queue>

using namespace std;

//СТЕК---------------------------------------------------------------------------------
struct stackSt {
	int data;
	stackSt *prev;
};

//создание стека
stackSt* makeStack(int n) {
	stackSt* first = new stackSt;
	cout << "Введите 1-ый элемент стека: ";
	cin >> first->data;
	first->prev = NULL;
	stackSt *p = new stackSt;
	p->prev = first;
	if (n != 1) {
		for (int i = 1; i < n; i++) {
			stackSt *temp = new stackSt;
			cout << "Введите " << i + 1 << "-ый элемент стека: ";
			cin >> p->data;
			temp->prev = p;
			p = temp;
		}
	}
	return p->prev;
}
//печать
void printStack(stackSt* top) {
	if (top == NULL) {
		cout << "Стек пуст";
		return;
	}
	stackSt *p = top;
	while (p->prev != NULL) {
		cout << p->data << " ";
		p = p->prev;
	}
	cout << p->data;
}
//Добавление элемента
stackSt* additionStack(stackSt *top, int n) {
	stackSt *p = new stackSt;
	p->prev = top;
	for (int i = 0; i < n; i++) {
		stackSt *temp = new stackSt;
		cout << "Введите новый элемент стека: ";
		cin >> p->data;
		temp->prev = p;
		p = temp;
	}
	return p->prev;
}
//удаление элемента
stackSt* deleteStackEl(stackSt *top, int n) {
	if (top == NULL)
	{
		cout << "Стек пустой!" << endl;
		return 0;
	}
	for (int i = n; i > 0; i--) {
		top = top->prev;
	}
	return top;
}
//удаление стека
stackSt* deleteStack(stackSt *top) {
	while (top != NULL) top = top->prev;
	return top;
}
//--------------------------------------------------------------------------------------

//ОЧЕРЕДЬ-------------------------------------------------------------------------------
struct queueSt {
	int data;
	queueSt *next;
};

//создание очереди
queueSt* makeQueue(int n) {
	queueSt* first = new queueSt;
	cout << "Введите 1-ый элемент очереди ";
	cin >> first->data;
	first->next = NULL;
	if (n != 1) {
		queueSt *p = new queueSt;
		first->next = p;
		for (int i = 1; i < n; i++) {
			queueSt *temp = new queueSt;
			cout << "Введите " << i + 1 << "-ый элемент очереди ";
			cin >> p->data;
			if (i != n - 1) {
				p->next = temp;
				p = temp;
			}
			p->next = NULL;
		}
	}
	return first;
}
//печать
void printQueue(queueSt* first) {
	if (first == NULL) {
		cout << "Очередь пуста";
		return;
	}
	queueSt *p = first;
	while (p->next != NULL) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << p->data;
}
//добавление элемента
queueSt* additionQueue(queueSt *first, int n) {
	queueSt *p = first;
	while (p->next != NULL) p = p->next;
	queueSt *temp1 = new queueSt;
	p->next = temp1;
	p = p->next;
	for (int i = 0; i < n; i++) {
		queueSt *temp = new queueSt;
		cout << "Введите новый элемент очереди ";
		cin >> p->data;
		if (i != n - 1) {
			p->next = temp;
			p = temp;
		}
		p->next = NULL;
	}
	return first;
}
//удаление элемента
void deleteQueueEl(queueSt *&first, int & n) {
	queueSt* p = first;
	first = first->next;
	n--;
	delete p;
	return;
}
//удаление очереди
queueSt* deleteQueue(queueSt *first) {

	while (first->next != NULL) {
		queueSt *top = first;
		while (top->next != NULL) top = top->next;
		queueSt *p = first;
		while (p->next != top) p = p->next;
		p->next = NULL;
	}
	first = NULL;
	return first;
}
//---------------------------------------------------------------------------------------


//СПИСКИ---------------------------------------------------------------------------------
//однонаправленный-----------------------------------------------------------------------
struct list1 {
	int data;
	list1* next;
};

//поиск элемента
list1* find1(list1* first, int val)
{
	if (first == NULL) return NULL;
	list1 *p = first;
	for (int i = 1; p->next != NULL; i++)
	{
		if (p->data == val)
			return p;
		p = p->next;
	}
	return 0;
}

//создание списка
list1* make_list1(int n)
{
	list1* first, *p;
	first = NULL;
	cout << "Введите 1-ый элемент списка: ";
	p = new list1;
	cin >> p->data;
	first = p;

	for (int i = 2; i <= n; i++)
	{
		list1* h = new list1;
		p->next = h;
		p = p->next;
		cout << "Введите " << i << "-ый элемент списка: ";
		cin >> p->data;
		p->next = NULL;
	}
	return first;
}

//для добавления элементов новый список
list1* make_list_for_add(int n)
{
	list1* first, *p;
	first = NULL;
	cout << "Введите 1-ый добавляемый элемент: ";
	p = new list1;
	cin >> p->data;
	first = p;

	for (int i = 2; i <= n; i++)
	{
		list1* h = new list1;
		p->next = h;
		p = p->next;
		cout << "Введите " << i << "-ый добавляемый элемент: ";
		cin >> p->data;
		p->next = NULL;
	}
	return first;
}

//печать списка
void print_list1(list1*first)
{
	if (first == NULL)
	{
		cout << "Список пустой";
	}

	list1* p = first;
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

//удаление списка
void deletes(list1* &first)
{
	list1 *q, *q1;
	q = first;
	q1 = first;
	while (q1 != NULL)
	{
		q = q1;
		q1 = q1->next;
		delete q;
	}
	first = NULL;
	//return NULL;
}

//удаление элемента по значению
/* list1 *deleteEl1(list1 *first, int value) {
	list1 *p = first;
	if (p->data == value) {
		if (p->next != NULL) {
			p = p->next;
			first = p;
			cout << "Список без элемента " << value << endl;
			print_list1(first);
			return first;
		}
		else {
			first = NULL;
			return first;
		}
	}
	while (p->data != value) {
		p = p->next;
	}
	if (p->data == value) {
		list1 *pr = first;
		while (pr->next != p) {
			pr = pr->next;
		}
		pr->next = p->next;
		cout << "Список с удаленным без элемента " << value << endl;
		print_list1(first);
	}
	return first;
}  */
void deleteEl1(int val, list1* &first)
{
	if (first == NULL) return ;
	list1*p = first;
	bool f = false;
	while (p != NULL)  //проверка на наличие нужного элемента												 
	{
		if (p->data == val)
			f = true;
		p = p->next;
	}
	if (!f)
	{
		cout << "Элемент с заданным ключом не был найден!" << endl;
		return ;
	}
	p = first;   //обнуление p
	list1* e = first;
	while (e != NULL)   //если удаляется 1ый элемент и последщующие элементы
	{
		if (first == find1(first, val))        //если это нужный элемент
		{
			p = p->next;        //то переходим ко второму
			first = p;          //второй становится первым
		}
		e = e->next;          //Доходим до конца списка
	}
	p = first;        //обнуление p
	int kol = 0;      //кол-во удаляемых элементов
	while (p != NULL)
	{
		if (p->data == val)
			kol++;
		p = p->next;
	}
	for (int j = 0; j < kol; j++)
	{
		list1*t = NULL;
		p = first;
		int k = 0;     //k - индекс удаляемого элемента
		while (p->data != val)   //пока это не нужный элемнт
		{
			p = p->next;
			k++;
			if (p->data == val)
				t = p->next;        //сохраняем ук-ли данного элемента
		}
		p = first;   //обнуление P
		for (int i = 0; p != NULL; i++)
		{
			if (i == k - 1)
				p->next = t;  //указателю на элемент, к-ый находится перед удаляемым
			p = p->next;
		}
	}
}

//добавление элементов
list1 *addition(list1 *first, list1 *firstNew, int num) 
{
	list1 *p = first;
	if (num == 1) {
		p = firstNew;
		while (p->next != NULL) p = p->next;
		p->next = first;
		first = firstNew;
	}
	if (num != 1) {
		for (int i = 1; i < num - 1; i++) {
			p = p->next;
		}
		list1 *pn = p->next;
		list1 *pr = firstNew;
		p->next = firstNew;
		while (pr->next != NULL) pr = pr->next;
		pr->next = pn;
	}
	return first;
} 
      
//--------------------------------------------------------------------------------------------
//ДВУНАПРАВЛЕННЫЙ---------------------------------------------------------------------------

struct list {
	string data;
	list* next;
	list* prev;
};

//поиск элемента
list* find(list* first, string val)
{
	if (first == NULL) return NULL;
	list *p = first;
	for (int i = 1; p->next != NULL; i++)
	{
		if (p->data == val)
			return p;
		p = p->next;
	}
	return 0;
}
//удаление списка
void deletes(list* &first)
{
	list *q, *q1;
	q = first;
	q1 = first;
	while (q1 != NULL)
	{
		q = q1;
		q1 = q1->next;
		delete q;
	}
	first = NULL;
	//return NULL;
}

//создание списка
list* make_list(int n)
{
	cout << "Вы можете ввести список как цельное предложение из " << n << " слов, разделённых пробелами, так и пословесно" << endl;
	list* first, *ptr;
	first = NULL;
	cout << "Введите 1-ый элемент списка: ";
	ptr = new list;              //выделение памяти под 1 элемент
	cin >> ptr->data;            //ввод данных 1-го элемента
	first = ptr;                 //новый элемент становится первым
	ptr->next = NULL;            //т.к всего 1 элемент, то его указатели - на нулл
	ptr->prev = NULL;
	for (int i = 2; i <= n; i++) {
		list* h = new list;    //выделение памяти для след. эл-та
		list* q = ptr;         //указ-ль на пред. элемент
		ptr->next = h;
		ptr = ptr->next;
		cout << "Введите " << i << "-ый элемент списка: ";
		cin >> ptr->data;      //ввод данных нового элемента
		ptr->next = NULL;      //обнуляем его указатель на след. элемент
		ptr->prev = q;	       //q указывает на пред. элем
	}
	return first;
}

//печать списка
void print_list(list* first)
{
	if (first == NULL)
	{
		cout << "Список пуст!" << endl;
		return;
	}
	list *p = first;
	while (p->next != NULL)      //если последний элемент
	{
		cout << p->data << " ";  //Вывод информации из списка
		p = p->next;
	}
	cout << p->data;        //вывод информации последнего элемента
}
//запись списка в файл
void print_list_in_file(list* first)
{
	ofstream out; out.open("laba11.txt");

	if (first == NULL)
	{
		cout << "Список пуст!" << endl;
		return;
	}
	list *p = first;
	while (p->next != NULL)      //если последний элемент
	{
		out << p->data << " ";  //запись информации из списка
		p = p->next;
	}
	out << p->data;                 //запись информации последнего элемента
	cout << "Список записан в файл";
	out.close();
}

//восстановление списка из файла
list* read_list_from_file(int n)
{
	ifstream in; in.open("laba11.txt");

	list* first, *ptr;
	first = NULL;
	ptr = new list;            
	in >> ptr->data;           
	first = ptr;               
	ptr->next = NULL;          
	ptr->prev = NULL;
	for (int i = 2; i <= n; i++) {
		list* h = new list;   
		list* q = ptr;        
		ptr->next = h;
		ptr = ptr->next;
		in >> ptr->data;     
		ptr->next = NULL;    
		ptr->prev = q;	     
	}
	cout << "Список был восстановлен из файла. Вы можете вывести его на экран" << endl;
	in.close();
	return first;
}
//добавление элементов
void add(int K, list* &first, int &n)

{
	if (first == NULL)  return;

	//if (num <= 1)                  //ДОБАВЛЕНИЕ В НАЧАЛО СПИСКА
	{
		list* p = first;
		for (int i = 0; i < K; i++)
		{
			list* h = new list;          //выделение памяти под новый элемент
			cout << "Введите добавляемое в начало " << i + 1 << "-ое слово: ";
			cin>>h->data;       //ввод данных
			h->next = first;         //т.к элемент в начала, то он указ-ыет на первый элемент в исходном списке
			h->prev = NULL;          //и в обратном направлении-на нулл
			first->prev = h;
			first = h;
			//cout << "Ваш список после добавления в начало " << K << " элементов : ";
			//print_list(first);
		}
	}

	//if (num >= n)              //ДОБАВЛЕНИЕ В КОНЕЦ СПИСКА
	{
		//num = n;
		list *p = first;
		int k = 0;              //счётчик кол-ва элементов в списке
		while (p != NULL)
		{
			p = p->next;
			k++;
		}
		p = first;      //обратно в начало списка ук-ль
		for (int i = 1; i < k; i++)        //ставим указатель на последний элемент списка
			p = p->next;
		for (int i = 1; i <= K; i++)
		{
			list*h = new list;
			list*q = p;
			p->next = h;                 //ставим указатель от последнего элемента к новому последнему
			p = p->next;                 //новый элемент - последний
			cout << "Введите добавляемое в конец " << i + 1 << "-ое слово:  ";
			cin >> p->data;
			p->next = NULL;
			p->prev = q;
			//cout << "Ваш список после добавления в начало и конец " << K << " элементов : ";
			//print_list(first);
			//cout << endl;
		}
		cout << "Ваш список после добавления в начало и конец " << K << " элементов(-а) : ";
		print_list(first);
		cout << endl;
	}
}

//УДАЛЕНИЕ ЭЛЕМЕНТА С ЗАДАННЫМ КЛЮЧОМ
void deleteEl(string val, list* &first)
{
	if (first == NULL) return;
	list*p = first;
	list*e = NULL;
	bool f = false;																						   
	while (p!=NULL)  //проверка на наличие нужного элемента												 
	{																									 
		if (p->data == val)																				 
			f = true;																					 
		p = p->next;																					 
	}																									 
	if (!f)																					 
	{																									 
		cout << "Элемент с заданным ключом не был найден!" << endl;										 
		return;																							 
	}
	p = first;   //обнуление p
	list* w = first;
	while (w != NULL)   //если удаляется 1ый элемент и последщующие элементы
	{
		if (first == find(first, val))        //если это нужный элемент
		{
			p = p->next;        //то переходим ко второму
			first = p;          //второй становится первым
			if (p != NULL)
				p->prev = NULL;
		}
		w = w->next;          //Доходим до конца списка
	}
	p = first;        //обнуление p
	int kol = 0;      //кол-во удаляемых элементов
	while (p != NULL)
	{
		if (p->data == val)
			kol++;
		p = p->next;
	}
	if (first == NULL) return;
	for (int j = 0; j < kol; j++)
	{
		list*t = NULL;
		p = first;
		int k = 0;     //k - индекс удаляемого элемента
		while (p->data != val)   //пока это не нужный элемнт
		{
			p = p->next;
			k++;
			if (p->data == val)
			{
				t = p->next;        //сохраняем ук-ли данного элемента
				e = p->prev;
			}
		}
		p = first;   //обнуление P
		for (int i = 0; p != NULL; i++)
		{
			if (i == k - 1)
				p->next = t;  //указателю на элемент, к-ый находится перед удаляемым
			if (i == k)
				p->prev = e;  //присваиваем ук-ли удаляемого
			p = p->next;
		}
	}	
} 
//--------------------------------------------------------------------------------------------------------


int main()
{
	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string D;
	int n, K, c = 0;
	list* spisok = 0;
	list1* kek = 0;
	list1* spisok1 = 0;
	stackSt* stackk = 0;
	queueSt* queueq = 0;
	stack <int> stek;
	queue <int> queueqq;
	int key1, key2, key3;
	cout << "\tГлавное меню\n1-Однонаправленный список целых чисел\n2-Двунаправленный список слов\n3-Стек\n4-Очередь\n0-Завершить программу" << endl;
	do
	{
		cout << endl << "Вы выбрали - ";
		cin >> key1;
		switch (key1)
		{

        //двунаправленный------------------------
		case 2:

			int key;
			system("cls");
			cout << "\tДвунаправленный список слов\n1-Cоздание списка\n2-Вывести список на экран\n3-Добавить K элементов в начало и конец списка\n4-Удалить элемент списка с заданным ключом\n5-Удаление списка\n6-Записать список в файл\n7-Восстановить список из файла(только если уже был создан)\n0-Назад" << endl;
			do
			{
				cout << endl << "Вы выбрали - ";
				cin >> key;

				switch (key)
				{

				case 1:
					cout << "Введите количество элементов в списке - ";
					cin >> n;
					spisok = make_list(n);
					cout << "Список создан" << endl;
					break;

				case 2:
					cout << "\nИсходный список: " << endl;
					print_list(spisok);
					cout << endl;
					break;

				case 3:
					cout << "Введите количество добавляемых элементов: ";
					cin >> K;
					print_list(spisok);
					cout << endl;
					add(K, spisok, n);
					cout << endl;
					break;

				case 4:
					cout << endl << "Введите слово, которое хотите удалить: ";
					cin >> D;
					deleteEl(D, spisok);
					print_list(spisok);
					cout << endl;
					break;

				case 5:
					deletes(spisok);
					cout << "Список удалён!" << endl; 
					break;
				case 6:
					print_list_in_file(spisok);
					break;

				case 7:
					spisok = read_list_from_file(n);
					break;

				default:
					if (key != 0)
					{
						cout << "Попробуй поточнее!" << endl;
						break;
					}
				}
			} while (key != 0);
			system("cls");
			cout << "\tГлавное меню\n1-Однонаправленный список целых чисел\n2-Двунаправленный список слов\n3-Стек\n4-Очередь\n0-Завершить программу" << endl;
		break;

		
		//Однонаправленный---------------------
		case 1:

			int b, num;
			system("cls");
			cout << "\tОдноправленный список целых чисел\n1-Cоздание списка\n2-Вывести список на экран\n3-Добавить K элементов начиная с заданного номера\n4-Удалить элемент списка с заданным ключом\n5-Удаление списка\n0-Назад" << endl;
			do
			{
				cout << endl << "Вы выбрали - ";
				cin >> key;
				switch (key)
				{

				case 1:
					cout << "Введите количество элементов в списке - ";
					cin >> n;
					spisok1 = make_list1(n);
					cout << "Список создан" << endl;
					break;

				case 2:
					cout << "\nИсходный список: " << endl;
					print_list1(spisok1);
					cout << endl;
					break;

				case 3:
					//Добавление в список
					cout << "Введите количество добавляемых элементов: ";
				    cin >> K;
					cout << "Введите номер элемента, с которого следует начать добавление: ";
					cin >> num;
					kek = make_list_for_add(K);
					spisok1 = addition(spisok1, kek, num);
					cout << "\nСписок после добавления:\n";
					print_list1(spisok1);
					cout << endl;
					break;

				case 4:
					//удаление
					cout << endl << "Введите число, которое хотите удалить: ";
					cin >> b;
					deleteEl1(b, spisok1);
					cout << "\nСписок после удаления:\n";
					print_list1(spisok1);
					cout << endl;
					break;

				case 5:
				    deletes(spisok1);
					cout << "Список удалён!" << endl;
					break;

				default:
					if (key != 0)
					{
						cout << "Попробуй поточнее!" << endl;
						break;
					}
				}
			} while (key != 0);
			system("cls");
			cout << "\tГлавное меню\n1-Однонаправленный список целых чисел\n2-Двунаправленный список слов\n3-Стек\n4-Очередь\n0-Завершить программу" << endl;
			
		break;

		//СТЕК------------------
		case 3:

			system("cls");
			cout << "\tСоздать стек через:\n1-Структуру\n2-Стандартную библиотеку\n0-Назад" << endl;
			do
			{
				cout << endl << "Вы выбрали - ";
				cin >> key3;
				switch (key3)
				{
			    //стек через структуру		
				case 1:

					system("cls");
					cout << "\tСтек через структуру\n1-Создание стека\n2-Печать стека\n3-Удаление элементов из стека\n4-Добавление элементов в стек\n5-Удаление стека\n0-Назад";
					do
					{
						cout << endl << "Вы выбрали - ";
						cin >> key2;
						switch (key2)
						{
						case 1:
							cout << "Введите количество элементов в стеке - ";
							cin >> n;
							stackk = makeStack(n);
							cout << "Стек создан" << endl;
							break;

						case 2: 
							cout << "Исходный стек: " << endl;
							printStack(stackk);
							cout << endl;
							break;

						case 3:
							cout << endl << "Введите количество удаляемых элементов: ";
							cin >> b;
							stackk=deleteStackEl(stackk, b);
							cout << "\nСтек после удаления\n";
							printStack(stackk);
							cout << endl;
							break;

						case 4:
							cout << "Введите количество добавляемых элементов: ";
							cin >> c;
							stackk=additionStack(stackk, c);
							cout << "Стек после добавления элементов:\n";
							printStack(stackk);
							cout << endl;
							break;

						case 5:
							stackk=deleteStack(stackk);
							cout << "Стек удалён!" << endl;
							break;


						default:

							if (key2 != 0)
						    {
							cout << "Попробуй поточнее!" << endl;
						 	break;
						    }
						}	

					} while (key2 != 0);
					system("cls");
					cout << "\tСоздать стек через:\n1-Структуру\n2-Стандартную библиотеку\n0-Назад" << endl;

					break;

                //стек через библ
				case 2:
					system("cls");
					cout << "\tСтек через стандартную библиотеку\n1-Создание стека\n2-Узнать количество элементов в стеке\n3-Удаление верхнего элемента\n4-Вывод верхнего элемента\n5-Проверить, пуст ли стек\n0-Назад";
					do
					{
						cout << endl << "Вы выбрали - ";
						cin >> key2;
						switch (key2)
						{
						case 1:
							cout << "Введите количество элементов в стеке: ";
							cin >> n;
							cout << "Последовательный ввод элементов:\n";
							for (int i = 0; i < n; i++)
							{
								cout << "Введите элемент стека: ";
								cin >> b;
								stek.push(b);
							}
							cout << "Стек заполнен" << endl;
							break;

						case 2:
							cout << "Количество элементов в стеке - " << stek.size() << endl;
							break;

						case 3:
							if (stek.empty() == true)
								cout << "Стек пустой!" << endl;
							else
							{
								stek.pop();
								cout << "Верхний элемент удалён!" << endl;
							}
							break;

						case 4:
							if (stek.empty() == true)
								cout << "Стек пустой!" << endl;
							else 
								cout << "Верхний элемент стека - " << stek.top() << endl;
							break;
					    case 5:
							if (stek.empty() == true)
								cout << "Стек пустой!" << endl;
							else cout << " Стек не пустой!" << endl;
							break;

							
						default:

							if (key2 != 0)
							{
								cout << "Попробуй поточнее!" << endl;
								break;
							}
						}

					} while (key2 != 0);
					system("cls");
					cout << "\tСоздать стек через:\n1-Структуру\n2-Стандартную библиотеку\n0-Назад" << endl;

					break;

				default:	
					if (key1 != 0)
					{
						cout << "Попробуй поточнее!" << endl;
						break;
					}
				}
			} while (key3 != 0);
			system("cls");
			cout << "\tГлавное меню\n1-Однонаправленный список целых чисел\n2-Двунаправленный список слов\n3-Стек\n4-Очередь\n0-Завершить программу" << endl;
          
			break;

		//ОЧЕРЕДЬ----------------------
		case 4:

			system("cls");
			cout << "\tСоздать очередь через:\n1-Структуру\n2-Стандартную библиотеку\n0-Назад" << endl;
			do
			{
				cout << endl << "Вы выбрали - ";
				cin >> key3;
				switch (key3)
				{
				//очередь через структ
				case 1:

					system("cls");
					cout << "\tОчередь через структуру\n1-Создание очереди\n2-Печать очереди\n3-Удаление элемента из очереди\n4-Добавление элементов в очередь\n5-Удаление очереди\n0-Назад";
					do
					{
						cout << endl << "Вы выбрали - ";
						cin >> key2;
						switch (key2)
						{
						case 1:
							cout << "Введите количество элементов в очереди - ";
							cin >> n;
							queueq = makeQueue(n);
							cout << "Очередь создана" << endl;							
							break;

						case 2:
							cout << "Исходная очередь: " << endl;
							printQueue(queueq);
							cout << endl;
							break;

						case 3:
							deleteQueueEl(queueq, b);
							cout << "\nОчередь после удаления\n";
							printQueue(queueq);
							cout << endl;
							break;

						case 4:
							cout << "Введите количество добавляемых элементов: ";
							cin >> c;
							queueq = additionQueue(queueq, c);
							cout << "Очередь после добавления элементов:\n";
							printQueue(queueq);
							cout << endl;
							break;

						case 5:
							queueq=deleteQueue(queueq);
							cout << "Очередь удалена!" << endl;
							break;

						default:
							cout << "Попробуй поточнее!" << endl;
							break;
						}

					} while (key2 != 0);
					system("cls");
					cout << "\tСоздать очередь через:\n1-Структуру\n2-Стандартную библиотеку\n0-Назад" << endl;

					break;

                //очередь через библ
				case 2:
					
					system("cls");
					cout << "\tОчередь через стандартную библиотеку\n1-Создание очереди\n2-Узнать количество элементов в очереди\n3-Удаление первого элемента\n4-Вывести первый и последний элементы очереди\n5-Проверить, пуста ли очередь\n0-Назад";
					do
					{
						cout << endl << "Вы выбрали - ";
						cin >> key2;
						switch (key2)
						{
						case 1:
							cout << "Введите количество элементов в очереди: ";
							cin >> n;
							cout << "Последовательный ввод элементов:\n";
							for (int i = 0; i < n; i++)
							{
								cout << "Введите элемент очереди: ";
								cin >> b;
								queueqq.push(b);
								
							}
							cout << "Очередь заполнена" << endl;
							break;

						case 2:
							cout << "Количество элементов в очереди - " << queueqq.size() << endl;
							break;

						case 3:
							if (queueqq.empty() == true)
								cout << "Очередь пустая!" << endl;
							else
							{
								queueqq.pop();
								cout << "Первый элемент удалён!" << endl;
							}
							break;

						case 4:
							if (queueqq.empty() == true)
								cout << "Очередь пустая!" << endl;
							else
							{
								cout << "Первый элемент очереди - " << queueqq.front() << endl;
								cout << "Последний элемент очереди - " << queueqq.back() << endl;
							}
							break;

						case 5:
							if (queueqq.empty() == true)
								cout << "Очередь пустая!" << endl;
							else cout << "Очередь не пустая!" << endl;
							break;

						default:

							if (key2 != 0)
							{
								cout << "Попробуй поточнее!" << endl;
								break;
							}
						}

					} while (key2 != 0);
					system("cls");
					cout << "\tСоздать стек через:\n1-Структуру\n2-Стандартную библиотеку\n0-Назад" << endl;

				default:
					if (key2 != 0)
					{
						cout << "Попробуй поточнее!" << endl;
						break;
					}
				}
			} while (key3 != 0);
			system("cls");
			cout << "\tГлавное меню\n1-Однонаправленный список целых чисел\n2-Двунаправленный список слов\n3-Стек\n4-Очередь\n0-Завершить программу" << endl;   
			break;

		default:
			if (key1 != 0)
			{
				cout << "Попробуй поточнее!" << endl;
				break;
			}
		}
	} while (key1 != 0);

	system("pause");
	return 0;
}

