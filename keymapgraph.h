#ifndef KEYMAPGRAPH_H
#define KEYMAPGRAPH_H

#include <iostream>
#include <string>
#include <vector>


class Keymap_graph {
private:
    static const std::string nodes;

    static const std::vector<std::vector<int>> edges;

    std::string pass;

    static int find_distance(int, int);

public:
    explicit Keymap_graph(const std::string&);

    std::string get_pass();

    int distance_between(int, int);
    int distance_between(std::string::iterator,
                         std::string::iterator);

    double keys_sequentially_arrangement_score();
};

const std::string Keymap_graph::nodes = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";

const std::vector<std::vector<int>> Keymap_graph::edges = {
        {1},                      {0, 2, 13},               {1, 13, 14, 3},
        {2, 14, 15, 4},           {3, 15, 16, 5},           {4, 16, 17, 6},
        {5, 17, 18, 7},           {6, 18, 19, 8},           {7, 19, 20, 9},
        {8, 20, 21, 10},          {9, 21, 22, 11},          {10, 22, 23, 12},
        {11, 23, 24},             {1, 2, 14, 26},           {2, 3, 13, 15, 26, 27},
        {3, 4, 14, 16, 27, 28},   {4, 5, 15, 17, 28, 29},   {5, 6, 16, 18, 29, 30},
        {6, 7, 17, 19, 30, 31},   {7, 8, 18, 20, 31, 32},   {8, 9, 19, 21, 32, 33},
        {9, 10, 20, 22, 33, 34},  {10, 11, 21, 23, 34, 35}, {11, 12, 22, 24, 35, 36},
        {12, 23, 25, 36},         {24, 36},                 {13, 14, 27, 37},
        {14, 15, 26, 28, 37, 38}, {15, 16, 27, 29, 38, 39}, {16, 17, 28, 30, 39, 40},
        {17, 18, 29, 31, 40, 41}, {18, 19, 30, 32, 41, 42}, {19, 20, 31, 33, 42, 43},
        {20, 21, 32, 34, 43, 44}, {21, 22, 33, 35, 44, 45}, {22, 23, 34, 36, 45, 46},
        {23, 24, 25, 35, 46},     {26, 27, 38},             {37, 27, 28, 39},
        {38, 28, 29, 40},         {39, 29, 30, 41},         {40, 30, 31, 42},
        {41, 31, 32, 43},         {42, 32, 33, 44},         {43, 33, 34, 45},
        {44, 34, 35, 46},         {45, 35, 36}
};

int Keymap_graph::find_distance(int from, int to) {
    int N = (int) nodes.size();
    if (from > N || to > N) return -1;
    if (from == to) return 0;
    std::vector<int> wave_distances(N);
    for (int to_change : edges[from]) {
        if (to_change == to) return 1;
        wave_distances[to_change] = 1;
    }
    bool nogaps = false; //no zeros in wave_distances except "from"
    for (int i = 2; !nogaps; i++) {
        for (int j = 0; j < N; j++) { //search for wave start
            if (wave_distances[j] == i-1) {
                for (int to_change : edges[j]) { //wave makes changes
                    if (wave_distances[to_change] == 0 && to_change != from) wave_distances[to_change] = i;
                }
                if (wave_distances[to]) return wave_distances[to];
            }
        }
        int zeros_count = 0;
        for (int wd : wave_distances) if (wd == 0) zeros_count++;
        if (zeros_count == 1) nogaps = true;
    }
    return -2;
}

Keymap_graph::Keymap_graph(const std::string & password) {
    /**
     * Constructor. Transforms entered password into "nodes" string.
     * Nodes are presented as lowercase keyboard keys.
     * @Parameters
     * password : const string - initial password string
     */
    Keymap_graph::pass = password;
    const std::string upper = "~!@#$%^&*()_+QWERTYUIOP{}|ASDFGHJKL:\"ZXCVBNM<>?";
    for (auto p = pass.begin(); p < pass.end(); p++) {
        int p_pos = (int) upper.find(*p);
        if (p_pos > -1) *p = nodes[p_pos];
    }
}

std::string Keymap_graph::get_pass() {
    /**
     * Returns password written as "nodes" string
     */
    return this->pass;
}

int Keymap_graph::distance_between(const int first, const int second) {
    /**
     * Returns distance between keys on keyboard by indexes of two chars from password
     * @Parameters
     * first, second : int - indexes of chars of password to find the distance between
     */
    return distance_between(pass.begin() + first, pass.begin() + second);
}

int Keymap_graph::distance_between(std::string::iterator first,
    std::string::iterator second) {
    /**
     * Returns distance between keys on keyboard by iterators of two chars from password
     * @Parameters
     * first, second : std::string::iterator - iterators of chars of password to find the distance between
     */
    int from = (int)nodes.find(*first);
    int to = (int)nodes.find(*second);
    return Keymap_graph::find_distance(from, to);
}

double Keymap_graph::keys_sequentially_arrangement_score() {
    
    int count_of_joined_symbols = 0;
    int last_sequence_index = -2;

    for (int i = 1; i < pass.length(); i++) {
        if (distance_between(i - 1, i) <= 1) {
            if ((i - 1) - last_sequence_index > 0)
                count_of_joined_symbols++;

            last_sequence_index = i;
            count_of_joined_symbols++;
        }
    }
    
    return ((1.0 - static_cast<double>(count_of_joined_symbols) / pass.length()) * 100.0);
}

#endif //KEYMAPGRAPH_H
