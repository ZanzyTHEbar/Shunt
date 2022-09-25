#ifndef SHUNT_hpp
#define SHUNT_hpp

#include <ctype.h>
#include <Arduino.h>

#define MAXOPSTACK 64
#define MAXNUMSTACK 64

class Shunt
{
public:
    Shunt();
    virtual ~Shunt();

    float shuntThis(char *in_formula);

private:
    struct operator_type
    {
        char op;
        int prec;
        int assoc;
        int unary;
        float (Shunt::*eval)(float a1, float a2);
    };

    enum
    {
        ASSOC_NONE = 0,
        ASSOC_LEFT,
        ASSOC_RIGHT
    };

    int nopstack;
    int nnumstack;
    float numstack[MAXNUMSTACK];

    operator_type operators[9];
    operator_type *opstack[MAXOPSTACK];

private:
    float eval_add(float a1, float a2);
    float eval_sub(float a1, float a2);
    float eval_uminus(float a1, float a2);
    float eval_exp(float a1, float a2);
    float eval_mul(float a1, float a2);
    float eval_div(float a1, float a2);

    float eval_mod(float a1, float a2);
    struct operator_type *getop(char ch);
    void push_opstack(operator_type *op);
    struct operator_type *pop_opstack();
    void push_numstack(float num);
    float pop_numstack();
    void shunt_op(operator_type *op);
    int isdigit_or_decimal(int c);
};

#endif
