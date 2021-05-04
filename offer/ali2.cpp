#include <algorithm>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>
#include <vector>

struct GraphNode
{
    int val_;
    bool visited_;
    std::vector<std::pair<int, int> > adj_;
};

int dfs(std::vector<GraphNode>& graph, int curNode, int maxTime, int curTime)
{
    if ( graph[curNode].visited_ || maxTime < curTime * 2 )
        return 0;

    graph[curNode].visited_ = true;
    int maxVal{};
    for ( auto& adjNode : graph[curNode].adj_ ) {
        maxVal = std::max(maxVal, dfs(graph, adjNode.first, maxTime, curTime + adjNode.second));
    }
    graph[curNode].visited_ = false;
    return maxVal + graph[curNode].val_;
}

int main()
{
    int n, t;
    std::cin >> n >> t;
    std::vector<GraphNode> graph(1);
    for ( int cnter{}; cnter < n; ++cnter ) {
        int tmpVal;
        std::cin >> tmpVal;
        graph.emplace_back(GraphNode{tmpVal});
    }
    for ( int node1{}, node2{}, val{}; std::cin >> node1 >> node2 >> val; ) {
        graph[node1].adj_.emplace_back(std::make_pair(node2, val));
        graph[node2].adj_.emplace_back(std::make_pair(node1, val));
    }
    std::cout << dfs(graph, 1, t, 0);

    return 0;
}

