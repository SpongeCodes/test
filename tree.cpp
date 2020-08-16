#include<bits/stdc++.h>
#define vi vector<int> 
using namespace std;

struct treeNode
{
	int data;
	treeNode * left = NULL , *right = NULL;
};

 treeNode * createNode(int i)
 {
	 treeNode* newNode = (treeNode*) malloc(sizeof(treeNode));
	 newNode->data = i ;
	 newNode->left = newNode->right = NULL;
	 return newNode;
 }


	 
	 int left(int i) {return (2 * i + 1);}
	 int right(int i) {return (2 * i + 2);}
	 
	 class TraverseTree
	 {   
		public:
		 treeNode *treeRoot;
		 string str;
		 public:
		  TraverseTree(treeNode* root);
		  string Preorder( treeNode* root,string s);
		  
		  
	 };
	
    // constructor that will define a few attributes of
	// object
	TraverseTree::TraverseTree(treeNode* root)
	{
		treeRoot =  root;
	
	}

		string TraverseTree::Preorder(treeNode* root,string s)
		{
			if (root == NULL)
			{
				//printf("what");
				return s;
			}//return s;
			s.append("(");
			//cout<<s<<endl;
			s.append(to_string(root->data));
			cout<<root->data<< " ";
			s = Preorder(root->left,s);
			s = Preorder(root->right,s);
			s.append(")");
			//str = s;
			return s;
		}

	
	
	treeNode* buildTree(vi &arr, int n, int i)
	{
		if (i < n)
		{
			//cout<<left(i)<<endl;
			treeNode* node = createNode(arr[i]);
			node->left = buildTree(arr,n, left(i));
			node->right = buildTree(arr,n,right(i));
			return node;
		}
		else
		return NULL;
		
	}
	
	

int main()
{
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	cout<<"Enter no. of cases: " ;
	int t;
	cin>>t;
	int i = 1;
	while( i <= t)
	{
	i++;
	int n;
	cout<<"Enter size of array: ";
	cin>>n;
	vi v (n);
	for (int i = 0 ; i < n ; i++)
		cin>>v[i];
	string s = "";
	treeNode* Tree = buildTree(v, n, 0);
	cout<<Tree->data<<endl;
	TraverseTree Tree_Obj(Tree);
	//Tree_Obj.Preorder(Tree,s);	
     s = Tree_Obj.Preorder(Tree,s)	;
	 s.erase(s.begin());
	 s.erase(s.end() - 1) ;
	cout << s <<endl;	
		
	}

	return 0;
}