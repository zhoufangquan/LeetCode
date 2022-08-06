/*
 * @lc app=leetcode.cn id=913 lang=cpp
 *
 * [913] 猫和老鼠
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {

public: 

    int f[5003][55][55];  // 记录所有的状态
    int n;   // 图中顶点的数目
    int get_state(vector<vector<int>>& graph, int k, int i, int j){
        int ans = f[k][i][j];
        if(i == 0) ans = 1;  // the mouse reach the hole
        else if (i == j) ans = 2;  // the cat catch the nouse
        else if(k>=2*n*n) ans = 0;  // a draw.  the cat never catch the mouse and the mouse can never reach the hole
        else if(ans == -1){  // this state is not updated. go to update
            bool win;  //  record  win or not
            bool draw;  //  record graw or not
            if(k%2 == 0){ // mouse's turn to move
                win = false; draw = false;
                for(auto &ne: graph[i]){  // iterat all node adj to node i
                    int t = get_state(graph, k+1, ne, j);  // search the state of node ne
                    if(t == 1) win=true;
                    else if(t == 0) draw = true;
                    if(win) break;  // find out win state , end for...
                }
                if(win) ans = 1;
                else if(draw) ans = 0;
                else ans = 2;
            }
            else {  // cat's turn to move 
                win = false; draw = false;
                for(auto &ne: graph[j]){
                    if(ne == 0) continue;  // the cat must not reach the hole
                    int t = get_state(graph, k+1, i, ne);
                    if(t == 2) win=true;
                    else if(t == 0) draw = true;
                    if(win) break;  // find out win state , end for...
                }
                if(win) ans = 2;
                else if(draw) ans = 0;
                else ans = 1;
            }
        }
        f[k][i][j] = ans;  //  the key step to decrease time 
        return ans;
    }

    int cat_strategy(vector<vector<int>>& graph, int k, int i, int j){
        int ans = 0;
        int sub_ans = 0;
        for(auto &ne: graph[j]){
            if(ne == 0) continue;
            if(ne == i){
                ans = i;
                break;
            } 
            else if(f[k+1][i][ne] == 2){
                ans = ne;
            }
            else if(f[k+1][i][ne] == 0){
                sub_ans = ne;
            }
        }
        if(ans != 0) return ans;
        else return sub_ans;
    }

    int mouse_strategy(vector<vector<int>>& graph, int k, int i, int j){
        int ans = j;
        int sub_ans = j;
        for(auto &ne:graph[i]){
            if(ne == j) continue;
            if(ne == 0){
                ans = 0;
                break;
            }
            else if(f[k+1][ne][j] == 1){
                ans = ne;
            }
            else if(f[k+1][ne][j] == 0){
                sub_ans = ne;
            }
        }
        if(ans != j) return ans;
        else return sub_ans;

    }

    void play_game(vector<vector<int>>& graph){
        int step = 0;  // step counter
        int i = 1, j = 2;  //  init location of mouse and cat
        while(1){
            if(step>2*n*n) {
                cout<<"This is a draw!\n";
                break;
            }
            if(step%2 == 0){  // mouse move
                i = mouse_strategy(graph, step, i, j);
                cout<<"mouse move to node: "<<i<<'\n';
                if(i == 0) {  // win
                    cout<<"mouse win!\n"; break;
                }
                else if(i == j){  // lose
                    cout<<"cat win!\n"; break;
                }
            }
            else{  // cat move
                j = mouse_strategy(graph, step, i, j);
                cout<<"cat move to node: "<<j<<'\n';
                if(j == i) { // win
                    cout<<"cat win!\n"; break;
                }
                else if(j == 0){
                    cout<<"mouse win!\n"; break;
                }
            }
            step+=1;  
            if(step%2 == 0) cout<<"==========================================================================\n\n";
        }

    }


    int catMouseGame(vector<vector<int>>& graph) {
        n = graph.size();  // get node of the graph
        memset(f, -1, sizeof f);  // init all states

        get_state(graph, 0, 1, 2); // get the best chiose of every state

        play_game(graph);  // start to play game.
        return 0;
    }
};
// @lc code=end

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int main(){

    vector<vector<int> > graph;
    Solution test;
    int n;

    cout<<"输入节点的个数：";
    cin>>n;

    for(int i=0;i<n;i++){
        cout<<"输入节点："<<i<<"的邻接节点：";
        string adjNode; cin>> adjNode;
        vector<int> temp = stringToIntegerVector(adjNode);
        graph.push_back(temp);
    }
    // test.catMouseGame(graph);

    return 0;
}

/*
6
[2,5]
[3]
[0,4,5]
[1,4,5]
[2,3]
[0,2,3]

4
1 3
0
3
0 2

*/
