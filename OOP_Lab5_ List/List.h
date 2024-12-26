#pragma once

#include <iostream>
#include <cmath>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <stdio.h>
#include <iomanip>

using std::cout;
using std::cin;
using std::ostream;
using std::istream;


template <typename Type>
void Swap(Type& A, Type& B)
{
	Type Buff = A;
    A = B;
    B = Buff;
}

template <typename ItemType>
class Node
{
public:
	ItemType key;
	Node<ItemType>* next;
};

template <typename ItemType>
class List
{
public:

	typedef Node<ItemType>* iterator; 

	iterator begin();
	iterator end();
	const iterator begin() const;
    const iterator end() const;

	List();
	List(ItemType* Array, int ArrSize);
	List(List<ItemType>& Other);
	~List(); 
	int Get_Size() const;
	void Swap(List<ItemType>& Other);
	Node<ItemType>* Find_Key(ItemType value) const;
	iterator Find_Key_Iter(ItemType value) const;
	void Add_to_Head(ItemType value);
	void Add_to_Tail(ItemType value);
	void Add_on_Pos(ItemType value, int position);
	void Add_After(ItemType value, ItemType element);
	void Add_to_Iter(ItemType value, iterator iter);
	void Del_Head();
	void Del_Tail();
	void Del_Pos(int position);
	void Del_Key(ItemType value);
	void Del_Iter(iterator iter);
	void Del_IterRange(iterator start, int quantity);
	ItemType Find_Max() const;
	ItemType Find_Min() const;
	bool isEmpty() const;
	void Clear();
	void Sort();

	List<ItemType>& operator=(const List<ItemType>& Other);
	ItemType& operator[](int index) const;
	bool operator==(const List<ItemType> Other) const;
	bool operator!=(const List<ItemType> Other) const;
	List<ItemType>& operator+=(const List<ItemType> Other);
	List<ItemType> operator+ (const List<ItemType> Other) const;

private:
	int m_Size;
	Node<ItemType>* head;
};

template <typename ItemType>
ostream& operator<<(ostream& os, const List<ItemType>& List){ //////////////////////
    os << '{';
    Node<ItemType>* Temp = List.begin();
	os << Temp->key << ',';
	while(Temp->next != nullptr){
		Temp = Temp->next;
		os << Temp->key;
		if (Temp->next != nullptr)
			os << ',';
	}

    os << '}';
    return os;
}

template <typename ItemType>
istream& operator>>(istream& is, List<ItemType>& List){ //////////////////////
    ItemType value;
	is >> value;
    List.Add_to_Tail(value);
    return is;
}

template <typename ItemType> 
typename List<ItemType>::iterator List<ItemType>::begin(){
	return head->next;
}

template <typename ItemType> 
typename List<ItemType>::iterator List<ItemType>::end(){
	return nullptr;
}

template <typename ItemType>
const typename List<ItemType>::iterator List<ItemType>::begin() const{
	return head->next;
}

template <typename ItemType>
const typename List<ItemType>::iterator List<ItemType>::end() const{
	return nullptr;
}

template <typename ItemType>
List<ItemType>::List(){
	m_Size = 0;
	head = new Node<ItemType>;
	head->next = nullptr;
}

template <typename ItemType>
List<ItemType>::List(ItemType* Array, int ArrSize){
	if(ArrSize <= 0){
		m_Size = 0;
		head = new Node<ItemType>;
		head->next = nullptr;
		return;
	}
	head = new Node<ItemType>;
	m_Size = ArrSize;
	Node<ItemType>* Temp = head;
	for(int i = 0; i < ArrSize; i++){
        Temp->next = new Node<ItemType>; 
        Temp = Temp->next;             
        Temp->key = Array[i]; 
	}
	Temp->next =nullptr;
}

template <typename ItemType>
List<ItemType>::List(List<ItemType>& Other){
	if(Other.m_Size == 0){
		m_Size = 0;
		head = new Node<ItemType>;
		head->next = nullptr;
		return;
	}
	head = new Node<ItemType>;
	m_Size = Other.m_Size;
	Node<ItemType>* Temp1 = head;
	Node<ItemType>* Temp2 = Other.head->next;
	for(int i = 1; i < m_Size; i++){
        Temp1->next = new Node<ItemType>;
        Temp1 = Temp1->next; 
        Temp1->key = Temp2->key;        
        Temp2 = Temp2->next;   
	}
	Temp1->next = nullptr;
}

template <typename ItemType>
List<ItemType>::~List(){
	Clear();
	delete head;
}

template <typename ItemType>
int List<ItemType>::Get_Size() const{
	return m_Size;
}

template <typename ItemType>
void List<ItemType>::Swap(List<ItemType>& Other){
	Swap(head, Other.head);
	Swap(m_Size, Other.m_Size);
}

template <typename ItemType>
Node<ItemType>* List<ItemType>::Find_Key(ItemType value) const{
	Node<ItemType>* Temp = head;
	while(Temp->key != value && Temp->next != nullptr){
		Temp = Temp->next;
	}
	if( Temp->key == value){
		return Temp;
	}
	return nullptr;
}

template <typename ItemType>
typename List<ItemType>::iterator List<ItemType>::Find_Key_Iter(ItemType value) const{
    for (auto it = begin(); it != end(); ++it) {
        if (it->key == value) {
            return it;
        }
    }
    return nullptr;
}

template <typename ItemType>
void List<ItemType>::Add_to_Head(ItemType value){
	Node<ItemType>* Temp = new Node<ItemType>;
	Temp->key = value;
	Temp->next = head->next;
	head->next = Temp;
	m_Size++;
}

template <typename ItemType>
void List<ItemType>::Add_to_Tail(ItemType value){
	Node<ItemType>* Temp = new Node<ItemType>;
	Temp->key = value;
	Temp->next = nullptr;
	Node<ItemType>* Step = head->next;
	while(Step->next != nullptr){
		Step = Step->next;
	}
	Step->next = Temp;
	m_Size++;
}

template <typename ItemType>
void List<ItemType>::Add_on_Pos(ItemType value, int position){
	if(position > m_Size){
		return;
	}
	if(position == m_Size){
		Add_to_Tail(value);
		return;
	}
	Node<ItemType>* Temp = new Node<ItemType>;
	Temp->key = value;
	Node<ItemType>* Step = head;
	for(int i = 1; i < position; i++){
		Step = Step->next;
	}
	Temp = Step->next->next;
	Step->next = Temp;
	m_Size++;
}

template <typename ItemType>
void List<ItemType>::Add_After(ItemType value, ItemType element){
	Node<ItemType>* Step = head;
	while(Step->key != element && Step->next != nullptr){
		Step = Step->next;
	}
	if(Step->key != element){
		return;
	}
	Node<ItemType>* Temp = new Node<ItemType>;
	Temp->key = value;
	Temp->next = Step->next;
	Step->next = Temp;
	m_Size++;
}

template <typename ItemType>
void List<ItemType>::Add_to_Iter(ItemType value, iterator iter){
	if(iter == nullptr){
		return;
	}
	Node<ItemType>*Temp = new Node<ItemType>;
	Temp->key = value;
	Temp->next = iter->next;
	iter->next = Temp;
}

template <typename ItemType>
void List<ItemType>::Del_Head(){
	if(isEmpty()){
		return;
	}
	Node<ItemType>* ToDelete = head->next;
	head->next = ToDelete->next;
	delete ToDelete;
	m_Size--;
}

template <typename ItemType>
void List<ItemType>::Del_Tail(){
	if(isEmpty()){
		return;
	}
	Node<ItemType>* Step = head;
	while(Step->next->next != nullptr){
		Step = Step->next;
	}
	Node<ItemType>* ToDelete = Step->next;
	Step->next = nullptr;
	delete ToDelete;
	m_Size--;
}

template <typename ItemType>
void List<ItemType>::Del_Pos(int position){
	if(isEmpty()){
		return;
	}
	if(m_Size < position){
		return;
	}
	Node<ItemType>* Step = head;
	for(int i = 1; i < position; i++){
		Step = Step->next;
	}
	Node<ItemType>* ToDelete = Step->next;
	Step->next = ToDelete->next;
	delete ToDelete;
	m_Size--;
}

template <typename ItemType>
void List<ItemType>::Del_Key(ItemType value){
	if(isEmpty()){
		return;
	}
	Node<ItemType>* Step = head;
	while(Step->next->key != value && Step->next != nullptr){
		Step = Step->next;
	}
	if(Step->next->key != value){
		return;
	}
	Node<ItemType>* ToDelete = Step->next;
    Step->next = ToDelete->next;
    delete ToDelete;
	m_Size--;
}

template <typename ItemType>
void List<ItemType>::Del_Iter(iterator iter){
 	if (iter == nullptr || iter->next == nullptr) 
 		return; 
    Node<ItemType>* ToDelete = iter->next;
    iter->next = ToDelete->next;
    delete ToDelete;

    m_Size--;
}

template <typename ItemType>
void List<ItemType>::Del_IterRange(iterator start, int quantity){
	    if (start == nullptr || quantity <= 0 || isEmpty()) {
        return; 
    }
    iterator prev = head; 
    while (prev->next != start && prev->next != nullptr) {
        prev = prev->next; 
    }
    if (prev->next != start) {
        return;
    }
    int count = 0; 
    iterator current = start; 
    while (current != nullptr && count < quantity) {
        iterator toDelete = current;
        current = current->next; 
        delete toDelete;         
        count++;
        m_Size--; 
	}
    prev->next = current;
}

template <typename ItemType>
ItemType List<ItemType>::Find_Max() const{
	if(isEmpty()){
		return;
	}
	ItemType Max = head->next->key;
	Node<ItemType>* Step = head->next;
	while(Step->next != nullptr){
		Step = Step->next;
		if(Max < Step->key){
			Max = Step->key;
		}
	}
	return Max;
}

template <typename ItemType>
ItemType List<ItemType>::Find_Min() const{
	if(isEmpty()){
		return;
	}
	ItemType Min = head->next->key;
	Node<ItemType>* Step = head->next;
	while(Step->next != nullptr){
		Step = Step->next;
		if(Min > Step->key){
			Min = Step->key;
		}
	}
	return Min;
}

template <typename ItemType>
bool List<ItemType>::isEmpty() const{
	return (head->next == nullptr);
}

template <typename ItemType>
void List<ItemType>::Clear(){
	if(isEmpty()){
		return;
	}
	while(!isEmpty()){
		Del_Tail();
	}
	m_Size = 0;
}

template <typename ItemType>
void List<ItemType>::Sort(){

}

template <typename ItemType>
List<ItemType>& List<ItemType>::operator=(const List<ItemType>& Other){
    Clear();
    Node<ItemType>* Temp = Other.head->next;
    while (Temp != nullptr) {
        Add_to_Tail(Temp->key);
        Temp = Temp->next;
    }
    return *this;
}

template <typename ItemType>
ItemType& List<ItemType>::operator[](int number) const{
	if(number > m_Size || number < 1){
		return nullptr;
	}
	Node<ItemType>* Temp = head;
	for(int i = 0; i < number; i++){
		Temp = Temp->next;
	}
	return Temp->key;
}

template <typename ItemType>
bool List<ItemType>::operator==(const List<ItemType> Other) const{
	if(m_Size != Other.m_Size){
		return false;
	}
	Node<ItemType>* Step1 = head->next;
	Node<ItemType>* Step2 = Other.head->next;
	while(Step1->next != nullptr){
		if(Step1->key != Step2->key){
			return false;
		}
		Step1 = Step1->next;
		Step2 = Step2->next;
	}
	return true;
}

template <typename ItemType>
bool List<ItemType>::operator!=(const List<ItemType> Other) const{
	return !(*this == Other);
}

template <typename ItemType>
List<ItemType>& List<ItemType>::operator+=(const List<ItemType> Other){
	if(Other.isEmpty()){
		return nullptr;
	}
	Node<ItemType>* Step = Other.head;
	while(Step->next != nullptr){
		Step = Step->next;
		Add_to_Tail(Step->key);
	}
	return *this;
}

template <typename ItemType>
List<ItemType> List<ItemType>::operator+ (const List<ItemType> Other) const{
	List<ItemType> Temp(*this);
	Temp += Other;
	return Temp;
}
