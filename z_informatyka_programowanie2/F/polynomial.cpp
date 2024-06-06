#include "cstdarg"
#include "iostream"

class POLYNOMIAL {
   public:  // constructor and destructors
    POLYNOMIAL(){};
    POLYNOMIAL(int degree, ...) {
        va_list args;
        va_start(args, degree);
        POLYNOMIAL::integerNode* prev = nullptr;
        for (int i = 0; i <= degree; i++) {
            POLYNOMIAL::integerNode* cur = new POLYNOMIAL::integerNode;
            cur->coefficient = va_arg(args, int);
            prev ? prev->next = cur : head = cur;  // its first ?
            prev = cur;
        }
        va_end(args);
        CheckForReduce();
    }

    ~POLYNOMIAL() {
        integerNode* cur = head;
        while (cur) {
            integerNode* tmp = cur;
            cur = cur->next;
            delete tmp;
        }
    }

    void CheckForReduce() {
        int minValue = INT_MAX;
        for (POLYNOMIAL::integerNode* cur = head; cur; cur = cur->next) {
            if (cur->coefficient == 0) continue;
            if (minValue > abs(cur->coefficient)) minValue = abs(cur->coefficient);
        }

        for (int reducer = minValue; reducer > 1 ; reducer--) {
            if(minValue% reducer != 0) continue;
            bool toReduce = true;
            for (POLYNOMIAL::integerNode* cur = head; cur && toReduce; cur = cur->next) {
                if (cur->coefficient % reducer != 0) toReduce = false;
            }
            if (toReduce) {
                for (POLYNOMIAL::integerNode* cur = head; cur; cur = cur->next) {
                    cur->coefficient /= reducer;
                }
                minValue /= reducer;
                reducer = minValue+1;
            }
        }
    }

   public:   // operators overload
   private:  // params
    struct integerNode {
        integerNode* next = nullptr;
        int coefficient;
    };
    integerNode* head = nullptr;

   public:  // friend
    friend std::istream& operator>>(std::istream& is, POLYNOMIAL& c);
    friend std::ostream& operator<<(std::ostream& os, const POLYNOMIAL& c);
};

std::ostream& operator<<(std::ostream& os, const POLYNOMIAL& c) {
    os << "( ";
    for (POLYNOMIAL::integerNode* cur = c.head; cur; cur = cur->next) {
        os << cur->coefficient;
        cur->next ? os << ", " : os << " )";  // its last ?
    }
    return os;
}

std::istream& operator>>(std::istream& is, POLYNOMIAL& c) {
    int degree;
    is >> degree;
    POLYNOMIAL::integerNode* prev = nullptr;
    for (int i = 0; i <= degree; ++i) {
        POLYNOMIAL::integerNode* cur = new POLYNOMIAL::integerNode;
        is >> cur->coefficient;
        prev ? prev->next = cur : c.head = cur;  // its first ?
        prev = cur;
    }
    c.CheckForReduce();
    return is;
}