#include <iostream>
using namespace std;

class tree
{	
	public:
		class node
		{	
			public: 
				char data;
				node *left,*right;
		}*T;
		tree();
		void creat(node*&);
		bool pre(node*&);
		bool mid(node*&);
		bool last(node*&);		
};

tree::tree()
{
	T=NULL;
} 

void tree::creat(node*&NODE)
{
	char c;
	cin>>c;
	if(c=='#')
		NODE=NULL;
	else
	{
		NODE=new node;
		NODE->data=c;
		creat(NODE->left);
		creat(NODE->right);
	}		
}

bool visit(char c)
{
	cout<<c;
	return true;
}

bool tree::pre(node*&NODE)
{
	if(NODE)
		{
			visit(NODE->data);
			pre(NODE->left);
			pre(NODE->right);
		}
	else
		return true;
}

bool tree::mid(node*&NODE)
{
	if(NODE)
		{
			mid(NODE->left);
			visit(NODE->data);
			mid(NODE->right);
		}
	else
		return true;
}

bool tree::last(node*&NODE)
{
	if(NODE)
		{
			last(NODE->left);
			last(NODE->right);
			visit(NODE->data);
		}
	else
		return true;
}

int main()
{
	tree Tree;
	Tree.creat(Tree.T);
	Tree.pre(Tree.T);cout<<endl;
	Tree.mid(Tree.T);cout<<endl;
	Tree.last(Tree.T);
}
