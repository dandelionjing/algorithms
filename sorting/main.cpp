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

void bubblesort(vector<int>& arr){
  int n = arr.size();
  int k = n;
  for(int i = 0; i < n;i++){
    int flag = 1;
    int r;
    for(int j = 1; j < k; j++)
    {
      if(arr[j-1] > arr[j]) {
        swap(arr[j], arr[j-1]); 
        flag =0; 
        r = j;
      }
    }
    k = r;
    if(flag) break;
  }
  return;
}

void select_sort(vector<int>& arr){
  int n = arr.size();
  for(int i = 0; i < n; i++){
    int min = i;
    for(int j = i+1; j < n; j++)
      if(arr[j] < arr[min]) min = j;
    swap(arr[i], arr[min]);
  }
  return;
}

void insert_sort(vector<int>& arr){
  int n = arr.size();
  for(int i = 1; i < n; i++){
    if(arr[i] < arr[i-1]){
      int tmp = arr[i];
      int index = i;
      for(int j = i-1; j >= 0; j--){
        if(arr[j] > tmp) {
          arr[j+1] = arr[j];
          index = j;
        }
        else break;
      }
      arr[index] = tmp;
    }
  }
  return;
}

void shell_sort(vector<int>& arr){
  int n = arr.size();
  int gap = n/2;
  while(gap > 0){
    for(int i = gap; i < n; i++){
      int tmp = arr[i];
      int j = i;
      while(j >= gap && arr[j-gap] > tmp){
        arr[j] = arr[j-gap];
        j -= gap;
      }
      arr[j] = tmp;
    }
    gap = gap/2;
  }
  return;
}

void merge(vector<int>& arr, int left, int right, int mid){
  vector<int> merged;
  int i, j;
  for(i = left, j = mid+1; i<= mid && j <= right;){
    if(arr[i] < arr[j]){
      merged.push_back(arr[i]);
      i++;
    }
    else{
      merged.push_back(arr[j]);
      j++;
    }
  }
  while(i<=mid){
    merged.push_back(arr[i]);
    i++;
  }
  while(j<=right){
    merged.push_back(arr[j]);
    j++;
  }
  for(i = left; i <= right; i++)
    arr[i] = merged[i-left];
  return;
}


void merge_sort(vector<int>& arr, int left, int right){
  if(arr.size()<=1) return;
  if(left >= right) return;
  int mid = (left+right)/2;
  merge_sort(arr, left, mid);
  merge_sort(arr, mid+1, right);
  merge(arr, left, right, mid);
  return;
}

void qsort(vector<int>& arr, int left, int right){
  if(left >= right) return;
  int key = arr[left];
  int l = left+1;
  int r = right;
  while(l  < r){
    while( l < r && arr[l] <= key) l++;
    while( l < r && arr[r] > key) r--;
    if(l<r) swap(arr[l],arr[r]);
  }
  swap(arr[l-1], arr[left]);
  qsort(arr, left, l-2);
  qsort(arr, r+1, right);
  return;
}
void quick_sort(vector<int>& arr){
  qsort(arr, 0, arr.size()-1);
  return;
}

void max_heap(vector<int>& arr, int start, int end){
  int root = start;
  while(true){
    int child = root * 2 + 1;
    if(child > end) break;
    if(child + 1 < end && arr[child] < arr[child + 1]) child +=1;
    if(arr[root] < arr[child]){
      swap(arr[root], arr[child]);
      root = child;
    }
    else break;
  }
  return;
}

void heap_sort(vector<int>& arr){
  int first = arr.size()/2 -1;
  for(int start = first; start >=0; start--)
    max_heap(arr, start, int(arr.size())-1);
  for(int end = arr.size()-1; end >=0; end--){
    swap(arr[end], arr[0]);
    max_heap(arr, 0, end-1);
  }
  return;
}
  

void print_last_Kline(int K){
  vector<string> L;
  L.resize(K);
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
  //bubblesort(test);
  heap_sort(test);
  for(const auto& i:test) cout << i;
  cout << endl;
  
  string s = "NNNBBBC";
  string t = "CB N";
  removeduplicates(s);
  cout << '\n' << s <<'\n';
  cout << anagram(s,t) << endl;
  replacespace(t);
  cout << t;
  return 0;
}

