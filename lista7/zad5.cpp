#include<iostream>


class UnionFind 
    {
        public:
            UnionFind(int n) : m_parent{new int[n]}, m_rank{new int[n]}
            {
                for(int i = 0; i < n; ++i)
                {
                    m_parent[i] = i;
                    m_rank[i] = 0;
                }
            }
            int find(int i)
            {
                if(m_parent[i] == i)
                    return i;
                return m_parent[i] = find(m_parent[i]);
            }
            void make_union(int i,int j)
            {
                int a = find(i);
                int b = find(j); 
                if(a!=b)
                    if(m_rank[a] < m_rank[b])
                        m_parent[a] = b;
                    else if(m_rank[b] < m_rank[a])
                        m_parent[b] = a;
                    else
                    {
                        m_parent[a] = b;
                        ++m_rank[b];
                    }
            }
            ~UnionFind()
            {
                delete[] m_rank;
                delete[] m_parent;
            }
        private:
            int* m_parent;
            int* m_rank;
    };

    int main(){
        
        return 0;
    }