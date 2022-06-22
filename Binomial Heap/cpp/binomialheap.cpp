#include "binomialheap.h"


BinomialHeap::Node::Node( double _value)
    :value { _value }
    ,parent { nullptr }
{
    std::list<Node*> _children ;
}

BinomialHeap::Node::Node()
    :Node( 0 )
{
}

BinomialHeap::Node::Node( double _value, std::list<Node*> _children )
    :value { _value }
    ,parent { nullptr }
    ,children { _children }
{
    for ( auto& it : _children)
        it ->parent = this;

}

BinomialHeap::Node::Node( double _value, Node& _parent, std::list<Node*> _children )
    : value { _value }
    , parent { &_parent }
    , children { _children }
{
    int flag {};
    for ( auto& it : _parent.children)
    {
        if ( it == this )
            flag =1;
    }
    if(flag == 0)
        _parent.children.push_back( this );
    for ( auto& it : _children)
        it ->parent = this;
    // if (!_children.size())
    //     order++;
    
} 

BinomialHeap::Node::Node( const Node& n)
    : value { n.value }
    , parent { n.parent }
{
    std::list<Node*> children ( n.children );
}

size_t BinomialHeap::Node::get_order()
{
    size_t temp1{};
    size_t temp2{};
    size_t max {};
    size_t size { this->children.size()};
    if ( size!=0)
        temp1++;
    
    for( auto it : this ->children )
    {
        temp2 = it->get_order();
        temp2+=temp1;
        if(max < temp2)
            max = temp2;
    }
    this->order =max;
    return max;
}

BinomialHeap::Node* BinomialHeap::Node::merge(BinomialHeap::Node* n1, BinomialHeap::Node* n2)
{

    
    if( n1->get_order() == n2->get_order())
    {
        if ( n1->value > n2->value)
        {
            n1->parent = n2;
            n2->children.push_back(n1);
            return n2;
        }
        else
        {
            n2->parent = n1;
            n1->children.push_back(n2);
            return n1;
        }
    }
    else   
    {
        throw std::logic_error("error");
    }
 
}

bool BinomialHeap::Node::is_min_heap( Node n )
{
    if( ! n.children.size())
        return 1;
    for( auto it : n.children)
    {
        if(n.value < it->value && is_min_heap( *it ))
            return 1;
        else
            return 0;
    }
    return 1;
}

bool BinomialHeap::Node::is_max_heap( Node n )
{
    if( ! n.children.size())
        return 1;
    for( auto it : n.children)
    {
        if(n.value > it->value && is_max_heap( *it ))
            return 1;
        else
            return 0;
    }
    return 1;
}

BinomialHeap::Node* BinomialHeap::Node::operator= ( const BinomialHeap::Node* n )
{
    this->parent = n->parent;
    this->children = n->children;
    this->value = n->value;
    this->order = n->order;
    return this;
}

std::ostream& operator<<(std::ostream& os , const BinomialHeap::Node& n )
{
    os << "(value: " << n.value;
    os<< ", parent:" << n.parent->value;
    os << ", order:" << n.get_order2() << ")";
    return os;
}

//for binomialheap

BinomialHeap::BinomialHeap()
    :N { 0 }
{
    roots.clear();
}

BinomialHeap::~BinomialHeap()
{
    roots.clear();
    for ( auto ptr : roots )
    {
        delete [] ptr;
    }
    for (auto p : nodes)
    {
        delete p;
    } 
    nodes.clear();
}

BinomialHeap::BinomialHeap( const BinomialHeap& b )
    :N { b.N }
{   
    for ( size_t i{}; i<b.nodes.size(); i++)
    {
        this->insert ( b.nodes[i]->value );
    }
 /*
    std::cout<< "size of bh is :"<<b.nodes.size()<<std::endl;
    for ( size_t i{}; i<b.nodes.size(); i++)
    {
           std::cout<<b.nodes[i]->value<<std::endl;
        std::cout <<" im in!"<<std::endl;
        double * val = new double (b.nodes[i]->value);
        double parentval {};
        double childval {};
        std::list<BinomialHeap::Node*> copychildren ;
        for (auto j = b.nodes[i]->children.begin(); j != b.nodes[i]->children.end(); ++j)
        {
            std::cout <<" hoooo!"<<std::endl;
            childval = (*j)->value;
            Node * child = new Node ( childval );
            copychildren.push_back( child );
        }
        if( b.nodes[i]->parent == nullptr )
        {
            Node* p = new Node ( *val  , copychildren );
            this->insert(p);
        }
        if( b.nodes[i]->parent != nullptr)
        {
            parentval= b.nodes[i]->parent->value;
            Node* copyparent = new Node (parentval);
        std::cout<<"silent!"<<std::endl;
            Node* p = new Node ( *val , *copyparent , copychildren );
            this->insert(p); 
        }
    }
    */
}

BinomialHeap::BinomialHeap( std::initializer_list<double> list)
{
    for ( auto i : list)
        this->insert ( i );
}

BinomialHeap::BinomialHeap( double no , double (*f)( double ))
{
    for ( size_t i{ 1 }; i<= no; i++)
        this->insert ( f (i));
}

BinomialHeap& BinomialHeap::operator=(const BinomialHeap& b)
{
    N = b.N;

    return *this;
}

BinomialHeap* BinomialHeap::insert( double _value )
{
    N++;
    temp = new Node( _value );
    nodes.push_back( temp );
    do
    {
        for( size_t i{}; i< nodes.size(); i++)
            if( nodes[i]->parent== nullptr && temp->get_order()== nodes[i]->get_order() &&  nodes[i]!=temp)
            {    
                Node::merge( nodes[i], temp );
                break;
            }
        
        roots.clear();
        for( auto it : nodes)
                if( it->parent == nullptr )
                    roots.insert( it );
        head =roots.begin();
        temp = *(roots.begin());
    } while( !set_roots( roots )); 
    return this;
}

BinomialHeap* BinomialHeap::insert( Node* n )
{
    std::cout<<" this is insert of node* ande size of nodes is:"<<nodes.size() <<std::endl;
    N++;
    nodes.push_back( n );
    Node* temp { nodes [nodes.size()-1]};
    do
    {
        for( size_t i{}; i< nodes.size(); i++)
            if( nodes[i]->parent== nullptr && temp->get_order()== nodes[i]->get_order() &&  nodes[i]!=temp)
            {    
                std::cout<< nodes[i]->value <<temp->value << temp->children.size() <<"merging"<<std::endl ;
                Node::merge( nodes[i], temp );
                break;
            }
        
        roots.clear();
        for( auto it : nodes)
                if( it->parent == nullptr )
                    roots.insert( it );
        head =roots.begin();
        temp = *(roots.begin());
        //std::cout<<" hello mary"<< roots.size() <<std::endl;
        show();
    } while( ! set_roots( roots )); 
    return this;
}

bool BinomialHeap::empty()
{
    if (roots.size() == 0)
        return 1;
    else 
        return 1;
}

void BinomialHeap::clear()
{
    nodes.clear();
    roots.clear();
}

void BinomialHeap::show()
{
     for ( auto i : nodes )
    {
        std::cout<<std::endl << " node: " << i->value;
        if( i->parent == nullptr)
            std::cout <<"  has parent: null";
        else
            std::cout <<"  has parent: "<< i->parent->value;
        
        for (auto &child: (*i).children ) 
            std::cout <<" and child: "<< child->value ; 
    }
}

bool BinomialHeap::set_roots( std::set<Node*,custom_compare> _roots )
{
    std::set<Node*,custom_compare>::iterator it1;
    std::set<Node*,custom_compare>::iterator it2;
std::cout<<"size of roots:"<<_roots.size()<<std::endl;
    for ( it1 = _roots.begin(); it1 != _roots.end(); it1++ )
        for ( it2 = _roots.begin(); it2 != _roots.end(); it2++ )
        {
                if( (*it1)!=(*it2) && (*it1)->get_order() == (*it2)->get_order() )
                return 0;
            
        }
                
    return 1;
}

void BinomialHeap::merge(const BinomialHeap& b ) 
{
    for ( size_t i{}; i< b.nodes.size(); i++)
    {
        this->insert ( b.nodes[i]->value );
    }
}

double BinomialHeap::pop()
{
    std::set<Node*> ordered_roots;
    for( auto i : roots)
        ordered_roots.insert( i );
    std::set<Node*>::iterator it1;
    it1 = ordered_roots.begin();
    return (*it1)->value ;
}