#include <iostream>


using namespace std;

struct Tree
{
	int n;
	Tree* left;
	Tree* right;
};

Tree* InsertNode(Tree* node, int q)
{
	if (node == NULL)
	{
		node = new (nothrow) Tree();
		if (node != NULL)
		{
			node->n = q;
			node->left = node->right = NULL;
		}
		return node;
	}

	if (q < node->n)
		node->left = InsertNode(node->left, q);
	else
		node->right = InsertNode(node->right, q);
	return node;
}

void Print(ostream& _out, const Tree* node, int q)
{
	if (node != NULL)
	{
		if (node->left != NULL)
			Print(_out, node->left, q);

		_out << node->n << '\t';


		if (node->right != NULL)
			Print(_out, node->right, q);
	}
}

void ClearNode(Tree* node)
{
	if (node != NULL)
	{
		if (node->left != NULL)
			ClearNode(node->left);
		if (node->right != NULL)
			ClearNode(node->right);
		delete node;
	}
}


Tree* Delete(Tree* node, int owo)
{
	if (node == NULL)
		return node;

	if (owo == node->n)
	{

		Tree* tmp;
		if (node->right == NULL)
			tmp = node->left;
		else {

			Tree* ptr = node->right;
			if (ptr->left == NULL)
			{
				ptr->left = node->left;
				tmp = ptr;
			}
			else {

				Tree* pmin = ptr->left;
				while (pmin->left != NULL)
				{
					ptr = pmin;
					pmin = ptr->left;
				}
				ptr->left = pmin->right;
				pmin->left = node->left;
				pmin->right = node->right;
				tmp = pmin;
			}
		}

		delete node;
		return tmp;
	}
	else if (owo < node->n)
		node->left = Delete(node->left, owo);
	else
		node->right = Delete(node->right, owo);
	return node;
}

void print_Tree(Tree* node, int level)
{
	if (node)
	{
		print_Tree(node->left, level + 1);
		for (int i = 0; i < level; i++) cout << "   ";
		cout << node->n << endl;
		print_Tree(node->right, level + 1);
	}
}

int main(void)
{
	setlocale(LC_ALL, "Russian");
	Tree* tree = NULL;
	int q = NULL;
	system("pause");
	system("cls");

	int e = 0;
	while (e != 5)
	{
		cout << "Выберите требуемое действие:" << endl
			<< "1 - Добавить один или несколько элементов" << endl
			<< "2 - Удалить элемент" << endl
			<< "3 - Вывести и отсортировать в виде списка" << endl
			<< "4 - Вывести в виде дерева" << endl
			<< "5 - Завершение работы программы" << endl;
		while (!(cin >> e) || (cin.peek() != '\n'))
		{
			cin.clear();
			cin.ignore((numeric_limits<streamsize>::max)(), '\n');
			cout << "Некорректные данные, попробуйте снова" << endl;
		}
		if (e == 1)
		{
			int n;
			cout << "Введите количество добавляемых элементов: ";
			cin >> n;
			for (int i = 0; i < n; ++i)
			{
				cout << "Введите числа:";
				while (!(cin >> q) || (cin.peek() != '\n'))
				{
					cin.clear();
					cin.ignore((numeric_limits<streamsize>::max)(), '\n');
					cout << "Некорректные данные, попробуйте снова" << endl;
				}

				tree = InsertNode(tree, q);
			}
			system("pause");
			system("cls");
		}
		if (e == 2)
		{
			int d;
			cout << endl;
			Print(cout, tree, q);
			cout << endl;
			cout << "Введите элемент, который требуется удалить: ";
			while (!(cin >> d) || (cin.peek() != '\n'))
			{
				cin.clear();
				cin.ignore((numeric_limits<streamsize>::max)(), '\n');
				cout << "Некорректные данные, попробуйте снова" << endl;
			}
			cout << endl;
			tree = Delete(tree, d);
			Print(cout, tree, q);
			system("pause");
			system("cls");
		}
		if (e == 3)
		{
			/*if (q == NULL)
			{
				cout << "Дерево пустое!";
				break;
			}*/
			Print(cout, tree, q);
			cout << endl;
			system("pause");
			system("cls");
		}
		if (e == 4)
		{
			/*if (q == NULL)
			{
				cout << "Дерево пустое!";
				break;
			}*/
			print_Tree(tree, q);
			system("pause");
			system("cls");
		}
		if (e == 5)
		{
			ClearNode(tree);
			system("pause");
			system("cls");
		}
	}
	return 0;
}

