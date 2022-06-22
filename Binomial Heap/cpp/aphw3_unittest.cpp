#include <limits.h>
#include "binomialheap.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include "gtest/gtest.h"

double square(double num){
    return num*num;
}

namespace
{

TEST(APHW3Test, Test1){
    BinomialHeap::Node n1(1);
    EXPECT_EQ(true, n1.parent==nullptr && n1.value==1 && n1.children.front()==nullptr);
    BinomialHeap::Node n2;
    EXPECT_EQ(true, n2.parent==nullptr && n2.value==0 && n2.children.front()==nullptr);
}

TEST(APHW3Test, Test2){
    BinomialHeap::Node nchild1(1);
    BinomialHeap::Node nchild2(2);
    BinomialHeap::Node nchild3(3);
    BinomialHeap::Node nparent(10);
    std::list<BinomialHeap::Node*> children = {&nchild1, &nchild2, &nchild3};
    BinomialHeap::Node n(5, nparent, children);
    EXPECT_EQ(true, nparent.children.front()->value==5 && nparent.children.size()==1);
    EXPECT_EQ(10, n.parent->value);
    EXPECT_EQ(1, n.children.front()->value);
    EXPECT_EQ(3, n.children.back()->value);
    for (auto const& child : n.children){
       EXPECT_EQ(5, child->parent->value);
    }
    BinomialHeap::Node nancestor(100);
    std::list<BinomialHeap::Node*> children2;
    children2.push_front(&nparent);
    children2.push_front(&nchild1);
    BinomialHeap::Node ngrandparent(20, nancestor, children2);
    EXPECT_EQ(4, nancestor.get_order());
    EXPECT_EQ(true, BinomialHeap::Node::is_max_heap(nancestor));
    std::cout<<n<<std::endl;    //(value:5, parent:10, order:1)
}

TEST(APHW3Test, Test3){
    BinomialHeap::Node n1(1);
    BinomialHeap::Node n2(2);
    BinomialHeap::Node n3(3);
    BinomialHeap::Node n4(4);
    BinomialHeap::Node* nparent1 = BinomialHeap::Node::merge(&n1, &n2);
    BinomialHeap::Node* nparent2 = BinomialHeap::Node::merge(&n3, &n4);
    EXPECT_EQ(1, n1.get_order());
    EXPECT_EQ(0, n2.get_order());
    EXPECT_EQ(1, nparent2->get_order());
    EXPECT_THROW(BinomialHeap::Node::merge(&n2, nparent1), std::logic_error);
    BinomialHeap::Node::merge(&n3, &n1);
    EXPECT_EQ(2, n1.get_order());
    EXPECT_EQ(1, n3.parent->value);
    EXPECT_EQ(true, BinomialHeap::Node::is_min_heap(n1));
}

TEST(APHW3Test, Test4){
    BinomialHeap::Node n1;
    BinomialHeap::Node n2;
    BinomialHeap::Node n3;
    for (size_t i = 1; i < 4; i++){
        n1.value = i;
        for (size_t j = 1; j < 4; j++){
            n2.value = j;
            EXPECT_EQ(true, (n2>n1)!=(n2<=n1) && (n2>n1)==(j>i));
            EXPECT_EQ(true, (n2>=n1)!=(n2<n1) && (n2>=n1)==(j>=i));
            EXPECT_EQ(true, (n2==n1)!=(n2!=n1) && (n2==n1)==(j==i));
            EXPECT_EQ(true, (n2>n1)==(n1<n2) && n1>n3);
        }
    }
}


// for BinomialHeap
TEST(APHW3Test, Test5){
    BinomialHeap bh1{10,20,30,40,50,60,70};
    EXPECT_EQ(7, bh1.get_length());
    EXPECT_EQ(70, (*(bh1.head))->value);
    BinomialHeap bh2(10, square);
    EXPECT_EQ(81, (*(bh2.head))->value);
    EXPECT_EQ(10, bh2.get_length());
    bh2.show();
}

TEST(APHW3Test, Test6){
    BinomialHeap bh{10,20,30,40,50,60};
    EXPECT_EQ(50, (*(bh.head))->value);
    BinomialHeap::Node* n1{new BinomialHeap::Node(70)};
    bh.insert(n1);
    EXPECT_EQ(70, (*(bh.head++))->value);
    EXPECT_EQ(50, (*(bh.head))->value);
}

 TEST(APHW3Test, Test7){
    BinomialHeap bh{1,2,3,4,5,6,7,8,9,10,11,12,13,14};
    BinomialHeap bh2(bh);
    EXPECT_EQ(14, bh2.get_length());
    bh2.head++;
    bh.head++;
    EXPECT_EQ(3, bh2.get_roots_length());
    EXPECT_EQ(false, *(bh.head)==*(bh2.head));
    EXPECT_EQ(true, (*(bh.head))->value==(*(bh2.head))->value);
    bh2.head++;
    EXPECT_EQ(3, (*(bh2.head))->get_order());
    BinomialHeap::Node* eldest_child;
    for (auto const& child : (*(bh2.head))->children){
        if(child->get_order()==2)
            eldest_child = child;
    }
    EXPECT_EQ(2, eldest_child->children.size());
    EXPECT_EQ(3, (*(bh2.head))->get_order());
    bh.show();
    bh2.show();
 }

 TEST(APHW3Test, Test8){
    BinomialHeap* bh{new BinomialHeap()};
    EXPECT_EQ(true, bh->empty());
    bh->insert(5)->insert(3)->insert(6)->insert(1);
    EXPECT_EQ(1, bh->get_roots_length());
    EXPECT_EQ(4, bh->get_length());
    EXPECT_EQ(2, (*(bh->head))->get_order());
    EXPECT_EQ(2, (*(bh->head))->children.size());
    bh->insert(4);
    EXPECT_EQ(0, (*(bh->head))->get_order());
}

TEST(APHW3Test, Test9){
    BinomialHeap* bh1{new BinomialHeap()};
    bh1->insert(10)->insert(12)->insert(18)->insert(15)->insert(11);
    BinomialHeap bh2{5,3,8,1,2,6,7};
    bh1->merge(bh2);
     EXPECT_EQ(2, bh1->get_roots_length());
     EXPECT_EQ(3, bh2.get_roots_length());
     EXPECT_EQ(12, bh1->get_length());
    EXPECT_EQ(7, bh2.get_length());
     EXPECT_EQ(2, (*(bh1->head))->get_order());
     bh1->insert(20);
    bh2.insert(30);
     EXPECT_EQ(3, bh1->get_roots_length());
     EXPECT_EQ(1, bh2.get_roots_length());
     EXPECT_EQ(13, bh1->get_length());
     EXPECT_EQ(8, bh2.get_length());
     EXPECT_EQ(0, (*(bh1->head))->get_order());
}

TEST(APHW3Test, Test10){
     BinomialHeap* bh1{new BinomialHeap()};
     bh1->insert((double)0)->insert(3)->insert(9)->insert(6)->insert(2);
    // bh1->merge(*bh1);
    // EXPECT_EQ(2, bh1->get_roots_length());
    // EXPECT_EQ(10, bh1->get_length());
    // EXPECT_EQ(3, (*(++(bh1->head)))->get_order());
    // bh1->insert(10);
    // EXPECT_EQ(3, bh1->get_roots_length());
    // EXPECT_EQ(11, bh1->get_length());
    // EXPECT_EQ(0, (*(bh1->head))->get_order());
}
/*
TEST(APHW3Test, Test11)
{
    BinomialHeap bh{1,7,3,4,5,8,9,10,2,6,14,12,11,13,15};
    double minimum = bh.pop();
    for (size_t i = 0; i < 13; i++){
        double second_minimum = bh.pop();
        EXPECT_EQ(true, second_minimum>=minimum);
        minimum = second_minimum;
    }
    bh.pop();
    EXPECT_THROW(bh.pop(), std::logic_error);
}

TEST(APHW3Test, Test12)
{
    BinomialHeap bh{1,7,5,4,3,9,8,10,2,12,14,6,11,15,13};
    BinomialHeap bh1, bh2{1,2,3};
    bh1 = bh2 = bh;
    EXPECT_EQ(true, (*bh1.head)->value==(*bh2.head)->value && (*bh1.head)->value==13);
    EXPECT_EQ(true, bh1.get_length()==bh2.get_length() && bh2.get_length()==15);
    EXPECT_EQ(true, bh1.get_roots_length()==bh2.get_roots_length() && bh2.get_roots_length()==4);
    EXPECT_EQ(true, (*bh1.head)->value==(*bh2.head)->value && (*bh1.head)->value==13);
    bh.show();
    bh[3] = 12;
    bh.show();
    bh1[3] = 6;
    bh1.show();
    bh2[0] = 4;
    bh2.show();
}
*/
}
