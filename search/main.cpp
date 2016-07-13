#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <initializer_list>

using namespace std;
//git added

int binary_search(vector<int>& arr, int target){
  if(arr.size() == 0) return -1;
  int left = 0, right = arr.size()-1;
  while(left<=right){
    int mid = (left + right)/2;
    if(arr[mid] == target) return mid;
    else if(arr[mid] > target) right = mid-1;
    else left = mid + 1;
  }
  return -1;
}

class Graph{
  int V;
  list<int> *adj;
  void DFS_recur(int, bool[]);
  public:
  Graph(int);
  void addedge(int, int);
  void BFS(int);
  void DFS(int);
  void DFS();
};

Graph::Graph(int v){
  this->V = v;
  adj = new list<int>[V];
};

void Graph::addedge(int v, int w){
  adj[v].push_back(w);
};

void Graph::BFS(int s){
  bool *visited = new bool[V];
  for(int i = 0; i < V; i++) visited[i] = false;
  
  queue<int> q;
  visited[s] = true;
  q.push(s);
  
  while(!q.empty()){
    s = q.front();
    cout << s;
    q.pop();
    
    for(list<int>::iterator it = adj[s].begin(); it != adj[s].end(); ++it){
      if(visited[*it] == false){
        visited[*it] = true;
        q.push(*it);
      }
    }
  }
  
  for(int i = 0; i < V; i++)
    if(visited[i] == false){
      visited[i] = true;
      q.push(i);
      
      while(!q.empty()){
      s = q.front();
      cout << s;
      q.pop();
    
        for(list<int>::iterator it = adj[s].begin(); it != adj[s].end(); ++it)
        {
          if(visited[*it] == false){
            visited[*it] = true;
            q.push(*it);
          }
        }
      }
    }
  
  return;
};

void Graph::DFS_recur(int v, bool visited[]){
  visited[v] = true;
  cout<<v;
  
  for(auto it = adj[v].begin(); it!= adj[v].end(); ++it)
    if(visited[*it] == false)
      DFS_recur(*it, visited);
  
  return;
}

void Graph::DFS(int s){
  bool *visited = new bool[V];
  for(int i = 0; i < V; i++) visited[i] = false;
  
  DFS_recur(s, visited);
  for(int i = 0; i < V; i++)
    if(visited[i] == false)
      DFS_recur(i, visited);
}

void Graph::DFS(){
  bool *visited = new bool[V];
  for(int i = 0; i < V ; i++) visited[i] = false;
  int s=0;
  
  stack<int> q;
  q.push(s);
  
  while(!q.empty()){
    s = q.top();
    q.pop();
    if(visited[s] == false){
      visited[s] = true;
      cout << s;
      for(list<int>::iterator it = adj[s].begin(); it != adj[s].end(); ++it)
        q.push(*it);
    }
  }
}

void print_last_Kline(int K){
  string L[K];
  int lines =0;
  ifstream myfile("example.txt");
  while(myfile.good()){
    getline(myfile, L[lines % K]);
    ++lines;
  }
  int start, end;
  if(lines<K){
    start = 0;
    end = lines;
  }
  else{
    start = lines % K;
    end = K;
  }
  for(int i = start; i < end; ++i)
    cout << L[(start + i) % K] << endl;
}

void removeduplicates( string& str){
  if(str.empty()) return;
  if(str.length() < 2) return;
  /*  
  //O(N^2)
  int tail = 1;
  
  for(int i = 1; i < str.length(); ++i){
    int j;
    for(j = 0; j < tail; ++j)
      if(str[j] == str[i]) break;
    if(j == tail){
      str[tail] = str[i];
      tail++;
    }
  }
  
  str = str.substr(0, tail);
  */
  //constant 
  bool* flag = new bool[256];
  for(int i = 0; i < 256; ++i) flag[i]= false;
  
  flag[(int)str[0]] = true;
  int tail = 1;
  for(int i = 1; i < str.length(); i++)
    if(flag[(int)str[i]] == false){
      str[tail] = str[i];
      ++tail;
      flag[(int)str[i]] = true;
    }
  
  str = str.substr(0, tail);
  
  return;
}

bool anagram(string s, string t){
  if(s.length() != t.length()) return false;
  vector<int> letters(256, 0);
  int count_s;
  int count_t;
  
  for(const auto& c : s){
    if(letters[c] == 0) ++count_s;
    ++letters[c];
  }
  for(string::iterator it = t.begin(); it != t.end(); ++it){
    if(letters[*it] == 0 ) return false;
    --letters[*it];
    if(letters[*it] == 0){
      ++count_t;
      if(count_s == count_t)
        return (++it) == t.end();
    }
  }
  return false;
    
}

void replacespace(string& s){
  int spacecount=0;
  for(const char& c :s)
    if(c == ' ') spacecount++;
  int old_length = s.length();
  s.resize(s.length() + spacecount*2);
  int new_length = s.length();
  for(int i = old_length - 1, j = new_length -1; i>=0; i--){
    if(s[i] == ' '){
      s[j] = '0';
      s[j-1] = '2';
      s[j-2] = '%';
      j -= 3;
    }
    else{
      s[j] = s[i];
      j--;
    }
  }
  return;
}
// To execute C++, please define "int main()"
int main() {
  auto words = { "Hello, ", "World!", "\n" };
  for (const string& word : words) {
    cout << word;
  }
  //auto il = {3, 5, 4, 1, 2, 7, 0};
  vector<int> test({3, 5, 4, 1, 2, 7, 0});
  cout << binary_search(test, 8)<<endl;
  
  Graph g(7);
  g.addedge(0, 1);
  g.addedge(1, 0);
  g.addedge(0, 2);
  g.addedge(2, 0);
  g.addedge(0, 4);
  g.addedge(4, 0);
  g.addedge(1, 3);
  g.addedge(3, 1);
  g.addedge(1, 5);
  g.addedge(5, 1);
  g.addedge(4, 5);
  g.addedge(5, 4);
  g.addedge(2, 6);
  g.addedge(6, 2);


  cout << "Following is Breadth First Traversal (starting from vertex 2) \n";
  g.BFS(2);
  cout << "\n Following is Depth First Traversal (starting from vertex 2) \n"; 
  g.DFS();
  
  string s = "NNNBBBC";
  string t = "CB N";
  removeduplicates(s);
  cout << '\n' << s <<'\n';
  cout << anagram(s,t) << endl;
  replacespace(t);
  cout << t;
  return 0;
}

