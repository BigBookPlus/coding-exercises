#include"Solution.h"
//a depth first traversal method to copy the graph.
UndirectedGraphNode* Solution::cloneGraph(UndirectedGraphNode *node) {

	if (node == NULL)
		return NULL;

	UndirectedGraphNode* ret = new UndirectedGraphNode(node->label);
	nodemap.insert(make_pair(node, ret));

	for (int i = 0; i<node->neighbors.size(); i++)
	{
		if (nodemap.find(node->neighbors[i]) == nodemap.end())
		{
			UndirectedGraphNode* tmp = cloneGraph(node->neighbors[i]);
			ret->neighbors.push_back(tmp);
		}
		else
		{
			ret->neighbors.push_back(nodemap[node->neighbors[i]]);
		}
	}
	return ret;
}
