#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <numeric>

#include <time.h>
#include <deque>

/***
 *  Formulate problem as a Graph search (not tree search)
 *      1. Discretize Honeycomb as a graph
 *              Classify the cells according to their property
 *      2. Apply effective graph search algorithm
 *
 *  For time to delivery reasons, choose BFS as it is guaranteed to converge and choosing UCS has no performance
 *  improvement since path cost to all adjancent cells is 1 considered to be equal (1)
 *
 *  Depth of the built BFS exploration tree has at most a depth of N
 *
 * ****/

std::vector<int> get_elements_per_row(int &R, int &total_rows, int &max_row_num_elem)
{
    std::vector<int> out_vec;
    int count;
    for(int i=0; i < R; ++i)
    {
        count = R+i;
        out_vec.push_back(count);
    }
    for(int i = 1; i < R; ++i)
    {
        out_vec.push_back(count-i);
    }
    return out_vec;
}


class HoneyComb // comb_nodes
{
public:
    /* public variables */
    std::unordered_map<int, std::vector<int>> comb_nodes;

    /*** Constructor ***/
    HoneyComb(int R_in, std::vector<int> cells_per_row_in, std::vector<int> x_cells, int i_largeRow)
    {
        forbid_cells = x_cells;
        cells_per_row = cells_per_row_in;
        R = R_in;
        R_total = int(std::pow(float(R), 3) - std::pow(float(R-1), 3));

        int value_counter = 0;

        generate_first_row_nodes();
        generate_last_row_nodes();

        // Build upper honeycomb
        for(int i = 1; i < i_largeRow-1; ++i)
        {
            generate_upperComb_row(i);
        }

        // Build middle row honeycomb
        generate_middleComb_row(i_largeRow-1);

        // Build lower honeycomb
        // Build upper honeycomb
        for(int i = i_largeRow; i < cells_per_row.size()-1; ++i)
        {
            generate_lowerComb_row(i);
        }


    }

private:

    std::vector<int> forbid_cells;
    std::vector<int> cells_per_row;

    int R;
    int R_total;

    void generate_first_row_nodes()
    {
        int n_firstRow = cells_per_row[0];
        int n_secondRow = cells_per_row[1];

        std::vector<int> neighbors;

        for(int i = 1; i < n_firstRow+1; ++i)
        {
            neighbors.clear();
            if(i == 1)
            {
                neighbors.push_back(2);
                neighbors.push_back(n_firstRow+1);
                neighbors.push_back(n_firstRow+2);
                // Add to graph
                comb_nodes[i] = neighbors;
            }
            else if(i == n_firstRow)
            {
                neighbors.push_back(n_firstRow-1);
                neighbors.push_back(n_firstRow+n_secondRow-1);
                neighbors.push_back(n_firstRow+n_secondRow);
                // Add to graph
                comb_nodes[i] = neighbors;
            }
            else
            {
                neighbors.push_back(i-1);
                neighbors.push_back(i+1);
                neighbors.push_back(n_firstRow+i);
                neighbors.push_back(n_firstRow+i+1);
                // Add to graph
                comb_nodes[i] = neighbors;
            }

        }
    }

    void generate_last_row_nodes()
    {
        int n_last = cells_per_row[cells_per_row.size()-1];
        int n_secondLast = cells_per_row[cells_per_row.size()-2];

        std::vector<int> neighbors;

        int i_start = R_total - n_last + 1;

        for(int i = i_start; i < i_start+n_last; ++i)
        {
            neighbors.clear();
            if(i == i_start)
            {
                neighbors.push_back(i_start+1);
                neighbors.push_back(i_start-n_secondLast);
                neighbors.push_back(i_start-n_secondLast+1);
                // Add to graph
                comb_nodes[i] = neighbors;
            }
            else if(i == R_total)
            {
                neighbors.push_back(R_total-1);
                neighbors.push_back(R_total-R);
                neighbors.push_back(R_total-R-1);
                // Add to graph
                comb_nodes[i] = neighbors;
            }
            else
            {
                neighbors.push_back(i-1);
                neighbors.push_back(i+1);
                neighbors.push_back(i-n_last-1);
                neighbors.push_back(i-n_last);
                // Add to graph
                comb_nodes[i] = neighbors;
            }

        }
    }

    void generate_upperComb_row(int row)
    {
        int n_currentRow = cells_per_row[row];
        int n_prevRow = cells_per_row[row-1];
        int n_nextRow = cells_per_row[row+1];

        int i_start = std::accumulate(cells_per_row.begin(), cells_per_row.begin() + row, 0) + 1;

        std::vector<int> neighbors;

        for(int i = i_start; i < i_start+n_currentRow; ++i)
        {
            neighbors.clear();
            if(i == i_start)
            {
                neighbors.push_back(i+1);
                neighbors.push_back(i_start-n_prevRow);
                neighbors.push_back(i_start+n_currentRow+1);
                neighbors.push_back(i_start+n_currentRow);
                // Add to graph
                comb_nodes[i] = neighbors;
            }
            else if(i == i_start+n_currentRow-1)
            {
                neighbors.push_back(i-1);
                neighbors.push_back(i+n_currentRow);
                neighbors.push_back(i+n_nextRow);
                neighbors.push_back(i-n_currentRow);
                // Add to graph
                comb_nodes[i] = neighbors;
            }
            else
            {
                neighbors.push_back(i-1);
                neighbors.push_back(i+1);
                neighbors.push_back(i-n_prevRow-1);
                neighbors.push_back(i-n_prevRow);
                neighbors.push_back(i+n_currentRow);
                neighbors.push_back(i+n_currentRow+1);
                // Add to graph
                comb_nodes[i] = neighbors;
            }

        }
    }

    void generate_middleComb_row(int row)
    {
        int n_currentRow = cells_per_row[row];
        int n_prevRow = cells_per_row[row-1];
        int n_nextRow = cells_per_row[row+1];

        int i_start = std::accumulate(cells_per_row.begin(), cells_per_row.begin() + row, 0) + 1;

        std::vector<int> neighbors;

        for(int i = i_start; i < i_start+n_currentRow; ++i)
        {
            neighbors.clear();
            if(i == i_start)
            {
                neighbors.push_back(i+1);
                neighbors.push_back(i_start-n_prevRow);
                neighbors.push_back(i_start+n_currentRow);
                // Add to graph
                comb_nodes[i] = neighbors;
            }
            else if(i == i_start+n_currentRow-1)
            {
                neighbors.push_back(i-1);
                neighbors.push_back(i+n_currentRow-1);
                neighbors.push_back(i-n_currentRow);
                // Add to graph
                comb_nodes[i] = neighbors;
            }
            else
            {
                neighbors.push_back(i-1);
                neighbors.push_back(i+1);
                neighbors.push_back(i-n_prevRow-1);
                neighbors.push_back(i-n_prevRow);
                neighbors.push_back(i+n_currentRow-1);
                neighbors.push_back(i+n_currentRow);
                // Add to graph
                comb_nodes[i] = neighbors;
            }

        }
    }

    void generate_lowerComb_row(int row)
    {
        int n_currentRow = cells_per_row[row];
        int n_prevRow = cells_per_row[row-1];
        int n_nextRow = cells_per_row[row+1];

        int i_start = std::accumulate(cells_per_row.begin(), cells_per_row.begin() + row, 0) + 1;

        std::vector<int> neighbors;

        for(int i = i_start; i < i_start+n_currentRow; ++i)
        {
            neighbors.clear();
            if(i == i_start)
            {
                neighbors.push_back(i+1);
                neighbors.push_back(i_start-n_prevRow);
                neighbors.push_back(i_start-n_prevRow+1);
                neighbors.push_back(i_start+n_currentRow);
                // Add to graph
                comb_nodes[i] = neighbors;
            }
            else if(i == i_start+n_currentRow-1)
            {
                neighbors.push_back(i-1);
                neighbors.push_back(i+n_currentRow-1);
                neighbors.push_back(i-n_currentRow-1);
                neighbors.push_back(i-n_currentRow);
                // Add to graph
                comb_nodes[i] = neighbors;
            }
            else
            {
                neighbors.push_back(i-1);
                neighbors.push_back(i+1);
                neighbors.push_back(i-n_prevRow);
                neighbors.push_back(i-n_prevRow+1);
                neighbors.push_back(i+n_currentRow-1);
                neighbors.push_back(i+n_currentRow);
                // Add to graph
                comb_nodes[i] = neighbors;
            }

        }
    }
};


struct GraphNode
{
    int id_node;
    int cost;
    int parent;

    bool operator==(const GraphNode& l)
    {
        return l.id_node == id_node;
    }

};


int main() {

    clock_t tStart = clock();

    /*** Read Input ***/
    int R, N, A, B, X;
    std::cin >> R >> N >> A >> B >> X;

    std::vector<int> x_val;
    for(int i = 0; i < X; i++)
    {
        int temp;
        std::cin >> temp;
        x_val.push_back(temp);
    }

//    /** Test purposes ***/
//    int R = 6;
//    int N = 6;
//    int A = 1;
//    int B = 45;
//    int X = 11;
//
//    std::vector<int> x_val = {15, 16, 17, 19, 26, 27, 52, 53, 58, 65, 74};

    int total_rows = 2*R -1;

    int max_row_num_elem = R + (R-1);
    int i_largeRow = R;

    std::vector<int> elem_per_row = get_elements_per_row(R, total_rows, max_row_num_elem);

    // Create Honey Comb
    HoneyComb honey_comb = HoneyComb(R, elem_per_row, x_val, i_largeRow);

//    printf("Time taken: %.5fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);


    /** START OF BFS ***/
    // Initialize helper arrays for exploration
    std::deque<GraphNode>  explored;
    std::deque<GraphNode>  frontier;

    // Add start cell ID to the frontier and to explored
    GraphNode A_node = {A, 0, 0};
    GraphNode B_node = {B, 10000, 0};

    explored.push_back(A_node);
    frontier.push_back(A_node);

    // Flag to get Solution

    bool solution = false;

    std::vector<int> temp_children;

    // Iterate over
    while(!frontier.empty())
    {

        // Access next node to explore
        GraphNode curr_node = frontier.front();
        frontier.pop_front();

        // Check if its the solution
        if (curr_node.id_node == B_node.id_node)
        {
            // Terminate loop if it is a solution
            solution = true;
            B_node = curr_node;
            break;
        }

        // Retrieve children of node
        temp_children = honey_comb.comb_nodes[curr_node.id_node];

        // See children of visited node
        for(int elem : temp_children)
        {

            // Add to frontier Only if it is a valid cell to explore and if not explored before
            if(std::find(x_val.begin(), x_val.end(), elem) == x_val.end())
            {
                GraphNode tempNode = {elem, curr_node.cost+1, curr_node.id_node};

                if (std::find(explored.begin(), explored.end(), tempNode) != explored.end())
                {
                    continue;
                }

                else
                {
                    if (std::find(frontier.begin(), frontier.end(), tempNode) != frontier.end())
                    {
                        // tempNode is in frontier, check the distances and update if necesary
                        auto ptr_node = std::find(frontier.begin(), frontier.end(), tempNode);
                        if(tempNode.cost < ptr_node->cost)
                            ptr_node->cost = tempNode.cost;
                    }
                    else
                        frontier.push_back(tempNode);
                }
            }
        }

        explored.push_back(curr_node);

    }

    if (!solution)
        std::cout << "No" << std::endl;
    else if (solution && (B_node.cost <= N))
        std::cout << B_node.cost << std::endl;
    else
        std::cout << "No" << std::endl;


//    printf("Time taken: %.5fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

//    std::cout << "That's it my man!" << std::endl;

    return 0;
}

/***
6 6 1 45 11
15 16 17 19 26 27 52 53 58 65 74
 */
