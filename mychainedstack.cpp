//
// Created by Guillaume on 05/10/2018.
//
#include <iostream>
#include "mychainedstack.h"

void Mychainedstack :: push(int number) {
    container *maillon = new container();
    maillon->item = number;
    maillon->next = nullptr;
    if(this->lc == nullptr){
        this->lc = maillon;
    }else{
        container *currentElement = this->lc;
        while(currentElement->next != nullptr){
            currentElement = currentElement->next;
        }
        currentElement->next = maillon;
    }
}
int Mychainedstack :: pop(){
    if(this->lc == nullptr) return -16384;
    container *currentElement = this->lc, *previousElement = this->lc;
    while(currentElement->next != nullptr){
        previousElement = currentElement;
        currentElement = currentElement->next;
    }
    int temp = currentElement->item;
    delete currentElement;
    if(currentElement == previousElement){
        this->lc = nullptr;
    }else{
        previousElement->next = nullptr;
    }
    return temp;
}
int Mychainedstack :: operator%(int mod) const{
    if(mod < 2) return -65536;
    return this->size() % mod;
}
int Mychainedstack :: size() const{
    container *currentElement = this->lc;
    int iterator = 1;
    if(currentElement != nullptr){
        while(currentElement->next != nullptr){
            currentElement = currentElement->next;
            iterator++;
        }
    }else{
        iterator = 0;
    }
    return iterator;
}
void Mychainedstack :: clear(){
    int nbrPop = this->size();
    for(int i=0; i<nbrPop; i++){
        this->pop();
    }
}