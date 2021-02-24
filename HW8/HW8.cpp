#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

//based on ppt and code of chapter 7 Kd tree
struct Coordinate
{
	public:
		double coor[2];
		double distance(Coordinate a)
		{
			//calculate the distance between points
			return sqrt(pow((coor[0] - a.coor[0]), 2) + pow((coor[1] - a.coor[1]), 2));
		}
		double distance(bool d, Coordinate a)
		{
			//calculate the shortest distance to determine whether to abandon the subtree
			return abs(coor[d] - a.coor[d]);
		}
		bool isSmaller(bool d, Coordinate a)
		{
			return (coor[d] < a.coor[d]);
		}
};

struct PointStruct : public Coordinate
{
	char name;
	public:
		bool isBigger(bool d, PointStruct a)
		{
			return (coor[d] > a.coor[d]);
		}
		bool isSmaller(bool d, PointStruct a)
		{
			return(coor[d] < a.coor[d]);
		}
		bool isEqual(PointStruct a)
		{
			return(name == a.name && coor[0] == a.coor[0] && coor[1] == a.coor[1]);
		}
};

//based on the link attached to honor code
void Merge(vector<PointStruct>& list, vector<PointStruct>& L, int leftCount, vector<PointStruct>& R, int rightCount, bool d)
{
	int i = 0, j = 0, k = 0;

	while (i < leftCount && j < rightCount) {
		if (L[i].coor[d] < R[j].coor[d])
		{
			list[k++] = L[i++];
		}
		else
		{
			list[k++] = R[j++];
		}
	}
	//if elements in R vector have all moved to list
	while (i < leftCount)
	{
		list[k++] = L[i++];
	}
	//if elements in L vector have all moved to list
	while (j < rightCount)
	{
		list[k++] = R[j++];
	}
}

void MergeSort(vector<PointStruct>& list, int size, bool d)
{
	int mid, i;
	vector<PointStruct> L, R;
	//base condition
	if (size < 2)
	{
		return;
	} 

	mid = size / 2;		//find the middle index.

	for (i = 0; i < mid; i++)
	{
		L.push_back(list[i]);		//move the first mid elements to L vector
	}
	for (i = mid; i < size; i++)
	{
		R.push_back(list[i]); 		//move the rest of elements to R vector
	}

	MergeSort(L, mid, d);		//sort L vector by calling recursive function
	MergeSort(R, size - mid, d);		//sort R vector by calling recursive function
	Merge(list, L, mid, R, size - mid, d);		//merge L vector and R vector
}

PointStruct findMid(bool d, vector<PointStruct>& list)
{
	MergeSort(list, list.size(), d);		//sort the list
	int mid = list.size() / 2;
	return list[mid];		//return the middle element
}

struct TreeNode : public PointStruct
{
	bool dimension;
	TreeNode* lchild;
	TreeNode* rchild;
};

class KdTree
{
public:
	TreeNode* root;
	TreeNode* buildTree(vector<PointStruct>& list, bool d);
	void constructTree(vector<PointStruct>& list);
	void nearSearch(TreeNode* ptr, bool d, Coordinate point, PointStruct &nearest);
};

TreeNode* KdTree::buildTree(vector<PointStruct>& list, bool d)
{
	int i;
	if (list.empty())
	{
		return NULL;		//base condition
	}
	PointStruct mid = findMid(d, list);
	vector<PointStruct> llist, rlist;
	for (i = 0; i < list.size(); i++)
	{
		//mid point is on the right side or top side of list[i]
		if (mid.isBigger(d, list[i]))
		{
			llist.push_back(list[i]);
		}
		//mid point is on the left side or down side of list[i]
		else if (mid.isSmaller(d, list[i]))
		{
			rlist.push_back(list[i]);
		}
		//mid point is not the same as list[i]
		else if (!mid.isEqual(list[i]))
		{
			rlist.push_back(list[i]);
		}
	}
	//create new treenode
	TreeNode* ptr = new TreeNode;
	ptr->coor[0] = mid.coor[0];
	ptr->coor[1] = mid.coor[1];
	ptr->name = mid.name;
	ptr->lchild = buildTree(llist, !d);		//build left subtree with the opposite dimension
	ptr->rchild = buildTree(rlist, !d);		//build right subtree with the opposite dimension
	ptr->dimension = d;
	return ptr;
}

void KdTree::constructTree(vector<PointStruct>& list)
{
	root = buildTree(list, 0);		//assign the first tree node to root
}

void KdTree::nearSearch(TreeNode* ptr, bool d, Coordinate point, PointStruct& nearest)
{
	if (!ptr)
	{
		return;
	}
	if (point.distance(*ptr) < point.distance(nearest))
	{
		nearest = *ptr;		//update the nearest treenode
	}
	//decide to go to left subtree first or right subtree
	if (point.isSmaller(d, *ptr))
	{
		nearSearch(ptr->lchild, !d, point, nearest);		//go to left subtree to search the nearest treenode
		//if points in right subtree may be nearer than the current nearest treenode
		if (point.distance(nearest) >= point.distance(d, *ptr))
		{
			nearSearch(ptr->rchild, !d, point, nearest);
		}
	}
	else
	{
		nearSearch(ptr->rchild, !d, point, nearest);		//go to right subtree to search the nearest treenode
		//if points in left subtree may be nearer than the current nearest treenode
		if (point.distance(nearest) >= point.distance(d, *ptr))
		{
			nearSearch(ptr->lchild, !d, point, nearest);
		}
	}
}

int main()
{
	int node_num, search_num, i;
	vector<PointStruct> list;
	PointStruct input, nearest;
	Coordinate point;
	cin >> node_num >> search_num;
	double* arr = new double[search_num];
	while (node_num != 0)
	{
		cin >> input.coor[0] >> input.coor[1] >> input.name;
		list.push_back(input);
		node_num--;
	}
	KdTree example;
	//construct the new tree
	example.constructTree(list);
	//the nearest treenode is initialized as the root of the tree
	nearest.coor[0] = (*example.root).coor[0];
	nearest.coor[1] = (*example.root).coor[1];
	nearest.name = (*example.root).name;
	//start searching
	for(i = 0; i < search_num; i++)
	{
		cin >> point.coor[0] >> point.coor[1];
		example.nearSearch(example.root, 0, point, nearest);
		arr[i] = point.distance(nearest);		//save the results in arr first
	}
	for(i = 0; i < search_num; i++)
	{
		printf("%.4f\n", arr[i]);
	}
	return 0;
}
