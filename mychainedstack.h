//
// Created by Guillaume on 05/10/2018.
//

#ifndef DEF_MYCHAINEDSTACK
#define DEF_MYCHAINEDSTACK
#include "mystack.h"

class Mychainedstack : public Mystack {
    public:
        struct container {
            int item;
            container *next;
        };
        container *lc = nullptr;
        void push(int number) override;
        int pop(void) override;
        int operator%(int mod) const override;
        void clear() override;
        int size() const;
};

#endif