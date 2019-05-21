#include <iostream>


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
    
    bool DoesPathExist(int n,const bool t[][5])
    {
        UnionFind obj(n*n); // tworzymy obiekt z ilością pól równą N*N.
        for(int i = 0; i < n; ++i) // pętla dla kolumn
            for(int j = 0; j < n; ++j) // pętla dla wierszy.
            {
                if(t[i][j]) // jesli pole istnieje
                {
                    if(i+1 < n && t[i+1][j]) //down //  ify sprawdzają czy w obrębie 1 są inne jedynki jesli tak scala je w wyspę.
                        obj.make_union(i*n+j,(i+1)*n+j);
                    if(i-1 >= 0 && t[i-1][j]) //up
                        obj.make_union(i*n+j,(i-1)*n+j);
                    if(j+1 < n && t[i][j+1]) //right
                        obj.make_union(i*n+j,i*n+j+1);
                 }
            }

        for(int i = 0; i < n; ++i)
            if(t[i][0]) // jeśli istnieje taki el
                for(int j = 0; j < n; ++j) // pętla po wierszach
                    if(t[j][n-1]) // jesli istenie taki element
                        if(obj.find(i*(n-1)) == obj.find(j*(n-1)+(n-1))) // sprawdza czy ścieżka istnieje jesli tak zwraca 1 (jeśli poczatkowy punkt ma tego samego reprezentanta co końcowy to zwróc 1 )
                            return 1;
        return 0;
    }

int main()
{
     const int n = 5;
        const bool t1[n][n] ={{1,1,1,1,1},
                              {0,1,0,0,1},
                              {0,0,1,0,1},
                              {0,0,0,0,1},
                              {1,0,1,0,1}};

        const bool t2[n][n] = {{1,1,0,0,0},
                               {1,0,0,0,1},
                               {1,1,0,0,0},
                               {0,1,0,1,0},
                               {1,1,1,1,1}};

        const bool t3[n][n] = {{0,1,1,0,0},
                               {0,0,1,0,1},
                               {0,1,1,0,0},
                               {0,0,1,1,0},
                               {1,1,0,1,1}};
    std::cout << DoesPathExist(n,t1) << std::endl;
    std::cout << DoesPathExist(n,t2) << std::endl;
    std::cout << DoesPathExist(n,t3) << std::endl;
}