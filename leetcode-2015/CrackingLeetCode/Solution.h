#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<sstream>
#include<map>
#include<set>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>
#include<functional>

#include"ListNode.h"
#include"Point.h"
#include"RandomListNode.h"
#include"UndirectedGraphNode.h"
#include"TreeNode.h"
#include"TreeLinkNodeh.h"
#include"Interval.h"
using namespace std;

class Solution{
private:
	unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> nodemap;
public:
	void reverseWords(string &s);

	int myatoi(string &s);
	string myitoa(int i);
	int evalRPN(vector<string> &tokens);

	int maxPoints(vector<Point> &points);

	ListNode* sortList(ListNode *head);
	ListNode* merge(ListNode* l1, ListNode* l2);
	ListNode* mergeSort(ListNode* list);

	ListNode* insertionSortList(ListNode *head);

	void reorderList(ListNode *head);

	ListNode* detectCycle(ListNode *head);
	bool hasCycle(ListNode *head);

	vector<string> wordBreak(string s, unordered_set<string> &dict);
	void findWordBreak(string s, int idx, unordered_set<string> &dict, string ans, vector<string> &ret);
	bool findWordBreak1(string s, int idx, vector<int> &ans, vector<vector<int>> &ret, vector<vector<int>> &sucs, bool* tag);
	bool findWordBreak2(string s, int idx, vector<int> &ans, vector<vector<int>> &ret, bool **dp, bool *tag);
	void findWordBreak3(string s, int idx, vector<int> ans, vector<vector<int>> &ret, vector<vector<int>> &sucs);

	bool wordBreak1(string s, unordered_set<string> &dict);
	bool findWordBreak4(string s, int idx, vector<vector<int>> &sucs, bool* tag);

	RandomListNode* copyRandomList(RandomListNode *head);

	int singleNumber(int A[], int n);

	int candy(vector<int> &ratings);

	int canCompleteCircuit(vector<int> &gas, vector<int> &cost);

	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node);

	vector<vector<string>> partition(string s);
	void dfs(string t, int** tag, int start, int tlen, vector<vector<string>> &ret, vector<string> ans);

	int minCut(string s);
	void findMin(string t, int** tag, int start, int tlen, int &ans, int count);

	void solve(vector<vector<char>> &board);//Surrounded Regions
	bool findTag(vector<vector<char>> &board, int x, int y, int m, int n, char num);
	
	int sumNumbers(TreeNode *root);
	void calc(TreeNode* node, int num, int *ans);

	int longestConsecutive(vector<int> &num);

	int ladderLength(string start, string end, unordered_set<string> &dict);

	vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict);
	void construct(unordered_set<int>* prev, vector<vector<string>>& ret, vector<string>& ans, unordered_set<string>::const_iterator* list, int p, int si);

	bool isPalindrome(string s);

	int maxPathSum(TreeNode *root);
	int calc(TreeNode *root, int& ans);

	int maxProfit(vector<int> &prices);

	int maxProfiti(vector<int> &prices);

	int maxProfitii(vector<int> &prices);

	int minimumTotal(vector<vector<int> > &triangle);

	void connect(TreeLinkNode *root);
	void connecti(TreeLinkNode *root);

	void flatten(TreeNode *root);
	TreeNode* solve(TreeNode* root);


	TreeNode *sortedListToBST(ListNode *head);

	TreeNode *sortedArrayToBST(vector<int> &num);
	TreeNode* sortedArrayToBST(vector<int> &num, int start, int end);

	vector<vector<int> > levelOrderBottom(TreeNode *root);

	TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder);
	TreeNode *buildTreeHelper(vector<int> &preorder, vector<int> &inorder, 
		int p, int start,int end);

	void recoverTree(TreeNode *root);
	void recoverTreeHelper(TreeNode* root, bool& flag, int &pre, TreeNode* &ptr1, TreeNode*& ptr2);

	vector<TreeNode *> generateTrees(int n);
//	vector<TreeNode *>  build(vector<TreeNode *>& ans, TreeNode*& node, int left, int right, int& count, int n, TreeNode* root);
	vector<TreeNode *>  build( int left, int right);

	TreeNode * copyTree(TreeNode* root);
	int num(TreeNode* root);

	int numDistinct(string S, string T);

	bool isInterleave(string s1, string s2, string s3);
	bool judge(int a, int b, int c, string &s1, string &s2, string &s3);

	vector<string> restoreIpAddresses(string s);
	void sep(vector<string>& ret, string s, int step, int start, vector<int>& idxs);
	bool num(string s, int start, int end);

	ListNode * reverseBetween(ListNode *head, int m, int n);

	vector<vector<int> > subsetsWithDup(vector<int> &S);
	void count(int n, vector<int>&S, int step, int start, vector<int>& ans, set<vector<int>>& ret);

	int numDecodings(string s);
	void countDecode(string s, int start, int&ans);
	bool isCode(string s, int start, int len);
	int codeVal(string s, int start, int len);

	vector<int> grayCode(int n);

	bool isScramble(string s1, string s2);
	bool judgeScramble(string &s1, string &s2, int start, int end);

	int largestRectangleArea(vector<int> &height);

	int maximalRectangle(vector<vector<char> > &matrix);

	bool exist(vector<vector<char> > &board, string word);
	bool searchWord(vector<vector<char> > &board, int x, int y, int m, int n, int step, int **tag, string&word);

	string minWindow(string S, string T);

	int minDistance(string word1, string word2);

	string simplifyPath(string path);

	int sqrt(int x);

	vector<string> fullJustify(vector<string> &words, int L);

	bool isNumber(const char *s);

	vector<vector<int> > generateMatrix(int n);

	string getPermutation(int n, int k);

	vector<Interval> insert(vector<Interval> &intervals, Interval newInterval);

	vector<Interval> merge(vector<Interval> &intervals);
	static bool cmp(const Interval& i1, const Interval& i2);

	string multiply(string num1, string num2);

	int jump(int A[], int n);

	int trap(int A[], int n);

	bool isMatch(const char *s, const char *p);

	int firstMissingPositive(int A[], int n);

	vector<vector<int> > Solution::combinationSum(vector<int> &candidates, int target);
	void solve(set<vector<int> >& retset, vector<int> &ans, vector<int> &candidates, int step, int sum, int target);

	vector<vector<int> > combinationSum2(vector<int> &num, int target);
	void solve2(set<vector<int> >& retset, vector<int> &ans, vector<int> &candidates, int step, int sum, int target);

	string countAndSay(int n);

	void solveSudoku(vector<vector<char> > &board);
	bool Solution::solveSudokuBT(vector<vector<char> > &board, int x, int y);

	bool isValidSudoku(vector<vector<char> > &board);

	int searchInsert(int A[], int n, int target);

	vector<int> searchRange(int A[], int n, int target);

	int search(int A[], int n, int target);

	int longestValidParentheses(string s);

	void nextPermutation(vector<int> &num);

	vector<int> findSubstring(string S, vector<string> &L);

	int divide(int dividend, int divisor);

	char *strStr(char *haystack, char *needle);

	int removeElement(int A[], int n, int elem);

	int removeDuplicates(int A[], int n);

	ListNode *reverseKGroup(ListNode *head, int k);

	ListNode *mergeKLists(vector<ListNode *> &lists);
	ListNode* kmerge(ListNode* a, ListNode* b);

	vector<string> generateParenthesis(int n);
	void _generateParenthesis(vector<string>& ret, string&ans, int open, int close, int n);

	bool isValid(string s);

	ListNode *removeNthFromEnd(ListNode *head, int n);

	vector<string> letterCombinations(string digits);
	void _letterCombinations(vector<string> &ret, string &ans, 
		vector<vector<char>>& dict, string digits, int step);

	vector<vector<int> > fourSum(vector<int> &num, int target);
	void _fourSum(vector<vector<int>>& ret, vector<int>& ans, vector<int> &num, int step, int idx, int sum, int target);
	static bool cmpSum(const vector<int>& v1, const vector<int>& p2);

	int romanToInt(string s);

	string intToRoman(int num);

	int maxArea(vector<int> &height);

	string longestCommonPrefix(vector<string> &strs);

	bool isPalindrome(int x);

	string getPermutation2(int n, int k);

	bool isMatch2(const char* s, const char * p);

	int atoi(const char *str);

	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2);

	string longestPalindrome(string s);

	int lengthOfLongestSubstring(string s);

	double findMedianSortedArrays(int A[], int m, int B[], int n);

	vector<int> twoSum(vector<int> &numbers, int target);

	string convert(string s, int nRows);
};