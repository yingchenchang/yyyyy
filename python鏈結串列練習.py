# -*- coding: utf-8 -*-
"""
Created on Wed Jun 22 21:23:26 2022

@author: User
"""

class Node(): #用鏈結串列實作堆疊，定義Node()類別
    def __init__(self,data=None): #初始化Node
        self.data=data #定義資料
        self.next=None #定義指標
        
class Stack(): #定義Stack()函數
    def __init__(self): #初始化
        self.head=None #定義第一個節點
        
    def print_list(self): #定義印出的函數
        ptr=self.head #指標指向第一個節點
        while ptr: #在串列中
            print(ptr.data) #印出串列資料
            ptr=ptr.next #指標移動到下一個
            
    def push(self,data): #定義堆疊函數
       new_add_node=Node() #新節點
       new_add_node.data=data #新節點資料
       new_add_node.next=self.head #將原本的第一個節點變為第二個節點
       self.head=new_add_node #定義新的第一個節點
       
    def length(self): #數鏈結長度方法
        ptr=self.head #指標指向第一個節點
        a=0 #長度為0
        while ptr: #指標
           a+=1 #指標指到節點+1
           ptr=ptr.next #移動指向下一節點
        print('目前鏈結串列長度:',a) #印出鏈結長度
        
    def pop(self): #定義移除方法
        ptr=self.head #指標指向第一個節點
        self.head=self.head.next #將原本的第一個節點變為第二個節點
        temp=ptr.data #原本的第一個節點
        print('移出',temp)
        return temp #刪除他
    
link=Stack() #鏈結串列
link.head=Node(10) #節點1
n2=Node(2) #節點2
n3=Node(22) #節點3
n4=Node(11) #節點4
n5=Node(2) #節點5
n6=Node(21) #節點6
link.head.next =n2 #節點1指向節點2
n2.next = n3 #節點2指向節點3
n3.next = n4 #節點3指向節點4
n4.next = n5 #節點4指向節點5
n5.next = n6 #節點5指向節點6
link.print_list() #印出目前堆疊資料  
link.push(6) #加入新堆疊資料
print('堆疊新資料後串列:') #印出
link.print_list() #印出目前堆疊資料
link.length() #計算堆疊長度
link.pop() #移除堆疊資料
print('移出一資料後:') #印出
link.print_list() #印出目前堆疊資料
       