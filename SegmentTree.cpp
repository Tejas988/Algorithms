#include <bits/stdc++.h>
using namespace std;
int N;
int tree[4N + 1];
int lazy[1000] = {0}; //initialise lazy to 0



//min max sum multiply gcd xor or and as they are associative a+(b+c)=(a+b)+c
void lazyupdate(int s, int e, int indx, int val, int l, int r)
{
	// l and r are the range which we need to update
	//val is the value which needs to be added

	// if lazy exists on current indx then resolve it and pass down to its children if its non leaf

	if (lazy[indx] != 0)
	{
		tree[indx] += lazy[indx];
		if (s != e)
		{
			//non leaf
			lazy[2 * indx] = lazy[indx];
			lazy[2 * indx + 1] = lazy[indx];
		}
		lazy[indx] = 0;
	}
	//no overlap
	if (s > r or e < l)
		return;


	if (s >= l and e <= r)
	{
		//complete overlap
		tree[indx] += val;
		if (s != e)
		{
			lazy[2 * indx] += val;
			lazy[2 * indx + 1] += val;
		}
		return;
	}

	//recursive case - partial overlap
	int mid = (s + e) / 2;
	upadteRange(s, mid, 2 * indx, val, l, r);
	upadteRange(mid + 1, e, 2 * indx + 1, val, l, r);

	// update tree while returning up
	tree[indx] = min(tree[2 * indx], tree[2 * indx + 1]);
	return;
}


//fun for returning value in range
int queryLazy(int s, int e, int L, int R, int indx)
{
	if (lazy[indx] != 0)
	{
		tree[indx] += lazy[indx];
		if (s != e)
		{
			//non leaf
			lazy[2 * indx] = lazy[indx];
			lazy[2 * indx + 1] = lazy[indx];
		}
		lazy[indx] = 0;
	}
	//no overlap
	if (s > r or e < l)
		return INT_MAX;
	if (s >= l and e <= r)
	{
		//complete overlap
		return tree[indx];
	}
	//partial overlap
	int mid = (s + e) / 2;
	upadteRange(s, mid, 2 * indx, val, l, r);
	upadteRange(mid + 1, e, 2 * indx + 1, val, l, r);
	// update tree while returning up
	return min(tree[2 * indx], tree[2 * indx + 1]);

}





void buildTree(int s, int e, int indx, int a[])
{
	if (s == e)
	{
		tree[indx] = a[s];
		return;
	}
	int mid = (s + e) / 2;
	buildTree(s, mid, 2 * indx, a);
	buildTree(mid + 1, e, 2 * indx + 1, a);
	tree[indx] = min(tree[2 * indx], tree[2 * indx + 1]);
	return;
}

int query(int s, int e, int L, int R, int indx)
{
	//complete overlap

	// L and R is query range and s and e are array ranges of a node

	//indx is node
	if (L <= s and R >= e)
		return tree[indx];
	if (L > s and R < e)
		return INT_MAX;
	int mid = (s + e) / 2;
	int left = query(s, mid, L, R, 2 * indx);
	int right = query(mid + 1, e, L, R, 2 * indx + 1);
	return min(left, right);
}

void update(int s, int e, int val, int indx, int i)
{

	// s and e is array  range of a node
	if (i > e or i < s)
	{
		return;
	}
	if (ss == se)
	{
		tree[indx] = val;
		return;
	}
	int mid = (s + e) / 2;
	update(s, mid, val, 2 * indx, i);
	update(mid + 1, e, val, 2 * indx + 1, i);
	tree[indx] = min(tree[2 * indx], tree[2 * indx + 1]);
	return;
}
void upadteRange(int s, int e, int l, int r, int val, int indx)
{
	// s and e is array  range of a node
	if (l > e || r < s)
	{
		return;
	}
	if (s == e)
	{
		tree[indx]  = val;
		return;
	}
	int mid = (s + e) / 2;
	upadteRange(s, mid, l, r, val, 2 * indx);
	upadteRange(mid + 1, e, l, r, val, 2 * indx + 1);
	tree[indx] = min(tree[2 * indx], tree[2 * indx + 1]);
	return;
}
int main()
{
	int a[] = {1, 2, 3, 4, -13, 34, 2, -3};
	N = sizeof(a) / sizeof(int);

	return 0;
}