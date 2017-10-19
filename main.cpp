#include <iostream>
#include<stack>
#include<deque>
#include<string>
#include<array>
#include<vector>
#include<map>

using namespace std;
class Tree{
     public:
    int data;
    Tree* left;
    Tree* right;
    Tree(int data)
    {
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};
void insertIntoTree(Tree** root,int data)
    {
        Tree *newNode=new Tree(data);
        if(!*root)
        {
            *root=newNode;
            return;
        }
        Tree* temp;
        deque<Tree*> deque;
        deque.push_back(*root);
        while(1)
        {
            temp=deque.front();
            deque.pop_front();
            if(!temp->left)
            {
                     temp->left=newNode;
                     return;
            }
            else{
                    deque.push_back(temp->left);
           }

            if(!temp->right)
            {
                     temp->right=newNode;
                     break;
            }
            else{
                    deque.push_back(temp->right);
           }


        }

    }
void inOrderTraversal(Tree* root)
{
    if(root)
    {
        inOrderTraversal(root->left);
        cout<<char(root->data)<<" ";
        inOrderTraversal(root->right);
    }
}
/*******************************
in-order traversal
void inOrderTraversal(Tree* root)
{
    stack<Tree*> stack_;
    Tree* temp;
    while(1)
    {
        while(root)
        {
            stack_.push(root);
            root=root->left;
        }
        if(stack_.empty())
            break;
        temp=stack_.top();
        stack_.pop();
        cout<<temp->data<<" ";
        root=temp->right;
    }
}*////////////////////////////////////////////////
/*******************************************
pre-order traverasl
void preOrderTraversal(Tree* root)
{
    stack<Tree*> stack_;
    Tree* temp;
    while(1)
    {
        while(root)
        {   cout<<root->data<<" ";
            stack_.push(root);
            root=root->left;
        }
        if(stack_.empty())
            break;
        temp=stack_.top();
        stack_.pop();
        root=temp->right;
    }


}*///////////////////////////////////////////
/********************************************
post-order traversal
void postOrderTraversal(Tree* root)
{
    stack<Tree*> stack1,stack2;
    stack1.push(root);
    Tree* temp;
    while(!stack1.empty())
    {
        temp=stack1.top();
        stack1.pop();
        stack2.push(temp);
        if(temp->left)
            stack1.push(temp->left);
        if(temp->right)
            stack1.push(temp->right);
    }
    while(!stack2.empty())
    {
        cout<<stack2.top()->data<<" ";
        stack2.pop();
            }



}*//////////////////////////////////////////////
/*************************************
find max element using recursion
question1
int findMaxElement(Tree* root)
{
    int value=INT_MIN;
    if(root)
    {
        int left=findMaxElement(root->left);
        int right=findMaxElement(root->right);
        int curr=root->data;
        if(left>right&&left>curr)
            value=left;
        else
             if(left<right&&right>curr)
            value=right;
        else
             if(curr>right&&left<curr)
            value=curr;
    }
    return value;
}*//////////////////////////////////////
/****************************************
question3
bool findElement(Tree* root,int data)
{
    if(!root)
    {
       return false;
    }
    else
    {
        if(root->data==data)
           return true;
        else return(findElement(root->left,data)||findElement(root->right,data));
    }
}*/////////////////////////
/**********************************
question 6
int sizeOfBinaryTree(Tree* root)
{
    if(!root)
        return 0;
    else
       return 1+sizeOfBinaryTree(root->left)+sizeOfBinaryTree(root->right);

}*/////////////////////////////////////////
/*************************
question 8
void levelOrderReverseTraversal(Tree* root)
{
    deque<Tree*> deque_;
    stack<Tree*> stack_;
    Tree* temp;
    deque_.push_back(root);
    //deque_.push_back(NULL);
    //int flag=0;
    while(!deque_.empty())
    {
        if(deque_.front()==NULL)
        {    deque_.push_back(NULL);
             flag=1;

        }

        temp=deque_.front();
        deque_.pop_front();
        stack_.push(temp);
        if(flag==0)
        {
            deque_.push_back(temp->right);
            deque_.push_back(temp->left);
        }
        else
        {
            deque_.push_back(temp->right);
            deque_.push_back(temp->left);

        }*/
       /*** temp=deque_.front();
        deque_.pop_front();
        stack_.push(temp);
        if(temp)
        {   if(temp->right)
            deque_.push_back(temp->right);
            if(temp->left)
            deque_.push_back(temp->left);
        }

    }
     while(!stack_.empty())
        {
            cout<<stack_.top()->data<< " ";
            stack_.pop();
        }


}*//////////////////////////////////////////////////////
/************************************
question 9
void deleteTree(Tree** root)
{
    if(*root)
    {   cout<<"c";
        deleteTree(&(*root)->left);
        deleteTree(&(*root)->right);
        delete(*root);
        *root=NULL;


    }
}*////////////////////////////////////////
/*******************************************
question 11
int heigtOfBinarytree(Tree* root)
{
    if(!root||!root->left&&!root->right)
        return 0;
    else
        return max(heigtOfBinarytree(root->left),heigtOfBinarytree(root->right))+1;
}*/////////////////////////////////////////
/****************************************************
question 11
int heightOfBinaryTree(Tree* root)
{

    int height=0;
    deque<Tree*> deque_;
    Tree* temp;
    deque_.push_back(root);
    deque_.push_back(NULL);
    while(1)
    {

        temp=deque_.front();
        deque_.pop_front();
        if(temp==NULL)
        {
            if(deque_.empty())
                break;
            height++;
            deque_.push_back(temp);
        }
        else
        {
            if(temp->left)
            deque_.push_back(temp->left);
            if(temp->right)
            deque_.push_back(temp->right);
        }
    }
   return height;

}************************************************/
/**************************************************
code for deleting a node in binary tree
Tree* findDeepestRightNode(Tree* root)
{
    deque<Tree*> deque_;
    Tree* temp;
    deque_.push_back(root);
    while(!deque_.empty())
    {
        temp=deque_.front();
        deque_.pop_front();
        if(temp->left)
            deque_.push_back(temp->left);
        if(temp->right)
            deque_.push_back(temp->right);
    }
    return temp;
}

void deleteNode(Tree** root,int data)
{
    Tree* deeprightnode=findDeepestRightNode(*root);
    deque<Tree*> deque_;
    Tree* temp;
    deque_.push_back(*root);
    while(!deque_.empty())
    {
        temp=deque_.front();
        deque_.pop_front();
        if(temp->left)
            deque_.push_back(temp->left);
        if(temp->right)
            deque_.push_back(temp->right);
    if(temp->left==deeprightnode)
    temp->left=NULL;
    if(temp->right==deeprightnode)
        temp->right=NULL;

        if(temp->data==data)
        {
            temp->data=deeprightnode->data;
        }
    }

    delete(deeprightnode);
    deeprightnode=NULL;

}*///////////////////////////////////////////////////////
/*********************************question 15
int numberOfLeaves(Tree* root)
{
    if(!root)
        return 0;
    else
        if(!root->right&&!root->left)
        return 1;
    else
        return numberOfLeaves(root->right)+numberOfLeaves(root->left);
}*////////////////////////////////////////////////
/***********************question 15
int numberOfFullNodes(Tree* root)
{
        if(root->right&&root->left)
        return 1+numberOfFullNodes(root->right)+numberOfFullNodes(root->left);
        else
            return 0;
}*//////////////////////////////////////////////
/*******************************************qusetion 17
bool isStructurallyIdentical(Tree* root,Tree* root1)
{
if(!root1&&!root)
        return true;
else
    if(!root1||!root)
    return false;
else
    return (root->data==root1->data)&&isStructurallyIdentical(root->right,root1->right)&&isStructurallyIdentical(root->left,root1->left);
}*////////////////////////////////////////////////////////////////////////////////////////////////////
/*****************************question 18 this gives 0(n^2) complexity
int heightOfTree(Tree* root)
{
    if(!root||!root->right&&!root->left)
        return 0;
    else
        return 1+max(heightOfTree(root->left),heightOfTree(root->right));
}
int diameterOfTree(Tree* root,)
{   if(!root)
return 0;
    int leftheight=heightOfTree(root->left)+1;
    int rightheight=heightOfTree(root->right)+1;
    int leftdiameter=diameterOfTree(root->left);
    int rightdiameter=diameterOfTree(root->right);
    return max(max(1+leftheight+rightheight,leftdiameter),rightdiameter);
}*////////////////////////////////////////////////////////////////////////
/***********************************************quetion 18 O(N) solution
int diameterOfTree(Tree* root,int *height)
{   if(!root)
{
    *height=0;
    return 0;
}
    int lh=0,rh=0;
    int leftdiameter=diameterOfTree(root->left,&lh);
    int rightdiameter=diameterOfTree(root->right,&rh);
    *height=max(lh,rh)+1;
    return max(max(lh+rh,leftdiameter),rightdiameter);
}*///////////////////////////////////////////////////////////////////////////////////
/************************************************************************************
int levelWithMaximumSum(Tree* root)
{
    int level=0,sum=INT_MIN,currsum=root->data,maxlevel;
    deque<Tree*> deque_;
    deque_.push_back(root);
    deque_.push_back(NULL);
    Tree* temp;
    while(!deque_.empty())
    {

     temp=deque_.front();
     deque_.pop_front();
     if(temp==NULL)
     {   if(deque_.empty())
            break;
         deque_.push_back(NULL);
         if(currsum>sum)
         {
             sum=currsum;
             maxlevel=level;

         }
         level++;
         currsum=0;
     }
     else
     {
         if(temp->left)
         {
             deque_.push_back(temp->left);
             currsum+=temp->left->data;

         }
         if(temp->right)
         {
             deque_.push_back(temp->right);
             currsum+=temp->right->data;

         }
     }
    }
    return maxlevel;
}*/
/*******************************************
question to be done later void printArray(vector<int> a)
{
    for(auto it:a)
        cout<<it<<" ";
    cout<<"\n";
}
void rootsToLeaves(Tree* root,vector<int> a,int l)
{
    if(!root)
        return;
    if(!root->left&&!root->right)
      {      a[l]=root->data;
            printArray(a);
      }
    else
    {
        a[l]=root->data;
        l++;
        rootsToLeaves(root->left,a,l);
        rootsToLeaves(root->right,a,l);
    }
}
*////////////////////////////////////////////////
/*************************
qestion 21
bool isSumExistForAnyPath(Tree* root,int sum)
{
    if(!root)
    {
        return sum==0;
    }
    else
    {
       return isSumExistForAnyPath(root->left,sum-root->data)||isSumExistForAnyPath(root->right,sum-root->data);
    }
}*/////////////////////////////////////////
/***************************question 23
int sumOfAllTheElementsInTree(Tree* root)
{
    if(!root)
        return 0;
    else
        return root->data+sumOfAllTheElementsInTree(root->left)+sumOfAllTheElementsInTree(root->right);
}*///////////////////////////////////////////
/***********************************
question 24
void converTreeToItsMirror(Tree** root)
{
    if(!*root)
        return;
    else
    {
        Tree* temp=(*root)->left;
        (*root)->left=(*root)->right;
        (*root)->right=temp;
        converTreeToItsMirror(&(*root)->left);
        converTreeToItsMirror(&(*root)->right);

    }
}*/////////////////////////////////////////////////////////////
/*****************************************************
Tree* converTreeToItsMirror(Tree* root)
{
    if(!root)
        return NULL;
    else
    {
        Tree* temp=(root)->left;
        (root)->left=(root)->right;
        (root)->right=temp;
        converTreeToItsMirror((root)->left);
        converTreeToItsMirror((root)->right);
        return root;
    }
}*///////////////////////////////////////////////////
/*****************************bool areMirror(Node* a,Node* b)
question 25
{
    if(!a&&!b)
    return true;
    else
    return a->data==b->data&&areMirror(a->left,b->right)&&areMirror(a->right,b->left);
}*///////////////////////////////////////////
/*******************************
question 26
Tree* lowestCoomonAncestor(Tree* root,int a,int b)
{
    if(!root)
        return NULL;
    else
        {
            if(root->data==a||root->data==b)
              return root;
            else
            {
                Tree* left=lowestCoomonAncestor(root->left,a,b);
                 Tree* right=lowestCoomonAncestor(root->right,a,b);
                if(left&&right)
                    return root;
                else
                    return left?left:right;
            }


    }
}*/////////////////////////////////////////////////////////////////////////////////
/***************************
try again later
Tree* constructTreeFromInorderAndPreorder(string inorder,string preorder,int* len)
{
    if(inorder.size()==0)
    {
        cout<<"amit";
          return NULL;


    }

    else
    { *len++;
        Tree* t=new Tree(preorder[*len]);
        cout<<preorder[*len]<<" ";

        t->left=constructTreeFromInorderAndPreorder(inorder.substr(0,inorder.find(preorder[*len])),preorder,&*len);
        t->right=constructTreeFromInorderAndPreorder(inorder.substr(inorder.find(preorder[*len+1],inorder.size())),preorder,&*len);
        return t;
    }
}*//////////////////////////////////////////////////
/***********************************
question 29
void printVector(vector<int> vec)
{
    for(auto it:vec)
    {
        cout<<it<<" ";
    }
}
void printAllAncestors(Tree* root,vector<int> &vec,int data)
{
    if(!root)
        return;
    else
        if(root->data==data)
        { printVector(vec);
       // cout<<"end\n";

        }
     else
        if(!root->left&&!root->right)
     {
         vec.push_back(root->data);
         //printVector(vec);
     }
    else
    {   vec.push_back(root->data);
   // printVector(vec);
        printAllAncestors(root->left,vec,data);
        vec.pop_back();
         printAllAncestors(root->right,vec,data);
         vec.pop_back();
    }
}*////////////////////////////////////////////////////////
/************************************
question 30
void zigzagTraverslOfTree(Tree* root)
{

           stack<Tree*> a,b;
           Tree* temp;
           int flag=1;
           a.push(root);
           while(1)
           {
               if(a.empty()&&b.empty())
                break;
               if(flag==1)
               {while(!a.empty())
              {
                   temp=a.top();
               a.pop();
               cout<<temp->data<<" ";
                if(temp->left)
               b.push(temp->left);
               if(temp->right)
               b.push(temp->right);

              }
               flag=0;

               }
               else
               {
                   while(!b.empty())
              {
                   temp=b.top();
               b.pop();
               cout<<temp->data<<" ";

                 if(temp->right)
               a.push(temp->right);
               if(temp->left)
               a.push(temp->left);

              }
               flag=1;
               }

           }

}*//////////////////////////////////////////////////////////////////////
/*****************************************************
question 31
void findingverticalSumOfBinaryTree(Tree* root,map<int,int> &map_,int column)
{
    if(!root)
        return;
    else
    {
        map_[column]+=root->data;
        findingverticalSumOfBinaryTree(root->left,map_,column-1);
        findingverticalSumOfBinaryTree(root->right,map_,column+1);
    }
}*///////////////////////////////////////////////////////////////
/***********************
question 33
Tree* constructTree(string s,int &l)
{
    if(l==s.size())
    {
        return NULL;
    }
    if(s[l]=='L')
    {   l++;
    Tree* t=new Tree('L');
        return t;
    }
    else
    {
        Tree* t=new Tree('I');
        cout<<s[l]<<" "<<l;
        t->left=constructTree(s,++l);
        t->right=constructTree(s,l);
        return t;
    }
}*////////////////////////////////////////////////////////////////////////////
int main()
{   Tree* root=NULL;
    insertIntoTree(&root,1);
   insertIntoTree(&root,2);
      insertIntoTree(&root,3);
       insertIntoTree(&root,4);
        insertIntoTree(&root,5);
         insertIntoTree(&root,6);
          insertIntoTree(&root,7);
         insertIntoTree(&root,50);
           insertIntoTree(&root,60);
          /* insertIntoTree(&root,99);
          insertIntoTree(&root,100);
          insertIntoTree(&root,101);
           insertIntoTree(&root,102);
            insertIntoTree(&root,110);
          insertIntoTree(&root,111);
           insertIntoTree(&root,112);*/

      /**q1  cout<<findMaxElement(root);*////////////

   /****** q2  if(findElement(root,6))
        cout<<"\yes";
      else
        cout<<"no";*///////////////////
   /*********q3     cout<<sizeOfBinaryTree(root);
*/
/*****q8
levelOrderReverseTraversal(root);*/////////////////////
/**********************q9
deleteTree(&root);
cout<<"\n";



 insertIntoTree(&root,1);
   insertIntoTree(&root,2);
      insertIntoTree(&root,3);
       insertIntoTree(&root,4);
inOrderTraversal(root);*/
  /****  inOrderTraversal(root);
    cout<<"\n";
    preOrderTraversal(root);
    cout<<"\n";
    postOrderTraversal(root);
    return 0;******/
/******************q11    cout<<heigtOfBinarytree(root);*////////////////////////////////
/*********************q11 cout<<heightOfBinaryTree(root);*///////////////////////////////
/********************** code for deleting node in binary tree inOrderTraversal(root);

deleteNode(&root,3);

cout<<"\n";
inOrderTraversal(root);*////////////////////////////////////////////
/******q 14cout<<numberOfLeaves(root);*/////////////////
/************q15cout<<numberOfFullNodes(root);*//////////////////////////
/***********************question 17 Tree* root1=NULL;
    insertIntoTree(&root1,1);
   insertIntoTree(&root1,2);
      insertIntoTree(&root1,3);
       insertIntoTree(&root1,13);
        insertIntoTree(&root1,59);
         insertIntoTree(&root1,6);
          insertIntoTree(&root1,7);
          insertIntoTree(&root1,50);
           insertIntoTree(&root1,60);
           insertIntoTree(&root1,70);
if(isStructurallyIdentical(root,root1))
    cout<<"\nYes";
else
    cout<<"\nNo";*///////////////////////////////////////////////////
/*******    int height=0;
cout<<diameterOfTree(root,&height);*///////////////////////////////////
/******q19 cout<<levelWithMaximumSum(root);*///////////////////////////
/***********int l;
vector<int> a;
rootsToLeaves(root,a,l);*//////////////////////
/********************q21
int sum=0;
cin>>sum;
if(isSumExistForAnyPath(root,sum))
    cout<<"Yes sum Exist";
else
    cout<<"No sum does not exist";*////////////////////////
/******************q23cout<<"Sum of alll the elemnts in binary tree is:"<<sumOfAllTheElementsInTree(root);*////////////////////
/**************** q24inOrderTraversal(root);
converTreeToItsMirror(&root);
cout<<"\n";
inOrderTraversal(root);*/////////////////////////////////////
/*****
Tree* root1=converTreeToItsMirror(root);
inOrderTraversal(root);
cout<<"\n";
if(root==root1)
    cout<<"yes";
else
    cout<<"no";*/
//inOrderTraversal(root1);
/******************************q26
int a,b;
cin>>a>>b;
cout<<lowestCoomonAncestor(root,a,b)->data;
*//////////////////////////////////////////////////
/*****string a,b;
cin>>a>>b;
int len=-1;
Tree* t=constructTreeFromInorderAndPreorder(a,b,&len);
inOrderTraversal(t);*/////
/************************
question 29
int data;
vector<int> vec;
cin>>data;
int len=0;
printAllAncestors(root,vec,data);
*///////////////////////////////////////////////////
/**************q 30zigzagTraverslOfTree(root);*//////////////////////////////////
/************************************
q31
map<int,int> map_;
int column=0;
findingverticalSumOfBinaryTree(root,map_,column);
map<int,int>::iterator it=map_.begin();
for(;it!=map_.end();it++)
{
    cout<<"column "<<it->first<<"equals:"<<it->second<<"\n";
}*///////////////////////////////////////////////////////
/*****************************
q33
string a;
 cin>>a;
 int l=0;

Tree* t= constructTree(a,l);
cout<<"\n";
inOrderTraversal(t);*//////////////////////////////////////////////////////////
}
