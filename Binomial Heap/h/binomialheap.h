#ifndef BINOMIALHEAP_H
#define BINOMIALHEAP_H

#include<iostream>
#include<list>
#include<iterator>
#include<compare>
#include<set>
#include<initializer_list>
#include<vector>
#include <bits/stdc++.h>

class BinomialHeap{
    public:
        class Node{
            public:
                double value;
                Node* parent;
                std::list<Node*> children;
                Node();
                Node(double);
                Node(double ,std::list<Node*> children);
                Node(double value, Node& parent, std::list<Node*> children);
                Node(const Node& n);
                size_t get_order() ;
                size_t get_order2() const { return order; };
                void set_order(size_t count);
                static Node* merge( Node*, Node* );
                static bool is_min_heap(Node);
                static bool is_max_heap(Node);
                BinomialHeap::Node* operator=(const BinomialHeap::Node*);
                bool operator<(const BinomialHeap::Node& n) const { return value < n.value; };
                bool operator<=(const BinomialHeap::Node& n) const { return value <= n.value; };
                bool operator>(const BinomialHeap::Node& n) const { return value > n.value; };
                bool operator>=(const BinomialHeap::Node& n) const { return value >= n.value; };
                bool operator==(const BinomialHeap::Node& n) const { return value == n.value; };
            private:
                size_t order=0;
        };  

        struct custom_compare
        {
            bool operator() ( const Node* a ,const Node* b ) const
            {
                return ( a->get_order2() < b->get_order2());
            }
        };
        std::set<Node* ,custom_compare>::iterator head { roots.begin() };
        BinomialHeap();
        BinomialHeap(const BinomialHeap&);
        BinomialHeap(std::initializer_list<double> list);
        BinomialHeap( double , double (*f)( double ));
        ~BinomialHeap();
        BinomialHeap& operator=(const BinomialHeap&);
        BinomialHeap* insert(double);
        BinomialHeap* insert(Node*);
        double pop();    // return the minimum Node of binomial heap
        bool empty();
        void clear();    // remove all Nodes!
        void show();
        size_t get_roots_length() { return roots.size();};
        size_t get_length(){ return nodes.size(); };
        bool set_roots(std::set<Node*, custom_compare>);
        void merge(const BinomialHeap&);


    private:
        size_t N=0;    // number of Nodes in binomial heap
        std::set<Node* , custom_compare> roots;            
        std::vector<Node*> nodes;                              
        Node* temp { nullptr };                                
};

std::ostream& operator<<(std::ostream& os, const BinomialHeap::Node& n);

#endif