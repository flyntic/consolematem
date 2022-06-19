// ConsoleMatem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

struct tree
{
	tree* tree_left=nullptr;
	tree* tree_right=nullptr;
	tree* tree_parent=nullptr;

	
	char node_action=' ';
	int node_number=0;
	

	tree(std::string str, tree* Tree_left = nullptr, char c_end = '0'): tree_left {Tree_left}
	{
		tree* t = this;//new tree;
		switch (str[0])
		{
		case'(': t->tree_left = new tree(str.substr(1,str.length()-1),nullptr, ')'); break;
		case '+':
		case '-':
		case '/':
		case '*': t->node_action = str[0]; t->tree_right = new tree(str.substr(1, str.length() - 1)); break;
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
		{
			int i = 0;
			while ((str[i] >= '0') && (str[i] <= '9'))
			{
				t->node_number = t->node_number * 10 + (str[i] - '0');
				i++;
			}
			if ((str.c_str()[i] == c_end)||(str.length() == i)) 
		     	return;
			t->tree_parent =new tree(str.substr(i, str.length() - i),this);
		}


		}
		return ;
	}
	tree* parent()
	{
		if (tree_parent == nullptr) return this;
		
		return tree_parent->parent();
	}

	int calculate()
	
	{
		int t_left = 0,t_right=0;
		if (tree_left != nullptr) t_left  = tree_left->calculate();
		if (tree_right != nullptr)t_right = tree_right->calculate();

		if (node_action != ' ') return t_left + t_right;

		return node_number;

	}
};

int main()
{
	std::string str;
	std::cin >> str;

	tree *t= new tree(str);
	tree* pt = t->parent();
   
	int calculate = pt->calculate();

	std::cout << calculate;
}

